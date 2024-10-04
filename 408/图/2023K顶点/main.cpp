#include <iostream>
#define MAXV 5
using std::cout;
using std::cin;

typedef struct {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;


int printVertices(MGraph G) {
    int count = 0;  // 记录出度大于入度的顶点数量
    for (int i = 0; i < G.numVertices; i++) {
        int in = 0, out = 0;

        // 计算顶点 i 的出度
        for (int j = 0; j < G.numVertices; j++) {
            out += G.Edge[i][j];  // i 顶点指向其他顶点的边
        }

        // 计算顶点 i 的入度
        for (int j = 0; j < G.numVertices; j++) {
            in += G.Edge[j][i];  // 其他顶点指向 i 顶点的边
        }

        // 如果出度大于入度，输出该顶点
        if (out > in) {
            cout << G.VerticesList[i] << ' ';
            count++;
        }
    }
    cout << '\n';  // 输出换行
    return count;
}


int main() {
    MGraph G;
    G.numVertices = 5;
    G.numEdges = 6;


    G.VerticesList[0] = 'A';
    G.VerticesList[1] = 'B';
    G.VerticesList[2] = 'C';
    G.VerticesList[3] = 'D';
    G.VerticesList[4] = 'E';


    int edges[5][5] = {
            // A  B  C  D  E
            {0, 1, 1, 0, 0},  // A -> B, A -> C
            {0, 0, 0, 1, 0},  // B -> D
            {0, 1, 0, 0, 0},  // C -> B
            {0, 0, 0, 0, 1},  // D -> E
            {0, 0, 0, 0, 0}   // E
    };

    // 将 edges 数组赋值给 G.Edge
    for (int i = 0; i < G.numVertices; i++) {
        for (int j = 0; j < G.numVertices; j++) {
            G.Edge[i][j] = edges[i][j];
        }
    }

    // 调用函数，输出结果
    int count = printVertices(G);
    cout << "顶点个数: " << count << '\n';

    return 0;
}




