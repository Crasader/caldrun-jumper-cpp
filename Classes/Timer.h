#pragma once
#include "cocos2d.h"

struct TimerPimpl;

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
    TimerPimpl* timerPimpl;
};
