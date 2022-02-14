#pragma once

class Game
{
private:

protected:
    bool done;
    bool isRunning;
    int *key;
public:
    virtual void init() = 0;
    virtual void run() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;
    virtual void quit() = 0;
};


