#include "world.h"
#include <lua.hpp>

void World::testMap(Graphics *graphics){
}

void World::load(const char* filename, Graphics *graphics){
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

    Texture *texture = new Texture();
    texture->set(graphics->getTexture(tex_file));

    tilemap.init(w,h,col,tilesize,texture,tiles);

}
