#include "Jogador.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "teste");
    Jogador jogador;

    while (window.isOpen()) {
        sf::Event evento;
        if (window.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        jogador.Executar();
        window.draw(jogador.print());
        window.display();
        window.setFramerateLimit(60);
    }

    return 0;
}


