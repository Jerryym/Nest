#pragma once
#ifdef NESTAPP_BUILD_DLL
#	define NESTAPP_API __declspec(dllexport)
#else
	#define NESTAPP_API __declspec(dllimport)
#endif //NEST_DYNAMIC_LINK

#ifdef NEST_ENABLE_ASSERTS
	#define NEST_ASSERT(X, ...) { if(!(x)) { NEST_ERROR("Assertion Failed: {0}", _VA_ARGS_); __debugbreak(); } }
	#define NEST_CORE_ASSERT(X, ...) { if(!(x)) { NEST_CORE_ASSERT("Assertion Failed: {0}", _VA_ARGS_); __debugbreak(); } }
#else
	#define NEST_ASSERT(X, ...)
	#define NEST_CORE_ASSERT(X, ...) 
#endif // NEST_ENABLE_ASSERTS
