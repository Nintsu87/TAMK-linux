
#include <dlfcn.h>
int main() {
  void* handle = dlopen("./libdynamicLibrary.so", RTLD_LAZY);
  if (handle) {
    void (*dHelloWorld)() = (void (*)())dlsym(handle, "dHelloWorld");
    if (dHelloWorld) {
      dHelloWorld();
    }
    dlclose(handle);
  }
  return 0;
}
