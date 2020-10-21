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

template <typename T>
struct Vec3T {
  T x, y, z;
};

template <typename T>
struct Vec4T {
  T x, y, z, w;
};

template <typename T>
struct Mat3T {
  T m[3][3];
};

template <typename T>
struct Mat4T {
  T m[4][4];
};

using Vec2f = Vec2T<float>;
using Vec3f = Vec3T<float>;
using Vec4f = Vec4T<float>;

using Mat3f = Mat3T<float>;
using Mat4f = Mat4T<float>;
}  // namespace rt::core

#endif
