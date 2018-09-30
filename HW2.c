//HW2_주어진 두개의 정수의 최대공약수를 구하는 프로그램을 작성하시오.

#include <stdio.h>

int main()
{
	int n, m, a;

	printf("두 정수를 입력하시오 ");
	scanf("%d%d", &n, &m);

	if (n > m) {

		for (a = m; 0 < a <= m; a--) {
			if ((n % a == 0) && (m%a == 0)) {
				printf("n과 m의  최대공약수 %d \n", a);
				break;
			}
		}
	}

	if(n < m) {

		for (a = n; 0 < a <= n; a--) {
			if ((n % a == 0) && (m%a == 0)) {
				printf("n과 m의  최대공약수 %d \n", a);
				break;
			}
		}
	}

	if (m == n) {
		a == m ==n;
		printf("최대공약수는 %d", a);
	}

	system("pause");
}
