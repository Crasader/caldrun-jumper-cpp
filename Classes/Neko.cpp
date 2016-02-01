#include "Neko.h"

USING_NS_CC;

// ---------------------------------------------------------------------------------------------------------------------

static const std::string ANIM_IDLE_NAME = "nekoAnimationIdle";
static const std::string ANIM_RIGHT_NAME = "nekoAnimationRight";
static const std::string ANIM_LEFT_NAME = "nekoAnimationLeft";

static const float SPEED = 0.5f;
static const float SPEED_DISTANCE = 300.0f;
static const float JUMP_SPEED = 0.7f;
static const float JUMP_DISTANCE = 450.0f;

// ---------------------------------------------------------------------------------------------------------------------

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
    this->setName("nekoSprite");

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
    AnimationCache::getInstance()->addAnimation(nekoAnimationIdle, ANIM_IDLE_NAME);

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
    AnimationCache::getInstance()->addAnimation(nekoAnimationRight, ANIM_RIGHT_NAME);

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
    AnimationCache::getInstance()->addAnimation(nekoAnimationLeft, ANIM_LEFT_NAME);

    this->initWithFile("neko/right1.png");
    this->Idle();

    this->scheduleUpdate();

    return true;
}

void
Neko::Idle()
{
    this->stopActionsByFlags(1);
    auto nekoAnimationIdle = AnimationCache::getInstance()->getAnimation(ANIM_IDLE_NAME);
    auto nekoAnimateIdle = Animate::create(nekoAnimationIdle);
    auto actionIdle = RepeatForever::create(nekoAnimateIdle);
    actionIdle->setFlags(1);
    this->runAction(actionIdle);
}

void
Neko::MoveRight()
{
    this->stopActionsByFlags(1);

    auto moveNekoRight = MoveBy::create(SPEED, Vec2(SPEED_DISTANCE, 0));
    auto nekoAnimationRight = AnimationCache::getInstance()->getAnimation(ANIM_RIGHT_NAME);
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

    auto moveNekoLeft = MoveBy::create(SPEED, Vec2(-1 * SPEED_DISTANCE, 0));
    auto nekoAnimationLeft = AnimationCache::getInstance()->getAnimation(ANIM_LEFT_NAME);
    auto nekoAnimateLeft = Animate::create(nekoAnimationLeft);

    auto actionAnimLeft = RepeatForever::create(nekoAnimateLeft);
    actionAnimLeft->setFlags(1);
    this->runAction(actionAnimLeft);

    auto actionMoveLeft = RepeatForever::create(moveNekoLeft);
    actionMoveLeft->setFlags(1);
    this->runAction(actionMoveLeft);
}

void
Neko::Jump()
{
    if (!this->getActionByTag(2) || (this->getActionByTag(2) && this->getActionByTag(2)->isDone())) {
        auto moveUp = MoveBy::create(JUMP_SPEED, Vec2(0, JUMP_DISTANCE));
        auto moveDown = MoveBy::create(JUMP_SPEED, Vec2(0, -1 * JUMP_DISTANCE));
        auto jumpSequence = Sequence::create(moveUp, moveDown, nullptr);
        jumpSequence->setTag(2);

        this->runAction(jumpSequence);
    }
}

void
Neko::update(float deltaTime)
{
    auto xPosition = this->getPositionX();
    if (xPosition < 40 || xPosition > 760) {
        this->Idle();

        if (40 > xPosition) {
            this->setPositionX(40);
        } else {
            this->setPositionX(760);
        }
    }
}