#include <audio/include/SimpleAudioEngine.h>
#include "HelloWorldScene.h"
#include "GameScene.h"
USING_NS_CC;

Scene*
HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);

    return scene;
}

bool
HelloWorld::init()
{
    if (!Layer::init())
    {
        return false;
    }

    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->preloadBackgroundMusic("sfx/An_Adventure_Awaits.mp3");
    audio->preloadBackgroundMusic("sfx/BEAD.mp3");
    audio->playBackgroundMusic("sfx/BEAD.mp3");
    audio->preloadEffect("sfx/sound4.ogg");
    audio->preloadEffect("sfx/sound5.ogg");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

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
    
    this->startGameButton = Label::createWithTTF("Start the game", "fonts/Marker Felt.ttf", 24);
    this->startGameButton->setPosition(
        Vec2(
            visibleSize.width/2,
            visibleSize.height/2 - this->startGameButton->getContentSize().height
        )
    );
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
        auto scene = Game::createScene();
        Director::getInstance()->pushScene(scene);
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,this->startGameButton);

    this->addChild(this->startGameButton, 1);

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
