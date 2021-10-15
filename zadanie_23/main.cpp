#include <iostream>
#include "../funcs.h"

void task_1(char C = 'H'){
    cout<<static_cast<char>(C-1)<<" "<<static_cast<char>(C+1);
}

void task_2(const std::string &S){
    for(char C:S){
        cout<<C<<" ";
    }
}

void task_3(const std::string &S){
    int from{'a'};
    int to{'z'};
    int count{0};

    for(char c:S){
        if (from<=c and c<=to){
            count++;
        }
    }
    cout<<count;
}

void task_4(char C, const std::string &S){
    std::string new_string;
    for(char letter:S){
        if(letter==C){
            new_string.push_back(letter);
            new_string.push_back(letter);
        }
        else{
            new_string.push_back(letter);
        }
    }
    printStr(new_string);
}

void task_5(const std::string &S, const std::string &S0){
    if(S0.empty()){
        cout<<"Введите подстроку для поиска"<<"\n";
        return;
    }
    if(S.empty()){
        cout<<"Введите строку"<<"\n";
        return;
    }
    int count{0};
    for(int i{0}; i<S.size()-S0.size(); ++i){
        int check{S.compare(i,S0.size(),S0)};
        if (check==0){
            ++count;
        }
    }
    cout<<count;
}

int main() {
    task_1();
    cout<<"\n\n";
    task_2("abcdefg");
    cout<<"\n\n";
    task_3("bfgHYfjElM"); //6
    cout<<"\n\n";
    task_4('a', "bbbagggaj");
    cout<<"\n\n";
    task_5("abcbbbcccbbbjhbbjk", "");
    return 0;
}
