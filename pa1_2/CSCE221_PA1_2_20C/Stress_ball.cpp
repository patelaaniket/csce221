#include "Stress_ball.h"

Stress_ball::Stress_ball() {
    srand(time(NULL));
    color = static_cast<Stress_ball_colors>(rand() % 4);
    size = static_cast<Stress_ball_sizes>(rand() % 3);
}
Stress_ball::Stress_ball(Stress_ball_colors c, Stress_ball_sizes s) {
    color = c;
    size = s;
}
Stress_ball_colors Stress_ball::get_color() const {
    return color;
}
Stress_ball_sizes Stress_ball::get_size() const {
    return size;
}
bool Stress_ball::operator ==(const Stress_ball& sb) {
    return (color == sb.get_color() && size == sb.get_size());
}
ostream& operator <<(std::ostream& o, const Stress_ball& sb) {
    o << "(";
    switch (sb.get_color()) {
        case Stress_ball_colors::red: o << "red"; break;
        case Stress_ball_colors::blue: o << "blue"; break;
        case Stress_ball_colors::green: o << "green"; break;
        case Stress_ball_colors::yellow: o << "yellow"; break;
    }
    o << ", ";
    switch (sb.get_size()) {
        case Stress_ball_sizes::small: o << "small"; break;
        case Stress_ball_sizes::medium: o << "medium"; break;
        case Stress_ball_sizes::large: o << "large"; break;
    }
    o << ")";
    return o;
}