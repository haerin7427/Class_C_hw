//HW4_1일의 요일과 그 달의 날짜 수를 입력받아 달력을 그려라.

#include<stdio.h>

int main()
{
	int start, date, i;
	printf("1일의 요일과 그 달의 날짜 수를 순서대로 입력하시오: \n (sun=0,mon=1,tue=2,wed=3,thu=4,fri=5,sat=6) \n");
	scanf("%d %d", &start, &date);

	printf(" sun mon tue wed thu fri sat \n");
	for (i = 1; i <= date + start; i++) {
		if (i <= start)
			continue;

		if (i == start+1 ) {
			if(start==0)
                printf("%4d",i-start);
			else if(start == 1)
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
		else printf("%4d", i-start);

		if ((i - start) % 7 == 7 - start)
			printf("\n");

		else if (start == 0) {
			if ((i - start) % 7 == 0)
				printf("\n");
		}


	}
	system("pause");
}
