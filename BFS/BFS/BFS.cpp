#include <fstream>
using namespace std;
ifstream f("bfsinput.txt");
ofstream g("bfsoutput.txt");

int queue[101], visited[101], graph[101][101],nodes;   //n = number of nodes

void bfs(int start)
{
	int st, dr;
	st = dr = 1;   // initialising the queue
	queue[1] = start;
	visited[start] = 1;  //we mark the start of the queue
	while (st <= dr)  //while the queue exists
	{
		int current = queue[st];  //we mark the node from the queue, the node from where we check the neighbours
		//g << queue[st] << " ";
		for (int i = 1; i <= nodes; i++)
		{
			if (visited[i] == 0 && graph[current][i] == 1)  //if the node i is neighbour with the current node, but is not visited
			{
				visited[i] = 1;  //we mark the visit
				queue[++dr] = i;   //we add the node to the queue for later checks
				g << i << " ";
			}
		}
		st++;  //we finish checking queue[st], we "delete" it from the queue
	}
}

int main() {
	int edges, start;
	f >> nodes >> edges >> start;
	for (int i = 1; i <= edges; i++)
	{
		int x, y;
		f >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1;
	}
	g << start << " ";
	bfs(start);


	return 0;
}