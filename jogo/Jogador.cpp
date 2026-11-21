#include "Jogador.h"
#include "Inim_Facil.h"

Jogador::Jogador() : Personagem(10, "Jogador"), cooldownDano(0)
{
    circulo.setRadius(50.f);
    circulo.setFillColor(sf::Color::Green);
    setPoint(375.f, 620.f);
    pFig = &circulo;
}

void Jogador::setPoint(float px, float py)
{
    Entidade::setPoint(px, py);
    circulo.setPosition(sf::Vector2f(px, py));
}

void Jogador::tomarDano(int dano)
{
    if (cooldownDano <= 0)
    {
        Personagem::tomarDano(dano);
        cooldownDano = 30;
    }
}

void Jogador::mover()
{
#if SFML_VERSION_MAJOR >= 3
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        circulo.move(sf::Vector2f(2.0f, 0.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        circulo.move(sf::Vector2f(-2.0f, 0.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        circulo.move(sf::Vector2f(0.f, -2.0f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        circulo.move(sf::Vector2f(0.f, 2.0f));
    }
#else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        circulo.move(sf::Vector2f(2.0f, 0.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        circulo.move(sf::Vector2f(-2.0f, 0.f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        circulo.move(sf::Vector2f(0.f, -2.0f));
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        circulo.move(sf::Vector2f(0.f, 2.0f));
    }
#endif

    sf::Vector2f pos = circulo.getPosition();
    Entidade::setPoint(pos.x, pos.y);
}

void Jogador::executar()
{
    if (cooldownDano > 0)
    {
        cooldownDano--;
    }
    mover();
}

void Jogador::salvar()
{
}
