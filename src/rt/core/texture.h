//
// Created by murmur-wheel on 2020/10/23.
//

#ifndef RT_CORE_TEXTURE_H
#define RT_CORE_TEXTURE_H

#include "common.h"
#include "interaction.h"
#include "linear_math.h"

namespace rt::core {
class TextureMapping2D {
 public:
  TextureMapping2D() = default;
  virtual ~TextureMapping2D() = default;

  /**
   * @param dst_dx destnation dx
   * @param dst_dy destnation dy
   */
  virtual Vec2f map(const SurfaceInteraction& surface_interaction,
                    Vec2f* dst_dx, Vec2f* dst_dy) const = 0;

  DISABLE_COPY_AND_MOVE(TextureMapping2D)
};

template <typename T>
class Texture {
 public:
  Texture() = default;
  virtual ~Texture() = default;
  virtual T evaluate(const SurfaceInteraction& surface_interaction) const = 0;

 private:
  DISABLE_COPY_AND_MOVE(Texture)
};
}  // namespace rt::core

#endif
