#include "Player.h"

Player::Player(int vida):
	Entidade(50.0,50.0,50.0)
{
	hp = vida;
	vel = sf::Vector2f(1.5f, 1.5f);
	box.setFillColor(sf::Color::Green);
}
Player::~Player()
{

}
//void operator++() 
//void operator--() sobrecarga de operadores pra cumprir o requesito
void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		box.move(-vel.x, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		box.move(vel.x, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		box.move(0.0f,-vel.y);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		box.move(0.0f, vel.y);
	}
}
void Player::Execute()
{
	move();
}