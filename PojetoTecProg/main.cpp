#include "Inimigo.h"

using namespace Entidades;
int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 600), "teste");
    Jogador jogador;
    Inimigo inimigo(sf::Vector2f(10.0, 10.0), sf::Vector2f(500.0, 0.0), sf::Vector2f(1.0, 0.0));
    inimigo.setjogador(&jogador);
    

    while (window.isOpen()) {
        sf::Event evento;
        if (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        jogador.Executar();
        inimigo.Executar();
        window.draw(jogador.print());
        window.draw(inimigo.print());
        window.display();
        window.setFramerateLimit(60);
    }

    return 0;
}


