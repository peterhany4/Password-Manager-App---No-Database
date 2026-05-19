#include <iostream>
#include "../User/user.h"
#include "BSTree.h"

node::node()
{
    data = user();
    left = nullptr;
    right = nullptr;
}
node::node(user u)
{
    data = u;
    left = nullptr;
    right = nullptr;
}

BSTree::BSTree()
{
    size = 0;
    root = nullptr;
}

node *BSTree::getroot()
{
    return root;
}

void BSTree::insert(user u)
{

    if (size == 0)
    {
        root = new node(u);
        size++;
        return;
    }
    else
    {
        node *parent = nullptr;
        node *current = root;

        while (current != nullptr)
        {
            if (u.getUser() < current->data.getUser())
            {
                parent = current;
                current = current->left;
            }
            else if (u.getUser() > current->data.getUser())
            {
                parent = current;
                current = current->right;
            }
            else
            {
                return;
            }
        }

        node *newnode = new node(u);
        if (u.getUser() < parent->data.getUser())
        {
            parent->left = newnode;
        }
        else
        {
            parent->right = newnode;
        }
        size++;
        return;
    }
}

bool BSTree::search(user u)
{
    node *current = root;

    while (current != nullptr)
    {
        if (u.getUser() == current->data.getUser())
        {
            cout << "User is found.\n";
            return true;
        }
        if (u.getUser() < current->data.getUser())
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false; // Loop ended, value does not exist
}

bool BSTree::validate(user u)
{
    node *current = root;

    while (current != nullptr)
    {
        if (u.getUser() == current->data.getUser())
        {
            if (u.getPass() == current->data.getPass())
            {
                cout << "Logged in!\n";
                return true;
            }
            else
            {
                cout << "Incorrect Password...\n";
                return false;
            }
        }
        if (u.getUser() < current->data.getUser())
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }
    }
    return false;
}