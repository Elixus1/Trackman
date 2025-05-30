#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP

#include <cmath>

class Vector3D {
public:
  double x, y, z;

  Vector3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}

  Vector3D operator+(const Vector3D &) const;
  Vector3D operator-(const Vector3D &) const;
  Vector3D operator*(double s) const;
  Vector3D operator/(double s) const;
  Vector3D &operator+=(const Vector3D &);
  bool operator==(const Vector3D &other) const;
  double norm() const;
  Vector3D normalized() const;
  Vector3D cross(const Vector3D &other) const;
  void print() const;

  
};

Vector3D operator*(double s, const Vector3D &);
#endif
