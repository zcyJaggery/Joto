#include "jtpch.h"
#include "Application.h"

#include "Joto\Events\ApplicationEvent.h"
#include "Joto\Log.h"

namespace Joto {
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		JT_TRACE(e);

		while (true);
	}

}