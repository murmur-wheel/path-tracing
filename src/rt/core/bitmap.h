//
// Created by murmur-wheel on 2020/10/23.
//

#ifndef RT_CORE_BITMAP_H
#define RT_CORE_BITMAP_H

#include "common.h"
#include "linear_math.h"

namespace rt::core {
class Bitmap {
 public:
  explicit Bitmap(int width, int height) : width_(width), height_(height) {
    int total = width_ * height_;
    buf_.resize(total);
  }

  int width() const { return width_; }
  int height() const { return height_; }
  const Vec3f* data() const { return buf_.data(); }
  const Vec3f& at(int x, int y) const { return buf_[x + y * width_]; }
  Vec3f& at(int x, int y) { return buf_[x + y * width_]; }

 private:
  int width_ = 0, height_ = 0;
  std::vector<Vec3f> buf_;
};

void save_bitmap(const Bitmap& bitmap, const std::string& filename);
Bitmap load_bitmap(const std::string& filename);
}  // namespace rt::core

#endif
