#include "Timer.h"

#include <time.h>

USING_NS_CC;

// ---------------------------------------------------------------------------------------------------------------------

struct TimerPimpl
{
    TimerPimpl() : currentTime(90), timer(0)
    {}

    int currentTime;
    time_t timer;
};

// ---------------------------------------------------------------------------------------------------------------------

GameTimer::~GameTimer()
{
    delete this->timerPimpl;
}

GameTimer::GameTimer() : timerPimpl(new TimerPimpl())
{
    time(&this->timerPimpl->timer);
}

bool
GameTimer::init()
{
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(50, 550);
    this->timerTtfConfig = new TTFConfig(GameTimer::FONT_FILE.c_str(), 24, GlyphCollection::DYNAMIC);
    this->setTTFConfig(*this->timerTtfConfig);

    this->scheduleUpdate();

    return true;
}

void
GameTimer::update(float deltaTime)
{
    time_t timeNow;
    time(&timeNow);
    this->timerPimpl->currentTime = 90 - static_cast<int>(difftime(timeNow, this->timerPimpl->timer));
    this->setString("points: " + std::to_string(this->timerPimpl->currentTime));
}