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
    audio->preloadEffect("sfx/sound4.wav");
    audio->preloadEffect("sfx/sound5.wav");
    audio->playBackgroundMusic("sfx/BEAD.mp3");

    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    auto startGameButton = Label::createWithTTF("Start the game", "fonts/Marker Felt.ttf", 24);
    startGameButton->setPosition(
        Vec2(
            visibleSize.width/2,
            visibleSize.height/2 - startGameButton->getContentSize().height
        )
    );
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
        auto scene = Game::createScene();
        Director::getInstance()->pushScene(scene);
        return true;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
        touchListener,
        startGameButton
    );
    this->addChild(startGameButton, 1);

    return true;
}
