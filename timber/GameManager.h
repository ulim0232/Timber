#pragma once
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include "MovingBgObj.h"
#include "InputMgr.h"
#include "Branch.h"
#include "Tree.h"
#include "Player.h"

class GameManager
{
protected:
    bool isPause = true; //일시정지
    int score = 0;

    int screenWidth = 1920;
    int screenHeight = 1080;

    sf::Font font;
    //sf::Text textMassage; //출력 메세지
    //sf::Text textScore; //점수 출력 메세지

    float uiTimerWidth = 400.f;
    float uiTimerHeight = 80.f;

    float duration;// = 3.f; //제한시간 3초
    float timer; //dt를 빼가면서 측정

    sf::Texture texBackground;
    sf::Texture texTree;
    sf::Texture texCloud;
    sf::Texture texBee;
    sf::Texture texBranch;
    sf::Texture texPlayer;

    sf::RectangleShape uiTimer;
    std::vector<GameObject*> gameObjects;

    Tree* tree;
    Player* player;
    MovingBgObj* bee;
    MovingBgObj* cloud;

public:
    //GameManager();
    ~GameManager();
    void SetTexture();
    void SetText(const sf::Text text, const sf::String &string, const int size, const sf::Color color, Origins origin, float x, float y);
    void SetTimer(const float duration, const Origins origin, const float x, const float y, const sf::Color color);
    void Init();
    void Update(float dt);
    void Draw();
    void Release();
};

