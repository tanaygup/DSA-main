/*
void inorder(BinaryTreeNode<int> *root, int &cnt)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left,cnt);
    if(root->left==NULL && root->right == NULL){
        cnt++;
    }
    inorder(root->right,cnt);
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    // Write your code here.
    int cnt=0;
    inorder(root,cnt);
    return cnt;
}*/