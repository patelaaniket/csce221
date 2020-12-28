#ifndef pa1_H
#define pa1_H

enum Stress_ball_colors {red, blue, yellow, green};
enum Stress_ball_sizes {small, medium, large};

class Stress_ball  {
private:    
    Stress_ball_colors color;
    Stress_ball_sizes size;
public:
    Stress_ball();
    Stress_ball(Stress_ball_colors c, Stress_ball_sizes s);
    int get_color() const;
    int get_size() const;
    bool operator ==(const Stress_ball& sb);
};
void operator <<(std::ostream& o, const Stress_ball& sb);
#endif