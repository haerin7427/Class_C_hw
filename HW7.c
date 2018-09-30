/*HW7_n*n 크기의 magic square*/

#include <stdio.h>

void magic_square(int n);

int main() {
	int n;
	printf("마방진 만들기: 2보다 크고 100보다 작은 홀수를 입력하시오\n");
    scanf("%d", &n);
	magic_square(n);

	system("pause");
}

void magic_square(int n) {
	int i, k, h;
	int x, y;
	int a[100][100] = { 0 };
	x = 0;
	y = n / 2;

	for (h = 1; h <= n*n; h++) {
		if (h == 1)
			a[x][y] = 1; //시작점
		else {
			x--;
			y--;

			if (x < 0)
				x += n;
			if (y < 0)
				y += n;

			if (a[x][y] != 0) {
					x += 2;
					y += 1;
			}
			if (x >= n || y >= n) {
				x -= n;
				y -= n;
			}
			a[x][y] = h;

		}
	}
    for (i = 0; i < n; i++) {
		for (k = 0; k < n; k++) {
			printf("%5d", a[i][k]);
			if (k == n - 1)
				printf("\n");
		}
	}

}
