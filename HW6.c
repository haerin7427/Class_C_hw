//HW6_임의로 주어진 년, 월, 일에 해당하는 달력 출력

#include <stdio.h>

int start_day(int y, int m, int d) {
	int i, a, b, c, h, x, t, r, dates, start;
	a = 0;
	b = 0;

	if (m == 1 && y == 1900)
		start = 1;

	else {

		if (y == 1900)
			a = 0, b = 0;

		else {
			for (i = 1900; i < y; i++) {
				if (i % 400 == 0)
					a++;
				else if (i % 100 == 0)
					b++;
				else if (i % 4 == 0)
					a++;
				else b++;
			}
		}

		x = 0;
		t = 0;
		r = 0;

		for (h = 1; h < m; h++) {

			switch (h) {
			case 4:
			case 6:
			case 9:
			case 11:
				x++;
				break;

			case 2:
				if (y % 400 == 0)
					r = 29;
				else if (y % 100 == 0)
					r = 28;
				else if (y % 4 == 0)
					r = 29;
				else r = 28;
				break;

			default:
				t++;
				break;
			}

		}

		c = (30 * x) + (31 * t) + r;


		dates = (a * 366) + (b * 365) + c;
		start = (dates % 7) + 1;

		if (start == 7)
			start = 0;

	}

	return start;
}


int main()
{
	int y, m, d, start,date, i;
	printf("1900년 대 이후로 보고싶은 달력의 년,월,일 을 입력하세요 \n");
	scanf("%d %d %d", &y, &m, &d);

	printf(" sun mon tue wed thu fri sat\n");
	start = start_day(y, m, d);

	switch (m) {
	case 4:
	case 6:
	case 9:
	case 11:
		date = 30;
		break;

	case 2:
		if (y % 400 == 0)
			date = 29;
		else if (y % 100 == 0)
			date = 28;
		else if (y % 4 == 0)
			date = 29;
		else date = 28;
		break;

	default:
		date = 31;
		break;
	}

	for (i = 1; i <= date + start; i++) {
		if (i <= start)
			continue;

		if (i == start + 1) {
			if (start == 0)
				printf("%4d", i - start);
			else if (start == 1)
				printf("%8d", i - start);
			else if (start == 2)
				printf("%12d", i - start);
			else if (start == 3)
				printf("%16d", i - start);
			else if (start == 4)
				printf("%20d", i - start);
			else if (start == 5)
				printf("%24d", i - start);
			else if (start == 6)
				printf("%28d", i - start);
		}
		else printf("%4d", i - start);

		if ((i - start) % 7 == 7 - start)
			printf("\n");

		else if (start == 0) {
			if ((i - start) % 7 == 0)
				printf("\n");
		}
	}
	system("pause");
}
