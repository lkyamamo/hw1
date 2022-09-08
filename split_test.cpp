#include <iostream>
#include "split.h"

using namespace std;

int main()
{
    Node five(9,NULL);
    Node four(7,&five);
    Node three(5,&four);
    Node two(3,&three);
    Node one(1,&two);

    Node* first = &one;
    Node* odds = NULL;
    Node* evens = NULL;
    split(first, odds, evens);

    Node* current = odds;
    while(current != NULL)
    {
        cout << current->value << endl;
        current = current->next;
    }

    cout << endl;

    current = evens;
    while(current != NULL)
    {
        cout << current->value << endl;
        current = current->next;
    }

    return 0;

}