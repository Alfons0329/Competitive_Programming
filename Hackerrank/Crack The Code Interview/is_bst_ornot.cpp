/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
/*// cout<<"Cur ndoe "<<cur->data<<" lmax "<<lmax<<" rmin "<<rmin<<endl;
if(cur->left)
{
// cout<<"cur left "<<cur->left->data;

}
if(cur->right)
{
// cout<<"cur right "<<cur->right->data;

}
// cout<<endl;*/
bool checkBST(Node* cur)
{
    int rmin = 99999999, lmax = 0;
    if(cur == NULL) //reach the end
    {
        return true;
    }
    subtree_maxval(cur->left, lmax);
    subtree_minval(cur->right, rmin);
    if(cur->left && (cur->data == cur->left->data || cur->data <= lmax)) //test left
    {
        return false;
    }
    if(cur->right && (cur->data == cur->right->data || cur->data >= rmin)) //test right
    {
        return false;
    }
    if(checkBST(cur->left) == false || checkBST(cur->right) == false)
    {
        return false;
    }
    return true; //pass all checking, return true
}
void subtree_maxval(Node* cur, int& max_val)
{
    if(cur == NULL)
    {
        return;
    }
    max_val = max(cur->data, max_val);
    subtree_maxval(cur->left, max_val);
    subtree_maxval(cur->right, max_val);
}
void subtree_minval(Node* cur, int& min_val)
{
    if(cur == NULL)
    {
        return;
    }
    min_val = min(cur->data, min_val);
    subtree_minval(cur->left, min_val);
    subtree_minval(cur->right, min_val);
}
