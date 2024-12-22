# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-src"
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-build"
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-subbuild/raylib-populate-prefix"
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-subbuild/raylib-populate-prefix/tmp"
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-subbuild/raylib-populate-prefix/src"
  "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/hanifmuhammad/Projects/pong-game-cmake/_deps/raylib-subbuild/raylib-populate-prefix/src/raylib-populate-stamp/${subDir}")
endforeach()
