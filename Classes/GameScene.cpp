#include <audio/include/SimpleAudioEngine.h>
#include "GameScene.h"
#include "Neko.h"
#include "Item.h"
#include "Highscore.h"
#include "Timer.h"
#include "HelloWorldScene.h"

USING_NS_CC;

Game::~Game()
{
}

Scene*
Game::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0,0));

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

    this->timer = GameTimer::create();
    this->addChild(this->timer);

    this->highscore = Highscore::create();
    this->addChild(this->highscore);

    auto eventListener = EventListenerKeyboard::create();
    eventListener->onKeyPressed = [&](EventKeyboard::KeyCode keyCode, Event* event){
        auto neko = static_cast<Neko *>(event->getCurrentTarget());

        if (nullptr != neko) {

            switch (keyCode) {
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
                    audio = CocosDenshion::SimpleAudioEngine::getInstance();
                    audio->playEffect("sfx/sound5.wav");
                    neko->Jump();
                    break;

                case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
                case EventKeyboard::KeyCode::KEY_S:
                    neko->Idle();
                    break;

                default:
                    break;
            }
        }
    };

    this->item = Item::create();
    this->item->showANewItem();
    this->addChild(this->item);

    this->neko = Neko::create();
    this->addChild(this->neko);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, this->neko);

    this->scheduleUpdate();

    return true;
}

void
Game::update(float deltaTime) {
    if (0 == this->timer->GetCurrentTime()) {
        if (this->getChildByName("nekoSprite")) {
            this->removeChildByName("nekoSprite");

            auto goBackToStart = Label::createWithTTF("back to start", "fonts/Marker Felt.ttf", 24);
            goBackToStart->setPosition(
                    Vec2(
                            400,
                            300 - goBackToStart->getContentSize().height
                    )
            );
            auto touchListener = EventListenerTouchOneByOne::create();
            touchListener->onTouchBegan = [](Touch* touch, Event* event) -> bool {
                auto scene = HelloWorld::createScene();
                Director::getInstance()->pushScene(scene);
                return true;
            };
            Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(
                    touchListener,
                    goBackToStart
            );
            this->addChild(goBackToStart, 1);
        }

    } else {

        auto nekoRect = this->neko->getBoundingBox();
        auto itemRect = this->item->getBoundingBox();

        if (nekoRect.intersectsRect(itemRect)) {
            auto audio = CocosDenshion::SimpleAudioEngine::getInstance();
            audio->playEffect("sfx/sound4.wav");

            this->highscore->AddScoreForOneItem();
            this->item->showANewItem();
        }
    }
}