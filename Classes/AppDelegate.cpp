#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include <audio/include/SimpleAudioEngine.h>

USING_NS_CC;

static cocos2d::Size DISPLAY_SIZE = cocos2d::Size(800, 600);

AppDelegate::AppDelegate()
{
}

AppDelegate::~AppDelegate() 
{
}

void
AppDelegate::initGLContextAttrs()
{
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};
    GLView::setGLContextAttrs(glContextAttrs);
}

static int
register_all_packages()
{
    return 0;
}

bool
AppDelegate::applicationDidFinishLaunching()
{
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();

    if(!glview) {
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
        glview = GLViewImpl::createWithRect("CaldrunJumper2", Rect(0, 0, DISPLAY_SIZE.width, DISPLAY_SIZE.height));
#else
        glview = GLViewImpl::create("CaldrunJumper2");
#endif
        glview->setFrameSize(800, 600);
        director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);
    glview->setDesignResolutionSize(DISPLAY_SIZE.width, DISPLAY_SIZE.height, ResolutionPolicy::NO_BORDER);

    register_all_packages();

    auto scene = HelloWorld::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

void
AppDelegate::applicationDidEnterBackground()
{
    Director::getInstance()->stopAnimation();
    CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

void
AppDelegate::applicationWillEnterForeground()
{
    Director::getInstance()->startAnimation();
    CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
