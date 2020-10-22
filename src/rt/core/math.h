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

  Vec2T<T> operator+(const Vec2T<T>& rhs) const {
    return Vec2T<T>(x + rhs.x, y + rhs.y);
  }
  Vec2T<T>& operator+=(const Vec2T<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Vec2T<T> operator-(const Vec2T<T>& rhs) const {
    return Vec2T<T>(x - rhs.x, y - rhs.y);
  }
  Vec2T<T>& operator-=(const Vec2T<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
  }

  static_assert(std::is_floating_point<T>(), "T must be floating point");
};

template <typename T>
struct Vec3T {
  T x, y, z;

  Vec3T() : x(0), y(0), z(0) {}
  explicit Vec3T(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

  T& operator[](int i) { return (&x)[i]; }
  const T& operator[](int i) const { return (&x)[i]; }

  Vec3T<T> operator+(const Vec3T<T>& rhs) const {
    return Vec3T(x + rhs.x, y + rhs.y, z + rhs.z);
  }
  Vec3T<T>& operator+=(const Vec3T<T>& rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
  }

  Vec3T<T> operator-(const Vec3T<T>& rhs) const {
    return Vec3T<T>(x - rhs.x, y - rhs.y, z - rhs.z);
  }
  Vec3T<T>& operator-=(const Vec3T<T>& rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
  }

  static_assert(std::is_floating_point<T>(), "T must be floating point");
};

template <typename T>
struct Vec4T {
  T x, y, z, w;

  Vec4T() : x(0), y(0), z(0), w(0) {}
  explicit Vec4T(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}

  T& operator[](int i) { return (&x)[i]; }
  const T& operator[](int i) const { return (&x)[i]; }

  static_assert(std::is_floating_point<T>(), "T must be floating point");
};

template <typename T>
struct Mat3T {
  T m[3][3];

  Mat3T() : m{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}} {}

  Vec3T<T> operator*(const Vec3T<T>& rhs) const {
    Vec3T<T> res;
    for (int i = 0; i < 3; ++i) {
      res[i] = 0;
      for (int k = 0; k < 3; ++k) {
        res[i] += m[i][k] * rhs[k];
      }
    }
    return res;
  }
  Mat3T<T> operator*(const Mat3T<T>& rhs) const {
    Mat3T<T> res;
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 3; ++j) {
        res.m[i][j] = 0;
        for (int k = 0; k < 3; ++k) {
          res.m[i][j] += m[i][k] * rhs.m[k][j];
        }
      }
    }
    return res;
  }

  static_assert(std::is_floating_point<T>(), "T must be floating point");
};

template <typename T>
struct Mat4T {
  T m[4][4];

  Mat4T() : m{{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}} {}

  static_assert(std::is_floating_point<T>(), "T must be floating point");
};

template <typename T>
std::ostream& operator<<(std::ostream& s, const Vec2T<T>& v) {
  s << "[" << v.x << "," << v.y << "]";
  return s;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const Vec3T<T>& v) {
  s << "[" << v.x << "," << v.y << "," << v.z << "]";
  return s;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const Vec4T<T>& v) {
  s << "[" << v.x << "," << v.y << "," << v.z << "," << v.w << "]";
  return s;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const Mat3T<T>& rhs) {
  s << "[";
  for (int i = 0; i < 3; ++i) {
    s << "[" << rhs.m[i][0] << "," << rhs.m[i][1] << "," << rhs.m[i][2] << "]";
    if (i != 2) {
      s << ",";
    }
  }
  s << "]";
  return s;
}

template <typename T>
std::ostream& operator<<(std::ostream& s, const Mat4T<T>& rhs) {
  s << "[";
  for (int i = 0; i < 4; ++i) {
    s << "[" << rhs.m[i][0] << "," << rhs.m[i][1] << "," << rhs.m[i][2] << ","
      << rhs.m[i][3] << "]";
    if (i != 3) {
      s << ",";
    }
  }
  s << "]";
  return s;
}

using Vec2f = Vec2T<float>;
using Vec3f = Vec3T<float>;
using Vec4f = Vec4T<float>;

using Mat3f = Mat3T<float>;
using Mat4f = Mat4T<float>;
}  // namespace rt::core

#endif
