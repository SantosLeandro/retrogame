#pragma once

class Keyboard{
    static int *key;
    public:
    static void init(int *k){
       key = k;
    }
    static int getKeyDown(int keycode){
        return key[keycode];
    }
};