#include "Menu.h"
#include "Jogo.h"

Menu::Menu(Jogo* pJ) : pJog(pJ)
{
    if (!fonte.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cout << "Erro ao carregar fonte" << std::endl;
    }

    fundo.setSize(sf::Vector2f(W_LARGURA, W_ALTURA));
    fundo.setFillColor(sf::Color(25, 25, 45));

    titulo.setFont(fonte);
    titulo.setString("Jogo do Simao");
    titulo.setCharacterSize(40);
    titulo.setPosition(330, 180);

    jogar.setFont(fonte);
    jogar.setString("Jogar");
    jogar.setCharacterSize(25);
    jogar.setPosition(420, 350);

    sair.setFont(fonte);
    sair.setString("Sair");
    sair.setCharacterSize(25);
    sair.setPosition(450, 430);
}

Menu::~Menu()
{
}

void Menu::executar()
{
    sf::RenderWindow* window = pGG->getWindow();

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

            if (jogar.getGlobalBounds().contains(mouse))
                pJog->iniciar();

            if (sair.getGlobalBounds().contains(mouse))
                window->close();
        }
    }

    window->clear();
    window->draw(fundo);
    window->draw(titulo);
    window->draw(jogar);
    window->draw(sair);
    window->display();
}