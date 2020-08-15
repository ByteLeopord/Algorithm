/*
graph：邻接矩阵
dist：从start节点到各节点的最短距离列表
start：起点
*/
void Dijkstra(vector<vector<int>>& graph, vector<int>& dist, int start)
{
	int len = graph.size();
	vector<bool> visited(len, false);
	vector<int> parent(len, -1);
	vector<int> dist(len, INT_MAX);
	
	for(int i = 0; i < len; ++i){
		dist[i] = graph[start][i];
		if(graph[start][i] != INT_MAX)
			parent[i] = start;
	}
	visited[start] = true;
	
	for(int i = 1; i < len; ++i){
		int mindis = INT_MAX;
		int index;
		for(int j = 0; j < len; ++j){
			//1.到当前未访问节点距离中 最小的一个节点
			if(!visited[j] && dist[j] < mindis){
				mindis = dist[j];
				index = j;
			}
		}
		//2.将上面找到的节点 加入到以查询节点列表
		visited[index] = true;
		
		//3.以上述节点为起点 更新 到各节点距离的列表和前置节点列表
		for(int j = 0; j < len; ++j){
			int newdist = (graph[index][j] == INT_MAX) ? INT_MAX : graph[index][j]+min;
			if(!visited[j] && dist[j] > newdist){
				dist[j] = newdist;
				parent[j] = index;
			}
		}
	}
}
