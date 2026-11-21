#include "Inim_Facil.h"

Inim_Facil::Inim_Facil() : Inimigo(1, 1)
{
    Retangulo.setSize(sf::Vector2f(50.f, 50.f));
    Retangulo.setFillColor(sf::Color::Red);
    setPoint(900.f, 670.f);
    pFig = &Retangulo;
}

Inim_Facil::~Inim_Facil()
{
}

void Inim_Facil::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Inim_Facil::mover()
{
}

void Inim_Facil::executar()
{
    mover();
}

void Inim_Facil::salvar()
{
}
