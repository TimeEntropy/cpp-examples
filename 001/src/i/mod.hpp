#pragma once
#include <string>

#if defined (IMPORT_DLL)
#define DLL_API __declspec(dllimport)
#else
#define DLL_API __declspec(dllexport)
#endif

namespace i {

	class module {
		virtual void say(const std::string& words) = 0;
	};

}