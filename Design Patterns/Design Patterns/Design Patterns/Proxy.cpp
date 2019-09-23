#include "Proxy.h"

//Real Subject(Implementation)
Graphic::Graphic()
{
}

Graphic::~Graphic()
{
}

void Graphic::Draw()
{
	std::cout << "Drawing Graphic Object" << std::endl;
}

//Proxy(Implementation)
GraphicProxy::GraphicProxy()
{
	this->graphic = 0;
}

GraphicProxy::~GraphicProxy()
{
	if (graphic)
	{
		delete graphic;
	}
}

void GraphicProxy::Draw()
{
	getInstance()->Draw();
}

Graphic* GraphicProxy::getInstance(void)
{
	if (!graphic)
	{
		graphic = new Graphic();
	}
	return graphic;
}
