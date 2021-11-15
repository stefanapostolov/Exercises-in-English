/*

	Implement a program that takes in input the name of
	a txt file (max of 80 char, including extension and 
	directory information).
	The program prints the number of numerical values
	that are contained in the file. For example:

	I --> a a a 231 32 1 d a s d 4 5	   O --> 5

*/

#include <stdio.h>

#define LEN 80
#define ZERO '0'
#define NINE '9'

int main(int argc, char * argv[]){

	FILE * f;
	char name[LEN+1];
	int count, isNumber;
	char v;

	scanf("%s", name);

	f = fopen(name, "r");
	if(f){
		count = 0;
		isNumber = 0;
		while(fscanf(f, "%c", &v) != EOF){
			if(isNumber == 1 && (v < ZERO || v > NOVE)){
				isNumber = 0;
				count++;
			} else if(isNumber == 0 && (v >= ZERO && v <= NOVE)) {
				isNumber = 1;
			}
		}
		fclose(f);

		count += isNumber;
		printf("%d", count);
	} else {
		printf("File could not be opened\n");
	}

}

