#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float* create_arr(int arr_size) {
	float* arr = (float*)malloc((arr_size+1) * sizeof(float));
	arr[0] = arr_size;
	for (int i = 1; i < arr_size+1; i++) {
		printf("arr[%d] = ", i-1);
		scanf_s("%f", &arr[i]);
	}
	return arr;
}
float* remove_el(float* arr, int arr_size) {
	int i, j, q, count_null = 0;
	for (i = 1, j = 2, q = 3; q < arr_size+1; i++, j++, q++) {
		if (arr[i] < 0 && arr[j] > 0 && arr[q] < 0) {
			arr[j] = -1*pow(10, 10);
			count_null += 1; 
		}
	}
	for (i = 1; i < arr_size+1; i++) {
		for (j = 1; j < arr_size - i+1; j++) {
			if (arr[j] == -1*pow(10, 10)) {
				float tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	arr[0] = arr_size - count_null;
	arr = (float*)realloc(arr, (arr_size - count_null+1) * sizeof(float));
	
	return arr;
}
void output_arr(float* a, int arr_size) {
	printf("[");
	for (int i = 1; i < arr_size+1; i++) {
		printf("%.2f,", a[i]);
	}
	printf("]\n");
}
void main() {
	float arr_size; 
	printf("Input array size: ");
	scanf_s("%f", &arr_size);
	if (arr_size > 0 && floor(arr_size) == arr_size) {
		float* arr = create_arr(arr_size); 
		output_arr(arr, arr_size); 
		arr = remove_el(arr, arr_size);
		arr_size = (int)arr[0];  
		output_arr(arr, arr_size); 
		free(arr); 
	}
	else {
		printf("\nERROR\n");
	}
}
