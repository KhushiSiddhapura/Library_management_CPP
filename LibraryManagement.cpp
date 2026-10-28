#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class User;
class Book
{
    static int nextBookId;
    int bookId;
    string bookName;
    int pages, available, issued;

public:
    Book() {}
    Book(string name, int pgs, int avl, int iss)
    {
        bookId = nextBookId++;
        bookName = name;
        pages = pgs;
        available = avl;
        issued = iss;
    }
    int getId()
    {
        return bookId;
    }
    void update(string name, int pgs, int av, int iss)
    {
        bookName = name;
        pages = pgs;
        available = av;
        issued = iss;
        cout << "Updated:" << endl;
        displayBookHeading();
        display();
    }
    void update(string name)
    {
        bookName = name;
        cout << "Updated:" << endl;
        displayBookHeading();
        display();
    }
    void update(int pgs)
    {
        pages = pgs;
        cout << "Updated:" << endl;
        displayBookHeading();
        display();
    }
    void update(int avl, int iss)
    {
        available = avl;
        issued = iss;
        cout << "Updated:" << endl;
        displayBookHeading();
        display();
    }
    void displayBookHeading()
    {
        cout << left
             << setw(8) << "Book ID"
             << "|" << setw(25) << "Book Name"
             << "|" << setw(6) << "Pages"
             << "|" << setw(10) << "Available"
             << "|" << setw(10) << "Issued" << endl;

        cout << setfill('-') << setw(63) << "-" << setfill(' ') << endl;
    }
    void display()
    {
        cout << setiosflags(ios::right) << setw(5) << "" << setfill('0') << setw(3) << bookId
             << setfill(' ') << setiosflags(ios::left)
             << "|" << setw(25) << bookName
             << "|" << setw(6) << pages
             << "|" << setw(10) << available
             << "|" << setw(10) << issued << endl;
    }
    friend void issueBook(User &u, Book &b);
    friend void returnBook(User &u, Book &b);
};
class Date
{
    int date, month, year;

