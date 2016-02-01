#pragma once

#include "cocos2d.h"

class Item : public cocos2d::Sprite
{
public:
    ~Item();

    virtual bool init();
    CREATE_FUNC(Item);

    void showANewItem();

    void update(float) override;

protected:
    Item();

private:
    const int DIFFERENT_ITEM_SIZE = 37;
    const float itemMinDistance = 70;

    float lastItemPosition;

};