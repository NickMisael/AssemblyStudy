#include <stdio.h>
#include <string.h>

void CntBits(char *value) {

    int result;

    asm(
        "xorl %%ecx, %%ecx;"
        "xorl %%edx, %%edx;"

        "movl (%%eax), %%eax;"

        "loop:"
            "bt %%ecx, %%eax;"
            "jnc cont;"
            "incl %%edx;"

            "cont:"
                "cmp $0x10, %%ecx;"
                "je fim;"
                "incl %%ecx;"
                "jmp loop;"

            "fim:"
                "movl %%edx, %0;"

        :"=r" (result)
        :"r" (&value)
        :"%eax", "%ebx", "%ecx", "%edx"
    );

    printf("The number %d has %d bits 1\n", *value, result);
}


int main() {

    char byte[3];

    printf("[!!] Warning [!!]\n"
           "There are a limit of 2 Bytes!\n");

    printf("Type a number: ");
    scanf("%5d",&byte);

    CntBits(byte);
}
