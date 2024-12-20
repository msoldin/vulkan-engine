module;
#include <memory>
#include <utility>
export module vulkan_engine.memory:allocator;

namespace vulkan_engine::memory {
export class Allocator {
 public:
  explicit Allocator(const size_t memorySize) : m_memoryStart(malloc(memorySize)), m_size(memorySize), m_spaceLeft(memorySize), m_numAllocations(0) {}

  virtual ~Allocator() { free(m_memoryStart); }

  Allocator(Allocator&&) = delete;

  Allocator(const Allocator&) = delete;

  Allocator& operator=(Allocator&&) = delete;

  Allocator& operator=(const Allocator&) = delete;

  template <typename T, typename... Args>
  T* makeNew(Args&&... args) {
    return new (allocate(sizeof(T), alignof(T))) T(std::forward<Args>(args)...);
  }

  [[nodiscard]] size_t getSize() const { return m_size; }
  [[nodiscard]] size_t getSpaceLeft() const { return m_spaceLeft; }
  [[nodiscard]] size_t getNumAllocations() const { return m_numAllocations; }

 private:
  virtual void* allocate(size_t size, size_t alignment) = 0;

  virtual void deallocate(void* p) = 0;

 protected:
  void* m_memoryStart;
  size_t m_size;
  size_t m_spaceLeft;
  size_t m_numAllocations;
};
}  // namespace vulkan_engine::memory
