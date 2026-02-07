/*
Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - đỉnh như sau:

typedef struct {
    int A[100][100];
    int n;
} Graph;
Giả sử đồ thị vô hướng, không chứa khuyên, nhưng có chứa đa cung

Viết hàm int edgeCount(Graph* G) để đếm số cung của đồ thị G.

int edgeCount(Graph* G) {
}
*/

int edgeCount(Graph* G){
    int i,j;
    int dem = 0;
    for(i=1; i<=G->n; i++)
        for(j=i+1; j<=G->n; j++)
            dem+= G->A[i][j];
    return dem;
}
