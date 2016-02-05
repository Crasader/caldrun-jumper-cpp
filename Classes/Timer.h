#pragma once
#include "cocos2d.h"

class GameTimer : public cocos2d::Label
{
public:
    ~GameTimer();

    virtual bool init();
    CREATE_FUNC(GameTimer);

    int GetCurrentTime() const;

    void update(float) override;

protected:
    GameTimer();

private:
    struct TimerPimpl;
    TimerPimpl* timerPimpl;
};
