#pragma once
#include "Entidade.h"
#include <string>

class Personagem :
    public Entidade
{
protected:
    int num_vidas;
    int max_vidas;
    std::string nome;

public:
    Personagem(int vidas = 1, const std::string& nomePers = "Personagem");
    virtual ~Personagem();

    int getNumVidas() const;
    int getMaxVidas() const;
    void setNumVidas(int v);
    const std::string& getNome() const;
    void setNome(const std::string& n);
    virtual void tomarDano(int dano);
    bool estaVivo() const;

    virtual void mover() = 0;
};
