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

  Vec2T<T> operator*(const Vec2T<T>& rhs) const {
    return Vec2T<T>(x * rhs.x, y * rhs.y);
  }
  Vec2T<T>& operator*=(const Vec2T<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  Vec2T<T> operator/(const Vec2T<T>& rhs) const {
    return Vec2T<T>(x / rhs.x, y / rhs.y);
  }
  Vec2T<T>& operator/=(const Vec2T<T>& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
  }

  static_assert(std::is_floating_point<T>(), "T must be floating point");
};  // namespace rt::core

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
  explicit Mat3T(T m00, T m01, T m02, T m10, T m11, T m12, T m21, T m22, T m23)
      : m{{m00, m01, m02}, {m10, m11, m12}, {m20, m21, m22}} {}

  explicit Mat3T(const std::initializer_list<std::initializer_list<float>>& l) {
    assert(l.size() == 3);

    for (int i = 0; i < 3; ++i) {
      assert(l.begin()[i].size() == 3);

      for (int j = 0; j < 3; ++j) {
        m[i][j] = l.begin()[i].begin()[j];
      }
    }
  }

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
  explicit Mat4T(T m00, T m01, T m02, T m03, T m10, T m11, T m12, T m13, T m20,
                 T m21, T m22, T m23, T m30, T m31, T m32, T m33)
      : m{{m00, m01, m02, m03},
          {m10, m11, m12, m13},
          {m20, m21, m22, m23},
          {m30, m31, m32, m33}} {}

  explicit Mat4T(const std::initializer_list<std::initializer_list<float>>& l) {
    assert(l.size() == 4);

    for (int i = 0; i < 4; ++i) {
      assert(l.begin()[i].size() == 4);

      for (int j = 0; j < 4; ++j) {
        m[i][j] = l.begin()[i].begin()[j];
      }
    }
  }

  Vec4T<T> operator*(const Vec4T<T>& rhs) const {
    Vec4T<T> res;
    for (int i = 0; i < 4; ++i) {
      res[i] = 0;
      for (int k = 0; k < 4; ++k) {
        res[i] += m[i][k] * rhs[k];
      }
    }
    return res;
  }

  static Mat4T<T> Identity() {
    return Mat4T<T>({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
  }

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
