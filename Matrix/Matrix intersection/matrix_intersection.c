/*

	The program asks the user to insert a matrix with m lines and n columns
	(m and n must be <= 10). Then asks the user how many lines and how many
	columns should be selected, proceeding to identify those lines by input.

	In output the program gives another matrix B, that contains the intersection
	of the lines and columns. It's clear that the smallest of the n_of_columns
	and n_of_lines selected will be the number of columns of the new matrix B

	Example:

	m and r are both 3;

	  	0.0  7.0  4.0 
                     
	        1.0  5.0  3.0     --> the users selects 1 column and 2 lines (line 1 and 3 and column 1)
                    
	  	1.0  4.0  6.0 
------------------------------------------------------------------------------------------------

		0.0  
			          --> Matrix B
		1.0  

*/

#include <stdio.h>

#define MAX_VALUE 10

int main()
{
	float A[MAX_VALUE][MAX_VALUE], B[MAX_VALUE][MAX_VALUE];
	int r_A, c_A, r_B, c_B, lines[MAX_VALUE], col[MAX_VALUE],i,j;
 
	printf("Insert the number of lines of A:\n");
	scanf("%d",&r_A);
	printf("Insert the number of columns of A:\n");
	scanf("%d",&c_A);
 
	for (i=0; i<r_A; i++){
		for (j=0; j<c_A; j++){
			printf("Line number %d, column number %d: \n", i+1, j+1);
			scanf("%f",&A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
 
	printf("Insert the number of lines of B: \n");
	scanf("%d",&r_B);
	printf("Insert the number of columns of B: \n");
	scanf("%d",&c_B);
 
	printf("Which lines do you want (you need to select %d)?",r_B);
	for (i=0; i<r_B; i++)
		scanf("%d",&lines[i]);
	printf("Which columns do you want (you need to select %d)?",c_B);
	for (i=0; i<c_B; i++)
		scanf("%d",&col[i]);
 
	for (i=0; i<r_B; i++)
		for (j=0; j<c_B; j++)
			B[i][j] = A[lines[i]][col[j]];
 
	printf("\n****** B *****\n");
	for (i=0; i<r_B; i++)
	{
		for (j=0; j<c_B; j++)
			printf("%f ",B[i][j]);
		printf("\n");
	}
 
	return 0;
}
