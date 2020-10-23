//
// Created by murmur-wheel on 2020/10/22.
//

#ifndef RT_CORE_INTERACTION_H
#define RT_CORE_INTERACTION_H

#include "common.h"
#include "linear_math.h"
#include "medium.h"

namespace rt::core {
class Shape;
class BSDF;
class BSSRDF;
class Primitive;

class Interaction {
 public:
  Vec3f point;
  Float time;

  Vec3f normal;  // surface normal
  Vec3f wo;      // negative ray direction

  MediumInterface medium_interface;
};

class SurfaceInteraction : public Interaction {
 public:
  Vec2f uv;
  Vec3f dp_du, dp_dv;
  Vec2f dn_du, dn_dv;
  const Shape* shape = nullptr;
  struct {
    Vec3f normal;
    Vec3f dp_du, dp_dv;
    Vec3f dn_du, dn_dv;
  } shading;

  const Primitive* primitive = nullptr;
  BSDF* bsdf = nullptr;
  BSSRDF* bssrdf = nullptr;
};
}  // namespace rt::core

#endif
