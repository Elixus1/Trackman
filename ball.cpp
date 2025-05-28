#include "ball.hpp"

GolfBall::GolfBall(const Vector3D &pos, const Vector3D &vel,
                   const Vector3D &spin)
    : position(pos), velocity(vel), spin(spin) {}
