#include <iostream>
#include "../random.hpp"
#include <list>
#include <map>
using Random = effolkronium::random_static;
using std::cout;
using std::endl;

void printArray(std::vector<int>& array){
    for(int element: array) cout<<element<<" ";
    cout<<"\n";
}

void printArray(std::list<int>& array){
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

std::list<int> getList(int N, int from = 1, int to = 128){
    std::list<int> list;
    for(int i{0}; i<N; ++i){
        list.push_back(Random::get(from, to));
    }
    return list;
}

void task_1(int N){
//    std::vector<int> arr{getArray(N)};
    std::vector<int> arr{1,1,1,1,1,1,1,1,1,1};
    std::vector<int> clearedArr;

    printArray(arr);
    for(int i{0}; i<N-1;){
        if (arr[i]==arr[i+1]){
            clearedArr.push_back(arr[i]);
            i+=2;
        }
        else {
            clearedArr.push_back(arr[i]);
            ++i;
        }
    }
    if(arr[N-1] != arr[N-2]) clearedArr.push_back(arr[N-1]);
    arr = clearedArr;
    printArray(arr);
}

void task_2(int N){
//    std::list<int> list{getList(N)};
    std::list<int> list{4,28,4,2,5,6,1,5,5,7,7,14};
    std::map<int, int> dict;
    printArray(list);
    for(int i:list){
        if (dict.contains(i)){
            dict[i] += 1;
        }
        else { dict[i] = 1; }
    }
    for (std::map<int,int>::iterator it{dict.begin()}; it!=dict.end(); it++){
        if (it->second==2) list.remove(it->first);
    }
    printArray(list);
}

void task_3(int N){
    std::list<int> list{getList(N)};
    printArray(list);
    int max{0};
    int min{99999};
    std::list<int>::iterator max_it;
    std::list<int>::iterator min_it;

    for(auto it{list.begin()}; it!=list.end(); it++){
        if(*it>max) {
            max = *it;
            max_it = ++it; // Чтобы вставить после max, а не перед
            --it; // вернуть итератор на прежнюю позицию
        }
        if(*it<min) {
            min = *it;
            min_it = it;
        }
    }
    list.insert(max_it, 0);
    list.insert(min_it, 0);
    printArray(list);
}

void task_4(int N){
    std::list<int> list{getList(N, -10, 10)};
    printArray(list);

    for(auto it{list.begin()}; it!=list.end(); it++){
        if(*it<0){
            list.insert(++it, 0);
            --it;
        }
    }
    printArray(list);
}

void task_5(int N){
    std::list<int> list{getList(N, -10, 10)};
    printArray(list);

    for(auto it{list.begin()}; it!=list.end(); it++){
        if(*it>0){
            list.insert(it, 0);
        }
    }
    printArray(list);
}

int main() {
    task_1(10);
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
