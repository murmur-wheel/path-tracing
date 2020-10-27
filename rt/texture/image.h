//
// Created by murmur-wheel on 2020/10/24.
//

#ifndef RT_TEXTURE_IMAGE_H
#define RT_TEXTURE_IMAGE_H

#include "../core/linear_math.h"
#include "../core/texture.h"

namespace rt::texture {
template <typename StorageType, typename ReturnType>
class ImageTexture : public core::Texture<ReturnType> {};
}  // namespace rt::texture

#endif