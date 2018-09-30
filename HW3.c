//HW3_2보다 큰 양의 n이 주어졌을 때, 2부터 n까지의 정수 중 소수를 모두 찾는 프로그램을 작성하시오.

#include <stdio.h>

int main() {
	int i,n, d, count;

	printf("2보다 큰 양의 정수 n을 입력하시오 : ");
	scanf("%d",&n);
	printf("2와 %d 사이의 소수 \n",n);

    d = 2;

	while (d <= n) {

    count = 0;
	i = 2;

		while (i < d) {
			if (d%i == 0) {
			count++;
		}   i++;
	     }

		if (count == 0)
			printf("%d \n", d);

		 d++;
	}

	system("pause");
}
