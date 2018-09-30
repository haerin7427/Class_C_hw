//HW5_주어진 두 날짜(년, 월, 일 형식)간의 날짜 수를 구하는 프로그램

#include<stdio.h>

int month_date_if_same_year(int y, int m, int d) {

	int i, a, sum;
	sum = 0;

	for (i = 1; i < m; i++) {
		switch (i) {
		case 4:
		case 6:
		case 9:
		case 11:
			a = 30;
			break;

		case 2:
			if (y % 400 == 0)
				a = 29;
			else if (y % 100 == 0)
				a = 28;
			else if (y % 4 == 0)
				a = 29;
			else a = 28;
			break;

		default:
			a = 31;
			break;

		}
		sum += a;

	}
	sum += d;

	return sum;
}



int main()
{
	int y1, m1, d1, y2, m2, d2, x, y, z, r, s, a, b, c, d, e, answer;
	int first, last;

	printf("두 날짜를 지정해주세요(시간순서대로 입력해주세요) \n");
	scanf("%d %d %d %d %d %d", &y1, &m1, &d1, &y2, &m2, &d2);

	a = 0;
	c = 0;
	d = 0;
	if (y1 != y2) {
		//a
		for (x = y1 + 1; x < y2; x++) {
			if (x % 400 == 0)
				a += 366;
			else if (x % 100 == 0)
				a += 365;
			else if (x % 4 == 0)
				a += 366;
			else a += 365;
		}

		//b
		switch (m1) {
		case 4:
		case 6:
		case 9:
		case 11:
			b = 30 - d1 + 1;
			break;

		case 2:
			if (y1 % 400 == 0)
				b = 29 - m1;
			else if (y1 % 100 == 0)
				b = 28 - m1;
			else if (y1 % 4 == 0)
				b = 29 - m1;
			else b = 28 - m1;
			break;

		default:
			b = 31 - d1 + 1;
			break;
		}


		//c
		for (y = m1 + 1; y <= 12; y++) {
			switch (y) {
			case 4:
			case 6:
			case 9:
			case 11:
				z = 30;
				break;

			case 2:
				if (y1 % 400 == 0)
						z = 29;
					else if (y1 % 100 == 0)
						z = 28;
					else if (y1 % 4 == 0)
						z = 29;
					else z = 28;
					break;


			default:
				z = 31;
				break;
			}


			c += z;

		}

		//d
		for (r = 1; r <= m2 - 1; r++) {
			switch (r) {
			case 4:
			case 6:
			case 9:
			case 11:
				s = 30;
				break;

			case 2:
				if (y2 % 400 == 0)
					s = 29;
				else if (y2 % 100 == 0)
					s = 28;
				else if (y2 % 4 == 0)
					s = 29;
				else s = 28;
				break;

			default:
				s = 31;
				break;
			}

			d += s;

		}

		//e
		e = d2;
        answer = a + b + c + d + e;
		printf("%d", answer);
	}


	else if (y1 == y2) {
		first = month_date_if_same_year(y1, m1, d1);
		last = month_date_if_same_year(y2, m2, d2);
		answer = last - first+1;
		printf("%d", answer);
	}

	system("pause");
	}
