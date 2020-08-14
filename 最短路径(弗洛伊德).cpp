void Floyd(vector<vector<int>>& graph, vector<vector<int>>& dist, vector<vector<int>>& sequ){
	int len = graph.size();
	
	for(int i = 0; i < len; ++i){
		for(int j = 0; j < len; ++j){
			dist[i][j] = graph[i][j];
			sequ[i][j] = j;
		}
	}
	
	for(int k = 1; k < len; ++k){
		for(int i = 0; i < len; ++i){
			for(int j = 0; j < len; ++j){
				if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
				if(dist[i][j] > dist[i][k] + dist[k][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					sequ[i][j] = sequ[i][k];
				}
			}
		}
	}
}
