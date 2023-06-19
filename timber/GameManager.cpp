#include "GameManager.h"

void GameManager::SetTexture()
{
    texBackground.loadFromFile("graphics/background.png");
    texTree.loadFromFile("graphics/tree.png");
    texCloud.loadFromFile("graphics/cloud.png");
    texBee.loadFromFile("graphics/bee.png");
    texBranch.loadFromFile("graphics/branch.png");
    texPlayer.loadFromFile("graphics/player.png");
}

void GameManager::SetText(sf::Text text, const sf::String& string, const int size, const sf::Color color, Origins origin, float x, float y)
{
    font.loadFromFile("fonts/KOMIKAP_.ttf");  //"~"경로에서 폰트 파일 가져오기
    text.setFont(font);

    text.setString(string); //문자열 지정
    text.setCharacterSize(size); //크기 지정
    text.setFillColor(color); //텍스트의 색상
    Utils::SetOrigin(text, origin);
    text.setPosition(x, y); //위치 지정
}

void GameManager::SetTimer(const float duration, const Origins origin, const float x, const float y, const sf::Color color)
{
    this->duration = duration;
    timer = duration;

    uiTimer.setSize(sf::Vector2f(uiTimerWidth, uiTimerHeight)); //size 설정
    Utils::SetOrigin(uiTimer, origin);
    uiTimer.setPosition(x, y);//50픽셀 위로 올리기
    uiTimer.setFillColor(color);
}

void GameManager::Init()
{
    gameObjects.push_back(new SpriteGo(texBackground, sf::Vector2f(1.f, 0.f), "BG", { 0, 0 }));

    for (int i = 0; i < 3; i++)//구름 3개 그리기, 배경 위 나무 아래
    {
        /*----구름생성----*/
        cloud = new MovingBgObj(texCloud, sf::Vector2f(-1.f, 0.f), "Cloud");
        cloud->SetSpeedRange(sf::Vector2f(300.f, 600.f));
        cloud->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), //시작 위치 고정
            sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));

        cloud->SetPosXRange(0, 0);
        cloud->SetPosYRange(-300, 300);

        gameObjects.push_back(cloud);
    }
    /*----나무 생성----*/
    tree = new Tree(texTree, sf::Vector2f(1.f, 0.f), "Tree");
    tree->SetOrigin(Origins::TC);
    tree->SetPosition(sf::Vector2f(screenWidth * 0.5f, 0.f));
    gameObjects.push_back(tree);


    /*-----플레이어 생성-----*/
    player = new Player(texPlayer, sf::Vector2f(-1.f, -1.f), "Player", sf::Vector2f(0.f, 900.f));
    player->SetTree(tree);
    gameObjects.push_back(player);

    /*----벌 생성----*/
    bee = new MovingBgObj(texBee, sf::Vector2f(-1.f, -1.f), "Bee");
    bee->SetSpeedRange(sf::Vector2f(100.f, 200.f));
    bee->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), //시작 위치 고정
        sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));
    bee->SetPosXRange(0, 0);
    bee->SetPosYRange(0, 300);
    bee->SetMoveY(5.f, 50.f);
    gameObjects.push_back(bee);

    /*-----초기화-----*/
    for (auto obj : gameObjects)
    {
        obj->Init();
    }
}

void GameManager::Update(float dt)
{
}

void GameManager::Draw()
{
}

void GameManager::Release()
{
}

