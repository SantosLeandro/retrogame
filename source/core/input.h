#pragma once

class Keyboard{
    static int *s_pKey;
    public:
    static void init(int *keys){
       s_pKey = keys;
    }
    static int getKeyDown(int keycode){
        return s_pKey[keycode];
    }
};
