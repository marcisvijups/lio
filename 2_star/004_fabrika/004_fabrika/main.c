#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

	uint64_t ptr1, ptr2;
	ptr1 = ptr2 = 0;

	int64_t last_indx = 0;
	while (1)
	{
		if (ptr1 == ptr2 && ptr1 == last_indx)
		{
			ptr1 += n;
			if (ptr1 <= k)
				nokrasoti++;
		}

		if (ptr1 < ptr2 && ptr1 <= k)
		{
			ptr1 += n;
			if (ptr1 <= k)
				nokrasoti++;
		}
		else if (ptr2 < ptr1 && ptr2 <= k)
		{
			ptr2 += m;
			if (ptr2 <= k)
				nolakoti++;
		}
		if ((ptr1 == ptr2) && (ptr1 < k) && (last_indx != ptr1))
		{
			last_indx = ptr1;
			neapstradati++;
			nokrasoti--;
			nolakoti--;
		}
		if (ptr1 > k && ptr2 > k)
			break;
	}

	apstradati = k - nokrasoti - nolakoti - neapstradati;

	fprintf(outfile, "%" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", apstradati, neapstradati, nolakoti, nokrasoti);
	fclose(outfile);

	return 0;
}
