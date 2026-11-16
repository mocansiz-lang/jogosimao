#pragma once
#include "Ente.h"

class Jogo;

class Menu : public Ente
{
private:
    Jogo* pJog;

    sf::Font fonte;
    sf::Text titulo;
    sf::Text jogar;
    sf::Text sair;

    sf::RectangleShape fundo;

public:
    Menu(Jogo* pJ);
    ~Menu();

    void executar();
};