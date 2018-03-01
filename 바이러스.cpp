#include <stdio.h>
#include <algorithm>
#define MAX 110

using namespace std;
int temp[2];
int parent[MAX];
int result;
int Find(int num){
	if( num == parent[num] )	return num;
	else{
		return	parent[num] = Find( parent[num] );
	}
}
void Union(int a, int b){
	parent[Find(b)] = Find( a );
}
int main()
{
	freopen("input.txt", "r", stdin);
	
	int num, cnt;	scanf("%d %d", &num, &cnt);
	// ÃÊ±âÈ­
	for( int i=0; i<= num; i++ ){
		parent[i] = i;
	}
	while(cnt--){
		int a, b;	scanf("%d %d", &temp[0], &temp[1]);
		sort(&temp[0], &temp[1]+1);
		Union(temp[0], temp[1]);
		
	}

	for(int i=2; i<= num; i++){
		if(Find(i) == Find(1)){
			result++;
		}
	}
	printf("%d", result);
	return 0;
}
