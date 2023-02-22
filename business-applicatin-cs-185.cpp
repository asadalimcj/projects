#include<iostream>    // there are few function which will be completed in the next version.
#include<cmath>
#include<conio.h>
#include<windows.h>
using namespace std;
void topHeader();
int number;
const int size = 50;
bool signUp(string name1, string password1, string role1);
string signIn(string name1, string password1);
int arraysize[10];
int loginMenu();
int userMenu();
int adminMenu();
string name[size];
string password[size];
string role[size];
int counter = 0;
string name1, password1, role1,city1;
void setfare();
string city[5] = {"islamabad", "faisalabad", "karachi", "sialkot", "rahim-yar-khan"};
int price[5] = {400, 500, 600, 700,800};
void destinaation();
int price1;
void seatRecord();
int Tseat = 30;
int seat, rem_seat;
int bill();
void discount();
int discount1 = 50;
string day[] = {"sunday", "saturday"};
void provideInfo();
// user functions
void checkFare();
void destinations();
void bookSeat();
bool checkAcount();


main()
{
   // int number, number1, number2;

    while(number!=3)
    {
        number = loginMenu();

        if(number==1) //register
        {

            cout<<"enter name:";

            cin>>name1;

            cout<<"enter password:";

            cin>>password1;

            cout<<"enter catagort e.g user or admin:";

            cin>>role1;


            bool valid = signUp(name1, password1, role1);
            cout<<"registerd:"<<endl;
            cout<<"enter a key to continue";
            getch();
        }
        else if(number==2)
        {
            cout<<"enter your name:";
            cin>>name1;
            cout<<"enter password:";
            cin>>password1;
            string valid = signIn(name1, password1);
            cout <<valid <<endl;
            cout<<"enter a key to continue:";
            getch();
            if(valid =="user")
            {
                // system("cls");
                // number = userMenu();// return from user
                while(number!=4)
                {
                    system("cls");
                    number = userMenu();// return from user
                   
                    if(number==1)
                    {
                        system("cls");
                        topHeader();
                        checkFare();
                        cout<<endl;
                        cout<<"enter a letter to move back:";
                        getch();
                    }
                    if(number==2)
                    {
                        system("cls");
                        topHeader();
                        destinations();
                        cout<<endl;
                        cout<<"enter a key to move back:";
                        getch();

                    }
                    if(number==3)
                    {
                        system("cls");
                        topHeader();
                        bookSeat();
                        cout<<endl;
                        cout<<"the seat is reserved for you:";
                        cout<<endl;
                        cout<<"enter a key to move back:";
                        getch();
                    }
                  

                }
               
   
            }
            else if(valid=="admin")
            {
                while(number!=7)
                {
                    number = adminMenu();//return from admin
                    
                    if(number==1)
                    {
                        system("cls");
                        
                        topHeader();
                        setfare();
                        cout<<endl;
                        cout<<"enter a key to move back";
                        getch();

                    }
                    if(number==2)
                    {
                        system("cls");
                        topHeader();
                        seatRecord();
                        cout<<endl;
                        cout<<"enter a key to move back";
                        getch();
                    }
                    if(number==3)
                    {
                        system("cls");
                        topHeader();
                        discount();
                        cout<<endl;
                        cout<<"enter a key to move back";
                        getch();
                    }
                    // if(number==4)
                    // {
                    //     system("cls");
                    //     topHeader();
                    //     provideInfo();
                    //     cout<<endl;
                    //     cout<<"enter a key to move back";
                    //     getch();
                    // }
                    
                }
              
            }
            
           
        }
    }
    
}
void bookSeat()
{
    discount();
    cout<<endl;
    seatRecord();
    // cout<<"enter the name of city:";
    // cin>>city1;
    // for(int idx = 0; idx<5; idx++)
    // {
    //     if(city1==city[idx])
    //     {

    //     }
    // }
    
}
void destinations()
{
    for(int idx = 0; idx<5; idx++)
    {
        cout<<idx+1<<"."<<city[idx]<<endl;
    }
}
void checkFare()
{
    for(int idx = 0; idx<5; idx++)
    {
        cout<<city[idx]<<" ::"<<price[idx]<<endl;
    }
}
void provideInfo()
{
    string info;
    cout<<"INFORMATION ABOUT OUR SERVICE::";
    (cin,info);
    // cout<<"We are providing travelling services to the people"<<endl;
    // cout<<" for last fifteen years. we travel toward big sities "<<endl;
    // cout<<"of country. our services are been appriated "
}
void discount()
{
    int new_bill;
    new_bill = bill();
    string day1;
    cout<<"enter the day ::";
    cin>>day1;
   
    if(day1=="sunday" || day1=="saturday")
    {
        // cout<<"enter the discount percent::";
        // cin>>discount1;
        new_bill = new_bill-(discount1*new_bill)/100;
        cout<<"bill after discount::"<<new_bill;
    }
    else
    {
        cout<<"the bill is :"<<new_bill;
    }
    
}
int bill()
{
    string city1;
    int seat;
    int bill;
    cout<<"inter the name of city:";
    cin>>city1;
    cout<<"enter number of seats :";
    cin>>seat;
    for(int idx = 0; idx<5; idx++)
    {
        if(city1==city[idx])
        {
            bill = seat*price[idx];
        }
    }
    return bill;
    // cout<<"the bill is:"<<bill;
}
void seatRecord()
{
    
    cout<<"enter number of occupied seats:";
    cin>>seat;
    rem_seat = Tseat-seat;
    cout<<"remaining seats are::"<<rem_seat;
}
void setfare()
{
    int idx = 0;
    for(idx = 0;idx<5; idx++)
    {
        cout<<"enter city name:";
        cin>>city1;
        for(int idx = 0; idx<5; idx++)
        {
            if(city1==city[idx])
            {
                cout<<"enter new price:";
                cin>>price1;
                price[idx] = price1;
            
            }
        
        }
       

    }
    // for(int idx = 0; idx<5; idx++)
    // {
    //     cout<<price[idx]<<endl;
    // }
        
    
   

}

