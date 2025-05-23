#ifndef BALL_HPP
#define BALL_HPP

#include "vector3d.hpp"

class GolfBall {
public:
    Vector3D position;
    Vector3D velocity;
    Vector3D spin;

    GolfBall(const Vector3D& pos, const Vector3D& vel, const Vector3D& spin);
};

#endif
