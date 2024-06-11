// Write a program to implement Ford-Fulkerson algorithm for Maximum Flow Problem
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 10;
bool bfs(int graph[MAXN][MAXN], int n, int source, int sink, int parent[]) {
bool visited[MAXN];
memset(visited, false, sizeof(visited));
queue<int> q;
q.push(source);
visited[source] = true;
parent[source] = -1;
while (!q.empty()) {
int current = q.front();

q.pop();
for (int i = 0; i < n; i++) {
if (!visited[i] && graph[current][i] > 0) {
q.push(i);
visited[i] = true;
parent[i] = current;
if (i == sink) {
return true;
}
}
}
}
return false;
}
int fordFulkerson(int graph[MAXN][MAXN], int n, int source, int sink) {
int residual[MAXN][MAXN];
memcpy(residual, graph, sizeof(residual));
int parent[MAXN];
int max_flow = 0;
while (bfs(residual, n, source, sink, parent)) {
int path_flow = INT_MAX;
for (int v = sink; v != source; v = parent[v]) {
int u = parent[v];
path_flow = min(path_flow, residual[u][v]);
}
for (int v = sink; v != source; v = parent[v]) {
int u = parent[v];
residual[u][v] -= path_flow;
residual[v][u] += path_flow;
}
max_flow += path_flow;
}
return max_flow;
}
int main() {
int graph[MAXN][MAXN] = {

{0, 16, 13, 0, 0, 0},
{0, 0, 10, 12, 0, 0},
{0, 4, 0, 0, 14, 0},
{0, 0, 9, 0, 0, 20},
{0, 0, 0, 7, 0, 4},
{0, 0, 0, 0, 0, 0}
};
int n = 6;
int source = 0;
int sink = 5;
int max_flow = fordFulkerson(graph, n, source, sink);
cout << "Maximum flow: " << max_flow << endl;
return 0
}
