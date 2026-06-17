//breadth first serarch
#include<stdio.h>
#define initial 1
#define waiting 2
#define visited 3
#define max 5
int queue[max];
int f=-1,r=-1,n,v;
int G[max][max],state[10];
void insertqueue(int x)
{
	if(f==-1)
		f++;
	queue[++r]=x;
}
int deletequeue()
{
	return(queue[f++]);
}
void create_graph()
{
    int origin, destination, c, max_edge;
    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            G[i][j] = 0;

    max_edge = n * (n - 1);
    for(c = 1; c <= max_edge; c++)
    {
        printf("Enter edge %d (origin destination, -1 -1 to end): ", c);
        scanf("%d%d", &origin, &destination);
        if(origin == -1 && destination == -1)
            break;
        else if(origin >= n || origin < 0 || destination >= n || destination < 0)
        {
            printf("Invalid edge\n");
            c--;
        }
        else
            G[origin][destination] = 1;
    }
}
void bfs(int v)
{
	int i;
	insertqueue(v);
	state[v]=waiting;
	while(r!=-1&&f!=r+1)
	{
		v=deletequeue();
		printf("%d ",v);
		state[v]=visited;
		for(i=0;i<n;i++)
			if(G[v][i]==1 && state[i]==initial)
			{
				insertqueue(i);
				state[i]=waiting;
			}
	}
}
void bf_traversal()
{
	int v;
	for(v=0;v<n;v++)
		state[v]=initial;
	printf("Enter starting number:");
	scanf("%d",&v);
	bfs(v);
}
void main()
{
	create_graph();
	bf_traversal();
}