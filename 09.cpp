// Count Number of SubTrees having given sum.

int solve(Node* root,int X,int& count){
    if(root==NULL){
        return 0;
    }
    int l=solve(root->left,X,count);
    int r=solve(root->right,X,count);
    int sum=root->data + l + r;
    if(sum==X){
        count++;
    }
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
	// Code here
	int count=0;
	solve(root,X,count);
	return count;
}
