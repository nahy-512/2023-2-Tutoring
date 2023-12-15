#include <stdio.h>

// This function converts decimal to binary number and print the result
void convert10to2(int num)
{
    int value = num;
    int arr[100];
    int count = 0;
    while (value != 0) {
        /* (A) Code here */
        arr[count] = value % 2; // arr[count] = (value & 1)
        value /= 2;             // value = (value >> 1)
        count++;
    }
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// This function converts decimal to octal number and print the result
void convert10to8(int num)
{
    int value = num;
    int arr[100];
    int count = 0;
    while (value != 0) {
        /* (B) Code here */
        arr[count] = value % 8; // arr[count] = (value & 7)
        value /= 8;             // value = (value >> 3);
        count++;
    }
    for (int i = count - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    convert10to2(10);
    convert10to8(10);

    return 0;
}