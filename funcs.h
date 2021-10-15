#ifndef FUNCS
#define FUNCS
#include <vector>
#include "random.hpp"
#include <list>
#include <utility>
#include <functional>
using Random = effolkronium::random_static;
using std::cout;

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

std::vector<std::vector<int>> getMatrix(int M, int N = 0, int from = 0, int to = 64){
    if(!N) N = M;
    std::vector<std::vector<int>> matrix;
    matrix.reserve(M);
    for(int i{0}; i<M; ++i){
        matrix.push_back(getArray(N, from, to));
    }
    return matrix;
}

void printMatrix(std::vector<std::vector<int>> &matrix){
    for(std::vector<int> &vec:matrix){
        for(int i:vec){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

void printStr(const std::string& str){
    for(char c:str){
        cout<<c<<" ";
    }
    cout<<"\n";
}

#endif