    int isLeapYear(int y)
    {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

public:
    Date()
    {
        date = 1;
        month = 1;
        year = 2000;
    }
    Date(int d, int m, int y)
    {
        if (y < 2000)
        {
            throw 1;
        }
        if (m < 1 || m > 12)
        {
            throw 1;
        }
        int maxDays;
        if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            maxDays = 30;
        }
        else if (m == 2)
        {
            if (isLeapYear(y))
            {
                maxDays = 29;
            }
            else
            {
                maxDays = 28;
            }
        }
        else
        {
            maxDays = 31;
        }
        if (d < 1 || d > maxDays)
        {
            throw 1;
        }
        date = d;
        month = m;
        year = y;
    }
    void displayDateFormatted()
    {
        cout <<setiosflags(ios::right)<< setfill('0')
             << setw(2) << date << "/"
             << setw(2) << month << "/"
             << setw(4) << year
             << setfill(' ');
    }
    int getDays()
    {
        int days = 0;
        for (int y = 2000; y < year; y++)
        {
            if (isLeapYear(y))
            {
                days += 366;
            }
            else
            {
                days += 365;
            }
        }
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (isLeapYear(year))
        {
            months[1] = 29;
        }
        for (int m = 1; m < month; m++)
        {
            days += months[m - 1];
        }
        days += date;

        return days;
    }
    int countDays(Date d)
    {
        int d1 = getDays();
        int d2 = d.getDays();
        if (d1 > d2)
        {
            return (d1 - d2);
        }
        else
        {
            return (d2 - d1);
        }
    }
};
class IssuedBook
{
    int IssuedBId;
    Date issueDate;

public:
    IssuedBook() {}
    IssuedBook(int id, Date d)
    {
        IssuedBId = id;
        issueDate = d;
    }
    int getIssuedId()
    {
        return IssuedBId;
    }
    Date getIssuedDate()
    {
        return issueDate;
    }
    void displayIssuedBookHeading()
    {
        cout << setiosflags(ios::left)
             << setw(10) << "Book ID"
             << "|" << setw(10) << "Issue Date" << endl;

        cout << setfill('-') << setw(21) << "-" << setfill(' ') << endl;
    }
    void display()
    {
        cout << setfill('0') << right << setw(3) << IssuedBId
             << setfill(' ') << left << setw(7) << ""
             << "|";

        issueDate.displayDateFormatted();
        cout << endl;
    }
};
class User
{
protected:
    static int nextId;
    int userId;
    string name;
    int age;
    IssuedBook books[10];
    int borrowed;
    int maxDaysAllowed;
    int finePerDay;
    int totalFine;
    string type;

public:
    User()
    {
        userId = 0;
        name = "";
        age = 0;
        borrowed = 0;
        maxDaysAllowed = 0;
        finePerDay = 0;
        totalFine = 0;
    }
    User(string n, int a)
    {
        userId = nextId++;
        name = n;
        age = a;
        borrowed = 0;
        maxDaysAllowed = 0;
        finePerDay = 0;
        totalFine = 0;
    }
    void displayUserHeading()
    {
        cout << left
             << setw(8) << "User ID"
             << "|" << setw(25) << "Name"
             << "|" << setw(6) << "Age"
             << "|" << setw(8) << "Type" << endl;

        cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;
    }
    void display()
    {
        cout << resetiosflags(ios::left)
             << setw(5) << ""
             << setfill('0') << setw(3) << userId
             << setfill(' ')
             << setiosflags(ios::left)
             << "|" << setw(25) << name
             << resetiosflags(ios::left)
             << "|" << setw(6) << age;
    }
    int getId()
    {
        return userId;
    }
    int getBorrowed()
    {
        return borrowed;
    }
    void updateName()
    {
        cout << "Enter updated name of user:" << endl;
        cin >> name;
        cout << "Updated:" << endl;
    }
    void updateAge()
    {
        cout << "Enter updated age of user:" << endl;
        cin >> age;
        cout << "Updated:" << endl;
    }
    void updateUser()
    {
        cout << "Enter updated name and age of user:" << endl;
        cin >> name >> age;
        cout << "Updated:" << endl;
    }
    void displayIssuedBooks()
    {
        if (borrowed == 0)
        {
            cout << "This user has not issued any books!" << endl;
            return;
        }
        cout << "Books issued by " << name << ":" << endl;
        books[0].displayIssuedBookHeading();
        for (int i = 0; i < borrowed; i++)
        {
            books[i].display();
        }
    }
    friend void issueBook(User &u, Book &b);
    friend void returnBook(User &u, Book &b);
};
class Student : public User
{
public:
    Student() {}
    Student(string n, int a) : User(n, a)
    {
        type = "Student";
        maxDaysAllowed = 15;
        finePerDay = 2;
        totalFine = 0;
    }

    void display()
    {
        User::display();
        cout << "|" << setw(8) << type << endl;
    }
};
class Faculty : public User
{
public:
    Faculty() {}
    Faculty(string n, int a) : User(n, a)
    {
        type = "Faculty";
        maxDaysAllowed = 30;
        finePerDay = 1;
        totalFine = 0;
    }

    void display()
    {
        User::display();
        cout << "|" << setw(8) << type << endl;
    }
};
class Guest : public User
{
public:
    Guest() {}
    Guest(string n, int a) : User(n, a)
    {
        type = "Guest";
        maxDaysAllowed = 7;
        finePerDay = 5;
        totalFine = 0;
    }

