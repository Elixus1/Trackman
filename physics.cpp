#include "physics.hpp"
#include <cmath>
const double mass = 0.045;
const double g = 9.81;
const double airDensity = 1.225;
const double dragCoefficient = 0.25;
const double radius = 0.02135;
const double area = 3.1416 * radius * radius;
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
