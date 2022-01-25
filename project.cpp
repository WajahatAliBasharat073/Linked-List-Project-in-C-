#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;
void start()
{
    system("color B4");
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\tLoading Please Wait " << endl;
    char x = 221;
    for (int i = 0; i < 47; i++)
    {
        cout << x;
        if (i < 10)
            Sleep(300);
        if (i >= 10 && i < 20)
            Sleep(150);
        if (i >= 20)
            Sleep(50);
    }
    system("cls");
}
void phonemenu()
{
    string name;
    cout << "                                     **************\t\tPHONE BOOK\t\t********************";
    cout << "\t\t\t\t\t\n WHAT IS YOUR NAME?\n";
    cin >> name;
    cout << "\n\t\t\t\t\t  !!!!!!!!!!!!!!!!   WELCOME " << name << "     !!!!!!!!!!!!!!!!!";
    system("Color BC");
    cout << endl;
    cout << "\t\t\t\t\t|**********************************************************|\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|         LET'S CREATE YOUR PHONEBOOK " << name << "               |\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
}
void details()
{
    // cout << "\t\t|                                                          |\n";
    cout << "\t\t\t\t\t|**********************************************************|\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|                                                          |\n";
    cout << "\t\t\t\t\t|        [1] Add Contact                                   |\n";
    cout << "\t\t\t\t\t|        [2] Search the Contact                            |\n";
    cout << "\t\t\t\t\t|        [3] Delete Contact                                |\n";
    cout << "\t\t\t\t\t|        [4] Delete All Contact                            |\n";
    cout << "\t\t\t\t\t|        [5] Display All Contacts                          |\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|                      [6] Exit                            |\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|**********************************************************|\n";
}
struct node
{
    string name, number;
    node *next;
};
node *head = NULL, *temp;
int totalcontacts = 0;
void Insert_Node()
{
    node *newnode = new node;
    cout << "Please Enter a Name" << endl;
    cin >> newnode->name;
    cout << "Please Enter a Number" << endl;
    cin >> newnode->number;
    newnode->next = NULL;
    
    if (head == NULL)
    {
        head = newnode;
        temp = newnode;
    }
    else
    {
        temp->next = newnode;
        temp = newnode;
    }
}
void display()
{

    if (head == NULL)
    {
        cout << "Contact list is empty" << endl;
    }
    else
    {
        node *trav = head;
        while (trav != NULL)
        {
            cout << "\n\tName " << trav->name;
            cout << "\n\tNumber " << trav->number;
            trav = trav->next;
            totalcontacts++;
        }
        cout << "\n\tTotal Contacts  in the list are " << totalcontacts << endl;
    }
}
void search_contact()
{
    string searchh;
    int count = 1;
    node *search_node = head;
    cout << "Enter Your Desired Contact To Search " << endl;
    cin >> searchh;
    bool found = true;
    if (head == NULL)
    {
        cout << "Contact List Is Empty" << endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if (searchh == search_node->name || searchh == search_node->number)
            {
                cout << "\t\tFull Name : " << search_node->name << endl;
                cout << "\t\tPhone Number : " << search_node->number << endl;
                found = true;
                break;
            }
            search_node = search_node->next;
            count++;
        }
    }
    if (found == true)
    {
        cout << "\t\tIndex of Contact : " << count << endl;
    }
    else
    {
        cout << "Desired Contact is not Found" << endl;
    }
}
void delete_contact_at_given_index()
{
    string position;
    node *temp = head;
    cout << "\t Enter Your Desired Contact To Delete" << endl;
    cin >> position;
    if (head == NULL)
    {
        cout << "t\tList is empty" << endl;
    }
    else
    {
        node *current = head;
        while (current != NULL)
        {
            temp = current->next;
            if (position == current->next->name || position == current->next->number)
            {
                current->next = current->next->next;
                delete temp;
                cout << "\tContact Delete Successfully" << endl;
                break;
            }
            else
            {
                current = current->next;
            }
        }
    }
}
void deleteall()
{
    if (head == NULL)
    {
        cout << "List Is Empty" << endl;
    }
    else
    {
        temp = head;
        while (head != NULL)
        {
            head = head->next;
            delete temp;
        }
        cout << "All Contacts Delete Successfully" << endl;
    }
}
int main()
{
    int op;
    start();
    phonemenu();
    while (true)
    {
        details();
        cin >> op;
        switch (op)
        {
        case 1:
            Insert_Node();
            break;
        case 2:
            search_contact();
            break;
        case 3:
            delete_contact_at_given_index();
            break;
        case 4:
            deleteall();
            break;
        case 5:
            totalcontacts = 0;
            display();
            break;
        case 6:
            exit(1);
        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }
}
