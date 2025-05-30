#include "ball.hpp"
#include "physics.hpp"
#include "simulator.hpp"
#include "vector3d.hpp"
#include "writer.hpp"
#include <cmath>
#include <fstream>
#include <iostream>

int main() {
  Vector3D pos(0, 0, 0); // x,y,z
  // 7 iron
  double launch_angle = 16.3 * pi / 180; // degree
  double ball_speed = 120 * 0.44704;     // insert mph but calc with m/s
  Vector3D vel(std::cos(launch_angle) * ball_speed, 0,
               std::sin(launch_angle) * ball_speed); // launch velocity
  Vector3D spin(0, 0, 7100);                         // backspin in rpm

  GolfBall ball(pos, vel, spin);
  std::cout << "Startgeschwindigkeit: " << ball.velocity.norm() << " in m/s "
            << std::endl;
  ball.velocity.print();
  std::cout << "Spin: " << ball.spin.norm() << " in rad/s" << std::endl;
  Simulator sim(0.01, 8.0);
  sim.euler(ball);

  return 0;
}
