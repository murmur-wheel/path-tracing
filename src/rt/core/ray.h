//
// Created by murmur-wheel on 2020/10/21.
//

#ifndef RT_CORE_RAY_H
#define RT_CORE_RAY_H

#include "math.h"

namespace rt::core {
class Medium;
struct Ray {
  Vec3f origin;
  Vec3f direction;

  float time;  // animating
  const Medium* medium;
};
}  // namespace rt::core

#endif
