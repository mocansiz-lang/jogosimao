#include "Inim_Facil.h"

Inim_Facil::Inim_Facil() :
    Inimigo(1, 1), // 1 de vida, 1 de nivel_maldade
    raio(100.f),
    velX(-2.0f)
{
    Retangulo.setSize(sf::Vector2f(50.f, 50.f));
    Retangulo.setFillColor(sf::Color::Red);
    Retangulo.setPosition(900.f, 670.f);
    x = 900;
    y = 670;
    pFig = &Retangulo;
}

Inim_Facil::~Inim_Facil()
{
}

void Inim_Facil::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();
    pos.x += velX * nivel_maldade;

    if (pos.x < 700.f || pos.x > 950.f)
        velX = -velX;

    Retangulo.setPosition(pos);
}

void Inim_Facil::executar()
{
    if (estaVivo())
        mover();
}

void Inim_Facil::salvar()
{
}
