#define MAX_VERTEX_NUM 26

typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
	ArcNode(){nextarc=NULL;}
}ArcNode;
 
typedef struct VNode{
	int data;
	ArcNode *firstarc;
	VNode(){firstarc=NULL;}
}VNode,AdjList[MAX_VERTEX_NUM];
 
typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;
 
bool TopologicalSort(ALGraph G,int *indegree)
{
	stack<int> s;
 
	int i,k;
	for(i=1;i<G.vexnum+1;i++)
	{
			if(!indegree[i])
					s.push(i);
	}

	int count=0;
	ArcNode *p;
	while(!s.empty())
	{
			i = s.top();
			s.pop();
			cout<<G.vertices[i].data<<"->";
			count++;
			for(p=G.vertices[i].firstarc; p; p=p->nextarc)
			{
				k = p->adjvex;
				indegree[k]--;
				if(!indegree[k])
					s.push(k);
			}
	}
 
	if(count < G.vexnum)
		return false;
 
	return true;
}
