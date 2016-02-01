#include "Highscore.h"

USING_NS_CC;

Highscore::Highscore()
{}

Highscore::~Highscore()
{
}

bool
Highscore::init()
{
//    this->createWithTTF("points: 0", "fonts/Marker Felt.ttf", 24);

    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(650, 550);
//    this->setLineHeight(24);
//    this->setSystemFontSize(24);
    this->highscoreTtfConfig = new TTFConfig(Highscore::FONT_FILE.c_str(), 24, GlyphCollection::DYNAMIC);
    this->setTTFConfig(*this->highscoreTtfConfig);

    this->score = 0;

    this->scheduleUpdate();

    return true;
}

void
Highscore::AddScoreForOneItem()
{
    this->score += 10;
}

void
Highscore::update(float deltaTime)
{
    this->setString("points: " + std::to_string(this->score));
}
