#include <iostream>
#define MAXV 5
using std::cout;
using std::cin;

typedef struct {
    int numVertices, numEdges;
    char VerticesList[MAXV];
    int Edge[MAXV][MAXV];
} MGraph;

// 初始化图
void InitGraph(MGraph &G) {
    G.numVertices = 0;
    G.numEdges = 0;
    for (int i = 0; i < MAXV; i++) {
        G.VerticesList[i] = ' ';
        for (int j = 0; j < MAXV; j++) {
            G.Edge[i][j] = 0;
        }
    }
}

// 插入顶点
void InsertVertex(MGraph &G, char vertex) {
    if (G.numVertices >= MAXV) {
        cout << "顶点数量已达最大值。\n";
        return;
    }
    G.VerticesList[G.numVertices++] = vertex;
}

// 插入边
void InsertEdge(MGraph &G, int from, int to, int weight) {
    if (from < 0 || from >= G.numVertices || to < 0 || to >= G.numVertices) {
        cout << "顶点序号错误。\n";
        return;
    }
    G.Edge[from][to] = weight;
    G.Edge[to][from] = weight; // 无向图
    G.numEdges++;
}

// 深度优先搜索
void DFS(MGraph &G, int v, bool visited[]) {
    cout << G.VerticesList[v] << " ";
    visited[v] = true;
    for (int i = 0; i < G.numVertices; i++) {
        if (G.Edge[v][i] != 0 && !visited[i]) {
            DFS(G, i, visited);
        }
    }
}

int IsExistEL(MGraph G) {
    int cur{0};
    for (int i = 0; i < G.numVertices; i++) {
        int count{0};
        for (int j = 0; j < G.numVertices; j++) {
            count += G.Edge[i][j];
        }
        if (count % 2 == 0) {
            continue;
        } else {
            cur++;
            if (cur > 2) break;
        }
    }
    if (cur == 0 || cur == 2) return 1;
    return 0;
}

int main() {
    MGraph G;
    InitGraph(G);

    // 插入顶点
    InsertVertex(G, 'A'); // 0
    InsertVertex(G, 'B'); // 1
    InsertVertex(G, 'C'); // 2
    InsertVertex(G, 'D'); // 3
    InsertVertex(G, 'E'); // 4

    // 构建一个存在EL的图
    InsertEdge(G, 0, 1, 1); // A-B
    InsertEdge(G, 1, 2, 1); // B-C
    InsertEdge(G, 2, 3, 1); // C-D
    InsertEdge(G, 3, 4, 1); // D-E
    InsertEdge(G, 4, 0, 1); // E-A
    InsertEdge(G, 1, 3, 1); // B-D

    // 测试IsExistEL函数
    if (IsExistEL(G)) {
        cout << "图存在欧拉路径。\n";
    } else {
        cout << "图不存在欧拉路径。\n";
    }

    return 0;
}



