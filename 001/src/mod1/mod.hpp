#include "dynm/dynlib.hpp"
#include "i/mod.hpp"

namespace mod1 {

	class module : public i::module {
	public:
		void say(const std::string& words) override;
		void hello();
	};

}
