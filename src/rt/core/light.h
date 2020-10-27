//
// Created by murmur-wheel on 2020/10/24.
//

#ifndef RT_CORE_LIGHT_H
#define RT_CORE_LIGHT_H

#include "geometry.h"
#include "interaction.h"
#include "linear_math.h"
#include "medium.h"
#include "spectrum.h"

namespace rt::core {

class VisibilityTester;

enum class LightFlags : int {
  DeltaPosition = 1,
  DeltaDirection = 2,
  Area = 4,
  Infinite = 8,
};

inline bool is_delta_light(int flags) {
  return flags & static_cast<int>(LightFlags::DeltaPosition) ||
         flags & static_cast<int>(LightFlags::DeltaDirection);
}

class Light {
 public:
  explicit Light(int flags, const Transform& light_to_world,
                 const MediumInterface& medium_interface, int num_samples = 1)
      : flags(flags),
        light_to_world(light_to_world),
        world_to_light(light_to_world.inverse()),
        num_samples(num_samples),
        medium_interface(medium_interface) {}
  virtual ~Light() = default;

  virtual Spectrum sample_Li(const Interaction& interaction, const Vec2f& u,
                             Vec3f* wi, Float* pdf,
                             VisibilityTester* vis) const = 0;

  const Transform light_to_world, world_to_light;
  const int flags;
  const int num_samples;
  const MediumInterface medium_interface;

 protected:
};
}  // namespace rt::core

#endif
