/* compile: gcc -m64 -z execstack -fno-stack-protector -o shellcoder-tester shellcoder-tester.c */

char shellcode[] = "PLACE SHELLCODE HERE";

int main()
{
    int *ret;
    /* The following sets *ret pointer 
     * equal to main return address 
     */
    ret = (int *)&ret + 2;
    /* The following sets the ret to the 
     * address of shellcode array
     */
    (*ret) = (int)shellcode;
}
