//depth first search
#include<stdio.h>
#define max 100
int adj[max][max];
int state[max],n;
void creategraph()
{
	int origin, dest, c, max_edge;
	printf("Enter no. of verices: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			adj[i][j]=0;
	max_edge=n*(n-1);
	for(c=1;c<=max_edge;c++)
	{
		printf("Enter edge: ");
		scanf("%d %d",&origin,&dest);
		if(origin==-1&&dest==-1)
			break;
		if(origin>=n || dest>=n || origin<0|| dest<0)
		{
			printf("Invalid edge\n");
			c--;
		}
		else
		{
			adj[origin][dest]=1;
			adj[dest][origin]=1;
		}
	}
}
void dfs(int vertex)
{
	int i;
	printf("%d",vertex);
		state[vertex]=1;
	for(i=0;i<n;i++)
		if(adj[vertex][i]==1 && state[i]==0)
			dfs(i);
}
void main()
{
	creategraph();
	int start_vertex;
	printf("Enter starting vertex: ");
	scanf("%d",&start_vertex);
	for(int i=0;i<n;i++)
	{
		state[i]=0;
	}   
	dfs(start_vertex);
}