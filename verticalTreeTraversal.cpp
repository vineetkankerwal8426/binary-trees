// Vertical Tree Traversal

// Given a Binary Tree, find the vertical traversal of it starting from the leftmost level to the rightmost level.
// If there are multiple nodes passing through a vertical line, then they should be printed as they appear in level order traversal of the tree.

vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>> m;
        queue<pair<Node *,int>> q;  //we will do BFS because if more than one node come in one vertical line then we should traverse like level order sequence.
        q.push({root,0});
        while(!q.empty()){
            Node * temp = q.front().first;
            int level = q.front().second;
            q.pop();
            m[level].push_back(temp->data);
            if(temp->left) q.push({temp->left,level-1});
            if(temp->right) q.push({temp->right,level+1});
        }
        vector<int> ans;
        for(auto i:m){
            ans.insert(ans.end(),i.second.begin(),i.second.end());
        }
        return ans;
    }