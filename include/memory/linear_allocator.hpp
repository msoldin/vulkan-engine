//
// Created by marvi on 04.05.2024.
//

#ifndef LINEAR_ALLOCATOR_HPP
#define LINEAR_ALLOCATOR_HPP
#include "allocator.hpp"

namespace vulkan_engine::memory {

class LinearAllocator : public Allocator {

 public:
  LinearAllocator(size_t size, void* start);

 private:
  void* allocate(size_t size, size_t alignment) override;
  void deallocate(void* p) override;
  void* m_currentPos;
};

}  // namespace vulkan_engine::memory

#endif  //LINEAR_ALLOCATOR_HPP
