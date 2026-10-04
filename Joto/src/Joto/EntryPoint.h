#pragma once

Joto::Application* Joto::CreatApplication();

int main()
{
	auto app = Joto::CreatApplication();
	app->Run();
	delete app;
}