#include "simulator.hpp"
#include "physics.hpp"
#include "writer.hpp"
#include <fstream>
#include <iostream>

Simulator::Simulator(double timeStep, double totalTime)
    : dt(timeStep), max_time(totalTime) {}

void Simulator::run(GolfBall &ball) {
  int steps = static_cast<int>(max_time / dt);
  // file to save trajectory
  std::ofstream file("trajectory.txt");
  Settings settings = {1, 0, 200, 0, 10, 0, 50};

  for (int i = 0; i < steps; ++i) {
    // Compute acceleration at current time
    Vector3D a0 = computeTotalForce(ball) / mass;
    // save current state into file
    WriteTrajectory(file, i, ball.position, ball.velocity, a0, settings);

    // Velocity Verlet position update
    ball.position += ball.velocity * dt + a0 * (0.5 * dt * dt);

    // Estimate new velocity (will update again below)
    Vector3D v_half = ball.velocity + a0 * (0.5 * dt);

    // Update velocity using acceleration at new position
    Vector3D a1 = computeTotalForce(ball, ball.position, v_half) / mass;
    ball.velocity = v_half + a1 * (0.5 * dt);

    // Optionally print or store trajectory
    // std::cout << i * dt << " " << ball.position.x << " " << ball.position.y
    //<< " " << ball.position.z << "\n";

    // Stop if ball hits the ground
    if (ball.position.z < 0.0)
      break;
  }
}
