//
// Created by murmur-wheel on 2020/10/23.
//

#ifndef RT_CORE_PRIMITIVE_H
#define RT_CORE_PRIMITIVE_H

#include "material.h"
#include "medium.h"
#include "shape.h"

namespace rt::core {
class AreaLight;
class Material;
class Arena;
enum class TransportMode;

class Primitive {
 public:
  virtual ~Primitive() = default;
  virtual Bounds3f world_bound() const = 0;
  virtual bool intersect(const Ray& r,
                         SurfaceInteraction* interaction) const = 0;
  virtual bool intersect_p(const Ray& r) const = 0;
  virtual const AreaLight* get_area_light() const = 0;
  virtual const Material* get_material() const = 0;
  virtual void compute_scattering_functions(
      SurfaceInteraction* interaction, Arena* arena, TransportMode mode,
      bool allow_multiple_lobes) const = 0;
};

class GeometricPrimitive : public Primitive {
 public:
  Bounds3f world_bound() const final;
  bool intersect(const Ray& r, SurfaceInteraction* interaction) const final;
  bool intersect_p(const Ray& r) const final;
  const AreaLight* get_area_light() const final;
  const Material* get_material() const final;
  void compute_scattering_functions(SurfaceInteraction* interaction,
                                    Arena* arena, TransportMode mode,
                                    bool allow_multiple_lobes) const final;

 private:
  std::shared_ptr<Shape> shape_;
  std::shared_ptr<Material> material_;
  std::shared_ptr<AreaLight> area_light_;
  MediumInterface medium_interface;
};

class Aggregate : public Primitive {
 public:
  const AreaLight* get_area_light() const final;
  const Material* get_material() const final;
};

}  // namespace rt::core

#endif