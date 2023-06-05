#pragma once
#include "..\Ente.h"

namespace Estados
{
	class Estado : public Ente
	{
	public:
		Estado();
		~Estado();
		virtual void Executar() = 0;
	};
}
