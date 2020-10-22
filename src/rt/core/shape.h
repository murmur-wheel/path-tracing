//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_SHAPE_H
#define RT_CORE_SHAPE_H

#include "math.h"
#include "ray.h"

namespace rt::core {
struct Bounds3f {
  Vec3f max_pt, min_pt;
};

class Interaction;

class Shape {
 public:
  virtual bool intersect(const Ray& ray, float* t_hit, Interaction* interaction,
                         bool test_alpha_texture = true) const = 0;

  virtual Bounds3f world_bound() const = 0;
  virtual Bounds3f object_bound() const = 0;

  const Mat4f* world_to_object;
  const Mat4f* object_to_world;
  bool reverse_orientation = false;

  DISABLE_COPY_AND_MOVE(Shape)
};
}  // namespace rt::core

#endif
