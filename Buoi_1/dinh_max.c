/*
Cho một đồ thị vô hướng, không khuyên, không đa cung có n đỉnh và m cung.

Viết chương trình tính và in ra màn hình đỉnh có bậc lớn nhất và bậc tương ứng của nó. Nếu có nhiều đỉnh có bật bằng nhau thì in ra đỉnh có số thứ tự nhỏ nhất.

Đầu vào (Input):

Dữ liệu đầu vào được nhập từ bàn phím với định dạng:

- Dòng đầu tiên chứa 2 số nguyên n và m, tương ứng là số đỉnh và số cung.

- m dòng tiếp theo mỗi dòng chứa 2 số nguyên u v mô tả cung (u, v)

Đầu ra (Output):

In ra màn hình đỉnh có bậc lớn nhất và bậc của nó.

Xem thêm ví dụ bên dưới.

Trong ví dụ đầu tiên ta có:

 

Bậc của đỉnh 1 là 1,
Bậc của đỉnh 2 là 3
Bậc của đỉnh 3 là 2
Bậc của đỉnh 4 là 2
Vậy đỉnh có bậc lớn nhất là đỉnh 2 và bậc của nó là 3. Vì thế ta in ra:

2 3

Chú ý:

Để chạy thử chương trình, bạn nên tạo một tập tin dt.txt chứa đồ thị cần kiểm tra.
Thêm dòng freopen("dt.txt", "r", stdin); vào ngay sau hàm main(). Khi nộp bài, nhớ gỡ bỏ dòng này ra.
Có thể sử dụng đoạn chương trình đọc dữ liệu mẫu sau đây:
	freopen("dt.txt", "r", stdin); //Khi nộp bài nhớ bỏ dòng này.
	Graph G;
	int n, m, u, v, w, e;
	scanf("%d%d", &n, &m);
	init_graph(&G, n);
	
	for (e = 0; e < m; e++) {
		scanf("%d%d%d", &u, &v);
		add_edge(&G, u, v);
	}
*/
#include <stdio.h>
#define MAX 100

typedef struct{
	int n,m;
	int a[MAX][MAX];
}Graph;

void init(Graph *G, int n){
	G->n = n;
	
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

int deg(Graph *G, int x){
	int i;
	int dem = 0;
	for(i=1; i<=G->n; i++)
		if(G->a[x][i] == 1) dem++;
	return dem;
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
	
	int dinh_max = 0;
	int bac_max = 0;
	for(i=1; i<=n; i++){
		int bac = deg(&G,i);
		if(bac > bac_max || (bac == bac_max && i < dinh_max)){
			bac_max = bac;
			dinh_max = i;
		}
	}
	
	printf("%d %d", dinh_max, bac_max);
	
	return 0;
}
