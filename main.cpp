#include "headers/first_util.h"  // include header

int main() {
    // Add you main function here
    // Call other functions as needed
    std::vector<int> array = {1, 5, 2, 7, 9, 10, 4, 8, 3, 6};
    
    std::vector<Query<int>> queries = {Query<int>(2,8), Query<int>(0,9), Query<int>(3,6), Query<int>(5,8)};
    // Query<int> query(2,8);
    moAlgorithm(array, queries);
    return 0;
}