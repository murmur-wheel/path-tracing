#include "memory.h"

namespace rt::core {
Arena::~Arena() {
  if (current_block_.alloc_ptr) {
    free(current_block_.alloc_ptr);
  }

  for (const auto& block : used_blocks_) {
    free(block.alloc_ptr);
  }

  for (const auto& block : available_blocks_) {
    free(block.alloc_ptr);
  }
}

Arena::MemoryBlock Arena::alloc_aligned_block(size_t alloc_size) {
  const size_t align = alignof(std::max_align_t);

  MemoryBlock res;
  res.alloc_size = alloc_size;

  res.alloc_ptr = ::malloc(alloc_size + align);

  auto int_ptr = reinterpret_cast<intptr_t>(res.alloc_ptr);
  res.aligned_ptr =
      reinterpret_cast<uint8_t*>((int_ptr + align - 1) & ~(align - 1));

  return res;
}
}  // namespace rt::core
