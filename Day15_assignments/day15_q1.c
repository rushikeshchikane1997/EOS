#include<stdio.h>
#include<pthread.h>
#include <unistd.h>


void* selection_sort(void* arg) {
	int* arr = (int*)arg;
	int n = 5; // array size 5
	for (int i = 0; i < n-1; i++) {
		int min_idx = i;
		for (int j = i+1; j < n; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
	pthread_exit(NULL);
}
int main() {
	pthread_t th;
	int i ,ret;

	int arr[5] = {12,10,9,8,3};
	ret = pthread_create(&th,NULL,selection_sort,arr);
	if(ret < 0) {
		perror("pthread_create() failed");
		_exit(0);
	}
	printf("array sorted");
	for(int i =0; i<=5; i++)
	{
		printf("%d\n",arr[i]);

	}



	return 0;
}





































