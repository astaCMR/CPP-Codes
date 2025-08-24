#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {3,1,2};
    sort(v.begin(), v.end());   // <-- Will this compile?
    std::cout << "Succeded" << std::endl;
}
