#include <iostream>
#include "../random.hpp"
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


    std::vector<int> temp;
    for(int i{N-1}; i>(N - arrLen.back() - 1); --i){
        temp.push_back(arr[i]);
    }

    int begin{0};
    for (int i{0}; i<K-1; ++i){
        begin += arrLen[i];
    }

    for(int i{begin}, j{}, c{0}; i < begin + arrLen[K - 1]; ++i, ++c, ++j){

    }
}

int main() {
    task_1(12);
    cout<<"\n\n";
    task_2(12, 2);
    cout<<"\n\n";
    task_3(12, 2);
    cout<<"\n\n";

    return 0;
}
