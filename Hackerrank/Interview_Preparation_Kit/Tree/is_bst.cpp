#define INT_MAX 0x7fffffff
bool checkBST(Node* root) 
{
    if(root == NULL)
    {
       return true; 
    }
    
    int lsub_max = 0, rsub_min = INT_MAX;
    sub_treemax(root -> left, lsub_max);
    sub_treemin(root -> right, rsub_min);
    // printf("root %d lsubmax %d rsubmin %d\n", root -> data, lsub_max, rsub_min);
    if(root -> data <= lsub_max)
    {
        // printf("fail 1 \n");
        return false;
    }
    
    if(root -> data >= rsub_min)
    {
        // printf("fail 2 \n");
        return false;
    }
    
    return checkBST(root -> left) && checkBST(root -> right) ; //finished all the test
    
}

void sub_treemax(Node* root, int& sub_max)
{
    if(root == NULL)
    {
        return;
    }
    
    sub_max = max(root -> data, sub_max);
    sub_treemax(root -> left, sub_max);
    sub_treemax(root -> right, sub_max);
}

void sub_treemin(Node* root, int& sub_min)
{
    if(root == NULL)
    {
        return;
    }
    
    sub_min = min(root -> data, sub_min);
    sub_treemax(root -> left, sub_min);
    sub_treemax(root -> right, sub_min);
}
