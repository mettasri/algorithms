#include <stdio.h>

unsigned int reverseBits(unsigned int num)
{
    unsigned int count = 7;
    unsigned int reverse_num = 0;
     
    printf("1) %X %X\n", num, reverse_num);
    while(num)
    {
       reverse_num |= num & 1;
       num >>= 1;
       reverse_num <<= 1;       
       count--;
       printf("2) %X %X\n", num, reverse_num);
    }
    reverse_num <<= count;
    printf("3) %X %X %d\n", num, reverse_num, count);
    return reverse_num;
}
 
int main()
{
    unsigned int x = 11;
    printf("%X", reverseBits(x));
}
