include<vector>
include<queue>

struct Edge{
	int start;
	int end;
	int weight;
	Edge(int s, int e, int w):start(s), end(e), weight(w){}
};
struct cmp{
	bool operator () (Edge &a, Edge &b){
		return a.weight > b.weight;
	}
};

int find(vector<int>& unionSet, int index){
	while(unionSet[index] != index){
		index = unionSet[index];
	}
	return index;
}

vector<Edge> Kruskal(vector<vector<int>>& graph){
	int len = graph.size();
	vector<Edge> ve;
	for(int i = 0; i < len; i++){
		for(int j = i+1; j < len; j++){
			if(graph[i][j] == INT_MAX) continue;
			ve.push_back(Edge(i, j, graph[i][j]);
		}
	}
	priority_queue<Edge, vector<Edge>, cmp> Edge_pq;
	int cnt = ve.size();
	for(int i = 0; i < cnt; i++){
		Edge_pq.push(ve[i]);
	}
	//并查集
	vector<int> unionSet(len, -1);
	for(int i = 0; i < len; i++){
		unionSet[i] = i;
	}
	
	vector<Edge> res;
	//当边数为节点数-1时，最小生成树完成
	while(res.size() < len-1){
		int start = Edge_pq.top().start;
		int end = Edge_pq.top().end;
		//并查集判断是否有环
		if(find(unionSet, start) != find(unionSet, end)){
			unionSet[find(unionSet, end)] = find(unionSet, start);
			res.push_back(Edge_pq.top());
		}
		Edge_pq.pop();
	}
	
	
}
