#include "Joto.h"

class Sandbox : public Joto::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};

Joto::Application* Joto::CreatApplication()
{
	return new Sandbox;
}