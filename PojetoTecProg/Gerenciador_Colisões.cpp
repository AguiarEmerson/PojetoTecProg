#include "Gerenciador_Colis�es.h"
namespace Gerenciadores
{

	Gerenciador_Colisao::Gerenciador_Colisao(ListaEntidades* listaEnt)
	{
		lista = listaEnt;
	}
	Gerenciador_Colisao::Gerenciador_Colisao()
	{
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
		for (i = 0; i < tam; i++)
		{
			//se for um personagem entra no loop
			if (lista->getEnt(i)->getId() == "personagem")
			{
				auxprincipal = lista->getEnt(i);
				//loop para testar cada personagem com cada obst�culo
				for (i = 0; i < tam; i++)
				{
					if (lista->getEnt(i)->getId() == "obstaculo")
					{
						auxsecundaria = lista->getEnt(i);
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
						if (ds.x < 0.0f && ds.y < 0.0f)
							auxprincipal->colide(auxsecundaria);
						//agora fazer as conclus�es da colisao
					}
					if (lista->getEnt(i)->getId() == "inimigo")
					{
						auxsecundaria = lista->getEnt(i);
						sf::Vector2f ds = calculaColisao(auxprincipal, auxsecundaria);
						if (ds.x < 0.0f && ds.y < 0.0f)
							auxprincipal->colide(auxsecundaria);
						//agora fazer as conclus�es da colisao
					}
				}
			}
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
							auxprincipal->colide(auxsecundaria);
					}
				}
			}
		}
	}



}