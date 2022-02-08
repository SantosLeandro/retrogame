#pragma once

#include <vector>
#include <memory>
#include "../core/gameobject.h"
#include "player.h"
#include "../core/graphics.h"
#include "tilemap.h"

class World{
    protected:
        std::vector<std::unique_ptr<GameObject> > gameObject;
        Tilemap tilemap;
    public:
        void load(const char* filename, Graphics *graphics);
        void testMap(Graphics *graphics);
        virtual void addGameObject(int type, Graphics *graphics){
            switch(type){
                case 0:
                    auto object = std::make_unique<Player>();
                    object->init(graphics);
                    gameObject.push_back(std::move(object));
                break;
            }

        }
        void clear(){

        }
        virtual void update(){
            for(auto &o: gameObject)
                o->update(0);
        }

        virtual void draw(Graphics *graphics){
        tilemap.draw(graphics);
            for(auto &o: gameObject)
                o->draw(graphics);
        }
};
