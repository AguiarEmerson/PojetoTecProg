#pragma once
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Gerenciadores\Grafico.h"

using namespace Personagens;
using namespace Gerenciadores;
class jogo
{
private:
	Grafico* Gerenciador_grafico;
	Jogador player;
public:
	jogo();
	~jogo();
	void exectutar();
};