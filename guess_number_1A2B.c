#include <stdio.h>
#include <stdlib.h>

main()
{
	int answer, answer_number_sp[4];
	int guess, guess_number_sp[4];
	int guess_count = 0;
	int guess_A = 0, guess_B = 0;
	int test_A = 0, test_B = 0;
	int test_num[10000] = {0}, test_number_sp[4];
	int i, j, k, temp;
	
	scanf("%d", &answer);
	for(i = 3; i >= 0; i--){
		answer_number_sp[i] = answer % 10;
		answer /= 10;
	}
	
	for(i = 0; i < 10000; i++) {
		if((i / 1000) == 0) test_num[i] = 1;
		else if ((i / 1000) == ((i % 1000) / 100)) test_num[i] = 1;
		else if ((i /1000) == (i % 100) / 10) test_num[i] = 1;
		else if ((i / 1000) == i % 10) test_num[i] = 1;
		else if (((i % 1000) / 100) == (i % 100) / 10) test_num[i] = 1;
		else if (((i % 1000) / 100) == i % 10) test_num[i] = 1;
		else if ((i % 100) / 10 == i % 10) test_num[i] = 1;
	}
	
	for(guess_count = 1; guess_A != 4; guess_count++) {
		//printf("TEST guess_count = %d\n", guess_count);
		if (guess_count == 1) guess = 1234;
		else if (guess_count == 2) guess = 5678;
		else {
			for(i = 1234; i <= 9876 && test_num[i] == 1; i++);
			guess = i;
			//printf("%d\n", i);
		}
		for(i = 3; i >= 0; i--){
			guess_number_sp[i] = guess % 10;
			guess /= 10;
		}
		
		guess_A = 0;
		guess_B = 0;
		
		for(i = 0; i < 4; i++) {
			for(j = 0; j < 4; j++) {
				if(guess_number_sp[j] == answer_number_sp[i]) {
					if(i == j) guess_A++;
					else guess_B++;
				}
			}
		}
		
		temp = 1000 * guess_number_sp[0] + 100 * guess_number_sp[1] + 10 * guess_number_sp[2] + guess_number_sp[3];
		if(guess_A != 4) {
			test_num[temp] = 1;
		}
		else break;
		
		//printf("%d%d%d%d %dA %dB\n", guess_number_sp[0], guess_number_sp[1], guess_number_sp[2], guess_number_sp[3], guess_A, guess_B);
		
		for(k = 1234; k <= 9876; k++) {
			temp = k;
			if(test_num[k] == 0) {
				for(i = 3; i >= 0; i--){
					test_number_sp[i] = temp % 10;
					temp /= 10;
				}
				
				test_A = 0;
				test_B = 0;
				
				for(i = 0; i < 4; i++) {
					for(j = 0; j < 4; j++) {
						if(test_number_sp[j] == guess_number_sp[i]) {
							if(i == j) test_A++;
							else test_B++;
						}
					}
				}
				//printf("%d%d%d%d %dA %dB\n", test_number_sp[0], test_number_sp[1], test_number_sp[2], test_number_sp[3], test_A, test_B);
				if(test_A != guess_A || test_B != guess_B) test_num[k] = 1;
			}
		}
	}
	printf("ans = %d\n", temp);
	printf("count = %d\n", guess_count);
}
