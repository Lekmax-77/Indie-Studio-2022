find_package(yaml-cpp QUIET)
if (NOT yaml-cpp_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    yaml-cpp
    URL https://github.com/jbeder/yaml-cpp/archive/refs/tags/yaml-cpp-0.7.0.zip
  )
  FetchContent_GetProperties(yaml-cpp)
  if (NOT yaml-cpp_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(yaml-cpp)
    add_subdirectory(${yaml-cpp_SOURCE_DIR} ${yaml-cpp_BINARY_DIR})
  endif()
endif()
