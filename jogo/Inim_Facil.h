#pragma once
#include "Inimigo.h"

class Inim_Facil : public Inimigo
{
private:
    sf::RectangleShape Retangulo;

public:
    Inim_Facil();
    ~Inim_Facil();

    sf::FloatRect getLados()
    {
        return Retangulo.getGlobalBounds();
    }

    sf::RectangleShape& getRetangulo() { return Retangulo; }
    void setPoint(float px, float py);
    void mover();
    void executar();
    void salvar();
};
