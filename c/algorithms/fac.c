#include <assert.h>

void test_fak() {
    assert(fak(0) == 1);
    assert(fak(1) == 1);
    assert(fak(2) == 2);
    assert(fak(3) == 6);
    assert(fak(4) == 24);
    assert(fak(5) == 120);
    assert(fak(-1) == 1);
}

int main() {
    test_fak();
    return 0;
}