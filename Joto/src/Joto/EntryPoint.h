#pragma once

Joto::Application* Joto::CreatApplication();

int main()
{
	Joto::Log::Init();
	JT_CORE_WARN("Initialized Log!");
	int a = 5;
	JT_INFO("Hello! Var = {0}", a);

	auto app = Joto::CreatApplication();
	app->Run();
	delete app;
}