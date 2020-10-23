//
// Created by murmur-wheel on 2020/10/22.
//

#ifndef RT_CORE_MATERIAL_H
#define RT_CORE_MATERIAL_H

#include "common.h"
#include "interaction.h"
#include "material.h"
#include "texture.h"

namespace rt::core {
class Arena;
enum class TransportMode { Radiance, Importance };

class Material {
 public:
  Material() = default;
  virtual ~Material() = default;

  virtual void compute_scattering_functions(
      SurfaceInteraction* surface_interaction, Arena* arena, TransportMode mode,
      bool allow_multiple_lobes) const = 0;

  virtual void bump(const std::shared_ptr<Texture<Float>>& map,
                    SurfaceInteraction* interaction) const;

 private:
  DISABLE_COPY_AND_MOVE(Material)
};
}  // namespace rt::core

#endif
