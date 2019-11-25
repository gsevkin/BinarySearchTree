#pragma once
#include <iostream>
#include <fstream>


template<class ItemType>
struct TreeNode
{
	ItemType info;
	TreeNode<ItemType> *left;
	TreeNode<ItemType> * right;
};

template<class ItemType>
class TreeType
{
public:
	TreeType(void);
	~TreeType(void);
	bool IsEmpty();
	void InsertItem(ItemType item);
	void DeleteItem(ItemType item);
	void RetrieveItem(ItemType &item, bool &found);
	void PrintTree(std::ofstream &outfile);
	//*  prints the tree in the preorder traversal*/

private:
	TreeNode<ItemType> *root;
	int _size;
	void DestructorHelper(TreeNode<ItemType> **node);
	void InsertHelper(TreeNode<ItemType> **node, ItemType item);
	void DeleteHelper(TreeNode<ItemType> **node, ItemType item);
	void RetrieveHelper(TreeNode<ItemType>*node, ItemType &item, bool &found);
	void PrintTreeHelper(TreeNode<ItemType>*node, std::ofstream &outfile);
};

template<class ItemType>
TreeType<ItemType>::TreeType(void)
{
	root = NULL;
	_size = 0;
}


template<class ItemType>
bool TreeType<ItemType>::IsEmpty()
{
	return (_size==0);
}

template<class ItemType>
void TreeType<ItemType>::InsertItem(ItemType item)
{
	InsertHelper(&root,item);
}


template<class ItemType>
void TreeType<ItemType>::InsertHelper(TreeNode<ItemType> **node, ItemType item)
{
	if(*node == nullptr)
	{
		(*node) = new TreeNode<ItemType>;
		(*node)->right = nullptr;
		(*node)->left = nullptr;
		(*node)->info = item;
		++_size;
	}
	else if(item<(*node)->info)
	{
		InsertHelper(&(*node)->left,item);;
	}
	else if(item>(*node)->info)
	{
		InsertHelper(&(*node)->right,item);;
	}
	else
	{
		std::cout<<item<<" is already in the tree."<<std::endl;
	}
}

template<class ItemType>
void TreeType<ItemType>::DeleteItem(ItemType item)
{
	DeleteHelper(&root,item);
}
template<class ItemType>
void TreeType<ItemType>::DeleteHelper(TreeNode<ItemType> **node,ItemType item)
{
	if((*node) == nullptr)
	{
		std::cout<<"There is not any "<<item<<" in the tree."<<std::endl;
	}
	else if(item<(*node)->info)
	{
		DeleteHelper(&(*node)->left,item);;
	}
	else if(item>(*node)->info)
	{
		DeleteHelper(&(*node)->right,item);;
	}
	else
	{
		delete (*node);
	
		(*node) = nullptr;
		--_size;
	}
}

template<class ItemType>
void TreeType<ItemType>::RetrieveItem(ItemType &item, bool &found)
{
	RetrieveHelper(root,item,found);
}

template<class ItemType>
void TreeType<ItemType>::RetrieveHelper(TreeNode<ItemType>*node, ItemType &item, bool &found)
{
	if(node == NULL)
	{
		found = false;
	}
	
	else if(node->info == item)
	{
		found = true;
	}

	else if(item<node->info)
	{
		RetrieveHelper(node->left,item,found);
	}

	else if(item>node->info)
	{
		RetrieveHelper(node->right,item,found);
	}
}

template<class ItemType>
void TreeType<ItemType>::PrintTree(std::ofstream &outfile)
{
	PrintTreeHelper(root, outfile);
}

template<class ItemType>
void TreeType<ItemType>::PrintTreeHelper(TreeNode<ItemType> *node, std::ofstream &outfile)
{
	
	if(node != nullptr)
	{
		PrintTreeHelper(node->left,outfile);
		outfile<<node->info<<" ";
		PrintTreeHelper(node->right,outfile);
	}
}

template<class ItemType> void TreeType<ItemType>::DestructorHelper(TreeNode<ItemType> **node)
{
	if((*node) != nullptr)
	{
		DestructorHelper(&(*node)->right);
		DestructorHelper(&(*node)->left);
		delete (*node);
		(*node) = nullptr;
	}
}

template<class ItemType>
TreeType<ItemType>::~TreeType(void)
{
	DestructorHelper(&root);
	_size = 0;
}
