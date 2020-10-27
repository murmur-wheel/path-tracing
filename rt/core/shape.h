//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_SHAPE_H
#define RT_CORE_SHAPE_H

#include "geometry.h"
#include "interaction.h"

namespace rt::core {

class Shape {
 public:
  explicit Shape(const Transform* object_to_world,
                 const Transform* world_to_object, bool reverse_orientation)
      : object_to_world(object_to_world),
        world_to_object(world_to_object),
        reverse_orientation(reverse_orientation) {}

  virtual ~Shape() = default;
  virtual bool intersect(const Ray& ray, float* t_hit,
                         SurfaceInteraction* interaction,
                         bool test_alpha_texture = true) const = 0;
  virtual bool intersect_p(const Ray& r,
                           bool test_alpha_texture = true) const = 0;

  virtual Bounds3f world_bound() const = 0;
  virtual Bounds3f object_bound() const = 0;

  const Transform* world_to_object;
  const Transform* object_to_world;
  bool reverse_orientation = false;

  DISABLE_COPY_AND_MOVE(Shape)
};
}  // namespace rt::core

#endif
