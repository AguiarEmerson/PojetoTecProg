#pragma once
#include "..\Menus\Menu.h"
#include "..\Estados\Estado.h"

namespace Menus
{
	class GameOver :public Menu, public Estados::Estado
	{
	private:
		Texto pontuacao;
		Texto nome;
		Texto situacao;
		void criabotoes();
		Texto* texto;
		bool primeiroCadastro;
		
	public:
		GameOver(bool Ganhou);
		~GameOver();
		void selecionar(Botao* botao);
		void cadastrar();
		void Executar();
		void salvaPonto(string nomeJ, int ponto);

		void cadastraPontuacao();
		void cadastrasegundaPontuacao();
		
	};

}
