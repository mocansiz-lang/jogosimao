#include "Menu.h"
#include "Jogo.h"
#if SFML_VERSION_MAJOR >= 3
#include <optional>
#endif

Menu::Menu(Jogo* pJ) : pJog(pJ)
#if SFML_VERSION_MAJOR >= 3
    , titulo(fonte), jogar(fonte), sair(fonte)
#endif
{
#if SFML_VERSION_MAJOR >= 3
    if (!fonte.openFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        if (!fonte.openFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
        {
            std::cout << "Erro ao carregar fonte" << std::endl;
        }
    }
#else
    if (!fonte.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        if (!fonte.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"))
        {
            std::cout << "Erro ao carregar fonte" << std::endl;
        }
    }
    titulo.setFont(fonte);
    jogar.setFont(fonte);
    sair.setFont(fonte);
#endif

    fundo.setSize(sf::Vector2f(W_LARGURA, W_ALTURA));
    fundo.setFillColor(sf::Color(25, 25, 45));

    titulo.setString("Jogo do Simao");
    titulo.setCharacterSize(40);
    titulo.setPosition(sf::Vector2f(330.f, 180.f));

    jogar.setString("Jogar");
    jogar.setCharacterSize(25);
    jogar.setPosition(sf::Vector2f(420.f, 350.f));

    sair.setString("Sair");
    sair.setCharacterSize(25);
    sair.setPosition(sf::Vector2f(450.f, 430.f));
}

Menu::~Menu()
{
}

void Menu::executar()
{
    sf::RenderWindow* window = pGG->getWindow();

#if SFML_VERSION_MAJOR >= 3
    while (const std::optional<sf::Event> event = window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window->close();

        if (event->getIf<sf::Event::MouseButtonPressed>())
        {
            sf::Vector2f mouse = window->mapPixelToCoords(
                sf::Mouse::getPosition(*window)
            );

            if (jogar.getGlobalBounds().contains(mouse))
                pJog->iniciar();

            if (sair.getGlobalBounds().contains(mouse))
                window->close();
        }
    }
#else
    sf::Event event;

    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();

        if (event.type == sf::Event::MouseButtonPressed)
        {
            sf::Vector2f mouse = window->mapPixelToCoords(
                sf::Mouse::getPosition(*window)
            );

            if (jogar.getGlobalBounds().contains(mouse.x, mouse.y))
                pJog->iniciar();

            if (sair.getGlobalBounds().contains(mouse.x, mouse.y))
                window->close();
        }
    }
#endif

    window->clear();
    window->draw(fundo);
    window->draw(titulo);
    window->draw(jogar);
    window->draw(sair);
    window->display();
}
