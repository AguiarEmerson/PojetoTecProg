#include "..\Menus\Texto.h"

namespace Menus
{
	Texto::Texto(const sf::Font fonte, const std::string info, const unsigned int tamFonte) :
		texto(), fonte(fonte), info(info), cortexto(sf::Color::White),corborda(sf::Color::Black),tamFonte(tamFonte)
	{
		inicializa();
	}

	Texto::~Texto()
	{
	}

	void Texto::inicializa()
	{
		texto.setString(info);
		texto.setCharacterSize(tamFonte);
		texto.setFont(fonte);
		texto.setOutlineThickness(5);
		texto.setOutlineColor(corborda);
		texto.setFillColor(cortexto);
		tam = sf::Vector2f(texto.getGlobalBounds().width, texto.getGlobalBounds().height);
	}
	const sf::Text Texto::getTexto() const
	{
		return texto;
	}
	void Texto::setPos(const sf::Vector2f pos)
	{
		texto.setPosition(pos);
	}
	sf::Vector2f Texto::getTam()
	{
		return tam;
	}
}