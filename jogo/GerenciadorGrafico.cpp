#include "GerenciadorGrafico.h"
#include "Ente.h"


GerenciadorGrafico::GerenciadorGrafico() :
#if SFML_VERSION_MAJOR >= 3
    window(new sf::RenderWindow(sf::VideoMode(sf::Vector2u(W_LARGURA, W_ALTURA)), NOME_JOGO))
#else
    window(new sf::RenderWindow(sf::VideoMode(W_LARGURA, W_ALTURA), NOME_JOGO))
#endif
{
    if (!window)
    {
        std::cout << "Erro ao criar janela" << std::endl;
        exit(1);
    }
    window->setFramerateLimit(MAX_FPS);
}
GerenciadorGrafico::~GerenciadorGrafico()
{
    if (window)
    {
        delete window;
        window = nullptr;
    }
}
void GerenciadorGrafico::desenharEnte(Ente* pE)
{
    if (pE == nullptr || pE->getFigura() == nullptr)
    {
        return;
    }

    window->draw(*pE->getFigura());
}
