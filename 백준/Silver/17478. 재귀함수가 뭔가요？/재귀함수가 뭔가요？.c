#include <stdio.h>


int j = 1;


void line(int num) { //num 은 1부터 시작

	for (int i = 1; i <= 4 * num; i++) {

		printf("_");

	}

}
void rago(int num) {
	for (int i = 1; i <= num; i++) {
		line(j - i);
		printf("라고 답변하였지.\n");
	}
	
}
void f(int n) {

	if (n == 1)
	{
		line(j);
		printf("\"재귀함수가 뭔가요?\"\n");
		line(j);
		printf("\"재귀함수는 자기 자신을 호출하는 함수라네\"\n");
		line(j);
		printf("라고 답변하였지.\n");
		//라고 재귀
		rago(j);
		return;
	}
	else {
		line(j);
		printf("\"재귀함수가 뭔가요?\"\n");
		line(j);
		printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
		line(j);
		printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
		line(j);
		printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	}
	j++;
	if (n > 1)
		f(--n);

}

int main() {


	int nn;

	scanf("%d", &nn);

	printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	printf("\"재귀함수가 뭔가요?\"\n");
	printf("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n");
	printf("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n");
	printf("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n");
	f(nn);
	return 0;
}