#include "gui.hpp"
#include <Geode/Bindings.hpp>

#ifdef GEODE_IS_MOBILE
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

static CCMenu* makeZBotButton(CCObject* target, SEL_MenuHandler cb) {
    auto spr = ButtonSprite::create("zBot", 40, true, "bigFont.fnt", "GJ_button_01.png", 30.f, .6f);
    auto btn = CCMenuItemSpriteExtra::create(spr, target, cb);
    auto menu = CCMenu::create();
    menu->addChild(btn);
    auto win = CCDirector::get()->getWinSize();
    menu->setPosition({ 40.f, win.height - 25.f });
    return menu;
}

class $modify(zPauseLayer, PauseLayer) {
    void customSetup() {
        PauseLayer::customSetup();
        this->addChild(makeZBotButton(this, menu_selector(zPauseLayer::onZBot)));
    }

    void onZBot(CCObject*) {
        GUI::get()->visible = !GUI::get()->visible;
    }
};

class $modify(zMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;
        this->addChild(makeZBotButton(this, menu_selector(zMenuLayer::onZBot)));
        return true;
    }

    void onZBot(CCObject*) {
        GUI::get()->visible = !GUI::get()->visible;
    }
};
#endif
