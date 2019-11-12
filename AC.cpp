#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100000;


void Revolve(int arr[]) {
	int arr_two[sizeof(arr)/sizeof(int)];
	printf("%d ", sizeof(arr));
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		arr_two[(sizeof(arr)/sizeof(int))-i-1] = arr[i];
		printf("%d ", arr_two[sizeof(arr)/sizeof(int)-i-1]);
	}

	for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		arr[i] = arr_two[i];
	}
}

int delete_(int arr[]) {

	for(int i = 0; i < sizeof(arr)/sizeof(int); i++) {
		arr[i] = arr[i+1];
	}
	arr[sizeof(arr)/sizeof(int)] = NULL;
}

int main() {
	
	int T;
	int num;
	char R, D;
	
	
	scanf("%d", &T);
	while(T>10) {
		printf("10 이하만 가능");
		scanf("%d", &T);
	}
	while(T>0) {
		scanf("%s", &R);
		scanf("%d", &num);
		int arr[num];
		for(int i = 0; i < num; i++) {
			scanf("%d", &arr[i]);
		}
		
		Revolve(arr);		
		
		T--;
	}	
}
