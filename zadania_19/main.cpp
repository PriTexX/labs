#include <iostream>
#include "../random.hpp"
using Random = effolkronium::random_static;
using std::cout;
using std::endl;

void printArray(std::vector<int>& array){
    for(int element: array) cout<<element<<" ";
    cout<<"\n";
}

void printArray(std::vector<double>& array){
    for(double element: array) cout<<element<<" ";
    cout<<"\n";
}

std::vector<int> getArray(int N, int from = 1, int to = 128){
    std::vector<int> arr(N);
    for(int i{0}; i<N; ++i){
        arr[i] = Random::get(from, to);
    }
    return arr;
}

void task_1(int N){
//    std::vector<int> arr{getArray(N)};
    std::vector<int> arr{5,2,3,1,7,7,8,9,34,34,12,78};
    std::vector<int> clearedArr;

    printArray(arr);
    for(int i{0}; i<N-1;){
        if (arr[i]==arr[i+1]){
            clearedArr.push_back(arr[i]);
            i+=2;
        }
        else {

        }
    }
    printArray(clearedArr);
    printArray(arr);
}

int main() {
    task_1(12);
    cout<<"\n\n";
    return 0;
}
