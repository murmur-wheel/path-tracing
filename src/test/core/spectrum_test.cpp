//
// Created by murmur-wheel on 2020/10/24.
//

#include <core/spectrum.h>
#include <gtest/gtest.h>

TEST(Spectrum, misc) {
  using namespace rt::core;
  Spectrum s1(0), s2(1);
  ASSERT_TRUE((s1 + s2) == s2);
}
