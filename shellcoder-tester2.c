/* compile: gcc -m64 -z execstack -fno-stack-protector -o shellcoder-tester2.c shellcoder-tester2 */

#include <stdio.h>
#include <string.h>

unsigned char code[] = ""; /* place shellcoder here */

int main()
{
    printf("Shellcode length: %d\n", strlen(code));
    /* declare a *ret() function, and point it to the 
     * memory location of code, when ret() is later 
     * called it will run code 
     */    
    int (*ret)() = (int(*)())code;
    
    ret();
}
