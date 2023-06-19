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
    bool isPause = true; //�Ͻ�����
    int score = 0;

    int screenWidth = 1920;
    int screenHeight = 1080;

    sf::Font font;
    //sf::Text textMassage; //��� �޼���
    //sf::Text textScore; //���� ��� �޼���

    float uiTimerWidth = 400.f;
    float uiTimerHeight = 80.f;

    float duration;// = 3.f; //���ѽð� 3��
    float timer; //dt�� �����鼭 ����

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