    void display()
    {
        User::display();
        cout << "|" << setw(8) << type << endl;
    }
};
Date enterDate()
{
    int flag = 0;
    int d, m, y;
    while (!flag)
    {
        try
        {
            cout << "Enter date, month and year:" << endl;
            cin >> d >> m >> y;
            Date temp(d, m, y);
            flag = 1;
            return temp;
        }
        catch (int i)
        {
            cout << "Invalid date! Please enter again." << endl;
        }
    }
}
void issueBook(User &u, Book &b)
{
    if (u.borrowed >= 10)
    {
        cout << "You can't borrow more than 10 books!" << endl;
        return;
    }
    if (b.available <= 0)
    {
        cout << "Book is not available!" << endl;
        return;
    }
    int id = b.bookId;
    cout << "Enter today's issue date:" << endl;
    Date issuedDate = enterDate();
    IssuedBook isb(id, issuedDate);
    u.books[u.borrowed] = isb;
    u.borrowed++;
    b.available--;
    b.issued++;
    cout << "-----------------------------------------" << endl;
    cout << "Book Issued!!" << endl;
    cout << "-----------------------------------------" << endl;
    u.displayIssuedBooks();
}
void returnBook(User &u, Book &b)
{
    int found = 0;
    for (int i = 0; i < u.borrowed; i++)
    {
        int tempId = u.books[i].getIssuedId();
        if (tempId == b.bookId)
        {
            found = 1;
            cout << "Enter today's return date:" << endl;
            Date today = enterDate();
            int d1 = today.getDays();
            Date issue = u.books[i].getIssuedDate();
            int d2 = issue.getDays();
            if (d1 < d2)
            {
                cout << "Return day cannot be before issued date!!" << endl;
                return;
            }
            if (d1 - d2 > u.maxDaysAllowed)
            {
                int delay = d1 - d2 - u.maxDaysAllowed;
                u.totalFine = delay * u.finePerDay;
                cout << "You are returning this book " << delay << " days late!" << endl;
                cout << "Pay Fine of rupees: " << u.totalFine << endl;
                int paid = 0;
                cout << "Enter 1: If it is paid" << endl;
                cout << "Enter 0: If not" << endl;
                cout << "Enter.." << endl;
                cin >> paid;
                if (paid == 1)
                {
                    u.totalFine = 0;
                    for (int j = i; j < u.borrowed - 1; j++)
                    {
                        u.books[j] = u.books[j + 1];
                    }
                    u.borrowed--;
                    b.available++;
                    b.issued--;
                    cout << "-----------------------------------------" << endl;
                    cout << "Book returned!!" << endl;
                    cout << "-----------------------------------------" << endl;
                    u.displayIssuedBooks();
                }
                else
                {
                    cout << "Pay your fine first!!" << endl;
                    return;
                }
            }
            else
            {
                for (int j = i; j < u.borrowed - 1; j++)
                {
                    u.books[j] = u.books[j + 1];
                }
                u.borrowed--;
                b.available++;
                b.issued--;
                cout << "-----------------------------------------" << endl;
                cout << "Book returned!!" << endl;
                cout << "-----------------------------------------" << endl;

                u.displayIssuedBooks();
            }
            break;
        }
    }
    if (!found)
    {
        cout << "This book is not issued by this user!!" << endl;
    }
}
int Book::nextBookId = 1;
int User::nextId = 1;
int main()
{
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "-----------------------------------------" << endl;
    char ch;
    Book b[1000];
    Student s[100];
    Faculty f[100];
    Guest g[100];
    int userCount = 0;
    int sCount = 0;
    int fCount = 0;
    int gCount = 0;
    int number = 0;
    do
    {
        int choice;
        cout << "01. Add Books" << endl;
        cout << "02. Update Book" << endl;
        cout << "03. Display Information of All Books" << endl;
        cout << "04. Display Information of a Book" << endl;
        cout << "05. Add user" << endl;
        cout << "06. Update user" << endl;
        cout << "07. Display all users" << endl;
        cout << "08. Display student users" << endl;
        cout << "09. Display Faculty users" << endl;
        cout << "10. Display Guest users" << endl;
        cout << "11. Display a user" << endl;
        cout << "12. Remove User" << endl;
        cout << "13. Issue a book" << endl;
        cout << "14. Return a book" << endl;
        cout << "15. Display Books Issued by a User" << endl;
        cout << "Enter.." << endl;
        cin >> choice;
        if (choice == 1)
        {
            int n;
            cout << "Enter number of books: " << endl;
            cin >> n;
            if (n < 0 || n > 1000 - number)
            {
                cout << "Invalid number of books!!" << endl;
            }
            else
            {
                int start = number;
                number += n;
                for (int i = start; i < number; i++)
                {
                    int pgs, avl, iss;
                    string name;
                    cout << "Enter Details of " << i + 1 << " book" << endl;
                    cout << "Enter Book name, pages, avaiable copies and issued copies:" << endl;
                    cin >> name >> pgs >> avl >> iss;
                    b[i] = Book(name, pgs, avl, iss);
                }
                b[0].displayBookHeading();
                for (int i = start; i < number; i++)
                {
                    b[i].display();
                }
            }
        }
        else if (choice == 2)
        {
            int id;
            int found = 0;
            cout << "Enter ID of book" << endl;
            cin >> id;
            for (int i = 0; i < number; i++)
            {
                int bId = b[i].getId();
                if (id == bId)
                {
                    found = 1;
                    int upCh;
                    cout << "This information is stored" << endl;
                    b[i].displayBookHeading();
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
            if (!found)
            {
                cout << "Book not found" << endl;
            }
        }
        else if (choice == 3)
        {
            b[0].displayBookHeading();
            for (int i = 0; i < number; i++)
            {
                b[i].display();
            }
        }
        else if (choice == 4)
        {
            int found = 0;
            int id;
            cout << "Enter id of book:" << endl;
            cin >> id;
            for (int i = 0; i < number; i++)
            {
                int bId = b[i].getId();
                if (bId == id)
                {
                    found = 1;
                    b[i].displayBookHeading();
                    b[i].display();
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (choice == 5)
        {
            int n;
            cout << "Enter number of users: " << endl;
            cin >> n;
            if (n < 0 || n > 100)
            {
                cout << "User cannot be created!!" << endl;
            }
            else
            {
                int uChoice;
                cout << "1. Student users" << endl;
                cout << "2. Faculty users" << endl;
                cout << "3. Guest users" << endl;
                cin >> uChoice;

                if (uChoice == 1)
                {
                    if (100 - sCount < n)
                    {
                        cout << "Could not create student users!" << endl;
                    }
                    else
                    {
                        userCount += n;
                        int start = sCount;
                        sCount += n;
                        for (int i = start; i < sCount; i++)
                        {
                            int age;
                            string name;
                            cout << "Enter User Name and age" << endl;
                            cin >> name >> age;
                            s[i] = Student(name, age);
                        }
                        s[0].displayUserHeading();
                        for (int i = start; i < sCount; i++)
                        {
                            s[i].display();
                        }
                    }
                }
                else if (uChoice == 2)
                {
                    if (100 - fCount < n)
                    {
                        cout << "Could not create faculty users!" << endl;
                    }
                    else
                    {
                        userCount += n;
                        int start = fCount;
                        fCount += n;
                        for (int i = start; i < fCount; i++)
                        {
                            int age;
                            string name;
                            cout << "Enter User Name and age" << endl;
                            cin >> name >> age;
                            f[i] = Faculty(name, age);
                        }
                        f[0].displayUserHeading();
                        for (int i = start; i < fCount; i++)
                        {
                            f[i].display();
                        }
                    }
                }
                else if (uChoice == 3)
                {
                    if (100 - gCount < n)
                    {
                        cout << "Could not create student users!" << endl;
                    }
                    else
                    {
                        userCount += n;
                        int start = gCount;
                        gCount += n;
                        for (int i = start; i < gCount; i++)
                        {
                            int age;
                            string name;
                            cout << "Enter User Name and age" << endl;
                            cin >> name >> age;
                            g[i] = Guest(name, age);
                        }
                        g[0].displayUserHeading();
                        for (int i = start; i < gCount; i++)
                        {
                            g[i].display();
                        }
                    }
                }
                else
                {
                    cout << "Invalid Choice!" << endl;
                }
            }
        }
        else if (choice == 6)
        {
            int id;
            cout << "Enter User ID: " << endl;
            cin >> id;
            int uChoice;
            cout << "1. Update name" << endl;
            cout << "2. Update age" << endl;
            cout << "3. Update both" << endl;
            cout << "Enter.." << endl;
            cin >> uChoice;
            int found = 0;
            for (int i = 0; i < sCount; i++)
            {
                if (id == s[i].getId())
                {
                    found = 1;
                    if (uChoice == 1)
                    {
                        s[i].displayUserHeading();
                        s[i].display();
                        s[i].updateName();
                        s[i].displayUserHeading();
                        s[i].display();
                    }
                    else if (uChoice == 2)
                    {
                        s[i].displayUserHeading();
                        s[i].display();
                        s[i].updateAge();
                        s[i].displayUserHeading();
                        s[i].display();
                    }
                    else if (uChoice == 3)
                    {
                        s[i].displayUserHeading();
                        s[i].display();
                        s[i].updateUser();
                        s[i].displayUserHeading();
                        s[i].display();
                    }
                    else
                    {
                        cout << "Invalid Choice!" << endl;
                    }
                    break;
                }
            }
            if (!found)
            {
                for (int i = 0; i < fCount; i++)
                {
                    if (id == f[i].getId())
                    {
                        found = 1;
                        if (uChoice == 1)
                        {
                            f[i].displayUserHeading();
                            f[i].display();
                            f[i].updateName();
                            f[i].displayUserHeading();
                            f[i].display();
                        }
                        else if (uChoice == 2)
                        {
                            f[i].displayUserHeading();
                            f[i].display();
                            f[i].updateAge();
                            f[i].displayUserHeading();
                            f[i].display();
                        }
                        else if (uChoice == 3)
                        {
                            f[i].displayUserHeading();
                            f[i].display();
                            f[i].updateUser();
                            f[i].displayUserHeading();
                            f[i].display();
                        }
                        else
                        {
                            cout << "Invalid Choice!" << endl;
                        }
                        break;
                    }
                }
            }
            if (!found)
            {
                for (int i = 0; i < gCount; i++)
                {
                    if (id == g[i].getId())
                    {
                        found = 1;
                        if (uChoice == 1)
                        {
                            g[i].displayUserHeading();
                            g[i].display();
                            g[i].updateName();
                            g[i].displayUserHeading();
                            g[i].display();
                        }
                        else if (uChoice == 2)
                        {
                            g[i].displayUserHeading();
                            g[i].display();
                            g[i].updateAge();
                            g[i].displayUserHeading();
                            g[i].display();
                        }
                        else if (uChoice == 3)
                        {
                            g[i].displayUserHeading();
                            g[i].display();
                            g[i].updateUser();
                            g[i].displayUserHeading();
                            g[i].display();
                        }
                        else
                        {
                            cout << "Invalid Choice!" << endl;
                        }
                        break;
                    }
                }
            }
            if (!found)
            {
                cout << "User not found!" << endl;
            }
        }
        else if (choice == 7)
        {
            s[0].displayUserHeading();
            for (int i = 0; i < sCount; i++)
            {
                s[i].display();
            }
            for (int i = 0; i < fCount; i++)
            {
                f[i].display();
            }
            for (int i = 0; i < gCount; i++)
            {
                g[i].display();
            }
        }
        else if (choice == 8)
        {
            s[0].displayUserHeading();
            for (int i = 0; i < sCount; i++)
            {
                s[i].display();
            }
        }
        else if (choice == 9)
        {
            f[0].displayUserHeading();
            for (int i = 0; i < fCount; i++)
            {
                f[i].display();
            }
        }
        else if (choice == 10)
        {
            g[0].displayUserHeading();
            for (int i = 0; i < gCount; i++)
            {
                g[i].display();
            }
        }
        else if (choice == 11)
        {
            int id;
            cout << "Enter User ID: " << endl;
            cin >> id;
            int found = 0;
            for (int i = 0; i < sCount; i++)
            {
                if (id == s[i].getId())
                {
                    s[i].displayUserHeading();
                    s[i].display();
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                for (int i = 0; i < fCount; i++)
                {
                    if (id == f[i].getId())
                    {
                        f[i].displayUserHeading();
                        f[i].display();
                        found = 1;
                        break;
                    }
                }
            }
            if (!found)
            {
                for (int i = 0; i < gCount; i++)
                {
                    if (id == g[i].getId())
                    {
                        g[i].displayUserHeading();
                        g[i].display();
                        found = 1;
                        break;
                    }
                }
            }
            if (!found)
            {
                cout << "User not found!" << endl;
            }
        }
        else if (choice == 12)
        {
            int id;
            cout << "Enter User ID: " << endl;
            cin >> id;
            int found = 0;
            for (int i = 0; i < sCount; i++)
            {
                if (id == s[i].getId())
                {
                    if (s[i].getBorrowed() > 0)
                    {
                        found = 1;
                        cout << "User has borrowed book!" << endl;
                        cout << "User deletation failed!" << endl;
                    }
                    else
                    {
                        for (int j = i; j < sCount - 1; j++)
                        {
                            s[j] = s[j + 1];
                        }
                        sCount--;
                        found = 1;
                        cout << "-----------------------------------------" << endl;
                        cout << "User Removed" << endl;
                        cout << "-----------------------------------------" << endl;
                        break;
                    }
                }
            }
            if (!found)
            {
                for (int i = 0; i < fCount; i++)
                {
                    if (id == f[i].getId())
                    {
                        if (f[i].getBorrowed() > 0)
                        {
                            found = 1;
                            cout << "User has borrowed book!" << endl;
                            cout << "User deletation failed!" << endl;
                        }
                        else
                        {
                            for (int j = i; j < fCount - 1; j++)
                            {
                                f[j] = f[j + 1];
                            }
                            fCount--;
                            found = 1;
                            cout << "-----------------------------------------" << endl;
                            cout << "User Removed" << endl;
                            cout << "-----------------------------------------" << endl;
                            break;
                        }
                    }
                }
            }
            if (!found)
            {
                for (int i = 0; i < gCount; i++)
                {
                    if (id == g[i].getId())
                    {
                        if (g[i].getBorrowed() > 0)
                        {
                            found = 1;
                            cout << "User has borrowed book!" << endl;
                            cout << "User deletation failed!" << endl;
                        }
                        else
                        {
                            for (int j = i; j < gCount - 1; j++)
                            {
                                g[j] = g[j + 1];
                            }
                            gCount--;
                            found = 1;
                            cout << "-----------------------------------------" << endl;
                            cout << "User Removed" << endl;
                            cout << "-----------------------------------------" << endl;
                            break;
                        }
                    }
                }
            }
            if (!found)
            {
                cout << "User not found!" << endl;
            }
        }
        else if (choice == 13)
        {
            int bId, uId, found = 0;
            cout << "Enter Book ID:" << endl;
            cin >> bId;
            for (int i = 0; i < number; i++)
            {
                if (b[i].getId() == bId)
                {
                    found = 1;
                    int id;
                    cout << "Enter User ID:" << endl;
                    cin >> id;
                    int userFound = 0;
                    for (int j = 0; j < sCount; j++)
                    {
                        if (s[j].getId() == id)
                        {
                            userFound = 1;
                            issueBook(s[j], b[i]);
                            break;
                        }
                    }
                    if (!userFound)
                    {
                        for (int j = 0; j < fCount; j++)
                        {
                            if (f[j].getId() == id)
                            {
                                userFound = 1;
                                issueBook(f[j], b[i]);
                                break;
                            }
                        }
                    }
                    if (!userFound)
                    {
                        for (int j = 0; j < gCount; j++)
                        {
                            if (g[j].getId() == id)
                            {
                                userFound = 1;
                                issueBook(g[j], b[i]);
                                break;
                            }
                        }
                    }
                    if (!userFound)
                    {
                        cout << "User not found!" << endl;
                    }
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (choice == 14)
        {
            int bId, uId, found = 0;
            cout << "Enter Book ID:" << endl;
            cin >> bId;
            for (int i = 0; i < number; i++)
            {
                if (b[i].getId() == bId)
                {
                    found = 1;
                    int id;
                    cout << "Enter User ID:" << endl;
                    cin >> id;
                    int userFound = 0;
                    for (int j = 0; j < sCount; j++)
                    {
                        if (s[j].getId() == id)
                        {
                            userFound = 1;
                            returnBook(s[j], b[i]);
                            break;
                        }
                    }
                    if (!userFound)
                    {
                        for (int j = 0; j < fCount; j++)
                        {
                            if (f[j].getId() == id)
                            {
                                userFound = 1;
                                returnBook(f[j], b[i]);
                                break;
                            }
                        }
                    }
                    if (!userFound)
                    {
                        for (int j = 0; j < gCount; j++)
                        {
                            if (g[j].getId() == id)
                            {
                                userFound = 1;
                                returnBook(g[j], b[i]);
                                break;
                            }
                        }
                    }
                    if (!userFound)
                    {
                        cout << "User not found!" << endl;
                    }
                    break;
                }
            }
            if (!found)
            {
                cout << "Book not found!" << endl;
            }
        }
        else if (choice == 15)
        {
            int id;
            int found = 0;
            cout << "Enter User ID:" << endl;
            cin >> id;
            for (int i = 0; i < sCount; i++)
            {
                if (s[i].getId() == id)
                {
                    s[i].displayIssuedBooks();
                    found = 1;
                    break;
                }
            }
            if (!found)
            {
                for (int i = 0; i < fCount; i++)
                {
                    if (f[i].getId() == id)
                    {
                        f[i].displayIssuedBooks();
                        found = 1;
                        break;
                    }
                }
            }
            if (!found)
            {
                for (int i = 0; i < gCount; i++)
                {
                    if (g[i].getId() == id)
                    {
                        g[i].displayIssuedBooks();
                        found = 1;
                        break;
                    }
                }
            }
            if (!found)
            {
                cout << "User not found!" << endl;
            }
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
        cout << "Do you want to continue?(Enter y for yes)" << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << "-----------------------------------------" << endl;
    cout << "THANK YOU FOR USING SYSTEM" << endl;
    cout << "-----------------------------------------" << endl;
    return 0;
}