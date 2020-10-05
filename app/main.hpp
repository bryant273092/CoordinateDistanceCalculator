#include "in_out_put.hpp"
double find_difference (double loc1, double loc2, std::string dir1, std::string dir2);
double get_mile_distance (double dlat, double lat1, double lat2, double dlon);
void great_circle_distance( std::vector<std::tuple<std::string, std::string, std::string>> locations,  std::vector<std::tuple<std::string, std::string, std::string, double>>* distances);
std::tuple<std::string, std::string, std::string, double> find_nearest(std::vector<std::tuple<std::string, std::string, std::string, double>>* distances);
std::tuple<std::string, std::string, std::string, double> find_furthest(std::vector<std::tuple<std::string, std::string, std::string, double>>* distances);
std::tuple<std::string, std::string, std::string, double> startAlgo();