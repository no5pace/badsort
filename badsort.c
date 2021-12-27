#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int array(int val, int num, int arr[], int arr2[]) {
	switch(val) {
		case 1:
			for (int i = 0; i < num; i++) {
				printf("%d ", arr[i]);
			}
			printf("\n");
			break;
		case 2:
			for (int i = 0; i < num; i++) {
				if (arr[i] != arr2[i]) {
					return 1;
				}
			}
			break;
		case 3:
			for (int i = 0; i < num; i++) {
				arr2[i] = arr[i];
			}
			break;
		default:
			break;
	}

	return 0;
}

int main() {
	srand(time(0));

	//variables
	int num, max, temp, verbose;
	float start, end, time;
	printf("number of items: ");
	scanf("%d", &num);
	printf("max value of items: ");
	scanf("%d", &max);
	printf("verbose mode (0 for no, 1 for yes): ");
	scanf("%d", &verbose);

	int arr[num];
	int arr2[num];

	for (int i = 0; i < num; i++) {
		arr[i] = (rand() % max) + 1;
	}

	// start benchmark
	start = (float)clock()/CLOCKS_PER_SEC;

	while (1) {
		// checks
		if (array(2, num, arr, arr2) == 0) {
			break;
		} else {
			array(3, num, arr, arr2);
		}

		// before
		if (verbose == 1) {
			array(1, num, arr, arr2);
		}
		
		// do the actual sorting
		for (int i = 0; i < num; i++) {
			if (i != 0) {
				if (arr[i] < arr[i-1]) {
					temp = arr[i];
					arr[i] = arr[i-1];
					arr[i-1] = temp;
				}
			} else if (i != num-1) {
				if (arr[i] > arr[i+1]) {
					temp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = temp;
				}
			}
		}
	}

	// end benchmark
	end = (float)clock()/CLOCKS_PER_SEC;
	time = end - start;
	printf("Time Elapsed: %f", time);

	return 0;
}
