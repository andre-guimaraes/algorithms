#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintArray(int* data, size_t data_size){
	for(int i = 0; i < data_size; i++){
		printf("%d", data[i]);
	}
	printf("\n");
}

void Merge(int* array_1, size_t array_1_size, int* array_2, size_t array_2_size, int* sorted_array, size_t sorted_array_size){
	int i = 0;
	int j = 0;
	int k = 0;

	for(; k<sorted_array_size; k++){
		if(i == (array_1_size) && (i > j)){
			sorted_array[k] = array_2[j];
			j++;
		} else if(j == (array_2_size) && (j > i)){
			sorted_array[k] = array_1[i];
			i++;
		} else if(array_1[i] < array_2[j]){
			sorted_array[k] = array_1[i];
			i++;
		} else {
			sorted_array[k] = array_2[j];
			j++;
		}
	}
}

int* MergeSort(int* unsorted_array, size_t unsorted_array_size){
	if(unsorted_array_size == 1){
		return unsorted_array;
	}

	int* array_1 = unsorted_array;
	int* array_2 = unsorted_array+(unsorted_array_size/2);

	int* sorted_array_1 = MergeSort(array_1, unsorted_array_size/2);
	int* sorted_array_2 = MergeSort(array_2, unsorted_array_size/2);

	int* sorted_array = malloc(sizeof(int)*unsorted_array_size);
	Merge(sorted_array_1, unsorted_array_size/2, sorted_array_2, unsorted_array_size/2, sorted_array, unsorted_array_size);
	
	memcpy(unsorted_array, sorted_array, sizeof(int)*unsorted_array_size);
	free(sorted_array);

	return unsorted_array;

	//This will eventually count all the inversions
}

int main () {
	int unsorted_array[8] = {3, 8, 2, 2, 2, 7, 6, 4};
	PrintArray(unsorted_array, 8);
	
	printf("SORT!\n");
	
	MergeSort(unsorted_array, 8);
	PrintArray(unsorted_array, 8);
	
	return 0;
}