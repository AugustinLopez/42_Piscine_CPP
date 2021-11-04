#include "Zombie.hpp"
#include <iostream>

/**
 * Test for the stack zombie.
 */
static void stack_test(void){
    randomChump("Stack");
}

/**
 * Test for the heap zombie, first part
 * @return a Zombie on the heap
 */
static Zombie *heap_test_1(void){
    return (newZombie("Heap"));
}

/**
 * Test for the heap zombie, second part
 * @param heap A Zombie to be announced, then deleted
 */
static void heap_test_2(Zombie *heap) {
    heap->annonce();
    delete heap;
}

int main(void) {
    stack_test();
    heap_test_2(heap_test_1());
    return (0);
}
