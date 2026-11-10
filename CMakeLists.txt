cmake_minimum_required(VERSION 3.20)
project(modulenta VERSION 0.1.0 LANGUAGES C)
option(MODULENTA_BUILD_TESTS "Build migrated tests" ON)
option(MODULENTA_STRICT_WARNINGS "Enable strict compiler warnings" OFF)
file(GLOB MODULENTA_SOURCES CONFIGURE_DEPENDS src/*.c)
add_library(modulenta STATIC ${MODULENTA_SOURCES})
target_include_directories(modulenta PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/modulenta/utility)
target_compile_features(modulenta PUBLIC c_std_99)
if(MODULENTA_STRICT_WARNINGS)
 if(MSVC)
  target_compile_options(modulenta PRIVATE /W4 /WX)
 else()
  target_compile_options(modulenta PRIVATE -Wall -Wextra -Wpedantic -Werror)
  if(CMAKE_C_COMPILER_ID MATCHES "Clang")
   # Preserved source units intentionally retain their original EOF bytes.
   target_compile_options(modulenta PRIVATE -Wno-newline-eof)
  endif()
 endif()
endif()
if(MODULENTA_BUILD_TESTS)
 enable_testing()
 set(MODULENTA_TESTS
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_nearest.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_binary_majority3x3_u32.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_opt_argmax_small_i32.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_opt_argmin_small_i32.c
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_all_public_api.c
  # The preserved discrepancy, USB frame and 1-Wire ROM tests belong to
  # source families that are not included in this standalone product.
  )
 foreach(test_source IN LISTS MODULENTA_TESTS)
  get_filename_component(test_name "${test_source}" NAME_WE)
  add_executable(modulenta_${test_name} ${test_source})
  target_include_directories(modulenta_${test_name} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/modulenta/utility)
  target_link_libraries(modulenta_${test_name} PRIVATE modulenta)
  if(MODULENTA_STRICT_WARNINGS)
   if(MSVC)
    target_compile_options(modulenta_${test_name} PRIVATE /W4 /WX)
   else()
    target_compile_options(modulenta_${test_name} PRIVATE -Wall -Wextra -Wpedantic -Werror)
    if(CMAKE_C_COMPILER_ID MATCHES "Clang")
     target_compile_options(modulenta_${test_name} PRIVATE -Wno-newline-eof)
    endif()
   endif()
  endif()
  add_test(NAME "${test_name}" COMMAND "modulenta_${test_name}")
 endforeach()
endif()
