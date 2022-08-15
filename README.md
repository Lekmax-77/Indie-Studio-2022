# INDIE STUDIO

***Summary:***

 - **Cmake** : How to use a Cmake 101

# Cmake

This part will detail in firset place how to build our project using Cmake and how our cmake work

## build the project

in order to build indie studio, you'll first need to build dependencies via the file  *CMakeLists.txt* located at the root of the project

Linux:

```bash
cmake relative_path_to_CMakeLists.txt
cmake --build relative_path_to_build_directory
```

Windows:

```cmd
cmake relative_path_to_CMakeLists.txt
cmake --build relative_path_to_where_is_CMakeLists.txt_directory
add_compile_options(-Wall)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "./build/")
```

## How does it work

### set project name

```cmake
project(name)

# you can call it through
${PROJECT_NAME}
```

### include an extern cmake script

```cmake
include(RelativePath)
```

### download extern dependencies

```cmake
find_package(LibName version QUIET)# QUIET or REQUIRED depending if package is essential
if (NOT LibName_FOUND)# If there's none, fetch and build the lib
  include(FetchContent)
  FetchContent_Declare(
    LibName
    URL https://URLToLibRepo.tar.gz
  )
  FetchContent_GetProperties(LibName)
  if (NOT LibName_POPULATED) # Have we downloaded our lib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(LibName)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
    add_subdirectory(${LibName_SOURCE_DIR} ${LibName_BINARY_DIR})
  endif()
endif()
```

### include directories and librairies in code
```cmake
# add a directories for includes like -i in a Makefile
include_directories(RelativePathToDirectory)

# add directory to a file for include
target_link_libraries(BinaryName LibName)
```
include_directories() is accessible for all the files in the source-tree 2, target_include_directories() is-only accessible for a specific target when compile

### For windows
There is two possibilities (maybe three but I didn't try on macos), because the compiler of Linux is not the same as Windows.
On Linux we compile with GNU and on Windows with MSCV.

There is flags who work on Linux but not in Windows and vice-versa.
So the solution to add flags on a specific OS is to add "if" and specify the compiler in the condition.