#include<stdio.h>
#include<stdlib.h>
#define ISSUES 5
#define RATINGS 10

void record(int issue, int rating);
void highestRating();
void lowestRatings();
float averageRating(int issue);
void displayResults();

int responses[ISSUES][RATINGS];
const char *topics[ISSUES] = {
	"Global Warming","The Economy","War","Health Care","Education"};

int main(void)
{
	int response, i;
	do 
	{
		printf("Please rate the following topics on a scale from 1-10\n"
		"1=least important,10=most important\n");
		for (i = 0; i < ISSUES; i++)
		{
			do
			{
				printf("%s", topics[i]);
				printf("? ");
				scanf_s("%d", &response);
			} while (response < 1 || response>10);
			record(i, response);
		}
		printf("Enter 1 to stop. Enter 0 to rate the issues again. ");
		scanf_s("%d", &response);
	} while (response != 1);
	displayResults();
	system("pause");
	return 0;
}

void record(int issue, int rating)
{
	responses[issue][rating - 1]++;
}

void lowestRatings(void)
{
	int lowRating, lowTopic = 0, i, j;
	for (i = 0; i < ISSUES; i++)
	{
		int topicRating = 0;
		for (j = 0; j < RATINGS; j++) topicRating += responses[i][j] * (j + 1);
		if (i == 0)lowRating = topicRating;
		if (lowRating > topicRating)
		{
			lowRating = topicRating;
			lowTopic  = i;
		}
	}
	printf("\nThe lowest rated topic was %s"" with a total rating of %d\n", topics[lowTopic],lowRating);
}

void highestRatings(void)
{
	int highRating=0, highTopic = 0, i, j;
	for (i = 0; i < ISSUES; i++)
	{
		int topicRating = 0;
		for (j = 0; j < RATINGS; j++) topicRating += responses[i][j] * (j + 1);
		if (highRating < topicRating)
		{
			highRating = topicRating;
			highTopic = i;
		}
	}
	printf("\nThe highest rabted topic was %s"" with a total rating of %d\n", topics[highTopic], highRating);
}

float averageRating(int issue)
{
	float total = 0;
	int   counter = 0;
	int j;
	for (j = 0; j < RATINGS; j++)
	{
		if (responses[issue][j] != 0)
		{
			total += responses[issue][j] * (j + 1);
			counter += responses[issue][j];
		}
	}
	return total / counter;
}

void displayResults()
{
	int i, j;
	printf("%20s", "Topic");
	for (i = 1; i <= RATINGS; i++) printf("%4d", i);
	printf("%20s", "Average Rating");
	for (i = 0; i < ISSUES; i++)
	{
		printf("\n%20s", topics[i]);
		for (j = 0; j < RATINGS; j++) printf("%4d", responses[i][j]);
		printf("%20.2f", averageRating(i));
	}
	highestRatings();
	lowestRatings();
}