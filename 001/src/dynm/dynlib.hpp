#pragma once
#include <string>

namespace dynlib {

	class library {
	public:
		void   load (const std::string& path  );
		void   free ();
		void*  findC(const std::string& symbol);
	private:
		void* handle;
	};

}