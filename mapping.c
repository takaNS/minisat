#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {

	int n = atoi(argv[1]);
	FILE *fp;
	int queens;

	fp = fopen("queenN.txt","r");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			fscanf(fp ,"%d",&queens);
			if (queens > 0) {
				printf("Q ");
			}else{
				printf("- ");
			}
		}
		printf("\n");
	}

	return 0;
}
