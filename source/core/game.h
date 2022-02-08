#pragma once

class Game
{
private:
    
protected:
    bool done;
    bool isRunning;
    int *key;
public:
    virtual void init();
    virtual void run();
    virtual void update();
    virtual void draw();
    virtual void quit();
};


