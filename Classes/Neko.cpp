#include "Neko.h"

USING_NS_CC;

Neko::Neko()
{}

Neko::~Neko()
{
}

bool
Neko::init()
{
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(100, 100);

    // init idle
    Vector<SpriteFrame*> animFramesIdle(4);
    char strJump[100] = {0};
    for(int i = 1; i < 4; i++)
    {
        sprintf(strJump, "neko/idle%d.png",i);
        auto frame = SpriteFrame::create(strJump, Rect(0,0,32,32));
        animFramesIdle.pushBack(frame);
    }
    auto nekoAnimationIdle = Animation::createWithSpriteFrames(animFramesIdle, 0.1f);
    AnimationCache::getInstance()->addAnimation(nekoAnimationIdle, Neko::ANIM_IDLE_NAME);

    // init right
    Vector<SpriteFrame*> animFramesRight(6);
    char strRight[100] = {0};
    for(int i = 1; i < 6; i++)
    {
        sprintf(strRight, "neko/right%d.png",i);
        auto frame = SpriteFrame::create(strRight, Rect(0,0,32,32));
        animFramesRight.pushBack(frame);
    }
    auto nekoAnimationRight = Animation::createWithSpriteFrames(animFramesRight, 0.1f);
    AnimationCache::getInstance()->addAnimation(nekoAnimationRight, Neko::ANIM_RIGHT_NAME);

    // init left
    Vector<SpriteFrame*> animFramesLeft(6);
    char strLeft[100] = {0};
    for(int i = 1; i < 6; i++)
    {
        sprintf(strLeft, "neko/left%d.png",i);
        auto frame = SpriteFrame::create(strLeft, Rect(0,0,32,32));
        animFramesLeft.pushBack(frame);
    }
    auto nekoAnimationLeft = Animation::createWithSpriteFrames(animFramesLeft, 0.1f);
    AnimationCache::getInstance()->addAnimation(nekoAnimationLeft, Neko::ANIM_LEFT_NAME);

    this->initWithFile("neko/right1.png");
    this->Idle();

    return true;
}

void
Neko::Idle()
{
    this->stopActionsByFlags(1);
    auto nekoAnimationIdle = AnimationCache::getInstance()->getAnimation(Neko::ANIM_IDLE_NAME);
    auto nekoAnimateIdle = Animate::create(nekoAnimationIdle);
    auto actionIdle = RepeatForever::create(nekoAnimateIdle);
    actionIdle->setFlags(1);
    this->runAction(actionIdle);
}

void
Neko::MoveRight()
{
    this->stopActionsByFlags(1);
//    this->stopAllActions();
    auto moveNekoRight = MoveBy::create(1, Vec2(Neko::SPEED, 0));
    auto nekoAnimationRight = AnimationCache::getInstance()->getAnimation(Neko::ANIM_RIGHT_NAME);
    auto nekoAnimateRight = Animate::create(nekoAnimationRight);

    auto actionAnimRight = RepeatForever::create(nekoAnimateRight);
    actionAnimRight->setFlags(1);
    this->runAction(actionAnimRight);

    auto actionMoveRight = RepeatForever::create(moveNekoRight);
    actionMoveRight->setFlags(1);
    this->runAction(actionMoveRight);
}

void
Neko::MoveLeft()
{
    this->stopActionsByFlags(1);
//    this->stopAllActions();
    auto moveNekoLeft = MoveBy::create(1, Vec2(-1 * Neko::SPEED, 0));
    auto nekoAnimationLeft = AnimationCache::getInstance()->getAnimation(Neko::ANIM_LEFT_NAME);
    auto nekoAnimateLeft = Animate::create(nekoAnimationLeft);
    auto actionAnimLeft = RepeatForever::create(nekoAnimateLeft);
    actionAnimLeft->setFlags(1);
    auto actionMoveLeft = RepeatForever::create(moveNekoLeft);
    actionMoveLeft->setFlags(1);
    this->runAction(actionAnimLeft);
    this->runAction(actionMoveLeft);
}

void
Neko::Jump()
{
    auto moveUp = MoveBy::create(1, Vec2(0, 450));
    auto moveDown = MoveBy::create(1, Vec2(0, -450));
    this->runAction(Sequence::create(moveUp, moveDown, nullptr));
}