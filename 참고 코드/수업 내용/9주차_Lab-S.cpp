#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX 100		  // 만들 데이터 개수
#define NUM_CITY 3	  // 도시 개수
#define NUM_CANDI 3	  // 후보자
#define RANGE_AGE 60  // 20세 ~ 80세
#define SAMPLE_LINE 4 // 네명 당 한 명씩 샘플링

const char *candidate[NUM_CANDI] = {"Watshington", "Lincoln", "Clinton"};
const char *city[NUM_CITY] = {"LA", "NewYork", "D.C"};

struct PERSON
{
	char region[20];
	int age;
	int cadidate_voted;
};

void generation(const char *file_name)
{
	int tmp_city, tmp_age, tmp_candidate;
	FILE *myOutFile;

	myOutFile = fopen(file_name, "w");
	if (myOutFile == NULL)
	{
		printf("Could not open input!\n");
	}

	srand(time(NULL));
	for (int i = 0; i < MAX; i++)
	{
		/* Code here */
		tmp_city = rand() % NUM_CITY;		// 0 ~ 2
		tmp_age = rand() % RANGE_AGE + 20;	// 0 ~ 60 --> 20 ~ 80
		tmp_candidate = rand() % NUM_CANDI; // 0 ~ 2
		fprintf(myOutFile, "%s %d %d\n", city[tmp_city], tmp_age, tmp_candidate);
	}

	fclose(myOutFile);
}

void init(struct PERSON *p, int num, const char *file_name)
{
	FILE *myInFile;
	myInFile = fopen(file_name, "r");
	if (myInFile == NULL)
	{
		printf("Could not open %s!\n", file_name);
	}

	for (int i = 0; i < num; i++)
	{
		/* Code here */
		fscanf(myInFile, "%s %d %d\n", p[i].region, &p[i].age, &p[i].cadidate_voted);
	}
	fclose(myInFile);
}

int num_count(struct PERSON *p, int candidate, int line, int num)
{
	int count = 0;

	/* Code here */
	for (int i = 0; i < num; i += line)
	{
		if (p[i].cadidate_voted == candidate)
			count++; /* 주목 */
	}

	return count;
}

int main()
{
	struct PERSON person[MAX];
	int num = MAX;
	int num_divide = 0;

	const char *file_name = "vote.txt";

	// generation of text file
	generation(file_name);

	// init person array
	init(person, num, file_name);

	// compute percentat of votes each candidates depending on the region
	for (int i = 0; i < NUM_CANDI; i++)
	{
		int num_vote;
		num_vote = num_count(person, i, SAMPLE_LINE, num); // 샘플링까지 고려해서 득표율. num_count: 점핑해서
		num_divide = (num / SAMPLE_LINE);				   // 세 명씩 점핑했다면
		printf("%s %.1f\n", candidate[i], ((float)num_vote / (float)num_divide) * 100);
	}

	return 0;
}
