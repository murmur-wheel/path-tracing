//
// Created by murmur-wheel on 2020/10/24.
//

#ifndef RT_CORE_MEMORY_H
#define RT_CORE_MEMORY_H

#include "common.h"

namespace rt::core {
class Arena {
 public:
  Arena(size_t block_size = 262144) : block_size_(block_size) {}
  ~Arena();

  template <typename T, typename... Args>
  T* make(Args&&... args) {
    return new (alloc(sizeof(T))) T(std::forward(args)...);
  }

  void* alloc(size_t num_bytes) {
    const int align = alignof(std::max_align_t);
    num_bytes = (num_bytes + align - 1) & ~(align - 1);
    if (current_block_pos_ + num_bytes > current_block_.alloc_size) {
      if (current_block_.alloc_ptr) {
        used_blocks_.push_back(current_block_);
        current_block_ = {};
      }

      for (auto it = available_blocks_.begin(); it != available_blocks_.end();
           ++it) {
        if (it->alloc_size >= num_bytes) {
          current_block_ = *it;
          available_blocks_.erase(it);
          break;
        }
      }

      if (!current_block_.alloc_ptr) {
        const auto alloc_size = std::max<size_t>(num_bytes, block_size_);
        current_block_ = alloc_aligned_block(alloc_size);
      }

      current_block_pos_ = 0;
    }

    void* ret = current_block_.aligned_ptr + current_block_pos_;
    current_block_pos_ += num_bytes;
    return ret;
  }

  void reset() {
    current_block_pos_ = 0;
    available_blocks_.splice(available_blocks_.begin(), used_blocks_);
  }

 private:
  struct MemoryBlock {
    void* alloc_ptr = nullptr;
    uint8_t* aligned_ptr = nullptr;
    size_t alloc_size = 0;
  };

  const size_t block_size_;

  // current
  MemoryBlock current_block_;
  size_t current_block_pos_ = 0;

  std::list<MemoryBlock> used_blocks_, available_blocks_;

  static MemoryBlock alloc_aligned_block(size_t alloc_size);
};
}  // namespace rt::core

#endif