#include <stdio.h>

 char convertCase(unsigned char ch) {
    unsigned char result;

    asm(
        "xorb $0x20, %%al;"
        "movb %%al, %0;"

        : "=r" (result)
        : "r" (&ch)
        : "%eax"
    );

    return result;
}

int MyStrLen(char * str) {
    int count = 0;

    for(; *str != '\0'; str++)
        count++;

    return count;
}

int main(){

    unsigned char str[100];

    printf("[!!] Warning [!!]\n"
           "There are a limit of 100 Bytes!\n");

    printf("Type a string: ");
    fgets(str, sizeof(char)*99, stdin);

    if(str[MyStrLen(str)-1] == 0x0a)
        str[MyStrLen(str)-1] = 0x0;
    //scanf("%s", str);

    printf("String Original: %s\n", str);

    int sizeStr = MyStrLen(str);

    printf("String Alterada: ");
    for(int i = 0; i < sizeStr; i++){
        if( (str[i] > 0x40 && str[i] < 0x5b) || (str[i] > 0x60 && str[i] < 0x7b))
            putchar(convertCase(str[i]));
        else
            putchar(str[i]);
    }
    putchar(0x0a);

    return 0;
}
