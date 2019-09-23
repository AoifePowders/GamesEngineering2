#include <iostream>

//Common Interface
class IGraphic {
public:
	virtual void Draw() = 0;
};

//Real Subject (Definition)
class Graphic : public
	IGraphic
{
public:
	Graphic();
	~Graphic();
	void Draw();
};


//Proxy(Definition)
class GraphicProxy : public
	IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();

private:
	Graphic* graphic;
	Graphic* getInstance(void);
};