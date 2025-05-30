#include "physics.hpp"
#include <cmath>
#include <numbers>
const double mass = 0.04593;         // in kg
const double g = 9.81;               // m/s^2
const double airDensity = 1.225;     // kg/m^3 at 15°C
const double dragCoefficient = 0.25; // dimensionless between 0.24 and 0.7
const double radius = 0.002135;      // in m
const double pi = 3.141593;
const double area = pi * radius * radius;
const double magnusCoefficient = 0.0005;
Vector3D computeGravity() { return Vector3D(0, 0, -mass * g); }

Vector3D computeDrag(const Vector3D &velocity) {
  double speed = velocity.norm();
  Vector3D dragDir = velocity.normalized();
  return -0.5 * airDensity * dragCoefficient * area * speed * speed * dragDir;
}

Vector3D computeMagnus(const Vector3D &spin, const Vector3D &velocity) {
  return magnusCoefficient * spin.cross(velocity);
}

Vector3D computeTotalForce(const GolfBall &ball) {
  return computeGravity() + computeDrag(ball.velocity) +
         computeMagnus(ball.spin, ball.velocity);
}

Vector3D computeTotalForce(const GolfBall &ball, const Vector3D &pos,
                           const Vector3D &vel) {
  return computeGravity() + computeDrag(vel) + computeMagnus(ball.spin, vel);
}
