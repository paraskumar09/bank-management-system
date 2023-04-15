//PARAS KUMAR
//210010140019
//BTech(IT)

#include <iostream>
#include <fstream>
#include <string>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;
int n=0;
class User
{
public:
    string name;
    int accNo;
    double money;
};

User user[100];

void add()
{
    if (n >= 100)
    {
        cout << "reach max" << endl;
        return;
    }

    cout << "Enter the Account no : ";
    cin >> user[n].accNo;
    cout << "Enter the name  : ";
    cin >> user[n].name;
    cout << "Enter the money : ";
    cin >> user[n].money;
    n++;
    system("cls");
}

void show()
{
    for (int i = 0; i < n; i++)
    {
        cout <<"\nAccount No= " <<user[i].accNo << endl;
        cout <<"Name= "<<user[i].name << endl;
        cout <<"Balance= "<<user[i].money<< endl;
    }
    cout << "\n\n press any key to exit" << endl;
    getch();
    system("cls");
}

void loadToFile()
{
    cout<<"data uploading to file";
    for(int i=0;i<8;i++)
    {
        Sleep(100);
        cout<<".";
    }

    
        cout<<"\n\nData uploaded enter any key to continue\n";
        getch();
        system("cls");
    

    ofstream file("bankdata.txt");
    if (file.is_open())
    {
        file << n << endl;
        for (int i = 0; i < n; i++)
        {
            file << user[i].accNo<< endl;
            file << user[i].name<< endl;
            file << user[i].money<<endl;
        }
        file.close();
    }
    else
    {
        cout << "cant able to open file" << endl;
    }
}

void loadFrmFile()
{

   

    ifstream file("bankdata.txt");
    file >> n;
    for (int i = 0; i < n; i++)
    {
        file >> user[i].accNo;
        file >> user[i].name;
        file >> user[i].money;
    }
    file.close();
}

void print(User &s){
    cout<<"account no "<<s.accNo<<endl;
    cout<<"name "<<s.name<<endl;
    cout<<"money "<<s.money<<endl;

}

int search2( int check){
    loadFrmFile();
    int a=0;
    for (int i = 0; i < n; i++)
    {
        if (check==user[i].accNo)
        {
            print(user[i]);
            cout<<"press any key to exit";
            getch();
            system("cls");
            return i; 
        }
        
    }
    return -1;
}

int search1( int check){
    loadFrmFile();
    char c;
    int a=0;
    for (int i = 0; i < n; i++)
    {
        if (check==user[i].accNo)
        {
            
            system("cls");
            return i; 
        }
        
    }
    return -1;
}


void withdraw(){
    int acc;
    double wtdr;
    cout<<"enter the account number ";cin>>acc;
    int temp=search1(acc);
    if(temp==-1){
        cout<<"No account found on this acc number"<<endl;
        return;
    }

   cout<<setw(50)<<".........................\n"
       <<setw(50)<<". Account details       .\n"
       <<setw(51)<<".........................\n\n"; 

    print(user[temp]);
            
    cout<<"\nenter the amount you want to withdraw ";cin>>wtdr;
    if(user[temp].money>wtdr){
       user[temp].money-=wtdr;
       cout<<"remain balance "<<user[temp].money<<endl; 
       loadToFile();
    }else{
        cout<<"insufficent money, account balance "<<user[temp].money<<endl;
        return;
    }
}

void deposit(){
    int acc;
    double wtdr;
    cout<<"enter the account number ";cin>>acc;
    int temp=search1(acc);
    if(temp==-1){
        cout<<"No account found on this acc number"<<endl;
        return;
    }

    cout<<setw(50)<<".........................\n"
       <<setw(50)<<". Account details       .\n"
       <<setw(51)<<".........................\n\n"; 

    print(user[temp]);

    cout<<"Enter the amount ";cin>>wtdr;
    user[temp].money+=wtdr;
    cout<<"Remain balance = "<<user[temp].money<<endl; 
    loadToFile();
}

int main()
{
    char c;
    loadFrmFile();
    do
    {

        system("color c");
        cout<<"\t\t\t..........................\n";
        cout<<"\t\t\t. Made by Paras kumar    . \n\t\t\t. Roll No : 210010140019 . \n\t\t\t. Btech(It)              . \n";
        cout<<"\t\t\t..........................\n\n\n";
        cout << "No. of accounts= "<<n << endl;
        cout << "\n";
        cout << "Operations" << endl;
        cout << "\t1. Add new account" << endl
             << "\t2. Show all account" << endl
             << "\t3. Upload data to file" << endl
             << "\t4. Load data from file" << endl
             << "\t5. Search account" << endl
             << "\t6. Withdraw money" << endl
             << "\t7. Deposit money" << endl
             << "\t8. exit" << endl;
        cin  >> c;
        switch (c)
        {
        case '1':
           system("cls");
            add();
            break;
        case '2':
            show();
            break;
        case '3':
            system("cls");
            loadToFile();
            break;
        case '4':
            system("cls");
            cout<<"Loading data from file";
            
            for(int i=0;i<8;i++)
            {
                Sleep(100);
                cout<<".";
            }
        
        
            cout<<"\n\nData loaded enter any key to continue\n";
            getch();
            system("cls");

            loadFrmFile();
            break;
        case '5':
            system("cls");
            cout<<"enter the account numer ";
            int acc;cin>>acc;
            search2(acc);
            break;
        case '6':
            withdraw();
            break;
        case '7':
            deposit();
            break;
        case '8':
            exit(0);    
        default:
            break;
        }
    } while (1);

    return 0;
}