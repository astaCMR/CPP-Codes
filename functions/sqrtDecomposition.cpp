#include<cmath>
#include<vector>

template <typename T, typename S>
std::vector<long long> sqrtDecomposition(const std::vector<T>& arr, const std::vector<std::vector<S>>& queries) {
    long long block_size = ceil(sqrt(arr.size()));
    std::vector<long long> blocks;
    long long sum = 0;
    for(long long i=0;i<arr.size();i++){
        if(i % block_size == 0) {
            if(i != 0) {
                blocks.push_back(sum);
            }
            sum = 0;
        }
        sum += arr[i];
    }
    std::vector<long long> results;
    for(long long i=0;i<queries.size();i++) {
        S l = queries[i][0];
        S r = queries[i][1];
        S block_start = l / block_size;
        S block_end = r / block_size;
        long long total_sum = 0;

        if(block_start == block_end) {
            for(S j=l; j<=r; j++) {
                total_sum += arr[j];
            }
        } else {
            for(S j=l; j < (block_start + 1) * block_size; j++) {
                total_sum += arr[j];
            }
            for(S j=block_start + 1; j < block_end; j++) {
                total_sum += blocks[j];
            }
            for(S j=block_end * block_size; j <= r; j++) {
                total_sum += arr[j];
            }
        }
        results.push_back(total_sum);
    }
    return results;
}

template std::vector<long long> sqrtDecomposition(const std::vector<long long>& arr, const std::vector<std::vector<long long>>& queries);
template std::vector<long long> sqrtDecomposition(const std::vector<long long>& arr, const std::vector<std::vector<int>>& queries);
template std::vector<long long> sqrtDecomposition(const std::vector<int>& arr, const std::vector<std::vector<long long>>& queries);
template std::vector<long long> sqrtDecomposition(const std::vector<int>& arr, const std::vector<std::vector<int>>& queries);
