// Connect Nodes at Same Level

class Solution
{
    public:
    //Function to connect nodes at same level.
    void connect(Node *root)
    {
       // Your Code Here
       queue<Node*> q;
       q.push(root);
       int count=q.size();
       while(count>0){
           for(int i=0;i<count;i++){
               Node* temp=q.front();
               q.pop();
               if(i==count-1){
                   temp->nextRight=NULL;
               }
               else{
                   temp->nextRight=q.front();
               }
               if(temp->left){
                   q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
           }
           count=q.size();
       }
    }

};
