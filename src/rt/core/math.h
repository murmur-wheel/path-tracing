//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_MATH_H
#define RT_CORE_MATH_H

#include "common.h"

namespace rt::core {
template <typename T>
struct Vec2T {
  static_assert(std::is_floating_point<T>(), "T must be floating point");
  T x, y;

  Vec2T() : x(0), y(0) {}
  explicit Vec2T(T a) : x(a), y(a) {}
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

  bool operator==(const Vec2T<T>& rhs) const {
    return x == rhs.x && y == rhs.y;
  }

  bool has_nan() const { return std::isnan(x) || std::isnan(y); }
};

template <typename T>
struct Vec3T {
  static_assert(std::is_floating_point<T>(), "T must be floating point");
  T x, y, z;

  Vec3T() : x(0), y(0), z(0) {}
  explicit Vec3T(T a) : x(a), y(a), z(a) {}
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

  Vec3T<T> operator*(const Vec3T<T>& rhs) const {
    return Vec3T<T>(x * rhs.x, y * rhs.y, z * rhs.z);
  }
  Vec3T<T>& operator*=(const Vec3T<T>& rhs) {
    x *= rhs.x;
    y *= rhs.y;
    z *= rhs.z;
    return *this;
  }

  Vec3T<T> operator/(const Vec3T<T>& rhs) const {
    return Vec3T<T>(x / rhs.x, y / rhs.y, z / rhs.z);
  }
  Vec3T<T>& operator/=(const Vec3T<T>& rhs) {
    x /= rhs.x;
    y /= rhs.y;
    z /= rhs.z;
    return *this;
  }

  bool has_nan() const {
    return std::isnan(x) || std::isnan(y) || std::isnan(z);
  }
};

template <typename T>
struct Vec4T {
  static_assert(std::is_floating_point<T>(), "T must be floating point");
  T x, y, z, w;

  Vec4T() : x(0), y(0), z(0), w(0) {}
  explicit Vec4T(T a) : x(a), y(a), z(a), w(a) {}
  explicit Vec4T(T _x, T _y, T _z, T _w) : x(_x), y(_y), z(_z), w(_w) {}
  explicit Vec4T(const Vec3T<T>& v, T _w) : x(v.x), y(v.y), z(v.z), w(_w) {}

  T& operator[](int i) { return (&x)[i]; }
  const T& operator[](int i) const { return (&x)[i]; }

  Vec4T<T> operator+(const Vec4T<T>& rhs) const {
    return Vec4T<T>(x + rhs.x, y + rhs.y, z + rhs.z, w + rhs.w);
  }
  Vec4T<T> operator-(const Vec4T<T>& rhs) const {
    return Vec4T<T>(x - rhs.x, y - rhs.y, z - rhs.z, w - rhs.w);
  }

  bool has_nan() const {
    return std::isnan(x) || std::isnan(y) || std::isnan(z) || std::isnan(w);
  }
};

template <typename T>
struct Mat3T {
  static_assert(std::is_floating_point<T>(), "T must be floating point");
  T m[3][3];

  Mat3T() : m{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}} {}
  explicit Mat3T(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22)
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
};

template <typename T>
struct Mat4T {
  static_assert(std::is_floating_point<T>(), "T must be floating point");
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

  static Mat4T<T> identity() {
    return Mat4T<T>({{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}});
  }

  static Mat4T<T> translate(T offset_x, T offset_y, T offset_z) {
    return Mat4T<T>({{1, 0, 0, offset_x},
                     {0, 1, 0, offset_y},
                     {0, 0, 1, offset_z},
                     {0, 0, 0, 1}});
  }

  static Mat4T<T> translate(const Vec3T<T>& offset) {
    return translate(offset.x, offset.y, offset.z);
  }

  static Mat4T<T> scale(T scale_x, T scale_y, T scale_z) {
    return Mat4T<T>({{scale_x, 0, 0, 0},
                     {0, scale_y, 0, 0},
                     {0, 0, scale_z, 0},
                     {0, 0, 0, 1}});
  }
  static Mat4T<T> scale(const Vec3T<T>& s) { return scale(s.x, s.y, s.z); }
};

// dot
template <typename T>
T dot(const Vec2T<T>& v1, const Vec2T<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y;
}

