#include <iostream>
#include <stdlib.h>
#include <string>
#include <windows.h>
#include <fstream>
#include <typeinfo>
#include <conio.h>
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
    cout << "\n   WHAT IS YOUR NAME?\n";
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
    cout << "\t\t\t\t\t|        [6] Update Contact                                |\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|                      [7] Exit                            |\n";
    cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
    cout << "\t\t\t\t\t|**********************************************************|\n";
}
struct node
{
    char name[28];
    char number[17];
    node *next;
};
node *head = NULL, *temp;
int totalcontacts = 0;
void Insert_Node()
{
    node *newnode = new node;
    cout << "\t\tPlease Enter a Name" << endl;
    cin >> newnode->name;
repeat:
    cout << "\t\tPlease Enter a Number" << endl;
    cin >> newnode->number;

    for (int i = 0; i < strlen(newnode->number); i++)

    {
        try
        {
            if (strlen(newnode->number) < 10)
                throw newnode->number[i];
        }
        catch (char a)
        {
            cout << "Enter a valid number" << endl;
            cout << "Try again" << endl;
            goto repeat;
        }
    }
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
    cout << "\t\tPhone details successfully stored " << endl;
}
void display()
{

    if (head == NULL)
    {
        cout << "\t\tContact list is empty" << endl;
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
        cout << "\n\t\tTotal Contacts  in the list are " << totalcontacts << endl;
    }
}
void search_contact()
{
    string searchh;
    node *search_node = head;
    cout << "\t\tEnter Your Desired Contact To Search " << endl;
    cin >> searchh;
    if (head == NULL)
    {
        cout << "\t\tContact List Is Empty" << endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if (searchh == search_node->name || searchh == search_node->number)
            {
                cout << "\t\tFull Name : " << search_node->name << endl;
                cout << "\t\tPhone Number : " << search_node->number << endl;
            }
            search_node = search_node->next;
        }
    }
}

void update_contact()
{
    string update;
    char temp1[28];
    char temp2[17];
    node *temp = head;
    cout << "\t Enter Your Desired Contact To Update " << endl;
    cin >> update;
    if (head == NULL)
    {
        cout << "t\tContact List is empty" << endl;
    }
    else
    {
        while (temp != NULL)
        {
            if (update == temp->name || update == temp->number)
            {
                cout << "\t\tEnter New Name : " << temp->name << endl;
                cin >> temp1;
            repeat:
                cout << "\t\t Enter New Number" << temp->number << endl;
                cin >> temp2;

                for (int i = 0; i < strlen(temp2); i++)

                {
                    try
                    {
                        if (strlen(temp2) < 10)
                            throw temp2[i];
                    }
                    catch (char a)
                    {
                        cout << "Enter a valid number" << endl;
                        cout << "Try again" << endl;
                        goto repeat;
                    }
                }
                for (int i = 0; i < 20; i++)
                {
                    temp->name[i] = temp1[i];
                    temp->number[i] = temp2[i];
                }
                cout << "\t\tUpdated Successfully" << endl;
                break;
            }
            temp = temp->next;
        }
    }
}
void delete_contact_at_given_index()
{
    string position;
    node *temp = head;
     node *current = head;
    cout << "\t\tEnter Your Desired Contact To Delete" << endl;
    cin >> position;
    if (head == NULL)
    {
        cout << "t\tList is empty" << endl;
    }
    else
    {
        while (current != NULL)
        {
            temp = current;
            if (position == current->name || position == current->number)
            {
                current = current->next;
                delete temp;
                cout << "\tContact Delete Successfully" << endl;
                break;
            }
            current = current->next;
        }
    }
}
void deleteall()
{
    if (head == NULL)
    {
        cout << "\tList Is Empty" << endl;
    }
    else
    {
        temp = head;
        while (head != NULL)
        {
            head = head->next;
            delete head;
        }
        cout << "\tAll Contacts Delete Successfully" << endl;
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
            update_contact();
            break;
        case 7:
            cout << endl;
            cout << endl;
            cout << endl;
            cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
            cout << "\t\t\t\t\t|**********************************************************|\n";
            cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
            cout << "\t\t\t\t\t|                                                          |\n";
            cout << "\t\t\t\t\t|                                                          |\n";
            cout << "\t\t\t\t\t|            THANKS FOR USING THIS NOTEBOOK                |\n";
            cout << "\t\t\t\t\t|                                                          |\n";
            cout << "\t\t\t\t\t|                                                          |\n";
            cout << "\t\t\t\t\t|----------------------------------------------------------|\n";
            cout << "\t\t\t\t\t|**********************************************************|\n";
            cout << "\t\t\t\t\t|----------------------------------------------------------|\n";

            cout << endl;
            cout << endl;
            cout << endl;
            cout << endl;
            exit(1);
        default:
            cout << "Invalid Option" << endl;
            break;
        }
    }
}

