#pragma once

#include "cocos2d.h"

class Item : public cocos2d::Sprite
{
public:
    ~Item();

    virtual bool init();
    CREATE_FUNC(Item);

    void showANewItem();

protected:
    Item();

private:
    struct ItemPimpl;
    ItemPimpl* itemPimpl;
};