//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_CAMERA_H
#define RT_CORE_CAMERA_H

#include "geometry.h"

namespace rt::core {
class Film;
struct CameraSample {
  // the point on the film
  Vec2f film_uv;
  // the point on the lens the ray passes through. (for cameras that include the
  // notion of lenses)
  Vec2f lens_uv;
  Float time;
};

class Camera {
 public:
  virtual ~Camera() = default;

  virtual Float generate_ray(const CameraSample& sample, Ray* ray) const = 0;
  virtual Float generate_ray_differential(const CameraSample& sample,
                                          RayDifferential* ray) const = 0;

  const AnimatedTransform camera_to_world;
  Float shutter_open, shutter_close;
  const Medium* medium;
  const Film* film;

  DISABLE_COPY_AND_MOVE(Camera)
};
}  // namespace rt::core

#endif