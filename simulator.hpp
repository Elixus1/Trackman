#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP

#include "ball.hpp"

class Simulator {
public:
    double dt;
    double max_time;

    Simulator(double time_step, double total_time);
    void run(GolfBall& ball);
};

#endif
