#pragma once

#ifdef JT_PLATFORM_WINDOWS
	#ifdef JT_BUILD_DLL
		#define Joto_API __declspec(dllexport)
	#else
		#define Joto_API __declspec(dllimport)
	#endif
#else
	#error Joto only supports Windows!
#endif