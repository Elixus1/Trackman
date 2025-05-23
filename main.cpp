#include "simulator.hpp"
#include "ball.hpp"

int main() {
    Vector3D pos(0, 0, 0);
    Vector3D vel(50, 0, 20);   // launch velocity
    Vector3D spin(0, 0, 200);  // backspin

    GolfBall ball(pos, vel, spin);
    Simulator sim(0.001, 5.0);
    sim.run(ball);

    return 0;
}
