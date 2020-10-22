//
// Created by murmur-wheel on 2020/10/22.
//

#include <core/geometry.h>
#include <gtest/gtest.h>

TEST(Bounds3T, misc) {
  using namespace rt::core;
  {
    Bounds3f bounds;
    bounds.min_pt = Vec3f(1, 2, 3);
    bounds.max_pt = Vec3f(4, 5, 6);
    ASSERT_TRUE(bounds.contains(Vec3f(3.5f)));
  }
}
