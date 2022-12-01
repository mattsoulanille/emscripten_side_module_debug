#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

typedef int64_t (*int64func)(int);
typedef void (*fooFunc)();

int main() {
  void *lib_handle = dlopen("./foo_lib.wasm", RTLD_LAZY | RTLD_LOCAL);
  if (!lib_handle) {
    puts(dlerror());
    abort();
  }
  printf("dll handle: %p\n", lib_handle);

  fooFunc x = (fooFunc)dlsym(lib_handle, "foo");

  printf("foo func handle: %p\n", x);
  if (!x) {
    printf("dlsym failed: %s\n", dlerror());
    return 1;
  }
  x();
  return 0;
}
