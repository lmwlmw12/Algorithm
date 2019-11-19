#include<stdio.h>
#include<stdlib.h>
#include<string.h>



typedef struct Node{
	
	int data;
	struct Node* next;
	
}Node;

typedef struct Queue{
	
	Node* front;
	Node* rear;
	int count;
	
}Queue;

void InitQueue(Queue* queue){
	
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

int IsEmpty(Queue* queue){
	
	return queue->front == NULL;//queue->count == 0;
	
}

int size(Queue* queue){
	
	printf("%d", queue->count);
	
}

int empty(Queue* queue){
	
	if(queue->count == 0){
		printf("1");
	}
	else
	printf("0");
	
}

int push(Queue* queue, int data){
	
	Node *now = (Node *)malloc(sizeof(Node));
	now->data = data;
	now->next = NULL;
	
	if(IsEmpty(queue)){
		
		queue->front = now;
	}
	
	else{
		
		queue->rear->next = now;
	}
	queue->rear = now;
	queue->count++;
	
}

int pop(Queue* queue){
	
	int re = 0;
	Node *now;
	if(IsEmpty(queue)){
		
		return re;
	}
	
	now = queue->front;
	re = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return re;
	
}

int front(Queue* queue){
	
	Node* now;
	int num;
	if(IsEmpty(queue)){
		
		return -1;
	}
	else
	now = queue->front;
	num = now->data;
	printf("%d", num);
}

int back(Queue* queue){
	
	Node* now;
	int num;
	if(IsEmpty(queue)){
		
		return -1;
	}
	
	else
	
	now = queue->rear;
	num = now->data;
	printf("%d", num);
}
int main() {
	
	 int i;
    Queue queue;
 
    InitQueue(&queue);

    for (i = 1; i <= 5; i++)
    {
        push(&queue, i);
    }
    printf("\n");
	size(&queue);
	empty(&queue);
    front(&queue);
	back(&queue);
    printf("\n");
    return 0;
	
}
