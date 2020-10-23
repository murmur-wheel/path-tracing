//
// Created by murmur-wheel on 2020/10/22.
//

#ifndef RT_CORE_MATERIAL_H
#define RT_CORE_MATERIAL_H

#include "common.h"
#include "interaction.h"

namespace rt::core {
class Arena;
enum class TransportMode;

class Material {
 public:
  virtual ~Material() = default;
  virtual void compute_scattering_functions(
      SurfaceInteraction* interaction, Arena* arean, TransportMode mode,
      bool allow_multiple_lobes) const = 0;

 private:
  DISABLE_COPY_AND_MOVE(Material)
};
}  // namespace rt::core

#endif
