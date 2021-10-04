#include <iostream>
#include "../funcs.h"
#include "matrix_el.h"

std::pair<__gnu_cxx::__normal_iterator<int *, std::vector<int>>, __gnu_cxx::__normal_iterator<int *, std::vector<int>>>
min_max_vec(std::vector<int> &vec){
    auto min_max{std::minmax_element(vec.begin(),vec.end())};
    return min_max;
}

void task_1(int M, int N){
    auto matrix{getMatrix(M, N)};

    for(auto vec:matrix){
        int min_index;
        int max_index;
        int max{0};
        int min{99999999};
        printArray(vec);
        for(int i{0}; i<N; ++i){
            if (vec[i]>max){
                max = vec[i];
                max_index = i;
                continue;
            }
            if (vec[i]<min){
                min = vec[i];
                min_index = i;
            }
        }
        vec[min_index] = max;
        vec[max_index] = min;
        printArray(vec);
        cout<<"\n\n";
    }
}

void task_2(int M, int N){
    auto matrix{getMatrix(M)};
    printMatrix(matrix);
    MatrixEl min{0,0,matrix[0][0]};
    MatrixEl max{0,0,matrix[0][0]};

    for(int i{0}; i<N; ++i){
        for(int j{1};j<M; ++j){
            if(max<matrix[i][j]){
                max.x = i; max.y = j; max.value = matrix[i][j];
            }
            if(min>matrix[i][j]){
                min.x = i; min.y = j; min.value = matrix[i][j];
            }
        }
    }
    for(int i{0}; i<M; ++i){
        std::swap(matrix[i][max.y], matrix[i][min.y]);
    }
    printMatrix(matrix);
}

void task_3(int M, int N){
    auto matrix{getMatrix(M, N, 10, 99)};
    printMatrix(matrix);
//    cout<<matrix[M/2-1][N/2-1];
//    cout<<matrix[M/2][N/2];
    for(int i{0}, k{M/2}; i<M/2; ++i, ++k){
        for(int j{0}, l{N/2}; j<N/2; ++j, ++l){
            std::swap(matrix[i][j], matrix[k][l]);
        }
    }
    cout<<"\n";
    printMatrix(matrix);
}

void task_4(int M, int N){
    auto matrix{getMatrix(M,N)};
    printMatrix(matrix);

    std::sort(matrix.begin(), matrix.end(), [](std::vector<int> &a, std::vector<int> &b){
        return a[0]<b[0];
    });
    printMatrix(matrix);
}

void task_5(int M){
    auto matrix{getMatrix(M,M,1,5)};
    printMatrix(matrix);

    for(int i{M-1}, count{0}; i>0; --i, ++count){
        int sum1{0};
        int sum2{0};

        for(int j{0}; j<count+1; ++j){
            sum1+=matrix[i+j][j];
            sum2+=matrix[j][i+j];
        }
        cout<<sum1<<" "<<sum2<<" ";
    }
    int sum{0};
    for(int d{0}; d<M; ++d){
        sum+=matrix[d][d];
    }
    cout<<sum;
}

int main() {
    task_1(3,7);
    cout<<"\n\n";
    task_2(5,5);
    cout<<"\n\n";
    task_3(4,4);
    cout<<"\n\n";
    task_4(5,5);
    cout<<"\n\n";
    task_5(5);
    cout<<"\n\n";
    return 0;
}
