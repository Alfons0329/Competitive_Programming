/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
bool checkBST(Node* cur)
{
    if(cur == NULL) //reach the end
    {
        return true;
    }
    if(cur->right && cur->data > cur->right->data)
    {
        return false;
    }
    if(cur->left && cur->data < cur->left->data)
    {
        return false;
    }

    if(checkBST(cur->left) == false || checkBST(cur->right) == false)
    {
        return false;
    }
    return true;
}
