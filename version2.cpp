// libriaries

#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
using namespace std;

// variables
const int size = 50;
int counter = 0;
int Tseats = 30;
int discount;
string description = "Travel and Enjoy with us";
string contact = "0302-9614436";
string email = "faisalmovers@gmail.com";
int seat5= 0 ;
string comment;

//  functions
void topHeader();
bool signUp(string name, string password, string role);
string signIn(string name, string password);
int loginMenu();
int userMenu();
int adminMenu();
//  admin functions
void setfare(string city);
void seatRecord();
void bill_discount();
int bill(string city, int seat);
void admin_aboutUs();
void viewFeedback();

// user function
void checkFare();
void destinations();
void user_aboutUs();
void book_seat();
void userFeedback();
void pay_bill();


// arrays
string isname[size];
string ispassword[size];
string isrole[size];
string setcity[5] = {"islamabad", "faisalabad", "karachi", "sialkot", "rahim-yar-khan"};
int setprice[5] = {400, 500, 600, 700, 800};
string feedBacker[size];
string feedBack[size];

main()
{
    string name, password, role;
    int number;
    while (number != 3)
    {
        number = loginMenu();

        if (number == 1)
        {
            cout << "enter name:";
            cin >> name;
            cout << "enter password:";
            cin >> password;
            cout << "enter catagort e.g user or admin:";
            cin >> role;
            bool valid = signUp(name, password, role);
            if (valid == true)
            {
                cout << "          REGISTERED SUCCESSFULLY:" << endl;
                cout << "enter a key to continue";
                getch();
            }
            else
            {
                cout << "User already present " << endl;
                cout<<"Press any key to continue ";
                getch();
            }
        }
        else if (number == 2)
        {
            cout << "enter your name:";
            cin >> name;
            cout << "enter password:";
            cin >> password;
            string valid = signIn(name, password);
            cout << valid << endl;
            cout << "        SIGNED IN SUCCESSFULLY" << endl;
            cout << "enter a key to continue:";
            getch();
            if (valid == "user")
            {

                while (number != 7)
                {
                    system("cls");
                    number = userMenu();
                    if (number == 1)
                    {
                        system("cls");
                        topHeader();
                        checkFare();
                        cout << endl;
                        cout << "enter a character to move back:";
                        getch();
                    }
                    if (number == 2)
                    {
                        system("cls");
                        topHeader();
                        destinations();
                        cout << endl;
                        cout << "enter a character to move back:";
                        getch();
                    }

                    if (number == 3)
                    {
                        system("cls");
                        topHeader();
                        book_seat();
                        cout << endl;
                        cout << "enter a character to move back:";
                        getch();
                    }

                    if (number == 4)
                    {

                        system("cls");
                        topHeader();
                        user_aboutUs();
                        cout<< endl;
                        cout<< "enter a character to move back:";
                        getch();
                    }
                    if(number==5)
                    {
                        system("cls");
                        topHeader();
                        userFeedback();
                        cout<< endl;
                        cout<<"enter a character to move back:";
                        getch();
                    }
                }
            }
            else if (valid == "admin")
            {
                while (number != 7)
                {
                    number = adminMenu(); // return from admin

                    if (number == 1)
                    {
                        system("cls");
                        topHeader();
                        string city;
                        cout << "enter the name of city you want to set fare:";
                        cin >> city;
                        setfare(city);
                        cout << endl;
                        cout << "enter a character to move back";
                        getch();
                    }
                    if (number == 2)
                    {
                        
                        system("cls");
                        topHeader();
                        // cout << "enter the number of occupied seats:";
                        // cin >> seat;
                        seatRecord();
                        cout << endl;
                        cout << "enter a character to move back";
                        getch();
                    }
                    if (number == 3)
                    {
                        system("cls");
                        topHeader;
                        bill_discount();
                        cout << endl;
                        cout << "enter a character to move back";
                        getch();
                    }
                    if (number == 4)
                    {
                        system("cls");
                        topHeader();
                        admin_aboutUs();
                        cout << endl;
                        cout << "enter a key to move back:";
                        getch();
                    }
                    if(number== 5)
                    {
                        system("cls");
                        topHeader();
                        viewFeedback();
                        cout << endl;
                        cout << "enter a key to move back:";
                        getch();
                    }
                }
            }
        }
    }
}
void pay_bill()
{}
void viewFeedback()
{
    for(int idx = 0; idx<counter; idx++)
    {
        cout<<feedBacker[idx] <<"\t"<<feedBack[idx];
    }
}

void userFeedback()
{
    char confirmation;
    cout<<"do you wnat to give feedback? (Y/N)";
    cin>>confirmation;
    if(confirmation=='y' || confirmation=='Y')
    {

        cout<<"enter your name:";
        cin>>feedBacker[counter];

        getline(cin,comment);
        cout<<"enter your comment:";
        getline(cin,feedBack[counter]);
        counter++;
    } 
}
void book_seat()
{
    // string destination;
    // cout<<"enter the name of city you want to book";
    // cin>>destination;
    bill_discount();
    cout<<endl;
}

