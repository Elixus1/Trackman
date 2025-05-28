#include "vector3d.hpp"

// Vector addition
Vector3D Vector3D::operator+(const Vector3D &v) const {
  return Vector3D(x + v.x, y + v.y, z + v.z);
}

// Vector subtraction
Vector3D Vector3D::operator-(const Vector3D &v) const {
  return Vector3D(x - v.x, y - v.y, z - v.z);
}

// Scalar multiplication
Vector3D Vector3D::operator*(double s) const {
  return Vector3D(x * s, y * s, z * s);
}

Vector3D operator*(double s, const Vector3D &vec) { return vec * s; }
// Scalar division
Vector3D Vector3D::operator/(double s) const {
  return Vector3D(x / s, y / s, z / s);
}

// Compound addition
Vector3D &Vector3D::operator+=(const Vector3D &v) {
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

// Vector norm (magnitude)
double Vector3D::norm() const { return std::sqrt(x * x + y * y + z * z); }

// Normalize vector
Vector3D Vector3D::normalized() const {
  double n = norm();
  return (n > 0) ? (*this / n) : Vector3D(0, 0, 0);
}

// Cross product
Vector3D Vector3D::cross(const Vector3D &other) const {
  return Vector3D(y * other.z - z * other.y, z * other.x - x * other.z,
                  x * other.y - y * other.x);
}
