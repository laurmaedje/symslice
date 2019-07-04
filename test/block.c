// compile with: gcc -nostdlib -o block block.c

int compare(int a, int b) {
    return a < b;
}

void first(int* c) {
    *c = 0xdeadbeef;
}

void second(int* c) {
    *c = 0xbeefdead;
}

void main() {
    int a = 10, b, c;

    if (a < 5) {
        b = 15;
    } else {
        b = 5;
    }

    if (compare(a, b)) {
        first(&c);
    } else {
        second(&c);
    }
}

void _start() {
    main();
    asm("mov $60,%rax; mov $0,%rdi; syscall");
}