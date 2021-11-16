
// Project include(s).
#include "execute_cuda_test.cuh"

/// Dummy functor, not doing anything useful
struct dummy_functor {
  __host__ __device__ void operator()(std::size_t i, float a, int b) {
    float c = a * b;
    a = c;
  }
}; // struct dummy_functor

int main() {

  // Execute the dummy functor on 1000 threads.
  execute_cuda_test<dummy_functor>(1000, 2.5f, 23);

  // Return gracefully.
  return 0;
}
