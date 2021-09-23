#include <iostream>
#include "../random.hpp"
#include "coord.h"
using Random = effolkronium::random_static;
using std::cout;

void printArray(std::vector<int>& array){
    for(int element: array) cout<<element<<" ";
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
//    std::vector<int> arr{getArray(N, 1, 10)};
    std::vector<int> arr{1,1,1,5,5,6,4,3,7,7,8,8};
    std::vector<int> arrLen;
    std::vector<int> arrValues;

    int count{1};
    for(int i{1}; i<N; ++i){
        if (arr[i-1]==arr[i]){
            ++count;
        }
        else{
            arrLen.push_back(count);
            arrValues.push_back(arr[i-1]);
            count = 1;
        }
    }
    arrLen.push_back(count);
    arrValues.push_back(arr[N-1]);
    printArray(arr);
    printArray(arrLen);
    printArray(arrValues);
}

void task_2(int N, int L){
    //    std::vector<int> arr{getArray(N, 1, 10)};
    std::vector<int> arr{2,1,1,5,5,5,4,7,7,7,9,8};
    std::vector<int> arrLen;
    std::vector<int> arrValues;

    int count{1};
    for(int i{1}; i<N; ++i){
        if (arr[i-1]==arr[i]){
            ++count;
        }
        else{
            arrLen.push_back(count);
            arrValues.push_back(arr[i-1]);
            count = 1;
        }
    }
    arrLen.push_back(count);
    arrValues.push_back(arr[N-1]);
    cout<<"Изначальный массив - ";
    printArray(arr);
    cout<<"Массив длинн серий - ";
    printArray(arrLen);
    cout<<"Массив значений элементов - ";
    printArray(arrValues);

    auto it{arr.begin()};
    for (int i{0}; i<arrLen.size(); ++i){
        if (arrLen[i]>L){
            arr.erase(it, it+arrLen[i]);
            arr.insert(it, 0);
            ++it;
        }
        else {
            it+=arrLen[i];
        }
    }
    cout<<"Измененный массив - ";
    printArray(arr);
}

void task_3(int N, int K){
    //    std::vector<int> arr{getArray(N, 1, 10)};
    std::vector<int> arr{2,1,1,5,5,5,4,7,7,7,8,8};
    std::vector<int> arrLen;
    std::vector<int> arrValues;

    int count{1};
    for(int i{1}; i<N; ++i){
        if (arr[i-1]==arr[i]){
            ++count;
        }
        else{
            arrLen.push_back(count);
            arrValues.push_back(arr[i-1]);
            count = 1;
        }
    }
    arrLen.push_back(count);
    arrValues.push_back(arr[N-1]);
    cout<<"Изначальный массив - ";
    printArray(arr);
    cout<<"Массив длинн серий - ";
    printArray(arrLen);
    cout<<"Массив значений элементов - ";
    printArray(arrValues);


    auto it_begin_end{arr.end() - arrLen.back()};
    auto it_end_end{arr.end()};

    int sum{0};
    for(int i{0}; i<K-1; ++i){
        sum += arrLen[i];
    }
    auto it_begin_K{arr.begin()+sum};
    auto it_end_K{arr.begin()+sum+arrLen[K-1]};

    std::vector<int> newArr;
    newArr.insert(newArr.begin(),arr.begin(), it_begin_K);
    newArr.insert(newArr.end(), it_begin_end, it_end_end);
    newArr.insert(newArr.end(), it_end_K, it_begin_end);
    newArr.insert(newArr.end(), it_begin_K, it_end_K);
    cout<<"Измененный массив - ";
    printArray(newArr);
}

void task_4(int N){
    std::vector<Coords> arr;
    for(int i{0}; i<N; ++i){
        arr.emplace_back(Random::get(-5,10), Random::get(-10, 5));
    }

    Coords start_coords{0,0};
    Coords longest_coords{0,0};
    for(Coords coords:arr){
        cout<<coords<<"   ";
        if (coords.getQuarter()!=2) continue;
        if (coords.getDistanceTo(start_coords) > longest_coords.getDistanceTo(start_coords)){
            longest_coords = coords;
        }
    }
    cout<<"\n";
    cout<<longest_coords;
}

int main() {
    task_1(12);
    cout<<"\n\n";
    task_2(12, 2);
    cout<<"\n\n";
    task_3(12, 3);
    cout<<"\n\n";
    task_4(12);
    cout<<"\n\n";

    return 0;
}
