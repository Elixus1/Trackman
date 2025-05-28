#include "ball.hpp"
#include "simulator.hpp"
#include "vector3d.hpp"
#include "writer.hpp"
#include <fstream>
#include <iostream>

int main() {
  Vector3D pos(0, 0, 0);    // y,x,z
  Vector3D vel(50, 0, 20);  // launch velocity
  Vector3D spin(0, 0, 200); // backspin

  GolfBall ball(pos, vel, spin);
  Simulator sim(0.1, 8.0);
  sim.run(ball);

  return 0;
}
