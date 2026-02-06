/*
Hãy viết chương trình đọc đồ thị từ tập tin và hiển thị ma trận kề của đồ thị này.

Giả sử đồ thị được cho là đồ thị vô hướng đơn.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ tập tin dt1.txt với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v).

Đầu ra (Output):

In ra Ma trận kề (0/1) của đồ thị
*/

#include <stdio.h>
#define MAX 100

typedef struct{
	int n,m;
	int a[MAX][MAX];
}Graph;

void init(Graph *G, int n){
	G->n = n;
	G->m = 0;
	
	int i,j;
	for(i=1; i<=G->n; i++)
		for(j=1; j<=G->n; j++)
			G->a[i][j] = 0;
}

void add_edge(Graph *G, int u, int v){
	G->a[u][v] = 1;
	G->a[v][u] = 1;
	G->m++;
}

void print_graph(Graph *G){
	int i,j;
	for(i=1; i<=G->n; i++)
	{
		for(j=1; j<=G->n; j++)
		{
			printf("%d ", G->a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	Graph G;
	int n,m,u,v;
	freopen("dt1.txt","r",stdin);
	scanf("%d%d", &n, &m);	
	init(&G,n);
	
	int i;
	for(i=1; i<=m; i++){
		scanf("%d%d", &u, &v);
		add_edge(&G,u,v);
	}
	print_graph(&G);
	
	return 0;
}
