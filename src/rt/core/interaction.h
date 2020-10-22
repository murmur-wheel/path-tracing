//
// Created by murmur-wheel on 2020/10/22.
//

#ifndef RT_CORE_INTERACTION_H
#define RT_CORE_INTERACTION_H

#include "common.h"
#include "math.h"

namespace rt::core {
class MediumInterface;
class Shape;

class Interaction {
 public:
  Vec3f point;
  Float time;

  Vec3f normal;  // surface normal
  Vec3f wo;      // negative ray direction

  MediumInterface* medium_interface = nullptr;
};

class SurfaceInteraction : public Interaction {
 public:
  Vec2f uv;
  Vec3f dp_du, dp_dv;
  Vec2f dn_du, dn_dv;
  const Shape* shape = nullptr;
};
}  // namespace rt::core

#endif
