#include "dynm/dynlib.hpp"

namespace mod1 {

	class module : public dynlib::module {
	public:
		void say(const std::string& words) override;
		void hello();
	};

}
