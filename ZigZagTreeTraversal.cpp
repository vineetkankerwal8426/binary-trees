// Given a binary tree with n nodes. Find the zig-zag level order traversal of the binary tree.
// HINT- Try to use stacks to perform the level order traversal for tracking the visited node.


class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> ans ;
    	queue<Node * > q;
    	stack<Node *> s;
    	q.push(root);
    	q.push(nullptr);
    	int level =0;
    	while(!q.empty()){
    	    Node * temp = q.front();
    	    q.pop();
    	    if(!temp){
    	        if(level%2 == 0){
    	            while(!s.empty()){
    	                ans.push_back(s.top()->data);
    	                s.pop();
    	            }
    	        }
    	        if(!q.empty()){
    	            q.push(nullptr);
    	            level++;
    	        }
    	    }
    	    else{
    	        if(temp->left){
    	            q.push(temp->left);
    	            if(level%2==0) s.push(temp->left);
    	        }
    	        if(temp->right){
    	            q.push(temp->right);
    	            if(level%2==0) s.push(temp->right);
    	        }
    	        if(level%2==0){
    	            ans.push_back(temp->data);
    	        }
    	    }
    	}
    	return ans;
    }
};