cmake_minimum_required(VERSION 3.22)
project(app)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(PkgConfig REQUIRED)
pkg_check_modules(ALLEGRO5 REQUIRED allegro-5 allegro_image-5 allegro_font-5 allegro_primitives-5)
find_package(Lua 5.4 EXACT REQUIRED)
message(" ${LUA_INCLUDE_DIRS}")
#file(STRINGS list.txt list)

set(SRCS 
source/game/player.h
source/game/tilemap.cpp
source/game/world.cpp
source/game/world.h
source/game/tilemap.h
source/game/player.cpp
source/components/component.h
source/components/component.cpp
source/allegro/graphics.cpp
source/allegro/game.cpp
source/allegro/game.h
source/allegro/graphics.h
source/app/main.cpp
source/core/vector2.h
source/core/input.cpp
source/core/game.cpp
source/core/game.h
source/core/gameobject.h
source/core/input.h
source/core/graphics.h
source/core/gameobject.cpp
)

add_executable(app ./source/app/main.cpp ${SRCS})
target_link_libraries(app ${ALLEGRO5_LIBRARIES}  ${LUA_LIBRARIES})
target_include_directories(app PUBLIC ${ALLEGRO5_INCLUDE_DIRS} ${LUA_INCLUDE_DIRS})
