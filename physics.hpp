#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "vector3d.hpp"
#include "ball.hpp"

namespace Physics {
    const double g = 9.81;
    const double rho = 1.225;
    const double Cd = 0.25;
    const double Cl = 0.2;
    const double mass = 0.045;
    const double radius = 0.02135;
    const double area = M_PI * radius * radius;

    Vector3D gravity_force();
    Vector3D drag_force(const Vector3D& velocity);
    Vector3D magnus_force(const Vector3D& omega, const Vector3D& velocity);
}

#endif
