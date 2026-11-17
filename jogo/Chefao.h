#pragma once
#include "Inimigo.h"

class Chefao : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    short int forca;
    float velX;

public:
    Chefao();
    ~Chefao();

    sf::FloatRect getLados()
    {
        return Retangulo.getGlobalBounds();
    }

    sf::RectangleShape& getRetangulo() { return Retangulo; }
    short int getForca() const { return forca; }

    void danificar(Jogador* pJog);
    void mover();
    void executar();
    void salvar();
};