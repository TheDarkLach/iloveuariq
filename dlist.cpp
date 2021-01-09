#include "dlist.h"

dlist::dlist() {
  head = NULL;
  tail = NULL;
}

dlist::~dlist() {
  while (head != NULL) {
    node* temp = head;
    head = head->next;
    delete temp;
  }
}

void dlist::build() {
  srand((unsigned)time(0));
  node* current = new node();
  current->data = (rand()%10 + 1);
  head = current;
  current->previous = NULL;
  node* previous = current;
  int additionalValues = (rand()&5);
  for (int a = 0; a < 15+additionalValues; a++) {
    current = new node();
    previous->next = current;
    current->previous = previous;
    current->data = (rand()%10 + 1);
    previous = current;
  }
  tail = current;
  current->next = NULL;
}

void dlist::display() {
	//Debug
	//int count = 0;
		
  node* current = head;
  while (current != NULL) {
	  cout << current->data << " ";
    //cout << current->data << " (" << count << ") ";
    current = current->next;
	//count++;
  }
  cout << endl;
}

void dlist::removefl(node* current_node, bool edited_head)
{
	if(!edited_head)
	{
		node* new_head = head->next;
		head           = new_head;
		head->previous = NULL;
		
		dlist::removefl(head->next, true);
	}
	else if(current_node == tail)
	{
		node* new_tail = tail->previous;
		tail           = new_tail;
		tail->next     = NULL;
		
		//head->previous = tail;
		//tail->next     = head;
		
		return;
	}
	else
	{
		dlist::removefl(current_node->next, true);
	}
}

