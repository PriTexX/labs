#include <iostream>
using std::cout;
using std::endl;

void PowerA3(double a, double &b){
    b = a*a*a;
    cout<<b;
}

int Sign(double x){
    if (x<0) return -1;
    if (x==0) return 0;
    return 1;
}

double RingS(double r1, double r2){
    return (3.14*r1*r1) - (3.14*r2*r2);
}

int Quarter(int x, int y){
    if (x>0){
        if (y>0) return 1;
        else return 2;
    }
    else {
        if (y<0) return 3;
        else return 4;
    }
    return 0;
}

double Fact2(int n){
    int i = n%2==0 ? 2 : 1;
    double val{1};

    for (i; i<=n; i+=2){
        val*=i;
    }
    return val;
}

int main() {
    double b;
    PowerA3(2, b);
    cout<<"\n\n";
    cout<<Sign(3)+Sign(-2);
    cout<<"\n\n";
    cout<<RingS(5,3)<<" ";
    cout<<RingS(2,1)<<" ";
    cout<<RingS(7,2)<<" ";
    cout<<"\n\n";
    cout<<Quarter(3,4)<<" ";
    cout<<Quarter(-3,-4)<<" ";
    cout<<Quarter(3,-4)<<" ";
    cout<<"\n\n";
    cout<<Fact2(5);
    return 0;
}
