#include "..\Principal.h"
/*int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}*/
int main()
{
    
    Principal objPricipal;
    objPricipal.executar();
    
    return 0;
}





/*#include "..\Gerenciadores\Colisao.h"
#include "..\Entidades\Personagens\Inimigo.h"
#include "..\Lista\ListaEntidades.h"
#include "..\Entidades\Obstaculos\Plataforma.h"
#include<iostream>
using namespace std;

#include <string>
using std::string;

using namespace Listas;
using namespace Entidades;
using namespace Personagens;
using namespace Gerenciadores;
using namespace Obstaculos;
int main()
{
    Colisao gerenciador;

    //oi
    sf::RenderWindow window(sf::VideoMode((unsigned int)TAMW_X, (unsigned int)TAMW_Y), "teste");
    Jogador jogador;
    ListaEntidades list;
    Plataforma plataforma(sf::Vector2f(1000.0, 100.0), sf::Vector2f(0.0, 580.0), sf::Vector2f(0.0, 0.0));
    Plataforma plataforma2(sf::Vector2f(800.0, 100.0), sf::Vector2f(0.0, 400.0), sf::Vector2f(0.0, 0.0));
    Inimigo inimigo(sf::Vector2f(50.0, 50.0), sf::Vector2f(500.0, -213.0), sf::Vector2f(1.0, 0.0));
    
    inimigo.setjogador(&jogador);
    list.incluir(static_cast<Entidade*>(&plataforma));
    list.incluir(static_cast<Entidade*>(&plataforma2));
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
        window.draw(jogador.desenhar());
        window.draw(inimigo.desenhar());
        window.draw(plataforma.desenhar());
        window.draw(plataforma2.desenhar());
        window.display();
        window.setFramerateLimit(60);
        gerenciador.executar();

    }

    return 0;
}*/


