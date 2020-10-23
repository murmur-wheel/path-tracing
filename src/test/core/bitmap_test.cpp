//
// Created by murmur-wheel on 2020/10/23.
//

#include <core/bitmap.h>
#include <gtest/gtest.h>

TEST(bitmap, misc) {
  using namespace rt::core;

  Bitmap bitmap(600, 400);
  for (int i = 0; i < bitmap.width(); i++) {
    for (int j = 0; j < bitmap.height(); j++) {
      int m = i / 64, n = j / 64;
      if ((m + n) % 2) {
        bitmap.at(i, j) = Vec3f(1);
      }
    }
  }

  save_bitmap(bitmap, "bitmap.png");

  auto loaded = load_bitmap("bitmap.png");
  save_bitmap(loaded, "saved.png");
}
