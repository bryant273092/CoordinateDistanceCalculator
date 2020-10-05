#include<iostream>
#include "in_out_put.hpp"
#include<cmath>
#include<unordered_set>

//Finds the difference in latitudes and longitude, takes 2 cordinates as double and 2 directions as string
//Returns the difference as a double 
double find_difference (double loc1, double loc2, std::string dir1, std::string dir2){
    std::unordered_set<std::string> multiply =  {"N", "S"};
    std::unordered_set<std::string> multiply2 =  {"E", "W"};
    if (multiply.find(dir1) != multiply.end()){
        if (multiply.find(dir2) != multiply.end()){
            if ((dir1.compare(dir2)) != 0){
                return loc1 + loc2;
            }  
        }  
    }
    else if (multiply2.find(dir1) != multiply2.end()){
        if (multiply2.find(dir2) != multiply2.end()){
            if ((dir1.compare(dir2)) != 0){
                return loc1 + loc2;
            }
        }  
    }
    return loc1 - loc2;
}
//Uses haversine formula to find the mile distance between two locations
//Takes the difference in latitude, latitude 1, latitude 2, and difference in longitude as parameters
//Returns distance in miles as double type
double get_mile_distance (double dlat, double lat1, double lat2, double dlon){
    double ang_to_rad = (M_PI/180);
    double haversine1 = (pow(sin((dlat * ang_to_rad)/2), 2))+ (cos(lat1*ang_to_rad) * cos(lat2*ang_to_rad)* (pow(sin((dlon*ang_to_rad)/2),2)));
    double haversine2 = 2 * (atan2(sqrt(haversine1), sqrt(1-haversine1)));
    double radius = 3959.9;
    double mile_distance = radius * haversine2;
    return mile_distance;
}
//Overview function that determines the great circle distance for each location passed in
void great_circle_distance( std::vector<std::tuple<std::string, std::string, std::string>> locations,  std::vector<std::tuple<std::string, std::string, std::string, double>>* distances){
    std::tuple start_location = locations[0];
    double lat1 = std::stod((std::get<0>(start_location)).substr(0, (std::get<0>(start_location)).find('/')));
    std::string lat1_direction = (std::get<0>(start_location)).substr((std::get<0>(start_location)).find('/')+1,(std::get<0>(start_location)).find('/') + 1 );
    double lon1 = std::stod((std::get<1>(start_location)).substr(0, (std::get<1>(start_location)).find('/')));
    std::string lon1_direction = (std::get<1>(start_location)).substr((std::get<1>(start_location)).find('/')+1,(std::get<1>(start_location)).find('/') + 1 );
    
    for ( int i = 1 ; i < locations.size() ; i++){
        double lat2 = std::stod((std::get<0>(locations[i])).substr(0, (std::get<0>(locations[i])).find('/')));
        std::string lat2_direction = (std::get<0>(locations[i])).substr((std::get<0>(locations[i])).find('/')+1,(std::get<0>(locations[i])).find('/') + 1 );
        double lon2 = std::stod((std::get<1>(locations[i])).substr(0, (std::get<1>(locations[i])).find('/')));
        std::string lon2_direction = (std::get<1>(locations[i])).substr((std::get<1>(locations[i])).find('/')+1,(std::get<1>(locations[i])).find('/') + 1 );
        double dlat = find_difference(lat1, lat2, lat1_direction, lat2_direction);
        double dlon = find_difference(lon1, lon2, lon1_direction, lon2_direction);
        double mile_distance = get_mile_distance (dlat, lat1, lat2, dlon);
        (*distances).push_back(std::make_tuple(std::get<0>(locations[i]), std::get<1>(locations[i]), std::get<2>(locations[i]), mile_distance));
    }
    
}

//Finds the nearest location by miles
std::tuple<std::string, std::string, std::string, double> find_nearest(std::vector<std::tuple<std::string, std::string, std::string, double>>* distances){
    std::tuple nearest = (*distances)[0];
    for (int i = 0 ; i < (*distances).size() ; i++){
        if ((std::get<3>(nearest)) > (std::get<3>((*distances)[i]))){
            nearest = (*distances)[i];
        }
    }
    return nearest;
}
//Finds the furthest location by miles
std::tuple<std::string, std::string, std::string, double> find_furthest(std::vector<std::tuple<std::string, std::string, std::string, double>>* distances){
    std::tuple furthest = (*distances)[0];
    for (int i = 0 ; i < (*distances).size() ; i++){
        if (std::get<3>(furthest) < std::get<3>((*distances)[i])){
            furthest = (*distances)[i];
        }
    }
    return furthest;
}

std::tuple<std::string, std::string, std::string, double> startAlgo(){
    std::vector<std::tuple<std::string, std::string, std::string>> locations;
    std::vector<std::tuple<std::string, std::string, std::string>>* locations_pointer = &locations;
    get_location_input(locations_pointer);
    std::vector<std::tuple<std::string, std::string, std::string, double>> distances;
    std::vector<std::tuple<std::string, std::string, std::string, double>>* distances_pointer = &distances;
    
    great_circle_distance(locations, distances_pointer);
    std::tuple nearest = find_nearest(distances_pointer);
    std::tuple furthest = find_furthest(distances_pointer);
    print_results(nearest, furthest, locations);
    return nearest;
}


int main(){
    std::tuple<std::string, std::string, std::string, double> nearest = startAlgo();
    return 0;
}

