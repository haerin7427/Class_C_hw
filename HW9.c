/*HW9_<전화번호 관리 program>
1. 새로운 번호 추가 (단, 중복되는 번호일 경우 추가하지 않는다.)
2. 번호 삭제 (단, 없는 번호인지 확인해야 한다.)
3. 이름으로 번호 조회
4. 번호로 이름 조회
5. 종료
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100   //저장할 수 있는 연락처 개수

void add_number(struct number_list *p);
void delate_number(struct number_list *p);
void search_name(struct number_list *p);
void search_number(struct number_list *p);

struct number_list
{
	char name[20];
	char number[20];
};

int main(void) {
	struct number_list numb[SIZE] = { { "홍길동","010-1234-5678" } };
	int n;
	printf("전화번호 관리 program - 기존에 저장되어 있는 연락처 1개를 포함하여 100개의 연락처 저장 가능\n");
	while (1) {
		printf("[메뉴] 원하는 기능에 해당하는 번호를 입력하세요.\n1. 새로운 번호 추가\n2. 번호 삭제\n3. 이름으로 번호 조회\n4. 번호로 이름 조회\n5. 종료\n");
		scanf("%d", &n);

		if (n == 1) {
			add_number(numb);    /*새로운 번호 추가*/
		}
		else if (n == 2) {
			delate_number(numb);    /*기존 번호 삭제*/
		}
		else if (n == 3) {
			search_name(numb);  /*이름으로 번호 조회하기*/
		}
		else if (n == 4) {
			search_number(numb);  /*번호로 이름 조회하기*/
		}
		else
			break;
	}

}

/*1. 새로운 번호 추가(만약 이미 있는 번호일 경우 추가하지 않는다.)*/
void add_number(struct number_list *p) {
	struct number_list *q = p;
	char new_number[20];
	int a = 0, h = 0;

	printf("추가하고 싶은 번호를 입력하세요\n(번호는 000-0000-0000 형식으로 입력하세요)\n");
	scanf("%s", new_number);

	//중복 검사 단계(중간 부분이 삭제되는 경우도 있기 때문에 중복검사는 배열끝까지 돌려야한다
	while (h < SIZE) {
		if (strcmp((q + h)->number, new_number) == 0) {
			a = 0;
			break;
		}
		else
			a = 1;
		h++;
	}

	/*중복 검사결과에 따른 처리*/
	if (a == 0)
		printf("<<이미 존재하는 번호입니다.>>\n");
	else {
		while ((*q).name[0] != '\0')
			q++;
		strcpy(q->number, new_number);
		printf("추가된 번호에 해당하는 이름을 적어주세요.\n");
		scanf("%s", q->name);
	}
}
/*2. 기존 번호 삭제하기(만약 없는 번호일 경우 지우지 않는다)*/
void delate_number(struct number_list *p) {
	struct number_list *q = p;
	char d_number[20];
	int a = 0, h = 0;

	printf("삭제하고 싶은 번호를 입력하세요\n(번호는 000-0000-0000 형식으로 입력하세요)\n");
	scanf("%s", d_number);
	/*삭제하고 싶은 번호가 기존 연락처에 존재여부를 확인하는 과정*/
	while (h < SIZE) {
		if (strcmp((q + h)->number, d_number) == 0) {
			a = 0;
			break;
		}
		else
			a = 1;
		h++;
	}
	/*위 결과에 따른 처리*/
	if (a == 0) {
		strcpy((q + h)->name, "\0");
		strcpy((q + h)->number, "\0");
		printf("<<삭제되었습니다.>>\n");
	}
	else
		printf("<<없는 번호입니다.>>\n");
}
/*3. 이름으로 번호 조회하기*/
void search_name(struct number_list *p) {
	struct number_list *q = p;
	char sname[20];
	int a = 0, h = 0, count = 0, i;

	printf("조회하고 싶은 이름을 입력하세요.\n");
	scanf("%s", sname);

	/*이름 조회*/
	while (h < SIZE) {
		if (strcmp((q + h)->name, sname) == 0) {
			a = 0;
			/*동일한 이름의 존재 여부 확인*/
			for (i = 0; i < SIZE; i++)
				if (strcmp((q + i)->name, sname) == 0) {
					count++;
				}
			break;
		}
		else
			a = 1;
		h++;
	}

	/*이름 조회 결과*/
	if (a == 0) {
		if (count != 1) {
			printf("<<동일한 이름을 가진 번호가 %d개 있습니다.>>\n", count);
			for (i = 0; i < SIZE; i++)
				if (strcmp((q + i)->name, sname) == 0) {
					printf("<<번호는 %s 입니다.>>\n", (q + i)->number);
				}
			h++;
		}
		else
			printf("<<번호는 %s 입니다.>>\n", (q + h)->number);
	}
	else
		printf("<<해당하는 번호가 존재하지 않습니다.>>\n");
}
/*4. 번호로 이름 조회하기*/
void search_number(struct number_list *p) {
	struct number_list *q = p;
	char snumber[20];
	int a = 0, h = 0;

	printf("조회하고 싶은 번호를 입력하세요.\n(번호는 000-0000-0000 형식으로 입력하세요)\n");
	scanf("%s", snumber);

	/*번호 조회*/
	while (h < SIZE) {
		if (strcmp((q + h)->number, snumber) == 0) {
			a = 0;
			break;
		}
		else
			a = 1;
		h++;
	}

	/*번호 조회 결과*/
	if (a == 0)
		printf("<<해당하는 이름은 %s 입니다.>>\n", (q + h)->name);
	else
		printf("<<해당하는 이름이 존재하지 않습니다.>>\n");
}
