#include <stdio.h>

typedef struct{
    void (*originalFunction)();
    void (*hookedFunction)();
}VirtualTable;

typedef struct{
    VirtualTable * vtable;
} vmtHooking;

void originalFunction(){
    printf("This is the original function\n");
}

void hookedFunction(){
    printf("This is the hooked function\n");
}

int main(){

    VirtualTable vtable;

    vtable.originalFunction = originalFunction;
    vtable.hookedFunction = hookedFunction;

    vmtHooking vmtHook;
    vmtHook.vtable = &vtable;

    vmtHook.vtable->originalFunction();

    vmtHook.vtable->originalFunction = vmtHook.vtable->hookedFunction;

    vmtHook.vtable->originalFunction();
}