void topHeader()
{
    cout<<"###################################################"<<endl;
    cout<<"#                                                 #"<<endl;
    cout<<"#                                                 #"<<endl;
    cout<<"#               FAISAL MOVERS                     #"<<endl;
    cout<<"#                                                 #"<<endl;
    cout<<"#                                                 #"<<endl;
    cout<<"###################################################"<<endl;
    cout<<endl;
    cout<<"                   WELCOME"<<endl;
}

int loginMenu()
{
    system("cls");
    topHeader();
    int number1;
    cout<<"1.register yourself:"<<endl;
    cout<<"2.login yourself:"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"please enter the choice:"<<endl;
    cin>>number1;
    return number1;
}

int userMenu()
{
    system("cls");
    topHeader();
    int number1;
    cout<<"         USER MENU"<<endl;
    cout<<"1. Check fare"<<endl;
    cout<<"2. Destnations"<<endl;
    cout<<"3. Book seat"<<endl;
                                // this will be added in final project
    cout<<"4. Trip booking"<<endl;
    cout<<"5. pay money"<<endl;
    cout<<"6. Feedback/suggesions"<<endl;  
    cout<<"7. Exit"<<endl;
    cout<<"enter the number:";
    cin>>number1;
    return number1;
}

int adminMenu()
{
    system("cls");
    topHeader();
    int number1;
    cout<<"             AMDIN MENUE"<<endl;
    cout<<"1. set fares"<<endl;   
    cout<<"2. seat records"<<endl;
    cout<<"3. Bills"<<endl;
                                // this will be in next version
    cout<<"4. About Us"<<endl;
    cout<<"5. refund"<<endl;
    cout<<"6. change drive"<<endl;
    cout<<"7. Exit"<<endl;
    cout<<"enter a number";
    cin>>number1;
    return number1;
}

bool signUp(string name1, string password1, string role1)
{

    system("cls");
    topHeader();
    name[counter] = name1;
    password[counter] = password1;
    role[counter] = role1;
    counter++;
    return true;
}
string signIn(string name1, string password1)
{
    string out;
    for(int idx = 0; idx<counter; idx++)
    {
        if(name[idx]==name1 && password[idx]==password1)
        {
            out = role[idx];
        }
    }
    return out;
}     // the validations will be in the final version.