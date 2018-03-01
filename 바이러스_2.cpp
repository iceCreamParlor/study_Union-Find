#include <stdio.h>
#include <queue>
#include <algorithm>
#define MAX 101

int arr[MAX][MAX];
int check[MAX];
int num, cnt;
std::queue<int> q;
using namespace std;

void bfs(){
	while( !q.empty() ){
		int now = q.front();
		q.pop();
		check[now] = 1;
		for( int i=1; i<= num; i++ ){
			if( arr[now][i] == 1){
				arr[now][i] = 2;
				arr[i][now] = 2;
				q.push(i);
			}
		}
	}
}


int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &num, &cnt);
	while(cnt--){
		int x, y;
		scanf("%d %d", &x, &y);
		arr[x][y]= 1;
		arr[y][x]= 1;
	}
	q.push(1);
	bfs();
	int result= 0;
	for(int i=1; i<= num; i++){
		if(check[i]){
			result++;
		}	
	}
	printf("%d", result-1);
	return 0;
}
