#include "../Gerenciador_Colisao.h"
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Lista\ListaEntidades.h"
#include<iostream>
using namespace std;

#include <string>
using std::string;

using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;
int main()
{
    Gerenciador_Colisao gerenciador;
    sf::RenderWindow window(sf::VideoMode(1000, 600), "teste");
    Jogador jogador;
    ListaEntidades list;
    Inimigo inimigo(sf::Vector2f(10.0, 10.0), sf::Vector2f(500.0, 0.0), sf::Vector2f(1.0, 0.0));
    inimigo.setjogador(&jogador);
    list.incluir(static_cast<Entidade*>(&jogador));
    list.incluir(static_cast<Entidade*>(&inimigo));

    gerenciador.setLista(&list);



    

    while (window.isOpen()) {
        sf::Event evento;
        if (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        list.percorrer();
        window.draw(jogador.print());
        window.draw(inimigo.print());
        window.display();
        window.setFramerateLimit(60);
        gerenciador.executar();

    }

    return 0;
}


