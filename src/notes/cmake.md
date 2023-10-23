# cmake

- Hard link the cmake_commands.json file generated after running `cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 ..` in the build directory.

Set up the dir tree as follows:

```
___ root
 |
 |--- build # artifacts go here
 |--- src # source files, including main go here
 |--- include # header files go here
 |--- libs # library dependencies go here
 |--- .git # no shit
 .gitgnore # add build to this
```

`CMakeLists.txt` at root:

```cmake
cmake_minimum_required(VERSION 3.27)

project(tic_tac_toe
    VERSION 0.1
    DESCRIPTION "Learning CMake and FXTUI together"
    LANGUAGES CXX
)
# CMAKE Standard
set (CMAKE_CXX_STANDARD 17)
# Adding global flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")
include(FetchContent)

FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)

FetchContent_GetProperties(ftxui)
if(NOT ftxui_POPULATED)
  FetchContent_Populate(ftxui)
  add_subdirectory(${ftxui_SOURCE_DIR} ${ftxui_BINARY_DIR} EXCLUDE_FROM_ALL)
endif()
# including the header files
include_directories(include)
# including the source files
add_subdirectory(src)
```

`CMakeLists.txt` at src:

```cmake
set (TARGET ${PROJECT_NAME})
file(GLOB SRC_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
add_executable(${TARGET} ${SRC_LIST})
target_link_libraries(${TARGET}
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
```

`CMakeLists.txt` at libs:

```cmake
# Note that headers are optional, and do not affect add_library, but they will not

file(GLOB LIB_HEADER_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/libs/*.cpp")
file(GLOB LIB_SRC_LIST CONFIGURE_DEPENDS "${ModernCMakeExample_SOURCE_DIR}/libs/src/*.cpp")

# Make an automatic library - will be static or dynamic based on user setting
add_library(modern_library ${LIB_SRC_LIST} ${LIB_HEADER_LIST})

# We need this directory, and users of our library will need it too
target_include_directories(modern_library PUBLIC ../libs)

# This depends on (header only) boost
target_link_libraries(modern_library PRIVATE Boost::boost)

# All users of this library will need at least C++17
target_compile_features(modern_library PUBLIC cxx_std_17)
```

`.gitignore` contains `/build*` and `.cache`

> Might have to add libs separately later on. Not sure how to do that.

## Links

- https://stackoverflow.com/questions/76214615/how-can-i-make-the-vs-code-clangd-extension-aware-of-the-include-paths-defined-i
- https://gitlab.com/CLIUtils/modern-cmake/-/blob/master/examples/extended-project/src/CMakeLists.txt
- https://stackoverflow.com/questions/42533166/how-to-separate-header-file-and-source-file-in-cmake#
-
