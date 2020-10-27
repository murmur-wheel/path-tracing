//
// Created by murmur-wheel on 2020/10/23.
//

#include "primitive.h"

namespace rt::core {

Bounds3f GeometricPrimitive::world_bound() const {
  return shape_->world_bound();
}

bool GeometricPrimitive::intersect(const Ray& r,
                                   SurfaceInteraction* interaction) const {
  Float t_hit;
  if (!shape_->intersect(r, &t_hit, interaction)) return false;
  r.t_max = t_hit;

  interaction->primitive = this;

  assert(dot(interaction->normal, interaction->shading.normal) > 0);

  if (medium_interface.is_medium_transition()) {
    interaction->medium_interface = medium_interface;
  } else {
    interaction->medium_interface = MediumInterface(r.medium);
  }

  return true;
}

bool GeometricPrimitive::intersect_p(const Ray& r) const {
  return shape_->intersect_p(r);
}

const AreaLight* GeometricPrimitive::get_area_light() const {
  return area_light_.get();
}

const Material* GeometricPrimitive::get_material() const {
  return material_.get();
}

void GeometricPrimitive::compute_scattering_functions(
    SurfaceInteraction* interaction, Arena* arena, TransportMode mode,
    bool allow_multiple_lobes) const {
  if (material_) {
    material_->compute_scattering_functions(interaction, arena, mode,
                                            allow_multiple_lobes);
  }

  assert(dot(interaction->normal, interaction->shading.normal) > 0);
}

const AreaLight* Aggregate::get_area_light() const { return nullptr; }

const Material* Aggregate::get_material() const { return nullptr; }
}  // namespace rt::core
