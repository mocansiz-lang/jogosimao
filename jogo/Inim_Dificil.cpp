#include "Inim_Dificil.h"
#include "GerenciadorGrafico.h"

Inim_Dificil::Inim_Dificil() : Inimigo(5, 3, "copilot(dificil)"), velX(2.5f), velY(1.5f)
{
    Retangulo.setSize(sf::Vector2f(70.f, 70.f));
    Retangulo.setFillColor(sf::Color::Cyan);
    setPoint(250.f, 260.f);
    pFig = &Retangulo;
}

Inim_Dificil::~Inim_Dificil()
{
}

void Inim_Dificil::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Inim_Dificil::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();
    pos.x += velX;
    pos.y += velY;

    if (pos.x <= 0.f || pos.x + 70.f >= W_LARGURA)
    {
        velX = -velX;
        pos.x += velX;
    }
    if (pos.y <= 0.f || pos.y + 70.f >= W_ALTURA)
    {
        velY = -velY;
        pos.y += velY;
    }
    setPoint(pos.x, pos.y);
}

void Inim_Dificil::executar()
{
    mover();
}

void Inim_Dificil::salvar()
{
}
