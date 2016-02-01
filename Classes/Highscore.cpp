#include "Highscore.h"

USING_NS_CC;

// ---------------------------------------------------------------------------------------------------------------------

const static std::string HIGHSCORE_FONT_FILE = "fonts/Marker Felt.ttf";

struct HighscorePimpl
{
    cocos2d::TTFConfig* highscoreTtfConfig;

    int score;
};

// ---------------------------------------------------------------------------------------------------------------------

Highscore::Highscore() : highscorePimpl(new HighscorePimpl())
{}

Highscore::~Highscore()
{
    delete this->highscorePimpl;
}

bool
Highscore::init()
{
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(650, 550);
    this->highscorePimpl->highscoreTtfConfig = new TTFConfig(HIGHSCORE_FONT_FILE.c_str(), 24, GlyphCollection::DYNAMIC);
    this->setTTFConfig(*this->highscorePimpl->highscoreTtfConfig);

    this->highscorePimpl->score = 0;

    this->scheduleUpdate();

    return true;
}

void
Highscore::AddScoreForOneItem()
{
    this->highscorePimpl->score += 10;
}

void
Highscore::update(float deltaTime)
{
    this->setString("points: " + std::to_string(this->highscorePimpl->score));
}
