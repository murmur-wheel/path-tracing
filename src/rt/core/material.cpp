#include "material.h"

namespace rt::core {
void Material::bump(const std::shared_ptr<Texture<Float>>& map,
                    SurfaceInteraction* interaction) const {
  assert(!"no impl");
}
}  // namespace rt::core
