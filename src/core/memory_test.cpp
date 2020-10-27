//
// Created by murmur-wheel on 2020/10/22.
//

#include <core/memory.h>
#include <gtest/gtest.h>

TEST(Arena, misc) {
  using namespace rt::core;
  Arena arena;
  size_t align = alignof(std::max_align_t);
  auto int_ptr = reinterpret_cast<intptr_t>(arena.alloc(align));
  ASSERT_TRUE(int_ptr % align == 0);
}
