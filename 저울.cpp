#define MAX 101
#include <stdio.h>
#include <algorithm>

short arr[MAX][MAX];
void myFunction(short arr[][MAX], int num){
	for(int i=1; i<=num; i++){
		for(int j=1; j<=num; j++){
			for(int k=1; k<=num; k++){
				if(arr[i][j] && arr[j][k]){
					arr[i][k] = 1;
				}
			}
		}
	}
}
int main(int argc, char *argv[])
{
	freopen("input.txt", "r", stdin);
	int result= 0;
	int num;	scanf("%d", &num);
	int cnt;	scanf("%d", &cnt);
	for(int i=0; i< cnt; i++){
		int a, b;	scanf("%d %d", &a, &b);
		arr[a][b] = 1;
	}
	myFunction(arr, num);
	for(int i=1; i<=num; i++){
		result= 0;
		for(int j=1; j<=num; j++){
			if(arr[i][j]==0 &&arr[j][i]==0)
				result++;
		}
		printf("%d\n", result-1);
	}
	return 0;
}
