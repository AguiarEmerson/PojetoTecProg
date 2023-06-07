#pragma once
#include"..\Ente.h"


namespace Entidades 
{
	class Entidade :public Ente
	{
	protected:
		sf::RectangleShape box;
		sf::Vector2f pos;
		sf::Vector2f vel;
		bool ta_no_chao;
		bool podeMover;
		bool vivo;
		sf::Texture textura;

	public:
		Entidade(sf::Vector2f tam, sf::Vector2f p = sf::Vector2f(0.0, 0.0), sf::Vector2f v = sf::Vector2f(8.0, 0.0));
		Entidade();
		~Entidade();

		void setbox(const sf::Vector2f tam);
		const sf::RectangleShape getbox();

		void setpos(const sf::Vector2f p);
		const sf::Vector2f getpos();

		void setvel(const sf::Vector2f v);
		const sf::Vector2f getvel();

		void gravidade();
		const sf::Vector2f getTam();

		void setVivo(const bool vive);
		const bool getVivo();

		virtual void Executar() = 0;
		virtual void colide(Entidade* secundaria, sf::Vector2f ds) = 0;


		void setTa_No_Chao(const bool chao);
		void setPodeMover(const bool mover);

		virtual char* salvaEnt() = 0;

		char* criaNomeArquivo(int num);
	};
}