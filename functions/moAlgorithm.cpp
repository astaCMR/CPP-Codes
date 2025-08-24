#include "../headers/first_util.h"
#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>

template <typename T, typename S>
void moAlgorithm(const std::vector<T> &arr, std::vector<Query<S>> &queries) {
    long long block_size = sqrt(arr.size());
    std::sort(queries.begin(), queries.end(), [&block_size](const Query<S> &x, const Query<S> &y) {
        S block_x = x.L / block_size;
        S block_y = y.L / block_size;
        if (block_x != block_y)
            return block_x < block_y;
        return x.R < y.R;
    });
    S currL = 0, currR = 0;
    long long currSum = 0;
    for(long long i=0;i<queries.size();i++) {
        S L=queries[i].L, R=queries[i].R;
        while(currL<L){
            currSum -= arr[currL];
            currL++;
        }
        while(currL>L){
            currSum += arr[currL-1];
            currL--;    
        }
        while(currR<=R){
            currSum += arr[currR];
            currR++;
        }
        while(currR>R+1){
            currSum -= arr[currR-1];
            currR--;
        }
        
        // Print sum of current range
        std::cout << "Sum of [" << L << ", " << R
             << "] is "  << currSum << std::endl;
    }
}

template void moAlgorithm(const std::vector<int> &arr, std::vector<Query<int>>& queries);
template void moAlgorithm(const std::vector<long long> &arr, std::vector<Query<long long>>& queries);
template void moAlgorithm(const std::vector<int> &arr, std::vector<Query<long long>>& queries);
template void moAlgorithm(const std::vector<long long> &arr, std::vector<Query<int>>& queries);
