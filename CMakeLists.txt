cmake_minimum_required(VERSION 3.22)
project(app)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALLEGRO5 REQUIRED allegro-5 allegro_image-5 allegro_font-5 allegro_primitives-5)
find_package(Lua REQUIRED)

#file(STRINGS list.txt list)

set(SRCS 
source/allegro/game.cpp
source/allegro/game.h
source/allegro/graphics.cpp
source/allegro/graphics.h
source/core/component.cpp
source/core/component.h
source/core/game.cpp
source/core/game.h
source/core/gameobject.cpp
source/core/gameobject.h
source/core/graphics.h
source/core/input.cpp
source/core/input.h
source/core/vector2.h
source/game/player.cpp
source/game/player.h
source/game/tilemap.cpp
source/game/tilemap.h
source/game/world.cpp
source/game/world.h
)

add_executable(app ./source/main.cpp ${SRCS})
target_link_libraries(app ${ALLEGRO5_LIBRARIES} ${LUA_LIBRARIES})
target_include_directories(app PUBLIC ${ALLEGRO5_INCLUDE_DIRS} ${LUA_INCLUDE_DIRS})
