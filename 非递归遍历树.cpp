class Solution{
public:
	//前序非递归实现
	vector<int> preorder(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> sk;
		if(root != NULL){
			sk.push(root);
		}
		while(!sk.empty()){
			TreeNode* node = sk.top();
			sk.pop();
			if(node != NULL){
				if(node->right)
					sk.push(node->right);
				if(node->left)
					sk.push(node->left);
				sk.push(node);
				sk.push(NULL);
			}
			else{
				res.push_back(sk.top()->val);
				sk.pop();
			}
		}
		return res;
	}
	
	//中序非递归实现
	vector<int> inorder(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> sk;
		if(root != NULL){
			sk.push(root);
		}
		while(!sk.empty()){
			TreeNode* node = sk.top();
			sk.pop();
			if(node != NULL){
				if(node->right)
					sk.push(node->right);
				
				sk.push(node);
				sk.push(NULL);
				
				if(node->left)
					sk.push(node->left);
			}
			else{
				res.push_back(sk.top()->val);
				sk.pop();
			}
		}
		return res;
	}
	
	//后序非递归实现
	vector<int> backorder(TreeNode* root){
		vector<int> res;
		stack<TreeNode*> sk;
		if(root != NULL){
			sk.push(root);
		}
		while(!sk.empty()){
			TreeNode* node = sk.top();
			sk.pop();
			if(node != NULL){
				sk.push(node);
				sk.push(NULL);
				
				if(node->right)
					sk.push(node->right);
				if(node->left)
					sk.push(node->left);
			}
			else{
				res.push_back(sk.top()->val);
				sk.pop();
			}
		}
		return res;
	}
};
