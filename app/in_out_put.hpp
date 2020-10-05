#include<iostream>
#include<vector>
#include<tuple>
void get_location_input(std::vector<std::tuple<std::string, std::string, std::string>>* locations);
void print_results(std::tuple<std::string, std::string, std::string, double> nearest , std::tuple<std::string, std::string, std::string, double> furthest,std::vector<std::tuple<std::string, std::string, std::string>> locations);
