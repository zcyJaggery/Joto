#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Joto {
	class JOTO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
	Application* CreatApplication();
}