#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Lista\ListaEntidades.h"

using namespace Listas;
using namespace Entidades;
using namespace Personagens;
int main()
{
    //oi
    sf::RenderWindow window(sf::VideoMode(TAMW_X, TAMW_Y), "teste");
    Jogador jogador;
    ListaEntidades list;
    Inimigo inimigo(sf::Vector2f(10.0, 10.0), sf::Vector2f(500.0, 0.0), sf::Vector2f(1.0, 0.0));
    inimigo.setjogador(&jogador);
    list.incluir(static_cast<Entidade*>(&jogador));
    list.incluir(static_cast<Entidade*>(&inimigo));
    

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
    }

    return 0;
}


