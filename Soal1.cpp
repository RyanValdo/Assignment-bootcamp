#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node
{
  int angka;
  Node *next;
} * head1, *tail1, *head2, *tail2, *head3, *tail3;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->angka = value;
  newNode->next = NULL;

  return newNode;
}

void pushTail1(int value)
{
  Node *temp = createNode(value);

  if (!head1)
  {
    head1 = tail1 = temp;
  }
  else
  {
    tail1->next = temp;
    tail1 = temp;
  }
}

void pushTail2(int value)
{
  Node *temp = createNode(value);

  if (!head2)
  {
    head2 = tail2 = temp;
  }
  else
  {
    tail2->next = temp;
    tail2 = temp;
  }
}

void pushTail3(int value)
{
  Node *temp = createNode(value);

  if (!head3)
  {
    head3 = tail3 = temp;
  }
  else
  {
    tail3->next = temp;
    tail3 = temp;
  }
}

void printLinkedList1()
{
  Node *curr = head1;

  printf("First LinkedList  : ");
  while (curr)
  {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

void printLinkedList2()
{
  Node *curr = head2;

  printf("Second LinkedList : ");
  while (curr)
  {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

void printLinkedList3()
{
  Node *curr = head3;

  printf("Sorted LinkedList : ");
  while (curr)
  {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

void findMaxMin()
{
  Node *max = tail3;
  Node *min = head3;

  printf("Max = %d\n", max->angka);
  printf("Min = %d\n", min->angka);
  printf("Range = %d\n", max->angka - min->angka);
}

int main()
{

  pushTail1(2);
  pushTail1(4);
  pushTail1(6);
  printLinkedList1();
  pushTail2(3);
  pushTail2(5);
  pushTail2(7);
  printLinkedList2();

  Node *curr1 = head1;
  Node *curr2 = head2;

  while (curr1 && curr2)
  {
    if (curr1->angka < curr2->angka)
    {
      pushTail3(curr1->angka);
      curr1 = curr1->next;
    }
    else
    {
      pushTail3(curr2->angka);
      curr2 = curr2->next;
    }
  }

  while (curr1)
  {
    pushTail3(curr1->angka);
    curr1 = curr1->next;
  }
  while (curr2)
  {
    pushTail3(curr2->angka);
    curr2 = curr2->next;
  }

  printLinkedList3();

  return 0;
}
