#include <iostream>
using namespace std;
// input : 1
//  1
//  2
//  3
//  4
//  -1
//  -1
//  5
//  -1
//  -1
//  -1
//  9
//  10
//  -1
//  -1
//  -1
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int x) : data(x), left(nullptr), right(nullptr) {}
};
// preorder build
node *prebuildtree()
{
    int data;
    cin >> data;
    if (data == -1)
        return nullptr;
    node *y = new node(data);
    y->left = prebuildtree();
    y->right = prebuildtree();
    return y;
}
void printtree(node *rt)
{

    if (rt == nullptr)
        return;
    cout << rt->data;
    printtree(rt->left);
    printtree(rt->right);
}

int main()
{
    node *root = prebuildtree();
    printtree(root);
}