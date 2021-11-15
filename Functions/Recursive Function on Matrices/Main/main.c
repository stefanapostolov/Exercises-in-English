/*
	
	Also implement a function that takes in input a matrix of integers
	and the coordinates of a point in the matrix, returns the number
	of connected cells of the initial point that have the same value.

	A cell in position (i,j) is connected to the initial point if, starting
	from that point, it is possible to reach (i,j), moving horizontally or
	vertically, passing only by cells that contain the same value.

	To solve the exercise it is possible to modify the matrix given in input
	and the information needed needs to be stored in a txt file.

*/

#include <stdio.h>

#define SIZE 10
#define LEN 60

int calculateCells(int mat[][SIZE], int R, int C, int r, int c);
void printMatrix(int mat[][SIZE], int R, int C);

int main(int argc, char * argv[]){

	int mat[SIZE][SIZE];
	char name[LEN+1];
	FILE * fd;
	int R, C;
	int r0, c0;
	int r, c;
	int result;

	scanf("%s", name);

	fd = fopen(name, "r");
	if(fd != NULL){
		fscanf(fd, "%d%d", &R, &C);
		for(r=0; r<R; r++){
			for(c=0; c<C; c++){
				fscanf(fd, "%d", &mat[r][c]);
			}
		}
	fscanf(fd, "%d%d", &r0, %c0);
	fclose(fd);

	result  = calculateCells(mat, R, C, r0, c0);
	printf("%d\n", result);
	} else {
		printf("File could not be opened!\n");
	} 
	
	return 0;
}

int calculateCells(int mat[][SIZE], int R, int C, int r, int c){

	int value = mat[r][c];
	int cells = 1;

	mat[r][c] = value + 3;

	printMatrix(mat, R, C);

	if( r - 1 >= 0 && mat[r + 1][c] == value){
		cells += calculateCells(mat, R, C, r-1, c);
	}

	if( r + 1 < R && mat[r + 1][c] == value){
		cells += calculateCells(mat, R, C, r+1, c);
	}

	if(c - 1 >= 0 && mat[r][c - 1] == value){
		cells += calculateCells(mat, R, C, r, c - 1);
	}

	if(c + 1 < C && mat[r][c + 1] == value){
		cells += calculateCells(mat, R, C, r, c + 1);
	}

	return cells;
}

void printMatrix(int mat[][SIZE], int R, int C){
	int i, j;

	for(i=0; i<R; i++){
		for(j=0; j<C; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");  
}
