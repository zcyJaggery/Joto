#pragma once

#ifdef JT_PLATFORM_WINDOWS
	#ifdef JT_BUILD_DLL
		#define JOTO_API __declspec(dllexport)
	#else
		#define JOTO_API __declspec(dllimport)
	#endif
#else
	#error Joto only supports Windows!
#endif

#define BIT(x) (1 << (x))