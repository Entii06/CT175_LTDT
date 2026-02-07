/*
Cho cấu trúc dữ liệu đồ thị được khai báo sử dụng ma trận đỉnh - đỉnh như sau:

typedef struct {
    int A[100][100];
    int n;
} Graph;
Giả sử đồ thị vô hướng, không chứa khuyên, không chứa đa cung

Viết hàm int deg3(Graph* G) để đếm số đỉnh có bậc là 3.

int deg3(Graph* G) {
}
*/
int deg(Graph *G, int x){
    int i;
    int deg = 0;
    for(i=1; i<=G->n; i++){
        if(G->A[x][i] == 1) 
            deg++;
    }
    return deg;
}

int deg3(Graph *G){
    int i;
    int deg_3 = 0;
    for(i=1; i<=G->n; i++)
        if(deg(G,i)%3 == 0) deg_3++;
    return deg_3;
}
