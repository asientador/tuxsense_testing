#include <stdio.h>
#include <dlfcn.h>

int main() {

    void *handle = dlopen("./liblibrary.so", RTLD_LAZY);

    if (!handle){
        printf("dlopen returned null handle\n");
        printf("Error description: %s\n",dlerror());
    return -1;
    }


    void (*functionPointer)() = dlsym(handle,"print_hello");

    if(!functionPointer){
        printf("dlsym returned null pointer\n");
        printf("Error description %s\n",dlerror());
        return -1;
    }


    functionPointer();

    dlclose(handle);
    return 0;
}

