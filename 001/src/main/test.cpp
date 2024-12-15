#include <functional>
#include "dynm/dynlib.hpp"
#include "mod1/mod.hpp"
#include "mod2/mod.hpp"

int main(int argc, char* argv[]) {

	dynlib::library lib1;
	dynlib::library lib2;

	lib1.load("build/libmod1.dll");
	lib2.load("build/libmod2.dll");

	using loadfunc1_t = mod1::module*(*)();
	using loadfunc2_t = mod2::module*(*)();
	loadfunc1_t load1 = reinterpret_cast<loadfunc1_t>(lib1.findC("load_mod"));
	loadfunc2_t load2 = reinterpret_cast<loadfunc2_t>(lib2.findC("load_mod"));

	mod1::module* ins1 = load1();
	mod2::module* ins2 = load2();

	ins1->say("test");
	ins2->say("test");

	// ins1->hello();
	// ins2->hi();

	delete ins1;
	delete ins2;

	ins1 = nullptr;
	ins2 = nullptr;

	lib1.free();
	lib2.free();
}
