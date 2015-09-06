#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100001

struct node
{
	char key[12];
	char value[12];
} dictionary[MAX];

int cmp(const void * str1, const void * str2)
{
	return strcmp(((struct node *)str1)->key, ((struct node *)str2)->key);
}

void binSearch(char key[], int length)
{
	int low, high, mid;
	low = 0;
	high = length - 1;
	mid = (low + high) / 2;
	bool found = false;

	while (low <= high)
	{
		if (strcmp(key, dictionary[mid].key) == 0)
		{
			printf("%s\n", dictionary[mid].value);
			found = true;
			break;
		}
		if (strcmp(key, dictionary[mid].key) < 0)
		{
			high = mid-1;
			mid = (low + high) / 2;
		}
		else
		{
			low = mid+1;
			mid = (low + high) / 2;
		}
	}
	if (!found)
		printf("eh\n");
}

int main(int argc, char const *argv[])
{
	char current_str[12];
	int i = 0;

	while (scanf("%s", dictionary[i].value) != EOF)
	{
		if (getchar() == '\n')
			break;

		scanf("%s", dictionary[i].key);
		++i;
	}

	qsort(dictionary, i, sizeof(node), cmp);

	binSearch(dictionary[i].value, i);

	while (scanf("%s", current_str) != EOF)
	{
		binSearch(current_str, i);
	}

	return 0;
}