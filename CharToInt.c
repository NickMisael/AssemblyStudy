#include <stdio.h>

int MyStrLen(char * str) {
    int count = 0;

    for(; *str != '\0'; str++)
        count++;

    return count;
}

int rad(int base, int elev) {
    if(elev == 0)
        return 1;

    if(elev == 1)
        return base;

    int result = base;
    for(int i = 2; i <= elev; i++)
        result *= base;


    return result;
}


int charToInt(char* value) {
    // 0x40 ===> 0x00000040
    // Mask

    int result = 0;
    int sizeValue = MyStrLen(value)-1;
    char * ptr = value;

    for(; *ptr != '\0'; ptr++, sizeValue--){
        int aux = 0;

        asm(
          "andl $0x0F,%%eax;"
          "movl %%eax, %0;"

          :"=r" (aux)
          :"r"  (ptr)
          :"%eax"
        );

        result += (aux*rad(10,sizeValue));
    }

    return result;
}

int main() {

    char chr[100];
    int newChr = 0;

    printf("[!!] Warning [!!]\n"
           "There are a limit of 100 Bytes!\n");
    printf("Type a string: ");
    fgets(str, sizeof(char)*99, stdin);

    if(str[MyStrLen(str)-1] == 0x0a)
        str[MyStrLen(str)-1] = 0x0;
    //scanf("%s",chr);

    printf("Antes da Conversao : %s - Addr: 0x%X\n", chr, chr, &chr);
    newChr = charToInt(chr);
    printf("Depois da Conversao: %d - Addr: 0x%X\n",newChr,&newChr);

    return 0;
}