template <typename T>
T dot(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

template <typename T>
T dot(const Vec4T<T>& v1, const Vec4T<T>& v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
}

// distance squared
template <typename T>
T distance_squared(const Vec2T<T>& v1, const Vec2T<T>& v2) {
  auto v = v1 - v2;
  return dot(v, v);
}

template <typename T>
T distance_squared(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  auto v = v1 - v2;
  return dot(v, v);
}

template <typename T>
T distance_squared(const Vec4T<T>& v1, const Vec4T<T>& v2) {
  auto v = v1 - v2;
  return dot(v, v);
}

// distance
template <typename T>
T distance(const Vec2T<T>& v1, const Vec2T<T>& v2) {
  return std::sqrt(distance_squared(v1, v2));
}

template <typename T>
T distance(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  return std::sqrt(distance_squared(v1, v2));
}

template <typename T>
T distance(const Vec4T<T>& v1, const Vec4T<T>& v2) {
  return std::sqrt(distance_squared(v1, v2));
}

// max
template <typename T>
Vec2T<T> max(const Vec2T<T>& v1, const Vec2T<T>& v2) {
  T x = std::max<T>(v1.x, v2.x);
  T y = std::max<T>(v1.y, v2.y);
  return Vec2T<T>(x, y);
}

template <typename T>
Vec3T<T> max(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  T x = std::max<T>(v1.x, v2.x);
  T y = std::max<T>(v1.y, v2.y);
  T z = std::max<T>(v1.z, v2.z);
  return Vec3T<T>(x, y, z);
}

template <typename T>
Vec4T<T> max(const Vec4T<T>& v1, const Vec4T<T>& v2) {
  T x = std::max<T>(v1.x, v2.x);
  T y = std::max<T>(v1.y, v2.y);
  T z = std::max<T>(v1.z, v2.z);
  T w = std::max<T>(v1.w, v2.w);
  return Vec4T<T>(x, y, z, w);
}

// min
template <typename T>
Vec2T<T> min(const Vec2T<T>& v1, const Vec2T<T>& v2) {
  T x = std::min<T>(v1.x, v2.x);
  T y = std::min<T>(v1.y, v2.y);
  return Vec2T<T>(x, y);
}

template <typename T>
Vec3T<T> min(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  T x = std::min<T>(v1.x, v2.x);
  T y = std::min<T>(v1.y, v2.y);
  T z = std::min<T>(v1.z, v2.z);
  return Vec3T<T>(x, y, z);
}

template <typename T>
Vec4T<T> min(const Vec4T<T>& v1, const Vec4T<T>& v2) {
  T x = std::min<T>(v1.x, v2.x);
  T y = std::min<T>(v1.y, v2.y);
  T z = std::min<T>(v1.z, v2.z);
  T w = std::min<T>(v1.w, v2.w);
  return Vec4T<T>(x, y, z, w);
}

// clamp
template <typename T>
T clamp(T val, T min_val, T max_val) {
  if (val < min_val) {
    return min_val;
  } else if (val > max_val) {
    return max_val;
  } else {
    return val;
  }
}

template <typename T>
Vec2T<T> clamp(const Vec2T<T>& val, const Vec2T<T>& min_val,
               const Vec2T<T>& max_val) {
  T x = clamp(val.x, min_val.x, max_val.x);
  T y = clamp(val.y, min_val.y, min_val.z);
  return Vec2T<T>(x, y);
}

template <typename T>
Vec3T<T> clamp(const Vec3T<T>& val, const Vec3T<T>& min_val,
               const Vec3T<T>& max_val) {
  T x = clamp(val.x, min_val.x, max_val.x);
  T y = clamp(val.y, min_val.y, max_val.y);
  T z = clamp(val.z, min_val.z, max_val.z);
  return Vec3T<T>(x, y, z);
}

template <typename T>
Vec4T<T> clamp(const Vec4T<T>& val, const Vec4T<T>& min_val,
               const Vec4T<T>& max_val) {
  T x = clamp(val.x, min_val.x, max_val.x);
  T y = clamp(val.y, min_val.y, max_val.y);
  T z = clamp(val.z, min_val.z, max_val.z);
  T w = clamp(val.w, min_val.w, max_val.w);
  return Vec4T<T>(x, y, z, w);
}

// cross
template <typename T>
Vec3T<T> cross(const Vec3T<T>& v1, const Vec3T<T>& v2) {
  T x = v1.y * v2.z - v1.z * v2.y;
  T y = v1.z * v2.x - v1.x * v2.z;
  T z = v1.x * v2.y - v1.y * v2.x;
  return Vec3T<T>(x, y, z);
}

template <typename T_>
std::ostream& operator<<(std::ostream& s, const Vec2T<T_>& v) {
  s << "[" << v.x << "," << v.y << "]";
  return s;
}

template <typename T_>
std::ostream& operator<<(std::ostream& s, const Vec3T<T_>& v) {
  s << "[" << v.x << "," << v.y << "," << v.z << "]";
  return s;
}

template <typename T_>
std::ostream& operator<<(std::ostream& s, const Vec4T<T_>& v) {
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
