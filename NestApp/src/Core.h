#pragma once
#ifdef NESTAPP_BUILD_DLL
#	define NESTAPP_API __declspec(dllexport)
#else
	#define NESTAPP_API __declspec(dllimport)
#endif //NEST_DYNAMIC_LINK
