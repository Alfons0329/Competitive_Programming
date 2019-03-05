/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
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
    if(root -> data <= lsub_max)
    {
        return false;
    }
    
    if(root -> data >= rsub_min)
    {
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
    sub_treemin(root -> left, sub_min);
    sub_treemin(root -> right, sub_min);
}
