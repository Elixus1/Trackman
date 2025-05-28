#include <gtest/gtest.h>
#include "vector3d.hpp"
TEST(vectorTest, cross) {
  const Vector3D a(1,2,3);
  const Vector3D b(4,5,6);
  const Vector3D cross = a.cross(b);
  const Vector3D expectedResult(-3,6,-3);
  ASSERT_EQ(expectedResult.x , cross.x);
  ASSERT_EQ(expectedResult.y, cross.y);
  ASSERT_EQ(expectedResult.z, cross.z);
}
