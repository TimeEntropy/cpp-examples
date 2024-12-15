#pragma once
#include <string>

namespace dynlib {
	
	class module {
	public:
		virtual void say(const std::string& words) = 0;
	};

	using module_handle = void  *;
	using module_ptr    = module*;

	module_handle load(module_ptr&   p     , const std::string& path, const std::string& symbol);
	void          free(module_handle handle, module_ptr         p   , const std::string& symbol);

}