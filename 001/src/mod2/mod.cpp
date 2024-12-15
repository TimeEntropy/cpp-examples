#include <iostream>
#include "mod.hpp"

namespace mod2 {

	extern "C" {
		module* load_mod2() {
			return new module();
		}
	}

	void module::say(const std::string& words) {
		std::cout << "mod2: " << words << "\n";
	}

	void module::hi() {
		std::cout << "mod2: hi\n";
	}

}
