#include "vector3d.hpp"
#include <cmath>
#include <gtest/gtest.h>
TEST(vectorTest, cross) {
  Vector3D a(1, 2, 3);
  Vector3D b(4, 5, 6);
  Vector3D cross = a.cross(b);
  const Vector3D expectedResult(-3, 6, -3);
  assert(cross == expectedResult);

  // parallel vectors
  a = Vector3D(1, 1, 1);
  b = Vector3D(9, 9, 9);
  cross = a.cross(b);
  const Vector3D expectedResult1(0, 0, 0);
  assert(cross == expectedResult1);
  // orthogonale Vektoren
  a = Vector3D(1, 0, 0);
  b = Vector3D(0, 1, 0);
  cross = a.cross(b);
  const Vector3D expectedResult2(0, 0, 1);
  assert(cross == expectedResult2);
}

TEST(vectorTest, mult) {
  Vector3D a(1, 2, 3);
  Vector3D b(4, 5, 6);
  double mult = std::sqrt(32);
  double result = std::sqrt(32);
  assert(mult == result);

  Vector3D smult = 5 * a;
  Vector3D expectedResult(5, 10, 15);
  assert(smult == expectedResult);
  smult = a * 5;
  assert(smult == expectedResult);
}

TEST(vectorTest, norm) {
  // norm => Betrag
  Vector3D a(2, 4, 6);
  double norm = a.norm();
  double b = std::sqrt(56);
  ASSERT_EQ(norm, b);

  // normalize => einheitsvektor
  Vector3D unit = a.normalized();
  Vector3D result(2 / b, 4 / b, 6 / b);
}

TEST(vectorTest, equal) {
  Vector3D a(-0, -0,-0);
  Vector3D b(0,0,0);
  assert( a == b); 

}
