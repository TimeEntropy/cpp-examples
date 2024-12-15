#pragma once
#include <string>

namespace dynlib {
	
	class module {
	public:
		virtual void say(const std::string& words) = 0;
	};

	class library {
	public:
		void   load (const std::string& path  );
		void   free ();
		void*  findC(const std::string& symbol);
	private:
		void* handle;
	};

}