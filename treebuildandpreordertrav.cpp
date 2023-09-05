#include <iostream>
#include <queue>
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
node *buildtree()
{
    int data;
    cin >> data;
    if (data == -1)
        return nullptr;
    node *y = new node(data);
    y->left = buildtree();
    y->right = buildtree();
    return y;
}
void preprinttree(node *rt)
{

    if (rt == nullptr)
        return;
    cout << rt->data;
    preprinttree(rt->left);
    preprinttree(rt->right);
}

void inorderprinttree(node *rt)
{

    if (rt == nullptr)
        return;
    inorderprinttree(rt->left);
    cout << rt->data;
    inorderprinttree(rt->right);
}

void postprinttree(node *rt)
{

    if (rt == nullptr)
        return;
    postprinttree(rt->left);
    postprinttree(rt->right);
    cout << rt->data;
}

void levelprinttree(node *rt)
{
    queue<node *> t;
    t.push(rt);
    t.push(nullptr);
    while (!t.empty())
    {
        if (t.front() == nullptr)
        {
            cout << endl;
            t.pop();
            if (!t.empty())
                t.push(nullptr);
        }
        else
        {
            if (t.front()->left != nullptr)
                t.push(t.front()->left);
            if (t.front()->right != nullptr)
                t.push(t.front()->right);
            cout << t.front()->data;
            t.pop();
        }
    }
}

int main()
{
    node *root = buildtree();
    // preprinttree(root);
    // cout << endl;
    // inorderprinttree(root);
    // cout << endl;
    // postprinttree(root);
    levelprinttree(root);
}