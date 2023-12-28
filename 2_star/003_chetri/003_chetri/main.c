#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PERMUTATIONS 120
#define HASH_TABLE_SIZE 100000 // Assuming 5-digit numbers

struct ThreeNumSet
{
	int num1, num2, num3;
};

struct ThreeNumSet uniqueCombinations[MAX_PERMUTATIONS];
int uniqueCount					= 0;
bool hashTable[HASH_TABLE_SIZE] = {false};

void addToHashTable(int num)
{
	hashTable[num] = true;
}

bool existsInHashTable(int num)
{
	return hashTable[num];
}

// Function to add a combination if it's unique
bool addIfUnique(int n1, int n2, int n3)
{
	// Sort the numbers
	int nums[3] = {n1, n2, n3};
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = i + 1; j < 3; j++)
		{
			if (nums[i] > nums[j])
			{
				int temp = nums[i];
				nums[i]	 = nums[j];
				nums[j]	 = temp;
			}
		}
	}

	// Check if this combination is unique
	for (i = 0; i < uniqueCount; i++)
	{
		if (uniqueCombinations[i].num1 == nums[0] && uniqueCombinations[i].num2 == nums[1] && uniqueCombinations[i].num3 == nums[2])
		{
			return false; // Combination already exists
		}
	}

	// Add the unique combination
	uniqueCombinations[uniqueCount++] = (struct ThreeNumSet){nums[0], nums[1], nums[2]};
	return true;
}

// Function to swap two characters
void swap(char* x, char* y)
{
	char temp = *x;
	*x		  = *y;
	*y		  = temp;
}


// Heap's algorithm for generating permutations iteratively
void heapPermute(char* a, int n, char output[][6], int* count)
{
	int c[n];
	memset(c, 0, sizeof(c));

	if (a[0] != '0')
	{
		strcpy(output[*count], a);
		(*count)++;
	}

	int i = 0;
	while (i < n)
	{
		if (c[i] < i)
		{
			if (i % 2 == 0)
			{
				swap(&a[0], &a[i]);
			}
			else
			{
				swap(&a[c[i]], &a[i]);
			}
			if (a[0] != '0')
			{
				strcpy(output[*count], a);
				(*count)++;
			}
			c[i]++;
			i = 0;
		}
		else
		{
			c[i] = 0;
			i++;
		}
	}
}

// Function to convert string to integer
int toInt(char* str)
{
	return (str[0] - '0') * 10000 + (str[1] - '0') * 1000 + (str[2] - '0') * 100 + (str[3] - '0') * 10 + (str[4] - '0');
}

// Recursive function to generate permutations
void permute(char* a, int l, int r, char output[][6], int* count)
{
	if (l == r)
	{
		if (a[0] != '0')
		{ // Skip numbers starting with 0
			strcpy(output[*count], a);
			(*count)++;
		}
	}
	else
	{
		int i;
		for (i = l; i <= r; i++)
		{
			swap((a + l), (a + i));
			permute(a, l + 1, r, output, count);
			swap((a + l), (a + i)); // backtrack
		}
	}
}

// Check if the numbers are distinct
bool areDistinct(int a, int b, int c, int d)
{
	return a != b && a != c && a != d && b != c && b != d && c != d;
}

int numValues[MAX_PERMUTATIONS]; // Array to store the integer values of permutations


int main()
{
	FILE* infile  = fopen("chetri.in", "r");
	FILE* outfile = fopen("chetri.out", "w");

	char digits[6];
	fscanf(infile, "%s %s %s %s %s", &digits[0], &digits[1], &digits[2], &digits[3], &digits[4]);
	digits[5] = '\0';

	// Generate permutations
	char permutations[MAX_PERMUTATIONS][6];
	int count = 0;
	// permute(digits, 0, 4, permutations, &count);
	heapPermute(digits, 5, permutations, &count);

	// Precompute the integer values of the permutations and add them to the hash table
	int numValues[MAX_PERMUTATIONS];
	int i, j, k, l;
	for (i = 0; i < count; i++)
	{
		numValues[i] = toInt(permutations[i]);
		addToHashTable(numValues[i]);
	}

	// Now proceed with checking combinations
	int result = 0;
	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			for (k = 0; k < count; k++)
			{
				int num1 = numValues[i];
				int num2 = numValues[j];
				int num3 = numValues[k];
				int sum	 = num1 + num2 + num3;

				// Check if sum is one of the permutations
				for (l = 0; l < count; l++)
				{
					int num4 = numValues[l];
					if (sum == num4 && areDistinct(num1, num2, num3, num4) && addIfUnique(num1, num2, num3))
					{
						if (existsInHashTable(num4))
						{
							// printf("%d + %d + %d == %d\n", num1, num2, num3, num4);
							result++;
						}
					}
				}
			}
		}
	}

	// Each set of 4 numbers is counted 4! times due to permutations, so divide by 24
	fprintf(outfile, "%d\n", result);

	fclose(infile);
	fclose(outfile);

	return 0;
}
