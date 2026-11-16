#include "Jogo.h"

Jogo::Jogo() :GG(), jogador(), inimigo(),GC(&jogador, &inimigo),menu(this), menua(true)
{
    Ente::setGG(&GG);
}
Jogo::~Jogo()
{
}
void Jogo::iniciar()
{
    menua = false;
}

void Jogo::menub()
{

    menua = true;

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
            sf::Event event;

            while (GG.getWindow()->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    GG.getWindow()->close();
            }

            jogador.executar();
            GC.executar();

            GG.getWindow()->clear(sf::Color::Black);

            jogador.desenhar();
            inimigo.desenhar();

            GG.getWindow()->display();
        }
    }
}
