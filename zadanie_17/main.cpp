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

int task_3(int N){
    std::vector<int> arr(N);
    for (int i{0}; i<N; ++i){
        arr[i] = Random::get(1, 128);
    }

    int min{99999};

    for (int i{2}; i<N; i+=2){
        if (arr[i]<min) min = arr[i];
    }
    return min;
}

int task_4(int N){
    std::vector<int> arr(N);
    for (int i{0}; i<N; ++i){
        arr[i] = Random::get(1, 128);
    }

    if (arr[N-1] > arr[N-2]) return N-1; // Если последний элемент массива больше, чем предпоследний, то он является последним локальным максимом

    int index_of_local_max{0};
    if(arr[0]>arr[1]) index_of_local_max = 0;

    for(int i{1}; i<N-1; ++i){
        if (arr[i]>arr[i+1] and arr[i]>arr[i-1]) index_of_local_max = i;
    }

    return index_of_local_max;
}

void task_5(int N = 13){
    std::vector<int> arr{2,7,3,5,1,56,12,89,345,234,3,45,90};

    for(int i{0}; i<N-1; ++i){
        for(int j{i+1}; j<N; ++j){
            if (arr[i] == arr[j]) {
                cout << i << " " << j << endl;
                return;
            }
        }
    }
}


int main() {
    cout<<task_1(10,3,10)<<endl;
    cout<<task_2()<<endl;
    cout<<task_3(24)<<endl;
    cout<<task_4(12)<<endl;
    task_5();
    return 0;
}