void destinations()
{
    for (int idx = 0; idx < 5; idx++)
    {
        cout << idx + 1 << "." << setcity[idx] << endl;
    }
}

void checkFare()
{
    for (int idx = 0; idx < 5; idx++)
    {
        cout << idx + 1 << "." << setcity[idx] << " ::" << setprice[idx] << endl;
    }
}

void admin_aboutUs()
{
    char confirmation;
    cout<< "About us : "<<endl;
    cout<< "     " << description<<endl;
    cout<< "Contact us at : "<<contact<<endl;
    cout<< "Email : "<<email<<endl;
    cout<< "Do you want to change ABOUT US? (Y/N)";
    cin>> confirmation;
    if (confirmation == 'y' || confirmation == 'Y')
    {
        string info;
        cout<<"Enter "<<endl;
        getline(cin, info);
        cout<<"About us : "<<endl;
        getline(cin, description);
        cout<<"Contact us at : ";
        getline(cin, contact);
        cout<<"Email. : ";
        getline(cin, email);
    }
    user_aboutUs();
}

void user_aboutUs()
{
    cout<< "About Us :"<<endl;
    cout<<"\t"<<description<<endl;
    cout<<"Contact us at :"<<contact<<endl;
    cout<<"Email :"<<email<<endl;
}

void bill_discount()
{

    string city;
    cout << "enter the name of city:";
    cin >> city;
    cout << "enetr the number of seats:";
    cin >> seat5;
    int new_bill = bill(city, seat5);
    string day1;
    cout << "enter the day ::";
    cin >> day1;

    if (day1 == "sunday" || day1 == "saturday")
    {
        new_bill = new_bill - (discount * new_bill) / 100;
        cout << "bill after discount::" << new_bill;
    }
    else
    {
        cout << "the bill is :" << new_bill;
    }
}
int bill(string city, int seat)
{
    int bill;
    for (int idx = 0; idx < 5; idx++)
    {
        if (city == setcity[idx])
        {
            bill = seat * setprice[idx];
        }
    }
    return bill;
}

void seatRecord()
{
    Tseats = Tseats - seat5;
    cout << "remaining seats are::" << Tseats;
}

void setfare(string city)
{

    for (int idx = 0; idx < 5; idx++)
    {
        if (city == setcity[idx])
        {
            cout << "Enter Price ";
            cin >> setprice[idx];
        }
    }

    for (int idx = 0; idx < 5; idx++)
    {
        cout << setprice[idx] << endl;
    }
}

void topHeader()
{
    cout << "###################################################" << endl;
    cout << "#                                                 #" << endl;
    cout << "#                                                 #" << endl;
    cout << "#               FAISAL MOVERS                     #" << endl;
    cout << "#                                                 #" << endl;
    cout << "#                                                 #" << endl;
    cout << "###################################################" << endl;
    cout << endl;
    cout << "                   WELCOME" << endl;
}

int loginMenu()
{
    system("cls");
    topHeader();
    int number1;
    cout << "1.register yourself:" << endl;
    cout << "2.login yourself:" << endl;
    cout << "3.Exit" << endl;
    cout << "please enter the choice:" << endl;
    cin >> number1;
    return number1;
}

int userMenu()
{
    system("cls");
    topHeader();
    int number1;
    cout << "         USER MENU" << endl;
    cout << "1. Check fare" << endl;
    cout << "2. Destnations" << endl;
    cout << "3. Book seat" << endl;
    cout << "4. Info About Company" << endl;
    cout << "5. Feedback/suggestions" << endl;
    cout << "6. Pay Bill" << endl;
    cout << "7. Exit" << endl;
    cout << "enter the number:";
    cin >> number1;
    return number1;
}

int adminMenu()
{
    system("cls");
    topHeader();
    int number1;
    cout << "             AMDIN MENUE" << endl;
    cout << "1. set fares" << endl;
    cout << "2. seat records" << endl;
    cout << "3. Bills/discount" << endl;
    cout << "4. About Us" << endl;
    cout << "5. view Feedback" << endl;
    cout << "6. change drive" << endl;
    cout << "7. Exit" << endl;
    cout << "enter a number";
    cin >> number1;
    return number1;
}

bool signUp(string name, string password, string role)
{
    bool check = false;
    system("cls");
    topHeader();
    for (int i = 0; i < counter; i++)
    {
        if (isname[i] == name && ispassword[i] == password)
        {
            check = true;
        }
    }
    if (check == true)
    {
        return 0;
        cout << "User already present " << endl;
        cout << "Press any key to continue....";
        getch();
    }
    else if (counter < size)
    {
        isname[counter] = name;
        ispassword[counter] = password;
        isrole[counter] = role;
        counter++;
        return true;
    }
    else
    {
        return false;
    }
}
string signIn(string name, string password)
{
    string output;
    for (int idx = 0; idx < counter; idx++)
    {
        if (isname[idx] == name && ispassword[idx] == password)
        {
            output = isrole[idx];
        }
    }
    return output;
}
