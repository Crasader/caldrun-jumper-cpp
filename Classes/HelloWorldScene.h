#pragma once

#include <memory>

#include "cocos2d.h"

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void menuCloseCallback(cocos2d::Ref* pSender);
//    void startGame(cocos2d::Ref* pSender);

    CREATE_FUNC(HelloWorld);

private:
    cocos2d::Label* startGameButton;
};

