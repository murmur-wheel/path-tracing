//
// Created by murmur-wheel on 2020/10/23.
//

#include "bitmap.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace rt::core {
void save_bitmap(const Bitmap& bitmap, const std::string& filename) {
  int buf_len = bitmap.width() * bitmap.height() * 3;
  std::vector<uint8_t> buf(buf_len);

  for (int x = 0; x < bitmap.width(); ++x) {
    for (int y = 0; y < bitmap.height(); ++y) {
      const auto& p = bitmap.at(x, y);
      int pos = (y * bitmap.width() + x) * 3;
      uint8_t* ptr = buf.data() + pos;
      for (int k = 0; k < 3; ++k) {
        ptr[k] = uint32_t(p[k] * 255.0f) & 0xff;
      }
    }
  }

  stbi_write_png(filename.c_str(), bitmap.width(), bitmap.height(), 3,
                 buf.data(), 0);
}

Bitmap load_bitmap(const std::string& filename) {
  int x, y, comp;
  auto buf = stbi_load(filename.c_str(), &x, &y, &comp, 3);

  Bitmap res(x, y);
  for (int x = 0; x < res.width(); ++x) {
    for (int y = 0; y < res.height(); ++y) {
      int pos = (x + y * res.width()) * 3;
      auto ptr = buf + pos;

      auto& p = res.at(x, y);
      for (int k = 0; k < 3; ++k) {
        p[k] = float(ptr[k]) / 255.0f;
      }
    }
  }

  stbi_image_free(buf);
  return res;
}

}  // namespace rt::core
