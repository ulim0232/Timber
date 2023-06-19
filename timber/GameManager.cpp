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
    font.loadFromFile("fonts/KOMIKAP_.ttf");  //"~"��ο��� ��Ʈ ���� ��������
    text.setFont(font);

    text.setString(string); //���ڿ� ����
    text.setCharacterSize(size); //ũ�� ����
    text.setFillColor(color); //�ؽ�Ʈ�� ����
    Utils::SetOrigin(text, origin);
    text.setPosition(x, y); //��ġ ����
}

void GameManager::SetTimer(const float duration, const Origins origin, const float x, const float y, const sf::Color color)
{
    this->duration = duration;
    timer = duration;

    uiTimer.setSize(sf::Vector2f(uiTimerWidth, uiTimerHeight)); //size ����
    Utils::SetOrigin(uiTimer, origin);
    uiTimer.setPosition(x, y);//50�ȼ� ���� �ø���
    uiTimer.setFillColor(color);
}

void GameManager::Init()
{
    gameObjects.push_back(new SpriteGo(texBackground, sf::Vector2f(1.f, 0.f), "BG", { 0, 0 }));

    for (int i = 0; i < 3; i++)//���� 3�� �׸���, ��� �� ���� �Ʒ�
    {
        /*----��������----*/
        cloud = new MovingBgObj(texCloud, sf::Vector2f(-1.f, 0.f), "Cloud");
        cloud->SetSpeedRange(sf::Vector2f(300.f, 600.f));
        cloud->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), //���� ��ġ ����
            sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));

        cloud->SetPosXRange(0, 0);
        cloud->SetPosYRange(-300, 300);

        gameObjects.push_back(cloud);
    }
    /*----���� ����----*/
    tree = new Tree(texTree, sf::Vector2f(1.f, 0.f), "Tree");
    tree->SetOrigin(Origins::TC);
    tree->SetPosition(sf::Vector2f(screenWidth * 0.5f, 0.f));
    gameObjects.push_back(tree);


    /*-----�÷��̾� ����-----*/
    player = new Player(texPlayer, sf::Vector2f(-1.f, -1.f), "Player", sf::Vector2f(0.f, 900.f));
    player->SetTree(tree);
    gameObjects.push_back(player);

    /*----�� ����----*/
    bee = new MovingBgObj(texBee, sf::Vector2f(-1.f, -1.f), "Bee");
    bee->SetSpeedRange(sf::Vector2f(100.f, 200.f));
    bee->SetLRPos(sf::Vector2f(-200.f, 1080.f / 2.f), //���� ��ġ ����
        sf::Vector2f(1920.f + 200.f, 1080.f / 2.f));
    bee->SetPosXRange(0, 0);
    bee->SetPosYRange(0, 300);
    bee->SetMoveY(5.f, 50.f);
    gameObjects.push_back(bee);

    /*-----�ʱ�ȭ-----*/
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

