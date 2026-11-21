#include "Jogo.h"
#include <algorithm>
#if SFML_VERSION_MAJOR >= 3
#include <optional>
#endif

Jogo::Jogo() :
    GG(),
    jogador(),
    claude(),
    gemini(),
    copilot(),
    fable(),
    GC(&jogador),
    menu(this),
    menua(true),
    fonteCarregada(false)
{
    Ente::setGG(&GG);
    GC.incluirInimigo(&claude);
    GC.incluirInimigo(&gemini);
    GC.incluirInimigo(&copilot);
    GC.incluirInimigo(&fable);

#if SFML_VERSION_MAJOR >= 3
    fonteCarregada = fonte.openFromFile("C:/Windows/Fonts/arial.ttf") ||
                     fonte.openFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
#else
    fonteCarregada = fonte.loadFromFile("C:/Windows/Fonts/arial.ttf") ||
                     fonte.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
#endif
}

Jogo::~Jogo()
{
}

void Jogo::iniciar()
{
    jogador.setNumVidas(10);
    jogador.setPoint(375.f, 620.f);
    menua = false;
}

void Jogo::menub()
{
    menua = true;
}

void Jogo::desenharVida(Personagem* p)
{
    if (p == nullptr || !p->estaVivo())
    {
        return;
    }

    sf::RenderWindow* window = GG.getWindow();
    sf::FloatRect bounds = p->getLados();

#if SFML_VERSION_MAJOR >= 3
    float left = bounds.position.x;
    float top = bounds.position.y;
    float width = bounds.size.x;
#else
    float left = bounds.left;
    float top = bounds.top;
    float width = bounds.width;
#endif

    float barWidth = std::max(50.f, width);
    float barHeight = 6.f;
    float barX = left + (width - barWidth) * 0.5f;
    float barY = std::max(20.f, top - 10.f);

    float maxV = static_cast<float>(std::max(1, p->getMaxVidas()));
    float ratio = std::max(0.f, std::min(1.f, static_cast<float>(p->getNumVidas()) / maxV));

    sf::RectangleShape fundoBarra(sf::Vector2f(barWidth, barHeight));
    fundoBarra.setPosition(sf::Vector2f(barX, barY));
    fundoBarra.setFillColor(sf::Color(60, 60, 60));

    sf::RectangleShape barraVida(sf::Vector2f(barWidth * ratio, barHeight));
    barraVida.setPosition(sf::Vector2f(barX, barY));
    barraVida.setFillColor(p == &jogador ? sf::Color::Green : sf::Color::Red);

    window->draw(fundoBarra);
    window->draw(barraVida);

    if (fonteCarregada)
    {
#if SFML_VERSION_MAJOR >= 3
        sf::Text textoVida(fonte);
#else
        sf::Text textoVida;
        textoVida.setFont(fonte);
#endif
        textoVida.setString(p->getNome() + ": " + std::to_string(p->getNumVidas()));
        textoVida.setCharacterSize(13);
        textoVida.setFillColor(sf::Color::White);
        textoVida.setPosition(sf::Vector2f(barX, std::max(2.f, barY - 17.f)));
        window->draw(textoVida);
    }
}

void Jogo::executar()
{
    while (GG.getWindow()->isOpen())
    {
        if (menua)
        {
            menu.executar();
        }
        else
        {
#if SFML_VERSION_MAJOR >= 3
            while (const std::optional<sf::Event> event = GG.getWindow()->pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    GG.getWindow()->close();
            }
#else
            sf::Event event;

            while (GG.getWindow()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    GG.getWindow()->close();
            }
#endif

            jogador.executar();
            if (claude.estaVivo()) claude.executar();
            if (gemini.estaVivo()) gemini.executar();
            if (copilot.estaVivo()) copilot.executar();
            if (fable.estaVivo()) fable.executar();

            GC.executar();

            if (!jogador.estaVivo())
            {
                menub();
                continue;
            }

            GG.getWindow()->clear(sf::Color::Black);

            jogador.desenhar();
            if (claude.estaVivo()) claude.desenhar();
            if (gemini.estaVivo()) gemini.desenhar();
            if (copilot.estaVivo()) copilot.desenhar();
            if (fable.estaVivo()) fable.desenhar();

            desenharVida(&jogador);
            desenharVida(&claude);
            desenharVida(&gemini);
            desenharVida(&copilot);
            desenharVida(&fable);

            if (fonteCarregada)
            {
#if SFML_VERSION_MAJOR >= 3
                sf::Text hudVida(fonte);
#else
                sf::Text hudVida;
                hudVida.setFont(fonte);
#endif
                hudVida.setString("Vida Jogador: " + std::to_string(jogador.getNumVidas()) +
                                  "/" + std::to_string(jogador.getMaxVidas()));
                hudVida.setCharacterSize(18);
                hudVida.setFillColor(sf::Color::White);
                hudVida.setPosition(sf::Vector2f(12.f, 10.f));
                GG.getWindow()->draw(hudVida);
            }

            GG.getWindow()->display();
        }
    }
}
