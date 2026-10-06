#pragma once

#include "Core.h"

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