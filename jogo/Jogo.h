#pragma once
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Claude_Easy.h"
#include "Gemini_Medium.h"
#include "Copilot_Hard.h"
#include "Fable_Boss.h"
#include "Gerenciador_Colisoes.h"
#include "Menu.h"
#include <string>

class Jogo
{
private:
    GerenciadorGrafico GG;
    Jogador jogador;
    Claude_Easy claude;
    Gemini_Medium gemini;
    Copilot_Hard copilot;
    Fable_Boss fable;
    Gerenciador_Colisoes GC;
    Menu menu;
    bool menua;
    sf::Font fonte;
    bool fonteCarregada;

    void desenharVida(Personagem* p);

public:
    Jogo();
    ~Jogo();
    void executar();
    void iniciar();
    void menub();
};
