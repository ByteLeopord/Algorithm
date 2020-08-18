//初始化父节点数组
void initParent(vector<int>& parent, int n){
	for(int i = 0; i < n; i++){
		parent[i] = -1;
	}
}
//找父节点
int find(vector<int>& parent, int index){
	int temp = index;
	while(parent[temp] != -1){
		temp = parent[temp];
	}
	return temp;
}
//判断是否有环
bool union_vertices(int x, int y, vector<int>& parent){
	int x_root = find(parent, x);
	int y_root = find(parent, y);
	
	if(x_root == y_root){
		return false;
	}
	else{
		parent[x_root] = y_root;
		return true;
	}
}
