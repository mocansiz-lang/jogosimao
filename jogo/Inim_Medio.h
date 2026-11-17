#pragma once
#include "Inimigo.h"

class Inim_Medio : public Inimigo
{
private:
    sf::RectangleShape Retangulo;
    int tamanho;
    float velX;
    float velY;
    bool noChao;

public:
    Inim_Medio();
    ~Inim_Medio();

    sf::FloatRect getLados()
    {
        return Retangulo.getGlobalBounds();
    }

    sf::RectangleShape& getRetangulo() { return Retangulo; }
    void mover();
    void executar();
    void salvar();
};