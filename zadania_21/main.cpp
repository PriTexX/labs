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
}

void task_1(int N){
    std::vector<std::vector<int>> matrix{getMatrix(N,N,10,99)};
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

int mult(std::vector<int> &arr){
    int mult{1};
    for(int i: arr){
        mult*=i;
    }
    return mult;
}

void task_2(int M, int N, int K){
    auto matrix{getMatrix(M, N)};
    printMatrix(matrix);

    int sum{0};
    for(int i{0}; i<N; ++i){
        sum+=matrix[K][i];
    }
    cout<<"\n";
    cout<<sum<<" "<<mult(matrix[K]);
}

void task_3(int M, int N){
    int index{0};
    int min{99999999};
    int cur_mult;

    auto matrix{getMatrix(M, N)};
    for(int i{0}; i<M; ++i){
        cur_mult = mult(matrix[i]);
        if(cur_mult<min){
            min = cur_mult;
            index = i;
        }
    }
    cout<<index<<" "<<min;
}

double getAverage(std::vector<std::vector<int>> &matrix, int column_index){
    int sum{0};
    int count{0};

    for(int i{0}; i<matrix.size(); ++i){
        sum+=matrix[i][column_index];
        count+=1;
    }
    return static_cast<double>(sum)/count;
}

void task_4(int M, int N){
    auto matrix{getMatrix(5,5)};
    printMatrix(matrix);
    cout<<"\n";

    for(int i{0}; i<N; ++i){
        double average{getAverage(matrix, i)};
        int count{0};

        for (int j{0}; j<M; ++j){
            if (matrix[j][i]>average){
                ++count;
            }
        }
        cout<<count<<" ";
    }
}

int task_5(int M, int N){
    auto matrix{getMatrix(5,5, 1 , 3)};
    printMatrix(matrix);
    cout<<"\n";

    for(int i{0}; i<N; ++i){
        bool flag = true;
        for(int j{0}; j<M; ++j){
            if(matrix[j][i]%2==0){
                flag = false;
                break;
            }
        }
        if (flag) return i;
    }
    return 0;
}

int main() {
    task_1(11);
    cout<<"\n\n";
    task_2(5,6,2);
    cout<<"\n\n";
    task_3(7,4);
    cout<<"\n\n";
    task_4(5,5);
    cout<<"\n\n";
    cout<<task_5(5,5);
    cout<<"\n\n";

    return 0;
}














