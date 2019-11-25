// BinarySearchTreeImpl.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BinarySearchTree.h"
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream infile;
	ofstream outfile1,outfile2;
	outfile1.open("treeBefore.txt");
	outfile2.open("treeAfter.txt");
	infile.open("numbers.txt");
	int numberFromFile;
	bool isFound;

	TreeType<int> tree;
	
	for(int i = 0; i<150; i++)
	{
		infile>>numberFromFile;
		tree.InsertItem(numberFromFile);
	}

	tree.PrintTree(outfile1);
	
	cout<<endl<<"Before deleting the items 20 through 40."<<endl;

	for(int i = 20; i<40 ; i++ )
	{
		tree.RetrieveItem(i, isFound);
		if(isFound)
			cout<<i<<" is found in the tree."<<endl;
		else
			cout<<i<<" is NOT found in the tree."<<endl;
	}	

	for(int i = 20; i<40 ; i++ )
	{
		tree.DeleteItem(i);
	}
	
	cout<<endl<<"After deleting the items 20 through 40."<<endl;

	for(int i = 20; i<40 ; i++ )
	{
		tree.RetrieveItem(i, isFound);
		if(isFound)
			cout<<i<<" is found in the tree."<<endl;
		else
			cout<<i<<" is NOT found in the tree."<<endl;
	}

	tree.PrintTree(outfile2);
	
	outfile1.close();
	outfile2.close();

	return 0;
}

