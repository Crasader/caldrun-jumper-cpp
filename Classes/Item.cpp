#include "Item.h"

USING_NS_CC;

// ---------------------------------------------------------------------------------------------------------------------

static const int DIFFERENT_ITEM_SIZE = 37;
static const float ITEM_MIN_DISTANCE = 70;

struct ItemPimpl
{
    float lastItemPosition;
};

float
getRandAwayFromX(float const min, float const max, float const lastItemPositionX)
{
    float newRand;

    while (true) {
        newRand = random(min, max);
        if (
            (newRand < lastItemPositionX && newRand < lastItemPositionX - ITEM_MIN_DISTANCE) ||
            (newRand > lastItemPositionX && newRand > lastItemPositionX + ITEM_MIN_DISTANCE)
        ) {
            return newRand;
        }
    }
}


// ---------------------------------------------------------------------------------------------------------------------

Item::Item() : itemPimpl(new ItemPimpl())
{}

Item::~Item()
{
    delete this->itemPimpl;
}

bool
Item::init()
{
    this->setAnchorPoint(Vec2(0, 0));
    this->setPosition(0, 0);

    this->itemPimpl->lastItemPosition = 40;

    return true;
}

void
Item::showANewItem()
{
    int itemNr = random(1, DIFFERENT_ITEM_SIZE);
    this->itemPimpl->lastItemPosition = getRandAwayFromX(40, 760, this->itemPimpl->lastItemPosition);
    this->setPosition(this->itemPimpl->lastItemPosition, random(300, 400));
    this->initWithFile("items/" + std::to_string(itemNr) + ".png");
}