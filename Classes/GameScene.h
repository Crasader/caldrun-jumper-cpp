#pragma once

#include "cocos2d.h"

class Neko;

class Game : public cocos2d::Layer
{
public:
    ~Game();

    static cocos2d::Scene* createScene();

    virtual bool init();

    CREATE_FUNC(Game);


private:
    cocos2d::Sprite* nekoSprite;

    Neko *neko;
};

