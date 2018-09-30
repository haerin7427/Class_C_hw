//HW1_점수를 입력받아, 해당 학점을 출력하시오.

#include <stdio.h>

int main()
{
	int x;
	printf("점수를 입력하시오 : ");
	scanf("%d", &x);
	printf("학점은 :");

	if ((89<x) && (x<101))
		printf("A\n");
	else if ((79<x) && (x<90))
		printf("B\n");
	else if ((69<x) && (x<80))
		printf("C\n");
	else if ((59<x) && (x<70))
		printf("D\n");
	else if (x<60)
		printf("F\n");
	system("pause");
}
