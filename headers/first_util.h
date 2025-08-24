#pragma once

#include<vector>

//Struct definitions here
template <typename T>
struct Query {
    T L, R;
    Query(T L, T R) : L(L), R(R) {};
};

// function declarations here
int getGCD(int a, int b);

template <typename T, typename S>
std::vector<long long> sqrtDecomposition(const std::vector<T>& arr, const std::vector<std::vector<S>>& queries);

template <typename T, typename S>
void moAlgorithm(const std::vector<T> &arr, std::vector<Query<S>> &queries);