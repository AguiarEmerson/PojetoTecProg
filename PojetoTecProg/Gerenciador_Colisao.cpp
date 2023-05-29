#include "Gerenciador_Colisao.h"

namespace Gerenciadores
{

	Gerenciador_Colisao::Gerenciador_Colisao(ListaEntidades* listaEnt)
	{
		lista = listaEnt;
	}
	Gerenciador_Colisao::Gerenciador_Colisao()
	{
		lista = nullptr;
	}
	Gerenciador_Colisao::~Gerenciador_Colisao()
	{
	}
	void Gerenciador_Colisao::setLista(ListaEntidades* listaEnt)
	{
		lista = listaEnt;
	}
	void Gerenciador_Colisao::executar()
	{
		
		int i, tam;
		tam = lista->getTam();
		Entidade* auxprincipal;
		Entidade* auxsecundaria;
		//for para identificar os jogadores
		/*for (i = 0; i < tam; i++)
		{
			
			
			//se for um personagem entra no loop
			if (lista->getEnt(i)->getId() == "jogador")
			{
				
				auxprincipal = lista->getEnt(i);
				//loop para testar cada personagem com cada obstáculo
				for (i = 0; i < tam; i++)
				{
					if (lista->getEnt(i)->getId() == "inimigo")
					{
						
						auxsecundaria = lista->getEnt(i);
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
						if (ds.x < 0.0f && ds.y < 0.0f)
						{
							auxprincipal->colide(auxsecundaria, ds);
						}
						//agora fazer as conclusões da colisao
					}
					if (lista->getEnt(i)->getId() == "obstaculo")
					{
						auxsecundaria = lista->getEnt(i);
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
						if (ds.x < 0.0f && ds.y < 0.0f)
						{
							auxprincipal->colide(auxsecundaria, ds);
						}

						//agora fazer as conclusões da colisao
					}
				}
			}*/
		for (i = 0; i < tam; i++)
		{
			//se for um personagem entra no loop
			if (lista->getEnt(i)->getId() == "inimigo")
			{

				auxprincipal = lista->getEnt(i);
				for (i = 0; i < tam; i++)
				{
					if (lista->getEnt(i)->getId() == "jogador")
					{

						auxsecundaria = lista->getEnt(i);
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
						sf::Vector2f ds2 = calculaColisao(auxsecundaria, auxprincipal);
						if (ds.x < 0.0f && ds.y < 0.0f)
						{
							auxprincipal->colide(auxsecundaria, ds);
							auxsecundaria->colide(auxprincipal, ds);
						}
						else {
							auxprincipal->setTa_No_Chao(false);
							auxsecundaria->setTa_No_Chao(false);
						}

					}
				}
			}
		}
		/*for (i = 0; i < tam; i++)
		{
			//se for um personagem entra no loop
			if (lista->getEnt(i)->getId() == "jogador")
			{

				auxprincipal = lista->getEnt(i);
				for (i = 0; i < tam; i++)
				{
					if (lista->getEnt(i)->getId() == "inimigo")
					{

						auxsecundaria = lista->getEnt(i);
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
						if (ds.x < 0.0f && ds.y < 0.0f)
						{
							auxprincipal->colide(auxsecundaria, ds);
						}
						else
							auxprincipal->setTa_No_Chao(false);

					}
				}
			}
		}*/
		
		
		
		
		for (i = 0; i < tam; i++)
			{
				//se for um personagem entra no loop
				if (lista->getEnt(i)->getId() == "jogador")
				{

					auxprincipal = lista->getEnt(i);
					for (i = 0; i < tam; i++)
					{
						if (lista->getEnt(i)->getId() == "obstaculo")
						{

							auxsecundaria = lista->getEnt(i);
							sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
							if (ds.x < 0.0f && ds.y < 0.0f)
							{
								auxprincipal->colide(auxsecundaria, ds);
							}

						}
					}
				}
			}
			for (i = 0; i < tam; i++)
			{
				//se for um personagem entra no loop
				if (lista->getEnt(i)->getId() == "inimigo")
				{
			
				

					auxprincipal = lista->getEnt(i);
					for (i = 0; i < tam; i++)
					{
						if (lista->getEnt(i)->getId() == "obstaculo")
						{

							auxsecundaria = lista->getEnt(i);
							sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
							if (ds.x < 0.0f && ds.y < 0.0f)
							{
								auxprincipal->colide(auxsecundaria, ds);
							}

						}
					}
				}
			}
			
		
	}
	//pegamos o código do monitor giovanni pois 
	sf::Vector2f Gerenciador_Colisao::calculaColisao(Entidade* entidade1, Entidade* entidade2)
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