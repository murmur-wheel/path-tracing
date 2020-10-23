//
// Created by murmur-wheel on 2020/10/24.
//

#include "matte.h"

namespace rt::material {

void MatteMaterial::compute_scattering_functions(
    SurfaceInteraction* surface_interaction, Arena* arena, TransportMode mode,
    bool allow_multiple_lobes) const {
  if (bump_map_) {
    bump(bump_map_, surface_interaction);
  }

  assert(!"no impl");
}
}  // namespace rt::material
