#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	
	int data;
	struct Node* prev;
	struct Node* next;
	
}Node;

typedef struct Deque {
	
	Node* front;
	Node* rear;
	int count;
	
}Deque;

int InitDeque(Deque *deque) {
	
	deque->front = NULL;
	deque->rear = NULL;
	deque->count = 0;
}

int IsEmpty(Deque *deque) {
	
	return deque->count == 0;
}

int empty(Deque *deque) {
	
	if(deque->count == 0) {
		printf("1");
	}
	else 
		printf("0");
	
}

int size(Deque *deque) {
	printf("%d", deque->count);
}

int push_front(Deque *deque, int data) {
	
	Node *now = (Node *)malloc(sizeof(Node));
	
	if(IsEmpty(deque)) {
		
		deque->front = now;
		deque->rear = now;
		now->data = data;
		now->next = NULL;
		now->prev = NULL;
		//return;
	}
	
	deque->front->prev = now;
	now->next = deque->front;
	deque->front = now;
	now->data = data;
	now->prev = NULL;	
	deque->count++;
	
}

int push_back(Deque *deque, int data) {
	
	Node *now = (Node *)malloc(sizeof(Node));
	
	
	if(IsEmpty(deque)) {
		deque->front = now;
		deque->rear = now;
		now->data = data;
		now->next = NULL;
		now->prev = NULL;
		//return;
	}
	
	deque->rear->next = now;
	now->prev = deque->rear;
	deque->rear = now;
	now->data = data;
	now->next = NULL;
	deque->count++;

}

int pop_front(Deque *deque) {

	int re = -1;
	Node *now;
	if(IsEmpty(deque)) {
		
		return re;
		
	}
	
	now = deque->front;
	re = now->data;
	deque->front = now->next;
	free(now);
	deque->count--;
	return re;
		
}

int pop_back(Deque *deque) {
	
	int re = -1;
	Node *now;
	if(IsEmpty(deque)) {
		
		return re;
	}
	
	now = deque->rear;
	re = now->data;
	deque->rear = now->next;
	free(now);
	deque->count--;
	return re;
	
}

int front_(Deque *deque) {
	
	if(IsEmpty(deque)) {
		
		return -1;
		
	}
	
	Node *now;
	int re;
	now = deque->front;
	re = now->data;
	printf("%d", re);
	return re;
}

int back_(Deque *deque) {
	
	if(IsEmpty(deque)) {
		
		return -1;
		
	}
	
	Node *now;
	int re;
	now = deque->rear;
	re = now->data;
	printf("%d", re);
	return re;
}

int main() {
	
	
	Deque deque;
	
	InitDeque(&deque);
	
	push_front(&deque, 10);
	push_back(&deque, 15);
	//push_front(&deque, 12);
	
	front_(&deque);
	back_(&deque);
	return 0; 
	
	
}
