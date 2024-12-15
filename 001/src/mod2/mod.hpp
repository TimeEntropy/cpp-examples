#include "dynm/dynlib.hpp"
#include "i/mod.hpp"

namespace mod2 {

	class DLL_API module : public i::module {
	public:
		void say(const std::string& words) override;
		void hi();
	};

}
