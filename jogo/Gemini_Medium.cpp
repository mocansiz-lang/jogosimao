#include "Gemini_Medium.h"
#include "GerenciadorGrafico.h"

Gemini_Medium::Gemini_Medium() : Inimigo(3, 2, "gemini(medium)"), velX(1.5f)
{
    Retangulo.setSize(sf::Vector2f(60.f, 60.f));
    Retangulo.setFillColor(sf::Color::Yellow);
    setPoint(550.f, 450.f);
    pFig = &Retangulo;
}

Gemini_Medium::~Gemini_Medium()
{
}

void Gemini_Medium::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    Retangulo.setPosition(sf::Vector2f(px, py));
}

void Gemini_Medium::mover()
{
    sf::Vector2f pos = Retangulo.getPosition();
    pos.x += velX;
    if (pos.x <= 0.f || pos.x + 60.f >= W_LARGURA)
    {
        velX = -velX;
        pos.x += velX;
    }
    setPoint(pos.x, pos.y);
}

void Gemini_Medium::executar()
{
    mover();
}

void Gemini_Medium::salvar()
{
}
