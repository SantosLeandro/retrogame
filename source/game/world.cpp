#include "world.h"
#include "../allegro/graphics.h"
#include <cstring>
#include "../core/component.h"

void Level::testMap(IGraphics *graphics){
}

void Level::load(const char* filename, IGraphics *graphics){
    lua_State *state;
    state = luaL_newstate();
    luaL_openlibs(state);
    int result = luaL_loadfile(state, filename);
    if(result != 0){
        std::cout<<"ERROR SCRIPT "<<lua_tostring(state, -1)<<"\n";
    }
    lua_pcall(state, 0, LUA_MULTRET, 0);

    lua_getglobal(state, "name");
    const char* name = lua_tostring(state, -1);
    std::cout<<"TILEMAP name "<<name<<"\n";
    lua_pop(state, 0);

    lua_getglobal(state, "texture");
    const char* tex_file = lua_tostring(state, -1);
    lua_pop(state, 0);

    lua_getglobal(state, "col");
    int col = lua_tointeger(state, -1);
    lua_pop(state, 0);

    lua_getglobal(state, "tilesize");
    int tilesize = lua_tointeger(state, -1);
    lua_pop(state, 0);

    lua_getglobal(state,"width");
    int w = lua_tointeger(state, -1);
    lua_pop(state,0);
    lua_getglobal(state,"height");
    int h = lua_tointeger(state, -1);
    lua_pop(state,0);

    lua_getglobal(state,"data");
    int n = lua_rawlen(state, -1);
    std::vector<int> tiles;
    for (int i=1; i<=n; i++){
        lua_rawgeti(state, -1, i);
        tiles.push_back(lua_tonumber(state, -1));
        lua_pop(state,1);
    }
    lua_pop(state, 0);

    lua_getglobal(state,"objects");
    n = lua_rawlen(state, -1);
    std::cout<<"N OBJECTS "<<n<<"\n";
    lua_rawgeti(state, -1, 1);
    lua_getfield(state, -1, "name");
    const char* type = lua_tostring(state, -1);
    lua_getfield(state, -2, "x");
    int x = lua_tointeger(state, -1);
    lua_getfield(state, -3, "y");
    int y = lua_tointeger(state, -1);
    std::cout<<"TYPE "<<type<<" position x: "<<x<<" y: "<<y<<"\n";



    lua_close(state);

    Texture *texture = graphics->getTexture(tex_file);
    if(!texture){
        std::cout<<"NOT FOUND\n";
    }

    tilemap.init(w,h,col,tilesize, graphics->getTexture(tex_file),tiles);

}




std::vector<Level*> LevelManager::level;

int LevelManager::levelId = 0;

Level* LevelManager::create(){
    Level* l = new Level();
    level.push_back(l);
    return l;

}

Level* LevelManager::load(const char* filename){
    lua_State *state;
    state = luaL_newstate();
    luaL_openlibs(state);
    lua_pushcfunction(state, lua_create_level);
    lua_setglobal(state, "_createLevel");
    lua_pushcfunction(state, lua_create_object);
    lua_setglobal(state, "_createObject");
    lua_pushcfunction(state, lua_create_object_ext);
    lua_setglobal(state, "_createObjectExt");
    lua_pushcfunction(state, lua_add_component);
    lua_setglobal(state, "_addComponent");
    int result = luaL_loadfile(state, filename);
    if(result != 0){
        std::cout<<"ERROR SCRIPT "<<lua_tostring(state, -1)<<"\n";
    }
    lua_pcall(state, 0, LUA_MULTRET, 0);
    return nullptr;
}



int lua_create_level(lua_State *state){
    printf("_create_level\n");
    Level* level = LevelManager::create();
    lua_pushlightuserdata(state, level);
    return 1;
}

int lua_create_object(lua_State *state){
    printf("_create_object\n");
    Level* level = (Level*)lua_touserdata(state, 1);
    int x = lua_tointeger(state, 2);
    int y = lua_tointeger(state, 3);
    GameObject *object = level->newGameObject();
    object->setPosition(Vector2(x,y));
    lua_pushlightuserdata(state, object);
    return 1;
}

int lua_add_component(lua_State *state){
    printf("_add_component\n");
    GameObject* object = (GameObject*)lua_touserdata(state, 1);
    const char* type = lua_tostring(state, 2);
    if(strcmp(type,"staticSprite")==0){
        printf("  _add_static_sprite\n");
        Sprite sprite;
        const char* texture = lua_tostring(state, 3);
        sprite.texture = Graphics::getInstance()->getTexture(texture);
        StaticSprite *ss = object->addComponent<StaticSprite>();
        ss->setSprite(sprite);
    }
    return 0;
}

int lua_create_object_ext(lua_State *state){
    printf("_create_object_ext\n");
    float x = lua_tonumber(state, 1);
    float y = lua_tonumber(state, 2);
    int len = lua_rawlen(state, 3);
    std::cout<<"len "<<len<<"\n\n";
    for(int i=1; i <= len;i++){
        printf("i = %d\n",i);
        lua_rawgeti(state, -1, i);
        lua_getfield(state, 4,"type");
        const char* type = lua_tostring(state,-1);
        printf("TYPE: %s\n\n",type);
        lua_pop(state,1);
        lua_pop(state,1);
    }
    return 1;
}
