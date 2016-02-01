#include <audio/include/SimpleAudioEngine.h>
#include "GameScene.h"
#include "Neko.h"

USING_NS_CC;

Game::~Game()
{
    if (nullptr != this->neko) {
        delete this->neko;
    }
}

Scene*
Game::createScene()
{
//    auto scene = Scene::create();
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0,0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    auto layer = Game::create();

    scene->addChild(layer);


    return scene;
}



bool
Game::init() {
    if (!Layer::init()) {
        return false;
    }

    auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
    audio->playBackgroundMusic("sfx/An_Adventure_Awaits.mp3");

    auto backgroundSprite = Sprite::create("background.jpg");
    backgroundSprite->setAnchorPoint(Vec2(0, 0));
    backgroundSprite->setPosition(0, 0);
    this->addChild(backgroundSprite, 0);

    auto timeOutput = Label::createWithTTF("time: 90", "fonts/Marker Felt.ttf", 24);
    timeOutput->setAnchorPoint(Vec2(0, 0));
    timeOutput->setPosition(50, 550);
    this->addChild(timeOutput);

    auto pointsOutput = Label::createWithTTF("points: 0", "fonts/Marker Felt.ttf", 24);
    pointsOutput->setAnchorPoint(Vec2(0, 0));
    pointsOutput->setPosition(650, 550);
    this->addChild(pointsOutput);


    auto moveNekoLeft = MoveBy::create(2, Vec2(-20, 0));
    moveNekoLeft->setTag(4);
    auto moveNekoUp = MoveBy::create(2, Vec2(0, 20));
    moveNekoUp->setTag(1);

    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [](EventKeyboard::KeyCode keyCode, Event* event){

        auto neko = static_cast<Neko *>(event->getCurrentTarget());

        switch(keyCode){
            case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
            case EventKeyboard::KeyCode::KEY_A:
                neko->MoveLeft();
                break;

            case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
            case EventKeyboard::KeyCode::KEY_D:
                neko->MoveRight();
                break;

            case EventKeyboard::KeyCode::KEY_UP_ARROW:
            case EventKeyboard::KeyCode::KEY_W:
            case EventKeyboard::KeyCode::KEY_SPACE:
                neko->Jump();
                break;

            case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
            case EventKeyboard::KeyCode::KEY_S:
                neko->Idle();
                break;

            default:
                break;
        }
    };

    auto nekoThing = Neko::create();
    this->addChild(nekoThing);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, nekoThing);

    return true;
}
