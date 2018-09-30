/*HW8_string의 array를 구성하고 이를 sort하는 프로그램*/

#include <stdio.h>
#include <string.h>
#define SIZE 20
#define N 10

char find_max_element(char a[][SIZE], int b);
void swap_two_element(char x[][SIZE], int y, int z);

int main() {
	char string_data[N][SIZE] = { "school","7427", "one", "Noodle", "hand", "english", "korea", "apple", "peach", "strawverry" };
	int i, h, k;

	for (i = 9; i >= 0; i--) {
		k=find_max_element(string_data, i);
		swap_two_element(string_data, k, i);
	}
	for (h = 0; h < N; h++) {
		printf(" %s ", string_data[h]);
	}
	system("pause");
}

char find_max_element(char a[][SIZE], int b) {
	int i, count = 0;
	char max[SIZE];
	strcpy(max, a[0]);

	for (i = 0; i <= b; i++) {
		if (strcmp(a[i], max)> 0) {
			strcpy(max, a[i]);
			count = i;
		}
	}
	return count;

}
void swap_two_element(char x[][SIZE], int y, int z) {
	char temp[SIZE];
	strcpy(temp, x[z]);
	strcpy(x[z], x[y]);
	strcpy(x[y], temp);
}
