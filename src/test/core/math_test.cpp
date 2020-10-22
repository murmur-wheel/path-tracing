//
// Created by murmur-wheel on 2020/10/22.
//

#include <core/math.h>
#include <gtest/gtest.h>

TEST(Vec2T, misc) {
  using namespace rt::core;
  {
    ASSERT_TRUE((Vec2f(1, 2) + Vec2f(3, 4)) == Vec2f(4, 6));
    ASSERT_TRUE((Vec2f(1, 2) - Vec2f(1, 2)) == Vec2f(0, 0));
    ASSERT_TRUE((Vec2f(1) * Vec2f(2)) == Vec2f(2));
    ASSERT_TRUE(distance(Vec2f(1, 2), Vec2f(1, 2)) == 0);
  }
}

TEST(Vec3T, misc) {
  using namespace rt::core;
  {
    Vec3f v1(1, 2, 3);
    Vec3f v2(1, 2, 3);
    std::cout << v1 << " + " << v2 << " = " << (v1 + v2) << std::endl;
    std::cout << v1 << " - " << v2 << " = " << (v1 - v2) << std::endl;
    std::cout << v1 << " * " << v2 << " = " << (v1 * v2) << std::endl;
    std::cout << v1 << " / " << v2 << " = " << (v1 / v2) << std::endl;
  }

  {
    Vec3f v(1, 2, 3);
    std::cout << "cross([1,2,3], [1,2,3]) = " << cross(v, v) << std::endl;
    ASSERT_TRUE(dot(v, v) == 14);
    ASSERT_TRUE(distance(v, v) == 0);
  }
}

TEST(Vec4T, misc) {
  using namespace rt::core;
  Vec4T<float> v4f;
  std::cout << v4f << std::endl;

  {
    std::cout << "identity = " << Mat4T<float>::identity() << std::endl;
    const auto I = Mat4f::identity();
    Vec4f v(1, 2, 3, 4);
    std::cout << I << " * " << v << " = " << I * v << std::endl;
    std::cout << "dot([1,2,3,4], [1,2,3,4]) = " << dot(v, v) << std::endl;
    std::cout << "distance([1,2,3,4], [1,2,3,4]) = " << distance(v, v)
              << std::endl;
  }
}

TEST(Mat3T, misc) {
  using namespace rt::core;
  Mat3T<float> m3f;
  std::cout << m3f << std::endl;
}

TEST(Mat4T, misc) {
  using namespace rt::core;
  {
    Mat4f m = Mat4f::translate(1, 2, 3);
    Vec3f v3f(1, 2, 3);
    auto v = m * Vec4f(v3f, 1);
    std::cout << "translate(1, 2, 3) * [1, 2, 3] = " << v << std::endl;
  }

  {
    Mat4f s = Mat4f::scale(Vec3f(0.5f));
    auto v = s * Vec4f(Vec3f(2), 0);
    std::cout << "scale(Vec3f(0.5)) * [2, 2, 2] = " << v << std::endl;
  }
}
