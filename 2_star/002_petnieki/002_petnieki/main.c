#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool matches(char a, char b)
{
	if (a == b)
		return true;
	if (a == '.')
		return true;
	if (b == '.')
		return true;
	if ((a == 'X' && (b == 'S' || b == 'P')) || (b == 'X' && (a == 'S' || a == 'P')))
		return true;
	if ((a == 'Y' && (b == 'S' || b == 'R')) || (b == 'Y' && (a == 'S' || a == 'R')))
		return true;
	if ((a == 'Z' && (b == 'P' || b == 'R')) || (b == 'Z' && (a == 'P' || a == 'R')))
		return true;
	if ((a == 'S' && (b == 'X' || b == 'Y')) || (b == 'S' && (a == 'X' || a == 'Y')))
		return true;
	if ((a == 'P' && (b == 'X' || b == 'Z')) || (b == 'P' && (a == 'X' || a == 'Z')))
		return true;
	if ((a == 'R' && (b == 'Y' || b == 'Z')) || (b == 'R' && (a == 'Y' || a == 'Z')))
		return true;
	return false;
}

bool isRepeatingPattern(const char* str, int length, int patternLength, int startIndex)
{
	int i, j, baseIndex;
	for (i = 0; i < patternLength; ++i)
	{
		baseIndex = (startIndex + i) % length;
		for (j = baseIndex; j < length; j += patternLength)
		{
			if (!matches(str[baseIndex], str[j]))
			{
				return false;
			}
		}
		for (j = baseIndex - patternLength; j >= 0; j -= patternLength)
		{
			if (!matches(str[baseIndex], str[j]))
			{
				return false;
			}
		}
	}
	return true;
}

int findShortestPatternLength(const char* str, int length)
{
	int patternLength, startIndex;
	for (patternLength = 1; patternLength <= length; patternLength++)
	{
		for (startIndex = 0; startIndex < patternLength; ++startIndex)
		{
			if (isRepeatingPattern(str, length, patternLength, startIndex))
			{
				return patternLength;
			}
		}
	}
	return length;
}

int main()
{
	FILE* infile  = fopen("petnieki.in", "r");
	FILE* outfile = fopen("petnieki.out", "w");

	if (infile == NULL || outfile == NULL)
	{
		perror("Error opening file");
		return 1;
	}

	int length;
	fscanf(infile, "%d\n", &length);
	char str[1001];
	fgets(str, 1001, infile);

	int result = findShortestPatternLength(str, length);
	fprintf(outfile, "%d\n", result);

	fclose(infile);
	fclose(outfile);
	printf("Atbilde : %d \n", result);
	return 0;
}