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

private:
    const std::string ANIM_IDLE_NAME = "nekoAnimationIdle";
    const std::string ANIM_RIGHT_NAME = "nekoAnimationRight";
    const std::string ANIM_LEFT_NAME = "nekoAnimationLeft";

    const float SPEED = 400.0f;
};