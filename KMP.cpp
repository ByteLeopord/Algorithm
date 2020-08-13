/* 模式串从1开始 */
void getNext(string& str, vector<int>& next)
{
	int t = 1, j = 0;
	int len = str.size();
	next[1] = 0;
	while(t < len){
		if(j == 0 || str[j] == str[t]){
			next[t+1] = j+1;
			++t;
			++j;
		}
		else{
			j = next[j];
		}
	}
}

int KMP(string& s, string& p)
{
	int i = 1, j = 1;
	int slen = s.size(); 
	int plen = p.size();
	vector<int> next(plen, 0);
	getNext(p, next);
	while(i < slen && j < plen){
		if(j == 0 || slen[i] == plen[j]){
			++i;
			++j;
		}
		else{
			j = next[j];
		}
	}
	if(j >= plen) 
		return i-plen;
	else
		return -1;
}
