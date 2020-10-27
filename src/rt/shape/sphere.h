//
// Created by murmur-wheel on 2020/10/22.
//

#ifndef RT_SHAPE_SPHERE_H
#define RT_SHAPE_SPHERE_H

#include "../core/shape.h"

namespace rt::shape {
class Sphere : public core::Shape {
 public:
  explicit Sphere(const core::Transform* object_to_world,
                  const core::Transform* world_to_object,
                  bool reverse_orientation, const core::Vec3f& center,
                  Float radius);

 private:
  core::Vec3f center_;
  Float radis_ = 0.0f;
};
}  // namespace rt::shape

#endif
