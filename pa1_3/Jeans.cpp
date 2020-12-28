#include "Jeans.h"

Jeans::Jeans() {
    srand(time(NULL));
    color = static_cast<Jeans_colors>(rand() % 4);
    size = static_cast<Jeans_sizes>(rand() % 4);
}
Jeans::Jeans(Jeans_colors c, Jeans_sizes s) {
    color = c;
    size = s;
}
Jeans_colors Jeans::get_color() const {
    return color;
}
Jeans_sizes Jeans::get_size() const {
    return size;
}
bool Jeans::operator ==(const Jeans& sb) {
    return (color == sb.get_color() && size == sb.get_size());
}
ostream& operator <<(std::ostream& o, const Jeans& sb) {
    o << "(";
    switch (sb.get_color()) {
        case Jeans_colors::white: o << "white"; break;
        case Jeans_colors::black: o << "black"; break;
        case Jeans_colors::blue: o << "blue"; break;
        case Jeans_colors::grey: o << "grey"; break;
    }
    o << ", ";
    switch (sb.get_size()) {
        case Jeans_sizes::small: o << "small"; break;
        case Jeans_sizes::medium: o << "medium"; break;
        case Jeans_sizes::large: o << "large"; break;
        case Jeans_sizes::xlarge: o << "xlarge"; break;
    }
    o << ")";
    return o;
}