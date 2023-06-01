#include "..\Gerenciadores\Colisao.h"

namespace Gerenciadores
{

	Colisao::Colisao(ListaEntidades* listaEnt )
	{
		lista = listaEnt;
		
	}
	Colisao::Colisao()
	{
		
			lista= nullptr;


	}
	Colisao::~Colisao()
	{
		if (lista)
			lista = NULL;
		listaInimigo.clear();
		listaObstaculo.clear();
		listaJogador.clear();
			
	}
	void Colisao::setLista(ListaEntidades* listaEnt)
	{
		lista = listaEnt;
		int i,tam;
		tam = lista->getTam();
		
		for (i = 0; i < tam; i++)
		{
			if (lista->getEnt(i)->getId() == "obstaculo")
				listaObstaculo.push_back(lista->getEnt(i));
			else if (lista->getEnt(i)->getId() == "inimigo") 
				listaInimigo.push_back(lista->getEnt(i));
			else if (lista->getEnt(i)->getId() == "jogador")
				listaJogador.push_back(lista->getEnt(i));
		
				
		}
	}
	void Colisao::executar()
	{
		std::list<Entidade*>::iterator it;
		std::list<Entidade*>::iterator it2;
		std::vector<Entidade*>::iterator it3;

		Entidade* auxprincipal;
		Entidade* auxsecundaria;
		bool colidiu;

		for (it=listaInimigo.begin();it!=listaInimigo.end(); it++)
		{
			auxprincipal = *it;
			colidiu = false;
			if (auxprincipal->getVivo() == true) {
				for (it2 = listaObstaculo.begin(); it2 != listaObstaculo.end(); it2++)
				{
					auxsecundaria =*it2;
					if (auxsecundaria->getVivo() == true)
					{
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);

						if (ds.x < 0.0f && ds.y < 0.0f) {
							auxprincipal->colide(auxsecundaria, ds);
							colidiu = true;
						}
					}

				}
				if (colidiu == false)
					auxprincipal->setTa_No_Chao(false);

			}
		}
		for (it3 = listaJogador.begin(); it3 != listaJogador.end(); it3++)
		{
			auxprincipal = *it3;
			colidiu = false;
			if (auxprincipal->getVivo() == true) {
				for (it2 = listaObstaculo.begin(); it2 != listaObstaculo.end(); it2++)
				{
					auxsecundaria = *it2;
	

					sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);

					if (ds.x < 0.0f && ds.y < 0.0f) {
						auxprincipal->colide(auxsecundaria, ds);
						colidiu = true;
					}
				}
				if (colidiu == false)
					auxprincipal->setTa_No_Chao(false);
			}
		}
		for (it = listaInimigo.begin(); it != listaInimigo.end(); it++)
		{
			auxprincipal = *it;
			if (auxprincipal->getVivo() == true) {
				for (it3 = listaJogador.begin(); it3 != listaJogador.end(); it3++)
				{
					auxsecundaria = *it3;
					if (auxsecundaria->getVivo() == true)
					{
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);

						if (ds.x < 0.0f && ds.y < 0.0f) {
							auxprincipal->colide(auxsecundaria, ds);
						}	
					}

				}
			}
		}
	}
	//pegamos o código do monitor giovanni pois 
	sf::Vector2f Colisao::calculaColisao(Entidade* entidade1, Entidade* entidade2)
	{
		sf::Vector2f pos1 = entidade1->getpos();
		sf::Vector2f pos2 = entidade2->getpos();

		sf::Vector2f tam1 = entidade1->getTam();
		sf::Vector2f tam2 = entidade2->getTam();

		sf::Vector2f distanciaEntreCentros(
			fabs((pos1.x + tam1.x / 2.0f) - (pos2.x + tam2.x / 2.0f)),
			fabs((pos1.y + tam1.y / 2.0f) - (pos2.y + tam2.y / 2.0f))
		);
		sf::Vector2f somaMetadeRectangulo(tam1.x / 2.0f + tam2.x / 2.0f, tam1.y / 2.0f + tam2.y / 2.0f);
		return sf::Vector2f(distanciaEntreCentros.x - somaMetadeRectangulo.x, distanciaEntreCentros.y - somaMetadeRectangulo.y);
	}


}