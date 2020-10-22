//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_GEOMETRY_H
#define RT_CORE_GEOMETRY_H

#include "common.h"
#include "math.h"

namespace rt::core {
class Medium;
template <typename T>
struct RayT {
  Vec3T<T> origin;
  Vec3T<T> direction;

  float time;  // animating
  const Medium* medium;
};

template <typename T>
struct Bounds3T {
  Vec3T<T> max_pt, min_pt;

  bool contains(const Vec3T<T>& pt) const {
    return (pt.x > min_pt.x) && (pt.y > min_pt.y) && (pt.z > min_pt.z) &&
           (pt.x < max_pt.x) && (pt.y < max_pt.y) && (pt.z < max_pt.z);
  }
};

template <typename T>
std::ostream& operator<<(std::ostream& s, const Bounds3T<T>& rhs) {
  s << "[" << rhs.min_pt << "," << rhs.max_pt << "]";
  return s;
}

using Ray = RayT<float>;
using Bounds3f = Bounds3T<float>;

}  // namespace rt::core

#endif
