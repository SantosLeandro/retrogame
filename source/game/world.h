#pragma once

#include <vector>
#include <memory>
#include "../core/gameobject.h"
#include "player.h"
#include "../core/graphics.h"
#include "tilemap.h"
#include <lua5.4/lua.hpp>

class Level{
    protected:
        std::vector<GameObject*> gameObject;
        Tilemap tilemap;
    public:
        void load(const char* filename, IGraphics *graphics);
        void testMap(IGraphics *graphics);
        GameObject* newGameObject();
        GameObject* addGameObject(int type, IGraphics *graphics){
            switch(type){
                case 0:
                    auto *object = new Player();
                    object->init(graphics);
                    gameObject.push_back(std::move(object));
                    return gameObject.back();
                break;
            }

        }
        void clear(){

        }
        void update();

        virtual void draw(IGraphics *graphics){
        tilemap.draw(graphics);
            for(auto &o: gameObject)
                o->draw(graphics);
        }
};

int lua_create_level(lua_State *L);
int lua_create_object(lua_State *L);
int lua_add_component(lua_State *L);
int lua_create_object_ext(lua_State *state);
int lua_move_to(lua_State *state);

class LevelManager{
        static std::vector<Level*> level;
        static int levelId;
        IGraphics *graphics;
    public:
        static void changeLevel(int id){
            levelId = id;
        }
        static void update(float deltatime){
            level[levelId]->update();
        }
        static void draw(IGraphics *graphics){
            level[levelId]->draw(graphics);
        }

        static void init(IGraphics *graphics);
        static Level* create();
        static Level* load(const char *filename);
};
