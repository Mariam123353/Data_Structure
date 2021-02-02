#include <iostream>
using namespace std;
struct node {
    int item;
    node* next;
};
class linked_list
{
    node* head = NULL;
public :
    linked_list() // constructor
    {
        head = NULL;
    }
    void insert_node_AtLast(int element) // insert node at End of list 
    {
        node* newNode = new node, * last;
        newNode->item = element;

        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            last = head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = newNode;
            newNode->next = NULL;
        }
    }
    void insert_node_begin(int element) // insert node at beginning of list 
    {
        node* newNode = new node;
        newNode->item = element;
        if (head == NULL)
        {
            head = newNode;
            newNode->next = NULL;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }
    void delete_Node(int val) // delete node by value  
    {
        node* curr, * pre;
        curr = head;
        pre = head;
        if (curr->item == val)
        {
            head = curr->next;
            free(curr);
            return;
        }
        while (curr->item != val)
        {
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        free(curr);
    }
    void delete_First()
    {
        if (head == NULL)
        {
            cout << "sorry, the linked list is empty";
        }
        else {
            node* first;
            first = head;
            head = first->next;
            free(first);
        }
    }
    int count() // get how many nodes in list 
    {
        int count = 0;
        node* q = head;
        while (q != NULL)
        {
            q = q->next;
            count++;
        }
        return count;
    }
    void insert_element_AtPos(int pos, int element) // insert node at specific position
    {
        node* newNode = new node;
        newNode->item = element;
        if (pos == 0)
        {
            insert_node_begin(element);
        }
        else if (pos == count())
        {
            insert_node_AtLast(element);
        }
        else if (pos > 0 && pos < count())
        {
            node* cur;
            cur = head;
            for (int i = 1; i < pos; i++)
            {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
        }
        else
            cout << "Invalid position "<<endl;
    }


    void delete_last() // delete last node of list 
    {
        if (head == NULL)
        {
            cout << "sorry, the linked list is empty";
        }
        else if (head->next == NULL)
        {
            delete(head);
            head = NULL;
        }
        else
        {
            node* ptr;
            ptr = head;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            delete(ptr->next);
            ptr->next = NULL;
        }
    }
    void print() // print all nodes 
    {
        node* h;
        if (head == NULL)
        {
            cout << "sorry,linked list is empty\n";
        }
        else
        {
            h = head;
            while (h != NULL)
            {
                cout << h->item << " ";
                h = h->next;
            }
            cout << endl;
        }
    }

    void searchList(int val) //function to search element in the linked list 
    {
        node* tmp;
        int i = 0;
        tmp = head;
        if (tmp == NULL)
        {
            cout << "\nEmpty List\n";
        }
        else
        {
            while (tmp != NULL)
            {
                if (tmp->item == val)  //If element is present in the list
                {
                    cout << "Item found at location: " << (i + 1) << endl;
                    break;
                }
                else
                {
                    i++;
                    tmp = tmp->next;
                }
            }
            if (tmp == NULL) //If element is not present in the list
            {
                cout << "Item not found\n";
            }
        }
    }
    void reverse() // To reverse items from End to beginning
    {
        node* prev, * curr, * next;
        prev = NULL;
        curr = head;
        next = curr->next;
        while (next != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
    ~linked_list() // destructor to  remove nodes from memory 
    {
       delete( head) ;
    }
};
int main()
{
    linked_list a;
    a.insert_node_AtLast(1);
    a.insert_node_AtLast(2);
   a.insert_node_AtLast(3);
  a. insert_node_AtLast(4);
   a. insert_node_begin(5);  
    a.insert_element_AtPos(1, 2);
    //a.delete_Node(3);
    a.print();
    //cout << "There is " << a.count() << "  element in list\n";
   //a.searchList(1);
    //a.delete_last();
    //a.delete_Node(3);
    a.reverse();
    a.print();
    
}