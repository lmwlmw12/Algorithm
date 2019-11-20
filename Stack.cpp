#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	
	int data;
	struct Node* next;
	struct Node* prev;
	
}Node;

typedef struct Stack {
	
	Node* front;
	Node* rear;
	int count;
}Stack;

void InitStack(Stack *stack) {
	
	stack->front = NULL;
	stack->rear = NULL;
	stack->count = 0;
}

int push(Stack *stack, int data) {
	
	Node *now = (Node *)malloc(sizeof(Node));
	
	
	if(stack->count == 0) {
		
		 stack->front = now;
		 stack->rear = now;
		 now->data = data;
		 now->next = NULL;
		 now->prev = NULL;
		 
	}
	else {
		
		stack->rear->next = now;
		now->prev = stack->rear;
		stack->rear = now;
		now->data = data;
		now->next = NULL;
		
	}
	
	
	stack->count++;
}

int pop(Stack *stack) {
	
	int re = 0;
	Node *now;
	if(stack->count == 0) {
		
		return re;
		
	}
	
	now = stack->rear;
	re = now->data;
	stack->rear = now->prev;
	free(now);
	stack->count--;
	return re;
}

int size(Stack *stack) {
	printf("%d\n", stack->count);
	
}

int empty(Stack *stack) {
	if(stack->count == 0) {
		printf("1\n");
	}
	else
	printf("0\n");
	
}

int top(Stack *stack) {
	if(stack->count == 0) {
		printf("-1\n");
	}
	else {
	
	Node *now;
	int re;
	
	now = stack->rear;
	re = now->data;
	printf("%d\n", re);
	}
}

int main() {
	
	int N, num;
	Stack stack;
	scanf("%d", &N);
	//fgetc(stdin);
	InitStack(&stack);
	
	char order[10];
	while(N>0) {
		
		scanf("%s", &order);
		//fgetc(stdin);
		
		if(!strcmp(order, "push")) {
			
			printf("들어갈 수입력");
			scanf("%d", &num);
			//fgetc(stdin);
			push(&stack, num);
		}
		else if(!strcmp(order, "pop")) {
			printf("삭제\n"); 
			pop(&stack);
		}
		else if(!strcmp(order, "empty")) {
			
			empty(&stack);
		}
		else if(!strcmp(order, "size")) {
			
			size(&stack);
		}
		else if(!strcmp(order, "top")) {
			
			top(&stack);
		}
		
		
		N--;
		
	}
}
