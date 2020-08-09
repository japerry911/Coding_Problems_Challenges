#include <stdio.h>

int unusual_five();

int main() {
    printf("Hello, World!\n");
    return 0;
}

int unusual_five() {
    return 'G' % '!';
}