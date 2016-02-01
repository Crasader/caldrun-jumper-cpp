#include <audio/include/SimpleAudioEngine.h>
#include "HelloWorldScene.h"

USING_NS_CC;

Scene*
HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool
HelloWorld::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->preloadBackgroundMusic("sfx/An_Adventure_Awaits.mp3");
    audio->playBackgroundMusic("sfx/An_Adventure_Awaits.mp3");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto backgroundSprite = Sprite::create("background.jpg");
    backgroundSprite->setAnchorPoint(Vec2(0, 0));
    backgroundSprite->setPosition(0, 0);
    this->addChild(backgroundSprite, 0);

    auto closeItem = MenuItemImage::create(
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(HelloWorld::menuCloseCallback, this)
    );
    
	closeItem->setPosition(
        Vec2(
            origin.x + visibleSize.width - closeItem->getContentSize().width/2,
            origin.y + closeItem->getContentSize().height/2
        )
    );

    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    auto label = Label::createWithTTF("Start the game", "fonts/Marker Felt.ttf", 24);
    label->setPosition(
        Vec2(
            visibleSize.width/2,
            visibleSize.height/2 - label->getContentSize().height
        )
    );
    this->addChild(label, 1);

    auto timeOutput = Label::createWithTTF("time: 90", "fonts/Marker Felt.ttf", 24);
    timeOutput->setAnchorPoint(Vec2(0, 0));
    timeOutput->setPosition(50, 550);
    this->addChild(timeOutput);

    auto pointsOutput = Label::createWithTTF("points: 0", "fonts/Marker Felt.ttf", 24);
    pointsOutput->setAnchorPoint(Vec2(0, 0));
    pointsOutput->setPosition(650, 550);
    this->addChild(pointsOutput);
    
    return true;
}

void
HelloWorld::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
