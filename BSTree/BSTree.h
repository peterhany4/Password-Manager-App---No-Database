#ifndef BSTREE_H
#define BSTREE_H
#include "../User/user.h"

class node
{
public:
    user data;
    node *left;
    node *right;

    node();
    node(user u);
};

class BSTree
{
private:
    int size;
    node *root;

public:
    BSTree();
    node *getroot();
    void insert(user u);
    bool search(user u);
    bool validate(user u);
};
#endif