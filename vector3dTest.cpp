#include <gtest/gtest.h>
#include "vector3d.hpp"
TEST(vectorTest, cross) {
  const Vector3D a(1,1,1);
  const Vector3D b(2,2,2);
  const Vector3D cross = a.cross(b);
  const Vector3D expectedResult(0,0,0);
  ASSERT_EQ(expectedResult.x , cross.x);

}
