#include "..\Menus\Botao.h"

namespace Menus
{
	Gerenciadores::Grafico* Botao::Pgrafico = Gerenciadores::Grafico::getgrafico();

	Botao::Botao(const std::string info, const sf::Vector2f tam, sf::Vector2f pos):
		texto(Pgrafico->carregarFonte("Arquivos/Fonte.ttf"),info),
		tam(tam), pos(pos), selecionado(false), corselecionado(sf::Color::Red)
	{
		caixa.setPosition(pos);
		caixa.setSize(tam);
		sf::Vector2f tamTexto = this->texto.getTam();
		sf::Vector2f posTexto = sf::Vector2f((pos.x+tam.x/2.0f)-(tamTexto.x/2.05f),(pos.y+tam.y/2.0f)-(tamTexto.y*1.2f));
		this->texto.setPos(posTexto);
		caixa.setFillColor(sf::Color::White);
	}

	Botao::~Botao()
	{
	}

	void Botao::seleciona(const bool select)
	{
		if (select) {
			caixa.setFillColor(corselecionado);
		}
		else {
			caixa.setFillColor(sf::Color::White);
		}
		this->selecionado = select;
	}

	const bool Botao::getselecionado() const
	{
		return selecionado;
	}

	void Botao::atualizapos(sf::Vector2f pos)
	{
		this->pos = pos;
		caixa.setPosition(pos);
		sf::Vector2f tamTexto = this->texto.getTam();
		sf::Vector2f posTexto = sf::Vector2f((pos.x + tam.x / 2.0f) - (tamTexto.x / 2.05f), (pos.y + tam.y / 2.0f) - (tamTexto.y * 1.2f));
		this->texto.setPos(posTexto);
	}

	const sf::Vector2f Botao::getpos() const {
		return caixa.getPosition();
	}

	const sf::Text Botao::gettexto() const
	{
		return texto.getTexto();
	}

	const std::string Botao::getinfo() const
	{
		return texto.getinfo();
	}

	void Botao::desenha()
	{
		Pgrafico->desenha(caixa);
		Pgrafico->desenha(texto.getTexto());
	}
}