#include <iostream>

//proxy is a class functioning as an interface to something else
//like a wrapper that is being called by the 
//client to access the real serving object behind the scenes
//controls and manages access to the object.

//Common Interface
class IGraphic {
public:
	virtual void Draw() = 0;
};

//Real Subject (Definition)
class Graphic : public IGraphic
{
public:
	Graphic();
	~Graphic();
	void Draw();
};


//Proxy(Definition)
//class contains pointer to object
//manages who can access objects
class GraphicProxy : public IGraphic
{
public:
	GraphicProxy();
	~GraphicProxy();
	void Draw();

private:
	Graphic* graphic;
	Graphic* getInstance(void);
};