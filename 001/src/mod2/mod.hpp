#include "main/dynlib.hpp"

namespace mod2 {

	class module : public dynlib::module {
	public:
		void say(const std::string& words) override;
		void hi();
	};

}
