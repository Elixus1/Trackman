#include "physics.hpp"
#include "vector3d.hpp"
#include <cmath>
#include <gtest/gtest.h>
#include <iostream>
#include <numbers>

TEST(physics, forces) {
  // read values from physics.cpp works
  ASSERT_EQ(mass, 0.04593);
  ASSERT_EQ(g, 9.81);

  // gravity force TEST
  Vector3D gravity = computeGravity();
  Vector3D grav(0, 0, -mass * g);
  assert(gravity == grav);

  // drag force TEST
  Vector3D vel(10, 0, 0); // m/s in x-Richtung
  double x_komponente = -0.5 * 1.225 * 100 * 0.25 * pi * 0.002135 * 0.002135;
  Vector3D result(x_komponente, 0, 0);
  Vector3D calc = computeDrag(vel);
  assert(calc == result);
  ASSERT_EQ(x_komponente, result.x);

  // magnus force TEST
  result;
  Vector3D spin(0, 0, 7100);
  calc = computeMagnus(spin, vel);
  calc.print();
}
