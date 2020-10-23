//
// Created by murmur-wheel on 2020/10/24.
//

#ifndef RT_MATERIAL_MATTE_H
#define RT_MATERIAL_MATTE_H

#include "../core/material.h"
#include "../core/spectrum.h"

namespace rt::material {
using namespace core;

class MatteMaterial : public Material {
 public:
  explicit MatteMaterial(std::shared_ptr<Texture<Spectrum>> diffuse_map,
                         std::shared_ptr<Texture<Float>> sigma,
                         std::shared_ptr<Texture<Float>> bump_map)
      : diffuse_map_(std::move(diffuse_map)),
        sigma_(std::move(sigma)),
        bump_map_(std::move(bump_map)) {}

  void compute_scattering_functions(SurfaceInteraction* surface_interaction,
                                    Arena* arena, TransportMode mode,
                                    bool allow_multiple_lobes) const override;

 private:
  std::shared_ptr<Texture<Spectrum>> diffuse_map_;
  std::shared_ptr<Texture<Float>> sigma_, bump_map_;
};
}  // namespace rt::material

#endif