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
	const std::string Texto::getinfo() const
	{
		return info;
	}

	void Texto::setinfo(const std::string i)
	{
		info = i;
		inicializa();
	}
	void Texto::setPos(const sf::Vector2f pos)
	{
		texto.setPosition(pos);
	}

	void Texto::operator+(char l)
	{
		info = info + l;
		inicializa();
	}

	void Texto::pop()
	{
		if (!info.empty()) {
			info.pop_back();
		}
	}

	sf::Vector2f Texto::getTam()
	{
		return tam;
	}
}