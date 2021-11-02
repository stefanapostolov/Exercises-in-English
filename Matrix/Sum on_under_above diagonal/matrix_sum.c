/*

	The program takes in input a square matrix which dimension 
	is given by the user (max 10 lines and 10 columns). Then proceeds
	to calculate the sum of the numbers on its diagonal, the sum of the
	numbers under the diagonal and the sum of the numbers above the diagonal

*/

#include <stdio.h>

#define M 10
#define N 10

int main(int argc, char * argv[])
{

	int lines, columns;
	float matrix[M][N];
	int i,j;
	float sumDiagonal, sumUnderDiagonal, sumAboveDiagonal;
	int minDimension;

	do{
		printf("Insert the number of lines:\n");
		scanf("%d", &lines);
		if(!(lines > 0 && lines <= 10)){
			printf("The number of lines is invalid. Try again!\n");
		}
	} while(!(lines > 0 && lines <= 10));

	do{
		printf("Insert the number of columns:\n");
		scanf("%d", &columns);
		if(!(columns > 0 && columns <= 10)){
			printf("The number of columns is invalid. Try again!\n");
		}
	} while(!(columns > 0 && columns <= 10));

	if(lines < columns){
		minDimension = lines;
	} else {
		minDimension = columns;
	}

	for(i=0; i<lines; i++){
		for(j=0; j<columns; j++){
			printf("Insert the value of line %d and columns %d:\n", i+1, j+1);
			scanf("%f", &matrix[i][j]);
		}
	}
	printf("\n");

	for(i=0; i<lines; i++){
		for(j=0; j<columns; j++){
			printf("%3f ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	sumDiagonal = 0;
	sumAboveDiagonal = 0;
	sumUnderDiagonal = 0;	

	for(i=0; i<minDimension; i++){
		sumDiagonal += matrix[i][i];
		if(i+1<columns)
			sumAboveDiagonal += matrix[i][i+1];
		if(i+1<lines)
			sumUnderDiagonal += matrix[i+1][i];

	}

	printf("The sum on the diagonal is: %f\n", sumDiagonal);
	printf("\n");
	printf("The sum under the diagonal is: %f\n", sumUnderDiagonal);
	printf("\n");
	printf("The sum above the diagonal is: %f\n", sumAboveDiagonal);
	printf("\n");

	return 0;
}
