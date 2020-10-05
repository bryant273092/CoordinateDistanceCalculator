#include<iostream>
#include<vector>
#include<tuple>
void get_location_input(std::vector<std::tuple<std::string, std::string, std::string>>* locations){
    std::string latitude, longitude, location_name;
    std::cin >> latitude >> longitude;
    std::getline(std::cin.ignore(1), location_name);
    (*locations).push_back(make_tuple(latitude, longitude, location_name));
    int number_of_locations;
    std::cin >> number_of_locations;
    for (int i = 0 ; i < number_of_locations; i++){
        std::string latitude, longitude, location_name;
        std::cin >> latitude >> longitude;
        std::getline(std::cin.ignore(1), location_name);
        (*locations).push_back(make_tuple(latitude, longitude, location_name));
    }
    
}
void print_results(std::tuple<std::string, std::string, std::string, double> nearest , std::tuple<std::string, std::string, std::string, double> furthest,std::vector<std::tuple<std::string, std::string, std::string>> locations){
    std::cout << "Start Location: " << std::get<0>(locations[0]) + " " << std::get<1>(locations[0]) << " (" +std::get<2>(locations[0]) + ") " << std::endl;
    std::cout << "Closest Location: " << std::get<0>(nearest) + " " << std::get<1>(nearest) << " (" +std::get<2>(nearest) + ") (" <<  std::get<3>(nearest) << " miles) "  << std::endl;
    std::cout << "Farthest Location: " << std::get<0>(furthest) + " " << std::get<1>(furthest) << " (" +std::get<2>(furthest) + ") ("<<  std::get<3>(furthest) << " miles) "<< std::endl;
}