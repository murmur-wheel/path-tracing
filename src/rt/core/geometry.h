//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_GEOMETRY_H
#define RT_CORE_GEOMETRY_H

#include "common.h"
#include "math.h"

namespace rt::core {
class Medium;

struct Ray {
  Vec3f origin;
  Vec3f direction;

  float time;  // animating
  const Medium* medium;
};

struct RayDifferential : public Ray {
  explicit RayDifferential(const Ray& ray)
      : Ray(ray), has_differentials(false) {}

  bool has_differentials = false;
  Vec3f rx_origin, ry_origin;
  Vec3f rx_direction, ry_direction;

  void scale_differentials(Float s) {
    rx_origin = origin + (rx_origin - origin) * s;
    ry_origin = origin + (ry_origin - origin) * s;
    rx_direction = direction + (rx_direction - direction) * s;
    ry_direction = direction + (ry_direction - direction) * s;
  }
};

struct Bounds3f {
  Vec3f max_pt, min_pt;

  bool contains(const Vec3f& pt) const {
    return (pt.x > min_pt.x) && (pt.y > min_pt.y) && (pt.z > min_pt.z) &&
           (pt.x < max_pt.x) && (pt.y < max_pt.y) && (pt.z < max_pt.z);
  }
};

inline std::ostream& operator<<(std::ostream& s, const Bounds3f& rhs) {
  s << "[" << rhs.min_pt << "," << rhs.max_pt << "]";
  return s;
}
}  // namespace rt::core

#endif
