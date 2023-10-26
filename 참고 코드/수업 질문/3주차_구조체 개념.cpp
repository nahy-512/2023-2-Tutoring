#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct
{
    int month;
    int day;
    int year;
} birth;

// int main()
// {
//     birth.month = 12;
//     birth.day = 28;
//     birth.year = 2003;

//     printf("My birth date is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>

// struct Birth
// {
//     int month;
//     int day;
//     int year;
// };

// int main()
// {
//     struct Birth birth;

//     birth.month = 12;
//     birth.day = 28;
//     birth.year = 2003;

//     printf("My birth date is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// struct
// {
//     int month;
//     int day;
//     int year;
// } birth;

// int main()
// {
//     printf("Type current day(Day Month Year): ");
//     scanf("%d %d %d", &birth.month, &birth.day, &birth.year);
//     printf("My birth date is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// struct Birth{
// 	int month;
// 	int day;
// 	int year;
// }birth;

// int main() {
// 	printf("Type current day(Day Month Year): ");
// 	scanf("%d %d %d", &birth.month, &birth.day, &birth.year);
// 	printf("My birth data is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// struct Birth
// {
//     int month;
//     int day;
//     int year;
// };

// int main()
// {
//     struct Birth birth;
//     printf("Type current day(Day Month Year): ");
//     scanf("%d %d %d", &birth.month, &birth.day, &birth.year);
//     printf("My birth data is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// struct Birth
// {
//     int month;
//     int day;
//     int year;
// } birth = {10, 20, 2021};

// int main()
// {
//     printf("My birth date is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// struct Birth
// {
//     int month;
//     int day;
//     int year;
// };

// int main()
// {
//     struct Birth birth = {10, 20, 2021};
//     printf("My birth data is %d/%d/%d\n", birth.month, birth.day, birth.year);
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #define NUM 5
// struct Stock
// {
//     char name[20];
//     float stock_earning;
//     float price_to_ratio;
// };
// void main()
// {
//     // variable
//     struct Stock sto[NUM];

//     // input
//     for (int i = 0; i < NUM; i++)
//     {
//         printf("Type stock information (Name, earning, ratio):");
//         scanf("%s %f %f", &sto[i].name, &sto[i].stock_earning, &sto[i].price_to_ratio);
//     }

//     // print
//     for (int i = 0; i < NUM; i++)
//     {
//         printf("Stock name:%s stock price:%f\n", sto[i].name, sto[i].stock_earning * sto[i].price_to_ratio);
//     }
// }

// #define _CRT_SECURE_NO_WARNINGS
// #include <stdio.h>
// #include <string.h>
// #define NUM 5
// struct Stock
// {
//     char name[20];
//     float est_price_ratio;
//     int est_earnings;
// };

// void main()
// {
//     int i = 0;
//     char t_name[20];
//     struct Stock sto[NUM];
//     for (i = 0; i < NUM; i++)
//     {
//         printf("Type %d-th stock information (Name, ratio, earnings):", i);
//         scanf("%s %f %d", &sto[i].name, &sto[i].est_price_ratio, &sto[i].est_earnings);
//     }
//     for (i = 0; i < NUM; i++)
//     {
//         printf("%d-th: %s stock price: %f\n", i, sto[i].name, sto[i].est_price_ratio * (float)sto[i].est_earnings);
//     }
// }
