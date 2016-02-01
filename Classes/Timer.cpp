#include "Timer.h"

USING_NS_CC;

// ---------------------------------------------------------------------------------------------------------------------

const static std::string TIMER_FONT_FILE = "fonts/Marker Felt.ttf";

struct TimerPimpl
{
    TimerPimpl() : currentTime(90), timer(0)
    {}
    int currentTime;

    time_t timer;
    cocos2d::TTFConfig* timerTtfConfig;
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
    this->timerPimpl->timerTtfConfig = new TTFConfig(TIMER_FONT_FILE.c_str(), 24, GlyphCollection::DYNAMIC);
    this->setTTFConfig(*this->timerPimpl->timerTtfConfig);

    this->scheduleUpdate();

    return true;
}

int
GameTimer::GetCurrentTime() const
{
    return this->timerPimpl->currentTime;
}

void
GameTimer::update(float deltaTime)
{
    if (0 != this->timerPimpl->currentTime) {
        time_t timeNow;
        time(&timeNow);
        this->timerPimpl->currentTime = 90 - static_cast<int>(difftime(timeNow, this->timerPimpl->timer));
        this->setString("time: " + std::to_string(this->timerPimpl->currentTime));
    }
}