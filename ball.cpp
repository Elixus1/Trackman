#include "ball.hpp"
#include "physics.hpp"

GolfBall::GolfBall(const Vector3D &pos, const Vector3D &vel,
                   const Vector3D &spin)
    : position(pos), velocity(vel), spin(spin * 2 * pi / 60) {}
