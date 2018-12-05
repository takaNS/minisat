#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

	int n = atoi(argv[1]);

	printf("p cnf %d\n", n*n);
	int RL[n][n];
	int m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m = m + 1;
			RL[i][j] = m;
			printf("%6d", RL[i][j]);
		}
	printf("%6d\n", 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%6d", RL[j][i]);
		}
	printf("%6d\n", 0);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				printf("%6d%6d%6d\n", RL[i][j]*(-1), RL[i][k]*(-1), 0);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = j+1; k < n; k++) {
				printf("%6d%6d%6d\n", RL[j][i]*(-1), RL[k][i]*(-1), 0);
			}
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int k = 0; k < n - i; k++) {
				printf("%6d%6d%6d\n", RL[j][k]*(-1), RL[j+i][k+i]*(-1), 0);
			}
		}
	}
	m = 0;
	for (int i = 0; i < n; i++) {
		for (int j = n; j > 0; j--) {
			m = m + 1;
			RL[i][j-1] = m;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			for (int k = 0; k < n - i; k++) {
				printf("%6d%6d%6d\n", RL[j][k]*(-1), RL[j+i][k+i]*(-1), 0);
			}
		}
	}

	return 0;
}
