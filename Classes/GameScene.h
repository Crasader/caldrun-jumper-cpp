#pragma once

#include "cocos2d.h"

class Game : public cocos2d::Layer
{
public:
    ~Game();

    static cocos2d::Scene* createScene();

    virtual bool init();
    CREATE_FUNC(Game);

    void update(float) override;

protected:
    Game();

private:
    class GamePimpl;
    GamePimpl* gamePimpl;
};

