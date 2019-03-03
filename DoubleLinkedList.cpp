// Double linked list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

struct node{
	int x;
	node *next, *prev;
};

node *start = NULL, *last;
int length = 0;

void traverse(){
	node *temp;
	temp = start;
	if (temp == NULL){
		cout << "List is empty. \n";
	}
	else
	{ 
		int i = 1;
		while (temp != NULL){
			cout << i << " : " << temp->x << endl;
			i++;
			temp = temp->next;
		}
	}
	return;
}
//****************************
//**************
//****************************
void Delete()
{
	if (start = NULL){
		cout << "Empty List. \n";
	}
	else
	{
		node *temp;
		cout << "Which element would you like to delete \n 1) First Element \n 2) Last Element \n 3) By value \n 4) Exit function :";
		int I; cin >> I;
		while (I != 4){
			switch (I)
			{
			case 1:
			{
					  temp = start;
					  start = temp->next;
					  start->prev = NULL;

			}
			case 2:
			{
					  temp = last;
					  last = temp->prev;
					  last->prev = NULL;

			}
			case 3:
			{
					  int y;
					  cout << "Please enter the value you would like to delete : ";
					  cin >> y;
					  node *after, *before;
					  temp = start;
					  while (temp->x != y && temp != NULL){
						  temp = temp->next;
					  }
					  if (temp == NULL)
						  cout << "Value not found : " << y << endl;
					  else
					  {
						  before=temp->prev;
						  after = temp->next;
						  before = after->next;
						  after = before->next;
					  }
					  delete before, after;
			}
			case 4:

			default:
				cout << "Please Select Values from above: \n";
				break;
			}
		}
		delete temp;
		length -= 1;
	}
	return;
}
//****************************
//**************
//****************************
void insert(){
	node *temp; int y;
	temp = new node;
	cout << "Please Input the value you would like to inset :";
	cin >> y;
	temp->x = y;
	if (start == NULL){
		start = temp;
		last = temp;
		temp->next = NULL;
		temp->prev = NULL;

	}
	else
	{
		int i = 0;
		while (i != 4){
			cout << "What would you like to insert this value ? \n 1) Start \n 2) End \n 3) In Chrologinical order \n 4) Exit :";
			cin >> i;
			switch (i)
			{
			case 1:
				node *temp1;
				temp1 = start;
				start = temp;
				temp->prev = NULL;
				temp->next = temp1;
				temp1->prev = temp;
				delete temp1;

			case 2:
				node *temp1;
				temp1 = last;
				last = temp;
				temp->prev = temp1;
				temp->next = NULL;
				temp1->next = temp;
				delete temp1;
			case 3:
				node *after, *before;
				after = start;
				while (after->x < y && after != NULL)
				{
					before = after;
					after = after->next;
				}
				if (after->x==y){
					cout << "Dublicate Value. \n";
				}
				else
				{
					before->next = temp;
					temp->next = after;
				}
				delete after, before;
			case 4:
				return;
			default:
				cout << "Invalid Input please enter again : \n";
				break;
			}
		}
	}
	delete temp;
	length += 1;
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

