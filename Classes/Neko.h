#pragma once

#include "cocos2d.h"

class Neko : public cocos2d::Sprite
{
public:
    ~Neko();

    virtual bool init();
    CREATE_FUNC(Neko);

    void Idle();
    void MoveRight();
    void MoveLeft();
    void Jump();

    void update(float) override;

protected:
    Neko();
};
