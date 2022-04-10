/*

Younghyun Kwon

Lab: Priority Queue

Date 22-4-2022

Windows 10 Home/ MinGW 8.2.0

*/
#include <iostream>
using namespace std;

class Node
{
public:
  Node()
  {
    next = NULL;
  }
  Node(int value)
  {
    priority = value;
    next = NULL;
  }

  int priority;
  Node* next;
};

class priorityQueue
{
public:
  priorityQueue()
  {
    head = NULL;
  }
  void Enqueue(int val);
  void Dequeue();
  int Peek();
  bool isEmpty();
  int GetLength();
  void printList();

  Node* head;
};
void priorityQueue::Enqueue(int val) {
    Node* newNode = new Node(val);

    if (isEmpty()) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL)
        {
          if(temp->next->priority > val) break;
          temp = temp->next;
        }
        Node* temp2 = temp->next;
        newNode->next = temp2;
        temp->next = newNode;
    }
}

void priorityQueue::Dequeue()
{
  Node* temp1 = head->next;
  delete head;
  head = temp1;
}

int priorityQueue::Peek()
{
  return head->priority;
}

bool priorityQueue::isEmpty()
{
  Node* temp = head;
  if(temp == NULL) return true;
  else return false;
}

int priorityQueue::GetLength()
{
  Node* temp = head;
  int length = 0;
  if(temp == NULL) return 0;
  while(temp != NULL)
  {
    length++;
    temp = temp->next;
  }
  return length;
}

void priorityQueue::printList()
{
  Node* temp = head;
  while(temp != NULL)
  {
    cout << temp->priority << " ";
    temp = temp->next;
  }
}

void queueStatus(priorityQueue q)
{
  cout << "Current Queue: ";
  q.printList();
  cout << endl;
  cout << "Is Empty? " << q.isEmpty() << endl;
  cout << "Length: " << q.GetLength() << endl;
  cout << "Peek: ";
  if(q.isEmpty()) cout << "The queue is empty!" << endl;
  else cout << q.Peek() << endl;
}

int main()
{
  priorityQueue l;
  queueStatus(l);
  l.Enqueue(42);
  l.Enqueue(61);
  l.Enqueue(98);
  queueStatus(l);
  l.Enqueue(87);
  queueStatus(l);
  l.Dequeue();
  queueStatus(l);
}
