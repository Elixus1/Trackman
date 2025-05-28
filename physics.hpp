#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include "ball.hpp"
#include "vector3d.hpp"

extern const double mass;
extern const double g;
extern const double airDensity;
extern const double dragCoefficient;
extern const double radius;
extern const double area;
extern const double magnusCoefficient;

Vector3D computeGravity();
Vector3D computeDrag(const Vector3D &velocity);
Vector3D computeMagnus(const Vector3D &spin, const Vector3D &velocity);
Vector3D computeTotalForce(const GolfBall &ball);
Vector3D computeTotalForce(const GolfBall &ball, const Vector3D &pos,
                           const Vector3D &vel);

#endif
