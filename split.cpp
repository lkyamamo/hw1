/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  //termination if current node is null
  if(in != NULL)
  {
    //odd
    if((in->value)%2 == 1)
    {
      //odd pointer points to current node pointer
      odds = in;
      odds->value = in->value;
      Node* follow = NULL;
      split(in->next, follow, evens);
      odds->next = follow;
      in = NULL;
    }
    //even
    else
    {
      //set current even noded to current in node
      evens = in;
      evens->value = in->value;
      Node* follow = NULL; 
      split(in->next, odds, follow);
      evens->next = follow;
      in = NULL;
    }
  }


// WRITE YOUR CODE HERE

}

/* If you needed a helper function, write it here */

// WRITE YOUR CODE HERE