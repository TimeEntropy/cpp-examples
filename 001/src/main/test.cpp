#include "dynlib.hpp"

#include "mod1/mod.hpp"
#include "mod2/mod.hpp"

int main(int argc, char* argv[]) {

	dynlib::module_handle h1;
	dynlib::module_ptr    m1;
	mod1::module*         t1;

	dynlib::module_handle h2;
	dynlib::module_ptr    m2;
	mod2::module*         t2;


	h1 = dynlib::load(m1, "build/libmod1.dll", "load_mod1");
	h2 = dynlib::load(m2, "build/libmod2.dll", "load_mod2");

	m1->say("test");
	m2->say("test");

	t1 = reinterpret_cast<mod1::module*>(m1);
	t2 = reinterpret_cast<mod2::module*>(m2);

	// t1->say("cast");
	// t2->say("cast");

	// error, can't find symbols of functions
	// t1->hello();
	// t2->hi();

	dynlib::free(h1, m1, "free_mod1");
	dynlib::free(h2, m2, "free_mod2");

}
