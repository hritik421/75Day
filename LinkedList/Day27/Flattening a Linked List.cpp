// Problem Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node *merge(Node *left, Node *right){
    Node *res = new Node(0);
    Node *temp = res;
    
    while(left && right){
        if(left->data <= right->data){
            res->bottom = left;
            left = left->bottom;
            
        }else{
            res->bottom = right;
            right = right->bottom;
        }
        res = res->bottom;
    }
    
    if(left) res->bottom = left;
    if(right) res->bottom = right;
    
    return temp->bottom;
}

Node *flatten(Node *root)
{
   // Your code here
   if(!root || !root->next) return root;
   
   root->next = flatten(root->next);
   
   return merge(root, root->next);
   
   
}
