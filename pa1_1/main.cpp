#include <iostream>
#include "pa1.h"

#include <iostream>
#include "pa1.h"

Stress_ball::Stress_ball() {
    srand(time(NULL));
    color = static_cast<Stress_ball_colors>(rand() % 4);
    size = static_cast<Stress_ball_sizes>(rand() % 3);
}
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) {
    color = c;
    size = s;
}
int Stress_ball::get_color() const {
    return color;
}
int Stress_ball::get_size() const {
    return size;
}
bool Stress_ball::operator ==(const Stress_ball& sb) {
    return (color == sb.get_color() && size == sb.get_size());
}
void operator <<(std::ostream& o, const Stress_ball& sb) {
    o << "(";
    switch (sb.get_color()) {
        case 0: o << "red"; break;
        case 1: o << "blue"; break;
        case 2: o << "yellow"; break;
        case 3: o << "green"; break;
    }
    o << ", ";
    switch (sb.get_size()) {
        case 0: o << "small"; break;
        case 1: o << "medium"; break;
        case 2: o << "large"; break;
    }
    o << ")";
}

int main() {
    Stress_ball x;
    Stress_ball y {blue, large};
    Stress_ball z;
    std::cout << x.get_color() << " " << z.get_size() << std::endl;
    std::cout << (x == y) << std::endl;
    std::cout << x;
    std::cout << y;
    std:: cout << z;
    std::cout << std::endl;
}