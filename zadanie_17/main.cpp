#include <iostream>
#include <vector>
#include "../random.hpp"
#include <algorithm>
#include <set>
using std::cout;
using std::endl;
using Random = effolkronium::random_static;

double task_1(int N, int K, int L){
    std::vector<int> arr(N);
    for(int i{0}; i<N; ++i){
        arr[i] = Random::get(1,36);
    }

    int sum{0};
    int count{0};

    for(int i{K}; i<L; ++i){
        sum += arr[i];
        ++count;
    }

    return static_cast<double>(sum)/count;
}

int task_2(int N = 9){
    std::vector<int> set{5,3,7,11,9,17,19,13,15};
    std::sort(set.begin(), set.end());

    int dif{set[1] - set[0]};
    for (int i{1}; i<N-1; ++i){
        if (set[i+1] - set[i] != dif) return 0;
    }
    return dif;
}



int main() {
    cout<<task_1(10,3,10)<<endl;
    cout<<task_2()<<endl;
    return 0;
}
