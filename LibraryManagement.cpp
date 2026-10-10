#include <iostream>
using namespace std;

class User;
class Book
{
    int bookId;
    string bookName;
    int pages, available, issued;

public:
    Book() {}
    Book(int id, string name, int pgs, int avl, int iss)
    {
        bookId = id;
        bookName = name;
        pages = pgs;
        available = avl;
        issued = iss;
    }
    int getId()
    {
        return bookId;
    }
    string getName()
    {
        return bookName;
    }
    int getPages()
    {
        return pages;
    }
    int getAvailable()
    {
        return available;
    }
    int getIssued()
    {
        return issued;
    }
    void update(string name, int pgs, int av, int iss)
    {
        bookName = name;
        pages = pgs;
        available = av;
        issued = iss;
        cout << "Updated ";
        display();
    }
    void update(string name)
    {
        bookName = name;
        cout << "Updated ";
        display();
    }
    void update(int pgs)
    {
        pages = pgs;
        cout << "Updated ";
        display();
    }
    void update(int avl, int iss)
    {
        available = avl;
        issued = iss;
        cout << "Updated ";
        display();
    }
    void display()
    {
        cout << "Book Details:" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Id: " << bookId << endl;
        cout << "Name: " << bookName << endl;
        cout << "Number of Pages: " << pages << endl;
        cout << "Available Copies: " << available << endl;
        cout << "Issued Copies: " << issued << endl;
        cout << "-----------------------------------------" << endl;
    }
    friend void issueBook(User u, Book b);
    friend void returnBook(User u, Book b);
};

class User{
    int userId;
    string userName;
    int age;
};

int main()
{
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "-----------------------------------------" << endl;
    char ch;
    Book b[100];
    int number = 0;
    do
    {
        int choice;
        cout << "1. Add Books" << endl;
        cout << "2. Update Book" << endl;
        cout << "3. Display Information of All Books" << endl;
        cout << "4. Display Information of a Book" << endl;
        cout << "Enter.." << endl;
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "Enter number of books: " << endl;
            cin >> n;
            int start = number;
            number += n;
            for (int i = start; i < number; i++)
            {
                int id, pgs, avl, iss;
                string name;
                cout << "Enter Details of " << n << " books" << endl;
                cout << "Enter Book ID, name, pages, avaiable copies and issued copies:" << endl;
                cin >> id >> name >> pgs >> avl >> iss;
                b[i] = Book(id, name, pgs, avl, iss);
            }
            for (int i = start; i < number; i++)
            {
                b[i].display();
            }
        }
        else if (choice == 2)
        {
            int id;
            cout << "Enter ID of book" << endl;
            cin >> id;
            for (int i = 0; i < number; i++)
            {
                int bId = b[i].getId();
                if (id == bId)
                {
                    int upCh;
                    cout << "This information is stored" << endl;
                    b[i].display();
                    int pgs, avl, iss;
                    string name;
                    cout << "1. Update Book Name" << endl;
                    cout << "2. Update number of pages" << endl;
                    cout << "3. Update avaiable and issued copies of book" << endl;
                    cout << "4. Update All Information" << endl;
                    cout << "Enter the choice:" << endl;
                    cin >> upCh;
                    if (upCh == 1)
                    {
                        cout << "Enter Book name:" << endl;
                        cin >> name;
                        b[i].update(name);
                    }
                    else if (upCh == 2)
                    {
                        cout << "Enter number of pages: " << endl;
                        cin >> pgs;
                        b[i].update(pgs);
                    }
                    else if (upCh == 3)
                    {
                        cout << "Enter avaiable number of copies and issued copies of book:" << endl;
                        cin >> avl >> iss;
                        b[i].update(avl, iss);
                    }
                    else if (upCh == 4)
                    {
                        cout << "Enter updated fields below and kindly enter old information in fields which is not updated " << endl;
                        cout << "Enter Book name, number of pages, available copies and issued copies:" << endl;
                        cin >> name >> pgs >> avl >> iss;
                        b[i].update(name, pgs, avl, iss);
                    }
                    else
                    {
                        cout << "Invalid Choice!" << endl;
                    }
                    break;
                }
            }
        }
        else if (choice == 3)
        {
            for (int i = 0; i < number; i++)
            {
                b[i].display();
            }
        }
        else if (choice == 4)
        {
            int id;
            cout << "Enter id of book:" << endl;
            cin >> id;
            for (int i = 0; i < number; i++)
            {
                int bId = b[i].getId();
                if (bId == id)
                {
                    b[i].display();
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
        cout << "Do you want to continue?" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "-----------------------------------------" << endl;
    cout << "THANK YOU FOR USING SYSTEM" << endl;
    cout << "-----------------------------------------" << endl;
    return 0;
}