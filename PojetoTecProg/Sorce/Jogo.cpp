#include "..\jogo.h"

jogo::jogo() :
	Gerenciador_grafico(Grafico::getgrafico()),
	player()
{
	Gerenciador_grafico->setPjogador(&player);
}
jogo::~jogo(){
}

void exectutar() {
	while()

}
