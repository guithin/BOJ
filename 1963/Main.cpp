#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

typedef struct patientData {
	char name[36];
}patientData;

#define queueType patientData

typedef struct queue {
	int sp, ep, alsz, full;
	patientData *arr;
}queue;

void init(queue* que, int sz) {
	que->sp = 0; que->ep = 0; que->full = 0;
	que->arr = malloc(sizeof(patientData)*sz);
	que->alsz = sz;
}

int size(queue* que) {
	if (que->full)return que->alsz;
	return (que->ep - que->sp + que->alsz) % que->alsz;
}

void push(queue* que, patientData val) {
	que->arr[que->ep++] = val;
	(que->ep) %= que->alsz;
	if (que->ep == que->sp)
		que->full = 1;
}

void pop(queue* que) {
	if (que->sp == que->ep)que->full = 0;
	que->sp++;
	(que->sp) %= que->alsz;
}

patientData front(queue* que) {
	return que->arr[que->sp];
}

int main() {
	queue *patientQ = malloc(sizeof(queue));
	init(patientQ, MAX_SIZE);
	while (1) {
		printf("원하시는 서비스를 입력해주세요.\n");
		printf("병원 도착: 1\n진료 완료: 2\n서비스 종료: 3\n");
		int service;
		scanf("%d", &service);
		if (service == 3) {
			printf("안녕히 가십시오.\n");
			return 0;
		}
		if (service == 1) {
			if (size(patientQ) == MAX_SIZE) {
				printf("Service not available.\n");
				continue;
			}
			printf("대기자 명단에 등록하시겟습니까? yes/no (현재 대기 인원: %d)\n", size(patientQ));
			char buf[5];
			scanf("%s", buf);
			if (buf[0] == 'y') {
				patientData inp;
				printf("이름을 입력해 주세요: ");
				scanf("%s", inp.name);
				push(patientQ, inp);
			}
			else {
				continue;
			}
		}
		else if (service == 2) {
			if (size(patientQ)) {
				pop(patientQ);
			}
			if (size(patientQ)) {
				printf("다음 환자분 성함: %s\n", front(patientQ).name);
			}
			else {
				printf("There is no patient waiting.\n");
			}
		}
	}
	return 0;
}