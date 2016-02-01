#include "Item.h"

USING_NS_CC;

// ---------------------------------------------------------------------------------------------------------------------

float
getRandAwayFromX(float const min, float const max, float const lastItemPositionX, float const itemMinDistance)
{
    float newRand;

    while (true) {
        newRand = random(min, max);
        if (
            (newRand < lastItemPositionX && newRand < lastItemPositionX - itemMinDistance) ||
            (newRand > lastItemPositionX && newRand > lastItemPositionX + itemMinDistance)
        ) {
            return newRand;
        }
    }
}

// ---------------------------------------------------------------------------------------------------------------------

Item::Item()
{}

Item::~Item()
{
}

bool
Item::init()
{
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(0, 0);

    this->lastItemPosition = 40;

//    this->scheduleUpdate();

    return true;
}

void
Item::showANewItem()
{
    int itemNr = random(1, Item::DIFFERENT_ITEM_SIZE);
    this->lastItemPosition = getRandAwayFromX(40, 760, this->lastItemPosition, Item::itemMinDistance);
    this->setPosition(this->lastItemPosition, random(300, 400));
    this->initWithFile("items/" + std::to_string(itemNr) + ".png");
}

void
Item::update(float deltaTime)
{

}
