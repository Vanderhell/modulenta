cmake_minimum_required(VERSION 3.20)
project(modulenta VERSION 0.1.0 LANGUAGES C)
option(MODULENTA_BUILD_TESTS "Build migrated tests" ON)
file(GLOB MODULENTA_SOURCES CONFIGURE_DEPENDS src/*.c)
add_library(modulenta STATIC ${MODULENTA_SOURCES})
target_include_directories(modulenta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/modulenta/utility)
target_compile_features(modulenta PUBLIC c_std_99)
if(MODULENTA_BUILD_TESTS)
 enable_testing()
 set(MODULENTA_TESTS
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_nearest.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_binary_majority3x3_u32.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_opt_argmax_small_i32.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_opt_argmin_small_i32.c
  # The preserved discrepancy, USB frame and 1-Wire ROM tests belong to
  # source families that are not included in this standalone product.
  )
 foreach(test_source IN LISTS MODULENTA_TESTS)
  get_filename_component(test_name "${test_source}" NAME_WE)
  add_executable(modulenta_${test_name} ${test_source})
  target_include_directories(modulenta_${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/modulenta/utility)
  target_link_libraries(modulenta_${test_name} PRIVATE modulenta)
  add_test(NAME "${test_name}" COMMAND "modulenta_${test_name}")
 endforeach()
endif()
