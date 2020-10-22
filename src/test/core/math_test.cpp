//
// Created by murmur-wheel on 2020/10/22.
//

#include <core/math.h>
#include <gtest/gtest.h>

TEST(Vec2T, misc) {
  using namespace rt::core;
  Vec2T<float> v2f;
  std::cout << v2f << std::endl;
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