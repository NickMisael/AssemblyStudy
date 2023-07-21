#include <stdio.h>

 char convertCase(unsigned char ch) {
    unsigned char result;

   // Assembly InLine Codeblocks' Sintax
    asm(
        "xorb $0x20, %%al;"
        "movb %%al, %0;"

        : "=r" (result)
        : "r" (&ch)
        : "%eax"
    );

    return result;
}


int main(){

    unsigned char str[100] = "HELLO world";

    printf("String Original: %s\n", str);

    printf("String Alterada: ");
    for(int i = 0; i < 11; i++){
        putchar(convertCase(str[i]));
    }
    putchar(0x0a);

    return 0;
}
