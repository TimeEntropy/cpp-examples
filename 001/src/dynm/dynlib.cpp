#include "dynlib.hpp"


#if _WIN32
#include <windows.h>

namespace dynlib {

	void library::load(const std::string& path) {
		handle = LoadLibrary(path.c_str());
		if (!handle)
			throw std::runtime_error("failed to get lib handle!");
	}

	void library::free() {
		FreeLibrary((HINSTANCE)handle);
	}

	void* library::findC(const std::string& symbol) {
		auto found = GetProcAddress(static_cast<HMODULE>(handle), symbol.c_str());
		if(!found)
			throw std::runtime_error("the symbol is not found!");
		return (void*)found;
	}

}

#else
	#error unsupport for non-windows platform
#endif
