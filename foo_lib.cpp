#include <inttypes.h>
#include <emscripten.h>
#include <emscripten/val.h>


extern "C" void foo() {
  emscripten::val console = emscripten::val::global("console");
  console.call<void>("log", std::string("This will be printed..."));
  console.call<void>("log", emscripten::val("This will throw BindingError..."));
  console.call<void>("log", console); // This also throws BindingError
  console.call<void>("log", console.as<bool>()); // Ditto
}
