#include "Player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "teste");
    Player jogador;

    while (window.isOpen()) {
        sf::Event evento;
        if (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        jogador.Execute();
        window.draw(jogador.print());
        window.display();
    }

    return 0;
}


