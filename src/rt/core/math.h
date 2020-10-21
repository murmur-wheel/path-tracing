//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_MATH_H
#define RT_CORE_MATH_H

#include "common.h"

namespace rt::core {
template <typename T>
struct Vec2T {
  T x, y;

  Vec2T() : x(0), y(0) {}
  explicit Vec2T(T _x, T _y) : x(_x), y(_y) {}

  T& operator[](int i) { return (&x)[i]; }
  const T& operator[](int i) const { return (&i)[i]; }
};
}  // namespace rt::core

#endif
