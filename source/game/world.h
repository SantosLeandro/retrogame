#pragma once

#include <vector>
#include <memory>
#include "../core/gameobject.h"
#include "player.h"
#include "../core/graphics.h"
#include "tilemap.h"

class World{
    protected:
        std::vector<std::shared_ptr<GameObject> > gameObject;
        Tilemap tilemap;
    public:
        void load(const char* filename, Graphics *graphics);
        void testMap(Graphics *graphics);
        std::shared_ptr<GameObject> addGameObject(int type, Graphics *graphics){
            switch(type){
                case 0:
                    auto object = std::make_shared<Player>();
                    object->init(graphics);
                    gameObject.push_back(std::move(object));
                    return gameObject.back();
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
