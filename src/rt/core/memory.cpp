#include "memory.h"

namespace rt::core {
Arena::~Arena() {
  free(current_block_.block);
  for (const auto& block : used_blocks_) {
    free(block.block);
  }
  for (const auto& block : available_blocks_) {
    free(block.block);
  }
}

Arena::MemoryBlock Arena::alloc_aligned(size_t alloc_size) {
  const size_t align = alignof(std::max_align_t);

  MemoryBlock res;
  res.alloc_size = alloc_size;

  res.block = ::malloc(alloc_size + align);

  auto int_ptr = reinterpret_cast<intptr_t>(res.block);
  res.aligned =
      reinterpret_cast<uint8_t*>((int_ptr + align - 1) & ~(align - 1));

  return res;
}
}  // namespace rt::core
