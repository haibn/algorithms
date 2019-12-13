#include<iostream>
#include<conio.h>
#include<assert.h>

using namespace std;

template <class item>
class Node{
    item data;
    Node* left;
    Node* right;
};
//------------------------------------------------------------------
template <class item>
Node<item>* searchInBinaryTree(Node<item>* root,item lookingData)
{
    if(root == NULL)
        return NULL;
    else if(root->data == lookingData)
             return root;
         else if(root->data < lookingData)
                  return searchInBinaryTree(root->right,lookingData);
              else return searchInBinaryTree(root->left,lookingData);
}
//------------------------------------------------------------------
template <class item>
Node<item>* Min(Node<item>* root) 
{
    if(root->left == NULL)
        return root;
    else return Min(root->left);
}
//------------------------------------------------------------------
template <class item>
Node<item>* Max(Node<item>* root)
{
    if(root->right == NULL)
        return root;
    else return Max(root->right);
}
//------------------------------------------------------------------
template <class item>
void insert(Node<item>* &root,item insertData)
{
    if(root==NULL){
        root = new Node<item>;
        root->data = insertData;
        root->left = root->right = NULL;
    }
    else if(insertData < root->data)
            insert(root->left,insertData);
         else insert(root->right,insertData); 
}
//-------------------------------------------------------------------
template <class item>
void Delete(Node<item>* &root,item deleteData)
{
if(search(root,deleteData)!=NULL)
{    
    if(root->data == deleteData){
        if(root->left!=NULL && root->right!=NULL){
            Node<item>* min = Min(root->right);
            root->data = min->data;
            Delete(min,min->data);
        }
        else if(root->left==NULL){
                  Node<item>* tmp=root;
                  root = root->right;
                  delete tmp;  
             }
             else {
                   Node<item>* tmp=root;
                   root = root->left;
                   delete tmp;                   
             }          
    }
    else if(deleteData<root->data)Delete(root->left,deleteData);
         else Delete(root->right,deleteData);
}                  
}    
//-------------------------------------------------------------------
    
