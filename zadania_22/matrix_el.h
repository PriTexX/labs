#ifndef ZADANIA_22_MATRIX_EL_H
#define ZADANIA_22_MATRIX_EL_H


class MatrixEl {
public:
    int value;
    int x;
    int y;

    MatrixEl(int p_x, int p_y, int p_value): x{p_x}, y{p_y}, value{p_value}
    {}

    MatrixEl& operator=(const MatrixEl &other) = default;
    bool operator>(const MatrixEl &other) const{
        return this->value>other.value;
    }
    bool operator<(const MatrixEl &other) const{
        return !(*this>other);
    }
    bool operator<(int val) const{
        return this->value<val;
    }
    bool operator>(int val) const{
        return !(*this<val);
    }
    friend std::ostream& operator<<(std::ostream& out, MatrixEl& el);
};

std::ostream& operator<<(std::ostream& out, MatrixEl& el){
    std::cout<<el.value<<" "<<el.x<<" "<<el.y<<"\n";
    return out;
}
#endif
