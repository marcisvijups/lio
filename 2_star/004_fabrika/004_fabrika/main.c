#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// gcd - greatest common divisor euclidean algorithm
uint64_t gcd(uint64_t a, uint64_t b)
{
	uint64_t tmp;
	while (b != 0)
	{
		tmp = b;
		b	= a % b;
		a	= tmp;
	}
	return a;
}


int32_t main()
{
	FILE* infile  = fopen("fabrika.in", "r");
	FILE* outfile = fopen("fabrika.out", "w");
	uint64_t n, m, k;
	fscanf(infile, "%" SCNu64 " %" SCNu64 " %" SCNu64, &n, &m, &k);
	fclose(infile);

	n++;
	m++;
	uint64_t nokrasoti, nolakoti, neapstradati, apstradati;
	nokrasoti = nolakoti = neapstradati = apstradati = 0;
	// inteligent mathematically approach
	uint64_t nokrasoti1, nolakoti1, neapstradati1, apstradati1;
	nokrasoti1 = nolakoti1 = neapstradati1 = apstradati1 = 0;
	nokrasoti1											 = k / (n);
	nolakoti1											 = k / (m);
	// LCM - least common multiple
	uint64_t lcm  = (n) * (m) / gcd(n, m);
	neapstradati1 = k / (lcm);
	nokrasoti1 -= neapstradati1;
	nolakoti1 -= neapstradati1;
	apstradati1 = k - nokrasoti1 - nolakoti1 - neapstradati1;
	fprintf(outfile, "%" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", apstradati1, neapstradati1, nolakoti1, nokrasoti1);


	// this is brute force approach but it is too slow for big numbers
	// uint64_t ptr1, ptr2;
	// ptr1 = ptr2 = 0;

	// int64_t last_indx = 0;
	// while (1)
	// {
	// 	if (ptr1 == ptr2 && ptr1 == last_indx)
	// 	{
	// 		ptr1 += n;
	// 		if (ptr1 <= k)
	// 			nokrasoti++;
	// 	}

	// 	if (ptr1 < ptr2 && ptr1 <= k)
	// 	{
	// 		ptr1 += n;
	// 		if (ptr1 <= k)
	// 			nokrasoti++;
	// 	}
	// 	else if (ptr2 < ptr1 && ptr2 <= k)
	// 	{
	// 		ptr2 += m;
	// 		if (ptr2 <= k)
	// 			nolakoti++;
	// 	}
	// 	if ((ptr1 == ptr2) && (ptr1 < k) && (last_indx != ptr1))
	// 	{
	// 		last_indx = ptr1;
	// 		neapstradati++;
	// 		nokrasoti--;
	// 		nolakoti--;
	// 	}
	// 	if (ptr1 > k && ptr2 > k)
	// 		break;
	// }

	// apstradati = k - nokrasoti - nolakoti - neapstradati;

	// fprintf(outfile, "%" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", apstradati, neapstradati, nolakoti, nokrasoti);
	fclose(outfile);

	return 0;
}
