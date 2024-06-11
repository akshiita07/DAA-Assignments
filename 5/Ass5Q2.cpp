//Given an adjacency matrix representation of an undirected graph consisting of N vertices, write a program
//to find whether the graph contains a Hamiltonian Path or not. If found to be true, then print “Yes”.
//Otherwise, print “No”.

#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10;

bool isSafe(int node, int graph[MAXN][MAXN], int path[], int pos) {
	if (graph[path[pos - 1]][node] == 0) {
		return false;
	}
	for (int i = 0; i < pos; i++) {
		if (path[i] == node) {
			return false;
		}
	}
	return true;
}

bool hamiltonianPathHelper(int graph[MAXN][MAXN], int path[], int pos, int n) {
	if (pos == n) {
		return true;
	}
	for (int node = 1; node < n; node++) {
		if (isSafe(node, graph, path, pos)) {
			path[pos] = node;
			if (hamiltonianPathHelper(graph, path, pos + 1, n)) {
				return true;
			}
			path[pos] = -1;
		}
	}
	return false;
}

bool hasHamiltonianPath(int graph[MAXN][MAXN], int n) {
	int path[MAXN];
	memset(path, -1, sizeof(path));
	for (int start = 0; start < n; start++) {
		path[0] = start;
		if (hamiltonianPathHelper(graph, path, 1, n)) {
			return true;
		}
	}
	return false;
}

int main() {
	int graph[MAXN][MAXN] = {
	{0, 1, 1, 0, 0},
	{1, 0, 1, 1, 0},
	{1, 1, 0, 1, 1},
	{0, 1, 1, 0, 1},
	{0, 0, 1, 1, 0}
	};
	
	int n = 5;
	
	if (hasHamiltonianPath(graph, n)) {
		cout << "Yes" <<endl;
	} 
	else {
		cout << "No" <<endl;
	}
	
	return 0;
}
