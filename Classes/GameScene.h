#pragma once

#include "cocos2d.h"

class Neko;
class Item;
class Highscore;
class GameTimer;

class Game : public cocos2d::Layer
{
public:
    ~Game();

    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(Game);

    void update(float) override;

private:
    Neko *neko;
    Item *item;

    Highscore *highscore;
    GameTimer *timer;
};

