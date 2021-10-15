#include <iostream>
#include <vector>
#include "../random.hpp"
#include <algorithm>
using std::cout;
using std::endl;
using Random = effolkronium::random_static;

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
    std::vector<int> arr1{getArray(N)};
    std::vector<int> arr2{getArray(N)};
    std::swap(arr1, arr2);
    printArray(arr2);
    printArray(arr1);
}

void task_2(int N){
    std::vector<int> arr1{getArray(N)};
    std::vector<double> arr2(N);

    int sum{0};
    int count{0};

    for(int i{0}; i<N; ++i){
        sum += arr1[i];
        ++count;
        arr2[i] = static_cast<double>(sum)/count;
    }
    printArray(arr1);
    printArray(arr2);
}

void task_3(int N){
    std::vector<int> arr{getArray(N)};
    int odd{0};
    for(int i{N-1}; i>=0; --i){
        if (arr[i]%2==1) {
            odd = i;
            break;
        }
    }
    if(!odd) return;
    printArray(arr);
    for(int i{0}; i<odd; ++i){
        if (arr[i]%2==1) arr[i]+=arr[odd];
    }
    printArray(arr);
}

void task_4(int N){
    std::vector<int> arr{getArray(N)};
    int max{0};
    int max_index{-1};
    int min{99999};
    int min_index{-1};
    for(int i{0}; i<N; ++i){
        if (arr[i]<min) {
            min = arr[i];
            min_index = i;
        }
        if (arr[i]>max){
            max = arr[i];
            max_index = i;
        }
    }
    if(max_index<min_index) std::swap(max_index, min_index);
    printArray(arr);
    for(int i{min_index+1}; i<max_index; ++i) {
        arr[i] = 0;
    }
    printArray(arr);
}

void task_5(int N){
    std::vector<int> arr{45,3,5,7,8,9,13,16,34,67,78,90};
    printArray(arr);
    std::sort(arr.begin(),arr.end());
    printArray(arr);
}

int main() {
    task_1(12);
    cout<<"\n\n";
    task_2(12);
    cout<<"\n\n";
    task_3(12);
    cout<<"\n\n";
    task_4(12);
    cout<<"\n\n";
    task_5(12);

    return 0;
}
