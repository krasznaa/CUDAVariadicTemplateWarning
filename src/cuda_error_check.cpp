
// Project include(s).
#include "cuda_error_check.hpp"

// System include(s).
#include <sstream>
#include <stdexcept>

namespace cuda {

void throw_error(cudaError_t errorCode, const char *expression,
                 const char *file, int line) {

  // Create a nice error message.
  std::ostringstream errorMsg;
  errorMsg << file << ":" << line << " Failed to execute: " << expression
           << " (" << cudaGetErrorString(errorCode) << ")";

  // Now throw a runtime error with this message.
  throw std::runtime_error(errorMsg.str());
}

} // namespace cuda
