vector<int> Prim(vector<vector<int>>& graph)
{
	int len = graph.size();
	vector<int> parent(len, -1);
	vector<int> dist(len, INT_MAX);
	vector<bool> visited(len, false);
	for(int i = 1; i < len; i++){
		if(graph[0][i] == INT_MAX) continue;
		dist[i] = graph[0][i];
		parent[i] = 0;
	}
	visited[0] = true;
	//生成所有边
	for(int k = 1; k < len; k++){
		int index, min = INT_MAX;
		//寻找最小的路径值
		for(int i = 0; i < len; i++){
			if(!visited[i] && dist[i] < min){
				min = dist[i];
				index = i;
			}
		}
		visited[index] = true;
		
		//更新路径值列表 和 父节点列表
		for(int i = 0; i < len; i++){
			if(!visited[i] && dist[i] > graph[index][i]){
				parent[i] = index;
				dist[i] = graph[index][i];
			}
		}
	}
	
	return parent;
}

//打印结果
void showPrim(vector<int>& parent)
{
	int len = parent.size();
	for(int i = 0; i < len; i++){
		if(parent[i] == -1) continue;
		cout << parent[i] << "->" << i << endl;
	}
}
