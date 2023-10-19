#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int strlen(char *a)
{
    int count = 0;
    while (*a++)
    {
        count++;
    }
    return count;
}
int match_count(char *text, char *sub)
{
    int text_length = 0, sub_length = 0, count = 0;
    text_length = strlen(text);
    sub_length = strlen(sub);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == sub[0])
        {
            int tmp = 0;
            for (int j = 0; j < sub_length; j++)
            {
                if (text[i + j] != sub[j])
                    break;
                else
                    tmp++;
                if (tmp == sub_length)
                {
                    count++;
                    i += sub_length;
                    break;
                }
            }
        }
    }

    return count;
}
int main()
{
    int mat_num;
    char text_arr[256], sub_arr[256];

    puts("Text matching program\n");
    printf("Type text:");
    gets(text_arr);
    printf("Type sub-string for matching:");
    gets(sub_arr);

    mat_num = match_count(text_arr, sub_arr);
    printf("Matched words: %d\n", mat_num);
    return 0;
}