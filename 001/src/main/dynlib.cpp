#include "dynlib.hpp"


#if _WIN32
#include <windows.h>

namespace dynlib {

	using loadlib_t = module_ptr(*)(void);
	using freelib_t = void(*)(module_ptr);

	module_handle load(module_ptr& p, const std::string& path, const std::string& symbol) {
		auto h = LoadLibrary(path.c_str());
		if (h) {
			auto load = (loadlib_t)GetProcAddress(h, symbol.c_str());
			if (load)
				p = load();
		}
		return h;
	}

	void free(module_handle handle, module_ptr p, const std::string& symbol) {
		auto free = (freelib_t)GetProcAddress((HINSTANCE)handle, symbol.c_str());
		if (free)
			free(p);
		FreeLibrary((HINSTANCE)handle);
	}

}

#else
	#error unsupport for non-windows platform
#endif
