#include "Grama.h"
#include "Jogador.h"

Grama::Grama()
{
	Chao.setSize(sf::Vector2f(300.f, 50.f));
	Chao.setFillColor(sf::Color::Green);
	Chao.setPosition(500.f, 200.f);
	pFig = &Chao;
	danoso = false;
}

Grama::~Grama()
{
}

void Grama::executar()
{
}
void Grama::salvar()
{
}

void Grama::obstaculizar(Jogador* p)
{
	sf::FloatRect LadosP = p->getLados();
	sf::FloatRect LadosO = getLados();
	
	sf::Vector2f pos = p->getCirculo().getPosition();
	pos.y = LadosO.top - LadosP.height;
	p->getCirculo().setPosition(pos);

}
