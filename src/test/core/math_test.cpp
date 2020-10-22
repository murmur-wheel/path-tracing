//
// Created by murmur-wheel on 2020/10/22.
//

#include <core/math.h>
#include <gtest/gtest.h>

TEST(Vec2T, misc) {
  using namespace rt::core;
  Vec2T<float> v2f;
  std::cout << v2f << std::endl;

  {
    Vec2f v1(1, 2);
    Vec2f v2(3, 4);
    std::cout << v1 << " + " << v2 << " = " << (v1 + v2) << std::endl;
  }

  {
    Vec2f v1(3, 4);
    Vec2f v2(2, 1);
    std::cout << v1 << " - " << v2 << " = " << (v1 - v2) << std::endl;
  }

  {
    Vec2f v1(2, 2);
    Vec2f v2(3, 3);
    std::cout << v1 << " * " << v2 << " = " << (v1 * v2) << std::endl;
  }

  {
    Vec2f v1(2, 2);
    Vec2f v2(3, 3);
    std::cout << v1 << " / " << v2 << " = " << (v1 / v2) << std::endl;
  }
}

TEST(Vec3T, misc) {
  using namespace rt::core;
  Vec3T<float> v3f(1, 2, 3);
  std::cout << v3f << std::endl;
}

TEST(Vec4T, misc) {
  using namespace rt::core;
  Vec4T<float> v4f;
  std::cout << v4f << std::endl;

  {
    std::cout << "identity = " << Mat4T<float>::Identity() << std::endl;
    const auto I = Mat4f::Identity();
    Vec4f v(1, 2, 3, 4);
    std::cout << I << " * " << v << " = " << I * v << std::endl;
  }
}

TEST(Mat3T, misc) {
  using namespace rt::core;
  Mat3T<float> m3f;
  std::cout << m3f << std::endl;
}

TEST(Mat4T, misc) {
  using namespace rt::core;
  Mat4T<float> m4f;
  std::cout << m4f << std::endl;
}