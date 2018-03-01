#include <stdio.h>
#define MAX 1000010
int parent[MAX];

int Find( int num ){
	if( num== parent[num] )	return num;
	else{
		return parent[num] = Find(parent[num]);
	}
}
void Union( int x, int y ){
	
	if( parent[x] != parent[y] ){
		parent[Find(y)] = Find(x);	
	}
}
int main()
{
	freopen("input.txt", "r", stdin);
	int n, m; scanf("%d %d", &n, &m);
	for( int i=0; i<= n; i++ ){
		parent[i] = i;
	}
	for(int i=0; i< m; i++){
		int cmd, a, b;	scanf("%d %d %d", &cmd, &a, &b);
		if( cmd == 0 )	Union(a, b);
		else {
			if( Find(a) == Find(b) )	printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}
