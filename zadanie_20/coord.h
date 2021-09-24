#ifndef ZADANIE_20_COORD_H
#define ZADANIE_20_COORD_H
#include <iostream>
#include <cmath>

class Coords {
private:
    int x;
    int y;
    unsigned int quarter;
public:
    Coords(int x_p, int y_p): x{x_p}, y{y_p}
    {
        if(x>0){
            if(y>0){quarter = 1;}
            else{quarter = 2;}
        }
        else{
            if(y>0){quarter = 4;}
            else{quarter = 3;}
        }
        if(x==0 and y==0) quarter = 0;
    }
    Coords(): x{0}, y{0}, quarter{0}
    {}
    Coords(const Coords &other) = default;

    double getDistanceTo(const Coords &initial_coords) const{
        int x_distance{std::abs(initial_coords.x - x)};
        int y_distance{std::abs(initial_coords.y - y)};

        return std::sqrt((x_distance*x_distance) + (y_distance*y_distance));
    }

    unsigned int getQuarter() const{
        return quarter;
    }

    Coords& operator=(const Coords &other) = default;

    explicit operator bool() const{
        if (this->x==0 and this->y==0) return false;
        return true;
    }

    friend std::ostream& operator<<(std::ostream& out, const Coords& coords);
};

std::ostream& operator<<(std::ostream& out, const Coords& coords){
    out<<coords.x<<" "<<coords.y;
    return out;
}

#endif //ZADANIE_20_COORD_H
