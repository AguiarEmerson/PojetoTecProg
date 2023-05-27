#pragma once
#include"..\Ente.h"


namespace Entidades 
{
	class Entidade :public Ente
	{
	protected:
		sf::Vector2f pos;
		sf::Vector2f vel;
		bool ta_no_chao;
	public:
		Entidade(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(8.0, 0.0));
		Entidade();
		~Entidade();

		void setpos(sf::Vector2f p);
		sf::Vector2f getpos();

		void setvel(sf::Vector2f v);
		sf::Vector2f getvel();

		void gravidade();
		void chaotemp();   // chaozinho temporario pra testar enquanto ainda n tem plataforma
		sf::Vector2f getTam();

		virtual void Executar() = 0;
		void colide(Entidade* secundaria,sf::Vector2f ds);
	};
}