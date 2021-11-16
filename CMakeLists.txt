
# Set up the project.
cmake_minimum_required( VERSION 3.18 )
project( CUDAVariadicTemplateWarning VERSION 0.0.1 LANGUAGES CXX CUDA )

# Set the language standards.
set( CMAKE_CXX_STANDARD 14 CACHE STRING "The (host) C++ standard to use" )
set( CMAKE_CUDA_STANDARD 14 CACHE STRING "The (CUDA) C++ standard to use" )

# Set the CUDA device architecture.
set( CMAKE_CUDA_ARCHITECTURE "52" CACHE STRING
   "CUDA architecture to build code for" )

# Find CUDA for the C++ code.
find_package( CUDAToolkit REQUIRED )

# Build the test executable.
add_executable( cuda_test "src/test.cu"
   "src/cuda_error_check.hpp" "src/cuda_error_check.cpp"
   "src/execute_cuda_test.cuh" )
target_link_libraries( cuda_test PRIVATE CUDA::cudart )
