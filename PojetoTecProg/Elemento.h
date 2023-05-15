#pragma once
template <class TE> class Elemento
{
private:
	Elemento<TE>* pProx;
	TE pInfo;
public:
	Elemento();
	~Elemento();
	TE getData();
	void setData(TE* pp);
	void setProx(TE* prox);
	Elemento<TE>* getProx();

};

