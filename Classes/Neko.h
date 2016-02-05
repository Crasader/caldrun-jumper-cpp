#pragma once

#include "cocos2d.h"

class Neko : public cocos2d::Sprite
{
public:
    ~Neko();

    virtual bool init();
    CREATE_FUNC(Neko);

    void idle();
    void moveRight();
    void moveLeft();
    void jump();

    void update(float) override;

protected:
    Neko();
};
