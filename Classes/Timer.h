#pragma once
#include "cocos2d.h"

struct TimerPimpl;

class GameTimer : public cocos2d::Label
{
public:
    ~GameTimer();

    virtual bool init();
    CREATE_FUNC(GameTimer);

    void update(float) override;

protected:
    GameTimer();

private:
    const std::string FONT_FILE = "fonts/Marker Felt.ttf";
    cocos2d::TTFConfig* timerTtfConfig;

    TimerPimpl* timerPimpl;
};
