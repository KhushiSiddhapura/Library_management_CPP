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
    friend void issueBook(User &u, Book &b);
    friend void returnBook(User &u, Book &b);
};

class Date
{
    int date, month, year;

public:
    Date()
    {
        date = 1;
        month = 1;
        year = 2000;
    }
    Date(int d, int m, int y)
    {
        if (y >= 2000)
        {
            year = y;
        }
        else
        {
            year = 2000;
            cout << "Entered year is invalid!" << endl
                 << "Setting it to default year(2000)" << endl;
        }
        if (m > 0 && m <= 12)
        {
            month = m;
            if (m == 4 || m == 6 || m == 9 || m == 11)
            {
                if (d > 0 && d <= 30)
                {
                    date = d;
                }
                else
                {
                    date = 1;
                    cout << "Entered date is invalid" << endl
                         << "Setting it to default date(1)" << endl;
                }
            }
            else if (m == 2)
            {
                if (isLeapYear(year))
                {
                    if (d > 0 && d <= 29)
                    {
                        date = d;
                    }
                    else
                    {
                        date = 1;
                        cout << "Entered date is invalid" << endl
                             << "Setting it to default date(1)" << endl;
                    }
                }
                else
                {
                    if (d > 0 && d <= 28)
                    {
                        date = d;
                    }
                    else
                    {
                        date = 1;
                        cout << "Entered date is invalid" << endl
                             << "Setting it to default date(1)" << endl;
                    }
                }
            }
            else
            {
                if (d > 0 && d <= 31)
                {
                    date = d;
                }
                else
                {
                    date = 1;
                    cout << "Entered date is invalid" << endl
                         << "Setting it to default date(1)" << endl;
                }
            }
        }
        else
        {
            month = 1;
            date = 1;
            cout << "Entered month is invalid" << endl
                 << "Setting date and month to default (1st January)" << endl;
        }
    }
    void displayDate()
    {
        cout << date << "/" << month << "/" << year << endl;
    }
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
    int getDate()
    {
        return date;
    }
    int getMonth()
    {
        return month;
    }
    int getYear()
    {
        return year;
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
    void display()
    {
        cout << "-----------------------------------------" << endl;
        cout << "Issued Book:" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "Book Id: " << IssuedBId << endl;
        cout << "Issued date";
        issueDate.displayDate();
    }
};

class User
{
    int userId;
    string name;
    int age;
    IssuedBook books[10];
    int borrowed;
    int maxDaysAllowed;
    int finePerDay;
    int totalFine;

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
    User(int id, string n, int a)
    {
        userId = id;
        name = n;
        age = a;
        borrowed = 0;
    }
    void display()
    {
        cout << "User ID: " << userId << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    void updateName()
    {
        display();
        cout << "Enter updated name of user:" << endl;
        cin >> name;
    }
    void updateAge()
    {
        display();
        cout << "Enter updated age of user:" << endl;
        cin >> age;
    }
    void updateUser()
    {
        display();
        cout << "Enter updated name and age of user:" << endl;
        cin >> name >> age;
    }
    friend void issueBook(User &u, Book &b);
    friend void returnBook(User &u, Book &b);
};

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
    int d, m, y;
    cout << "Enter today's date, month and year: " << endl;
    cin >> d >> m >> y;
    Date issuedDate(d, m, y);
    IssuedBook isb(id, issuedDate);
    u.books[u.borrowed] = isb;
    u.borrowed++;
    b.available--;
    b.issued++;
    cout << "-----------------------------------------" << endl;
    cout << "Book Issued!!" << endl;
    cout << "-----------------------------------------" << endl;
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
            int d, m, y;
            cout << "Enter today's date,month and year:" << endl;
            cin >> d >> m >> y;
            Date today(d, m, y);
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
                cout << "Pay Fine of rupees: " << u.totalFine;
                int paid = 0;
                cout << "1. If it is paid" << endl;
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
            }
            break;
        }
    }
    if (!found)
    {
        cout << "This book is not issued by this user!!" << endl;
    }
}

int main()
{
    cout << "-----------------------------------------" << endl;
    cout << "WELCOME TO LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "-----------------------------------------" << endl;
    char ch;
    Book b[1000];
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
            if (n < 0 || n > 1000)
            {
                cout << "Invalid number of books!!" << endl;
            }
            else
            {
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
                else
                {
                    cout << "Book not found!" << endl;
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
                else
                {
                    cout << "Book not found!" << endl;
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