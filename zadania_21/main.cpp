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

std::vector<std::vector<int>> getMatrix(int M, int N = 0){
    if(!N) N = M;
    std::vector<std::vector<int>> matrix;
    matrix.reserve(M);
    for(int i{0}; i<M; ++i){
        matrix.push_back(getArray(N, 0, 64));
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
}

void task_1(int N){
    std::vector<std::vector<int>> matrix{getMatrix(N)};
    printMatrix(matrix);
    std::vector<int> arr(N * N);
    int INT{N - 1};
    int MULT{0};
    int count;
    for (int j{0}; j<N/2; ++j){
//        if(j>=1) MULT += ((INT - (j-1)) * (INT - (j-1)));
        if(j>=1) MULT += count*4;
        count = 0;
        for(int i{0}; i < INT-(j*2); ++i){
            ++count;
            arr[i+MULT] = matrix[i+j][j];
            arr[i+(INT-j)+MULT-j] = matrix[INT-j][i+j];
            arr[i+(INT-j)*2+MULT-j*2] = matrix[INT-i-j][INT-j];
            arr[i+(INT-j)*3+MULT-j*3] = matrix[j][INT-i-j];
        }
    }
    arr[N*N-1] = matrix[N/2][N/2];
    cout<<"\n";
    printArray(arr);

}

int main() {
    task_1(9);
    cout<<"\n\n";

    return 0;
}
