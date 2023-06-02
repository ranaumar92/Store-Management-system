#ifndef LINKLIST_H
#define LINKLIST_H
#pragma
#include<iostream>
using namespace std;

template <typename T>
class node {
public:
	T data;
	node* next;
	node* prev;
	//pointer to next Node
};

template <typename T>
class DoublyList
{
	node<T>* head;
	node<T>* curr;
	node<T>* tail;
public:
	DoublyList() {
		head = nullptr;
		curr = nullptr;
	}

	bool isEmpty(){
		if(head == nullptr){
			return true;
		}
		return false;
	}

	void insert(T data) { //linklist based insertion
		node<T>* newNode = new node<T>;
		newNode->data = data;
		if (head == nullptr) {
			head = newNode;
			head->next = nullptr;
			head->prev = nullptr;
			curr = head;
			tail = head;
			
		}

		else if (head != nullptr)
		{
			newNode->prev = curr;
			curr->next = newNode;
			curr = curr->next;
			curr->next = nullptr;
			tail = curr;
		}


	}

	void updateProduct( T value,int i) // it will modufy the existing products 
	{
		if (head == nullptr)
			return;
		int curIndex = 1;
		node<T> *temp = head;
		while (curIndex != i && temp)
		{
			temp = temp->next;
			curIndex++;
		}
		temp->data = value;
	}


	void deleteProduct()// delete the product (it is used in destructor)
	{
		struct node<T> *ptr;
		if (head == nullptr){
			return;
		}
		else
		{
			ptr = curr;
			ptr->prev->next = NULL;
			curr = curr->prev;
			tail = curr;
			curr->next = nullptr;
			delete ptr;
		}
	}

	void specificDeletion(int i) {//delete the specific product
		if (head == nullptr)
			return;
		int curIndex = 1;
		node<T>* temp = head;
		while (curIndex != i) {
			temp = temp->next;
			curIndex++;
		}

		node<T>* delNode = temp;
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;

		delete delNode;
	}

	T returnNode(int i){

		int curIndex = 1;
		node<T> *temp = head;
		while (curIndex != i && temp)
		{
			temp = temp->next;
			curIndex++;
		}

		return temp->data;
	}


	void displayFavourite() {//display the favourite product of the customer
		node<T>* t = tail;

		while (t!= head){
			cout << t->data << endl;
			t = t->prev;
		}
		if (t == head)
			cout << t->data;
	}

	void displayProducts() {// display all products
		node<T>* t = head;
		while (t) {
			cout << t->data << endl;
			t = t->next;
		}
	}

    ~DoublyList(){  //destructor
        while(head){
            deleteProduct();
        }
    }

};



#endif // !LINKLIST_H