#include <iostream>
#include "mod.hpp"

namespace mod1 {

	extern "C" {
		module* load_mod() {
			return new module();
		}
	}

	void module::say(const std::string& words) {
		std::cout << "mod1: " << words << "\n";
	}

	void module::hello() {
		std::cout << "mod1: hello\n";
	}

}
