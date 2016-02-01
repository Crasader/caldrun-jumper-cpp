#pragma once
#include "cocos2d.h"

class Highscore : public cocos2d::Label
{
public:
    ~Highscore();

    virtual bool init();
    CREATE_FUNC(Highscore);

    void AddScoreForOneItem();

    void update(float) override;

protected:
    Highscore();

private:
    const std::string FONT_FILE = "fonts/Marker Felt.ttf";
    cocos2d::TTFConfig* highscoreTtfConfig;

    int score;
};