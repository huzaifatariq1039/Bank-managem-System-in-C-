#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<Windows.h>
using namespace std;

class bank{
    private:
    string pin;
    float balance;
    string id;
    string pass;
    string name;
    string Fathername;
    string address;
    string phone;
    public:
    void menu();// Menu bar
    void bankmanagement();// Bank Operations
    void ATMmanagement(); // ATM operations
    void NewUser();// Adding new user to the record
    void ExistingUser();// For checking the record of existing user
    void deposit();// For deposition of money
    void withdraw();// For withdrawl of money
    void transfer();// For transfer of money
    void payment(); // For all type of payments
    void search();// For searching user in the records
    void edit();//For editing a user record
    void Delete();//For deleting a user record
    void showrecords(); //For showing all records
    void showpayments();// For showing all payments
    void userbalance(); //For user login and check balance
    void withdrawatm(); //For withdrawl from atm
    void checkdetail(); // For checking detail
};

void bank::menu(){
    m: //label for goto 
    int choice;
    string email;
    char ch1,ch2;
    string pass, pin;
    cout<<"\n\t\t__________________________\n";
    cout<<"\n\t\t                          \n";
    cout<<"\n\t\t    Meezan Bank Limited   \n";
    cout<<"\n\t\t                          \n";
    cout<<"\n\t\t__________________________\n";
    cout<<"\n\t\t                          \n";
    cout<<"\n\t\t| 1. Bank Management   |\n";
    cout<<"\n\t\t|                      |\n";
    cout<<"\n\t\t| 2. ATM Management    |\n";
    cout<<"\n\t\t|                      |\n";
    cout<<"\n\t\t| 3. Exit              |\n";
    cout<<"\n\t\t Enter your choice: ";
    cin>>choice;

    switch (choice){
        case 1:
            cout<<"\n\n\t\t Login Account \n";
            cout<<"\n\n\t\t Enter your email : ";
            cin>>email;
            cout<<"\n\n\t\t Enter your password : ";
            for(int i=1; i<8; i++){
                ch1= getch();
                pass+=ch1;
                cout<<"*";
            }
            cout<<"\n\n\t\t Enter your pin : ";
            for(int i=0; i<5; i++){
                ch2= getch();
                pin+=ch2;
                cout<<"*";
            }
            if(email=="huzaifa@gmail.com" && pin=="12345" && pass=="huzaifa"){
                bankmanagement();
            }
            else{
                cout<<"Wrong email/password/pin......Please try again!";
            }
            break;
        case 2:
            ATMmanagement();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"\n Invalid choice.....Please try again !";
    }
    goto m;
}

void bank :: bankmanagement(){
    int choice;
    m:
    cout<<"\n\t\t_____________________________\n";
    cout<<"\n\t\t                             \n";
    cout<<"\n\t\t       Bank Management       \n";
    cout<<"\n\t\t                             \n";
    cout<<"\n\t\t_____________________________\n";
    cout<<"\n\t\t| 1. New User              |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 2. Existing User         |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 3. Deposit               |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 4. Withdraw              |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 5. Transfer              |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 6. Payment               |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 7. Search User records   |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 8. Edit User records     |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 9. Delete User records   |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 10. Show All records     |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 11. Payment All records  |\n";
    cout<<"\n\t\t|                          |\n";
    cout<<"\n\t\t| 12. Go back              |\n";


    cout<<"\n\t\t Enter your choice(1-10): ";
    cin>>choice;

    switch(choice){
        case 1:
            NewUser();
            break;
        case 2:
            ExistingUser();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            payment();
            break;
        case 7:
            search();
            break;
        case 8:
            edit();
            break;
        case 9:
            Delete();
            break;
        case 10:
            showrecords();
            break;
        case 11:
            showpayments();
            break;
        case 12:
            menu();
            break;
        default:
            cout<<"\n Ivalid choice.....Please try again !";

    }
    goto m;
}

void bank:: ATMmanagement(){
    int choice;
    m:
    cout<<"\n\t\t_____________________________\n";
    cout<<"\n\t\t                             \n";
    cout<<"\n\t\t       ATM Management        \n";
    cout<<"\n\t\t                             \n";
    cout<<"\n\t\t_____________________________\n";
    cout<<"\n\t\t| 1. User Login and Check Banlance |\n";
    cout<<"\n\t\t|                                  |\n";
    cout<<"\n\t\t| 2. Withdraw Amount               |\n";
    cout<<"\n\t\t|                                  |\n";
    cout<<"\n\t\t| 3. Account Details               |\n";
    cout<<"\n\t\t|                                  |\n";
    cout<<"\n\t\t| 4. Go Back                       |\n";
    cout<<"\n\t\t Enter your choice(1-4): ";
    cin>>choice;

    switch(choice){
        case 1:
            userbalance();
            break;
        case 2:
            withdrawatm();
            break;
        case 3:
            checkdetail();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"\n Ivalid choice.....Please try again !";

    }
    goto m;
}
void bank:: NewUser(){
    m:
    fstream file;
    int p;
    string n,f,pa, a, ph, i;
    float b;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t            Add new User               \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\t\t Enter your ID : ";
    cin>>id;
    cout<<"\n\t\t Enter your name : ";
    cin>>name;
    cout<<"\n\t\t Enter your Father Name : ";
    cin>>Fathername;
    cout<<"\n\t\t Enter your Address : ";
    cin>>address;
    cout<<"\n\t\t Enter your Pin Code(5 digit) : ";
    cin>>pin;
    cout<<"\n\t\t Enter your Password : ";
    cin>>pass;
    cout<<"\n\t\t Enter your Phone Number : ";
    cin>>phone;
    cout<<"\n\t\t Current Balance : ";
    cin>>balance;
    file.open("bank.txt", ios::in); //Reading Mode
    if(!file){
        file.open("bank.txt", ios::app | ios:: out); //Append and Write mode
        file<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    else{
        file>>i>>n>>f>>a>>p>>pa>>ph>>b;

        while(file.eof()){
            if(i == id){
                cout<<"\n\t User ID already exists !";

                goto m;
            }
             file>>i>>n>>f>>a>>p>>pa>>ph>>b;
        }
        file.close();

        file.open("bank.txt", ios::app | ios:: out); 
        file<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
        file.close();
    }
    cout<<"\n New User Account Created Successfully !";
}

void bank:: ExistingUser(){
    fstream file;
    string eID; //Existing user id
    int found=0;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t            Existing User              \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";

    file.open("bank.txt", ios::in);
    if(!file){
        cout<<"\n\t\t File Opening Error !";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;

        while(!file.eof()){
            if(eID == id){
                cout<<"\n\t\t User ID : " <<id<<"   Pin Code : "<<pin<<"   Password : "<<pass;
                found++;
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();

        if(found==0){
            cout<<"\n\t User ID can not be found !";
        }
    }

};

void bank:: deposit(){
    fstream file,file1;
    string eID; 
    int found=0;
    float deposit;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t           Deposit Amount              \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";

    file.open("bank.txt", ios :: in);
    if(!file){
        cout<<"\n\t\t File opening error";
    }
    else{
         cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        file1.open("bank1.txt", ios::app | ios::out);
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;

        while(!file.eof()){
            if(eID == id){
                cout<<"\n\t\t Enter amount for deposit : ";
                cin>>deposit;
                balance+=deposit;
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                found++;
                cout<<"\n\t\t The amount "<<deposit<<" has been successfully deposited !";
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found==0){
            cout<<"\n\t User ID can not be found !";
        }
    }
}

void bank:: withdraw(){
    fstream file,file1;
    string eID; 
    int found=0;
    float withdraw;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t           Withdraw Amount             \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";

    file.open("bank.txt", ios :: in);
    if(!file){
        cout<<"\n\t\t File opening error";
    }
    else{
         cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        file1.open("bank1.txt", ios::app | ios::out);
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;

        while(!file.eof()){
            if(eID == id){
                cout<<"\n\t\t Enter amount for withdraw : ";
                cin>>withdraw;
                if(withdraw <= balance){
                balance -= withdraw;
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                cout<<"\n\t\t The amount "<<withdraw<<" has been successfully withdrawn !";
                }
                else{
                    file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\t\t The amount you entered is larger than the current balance !";
                }
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found==0){
            cout<<"\n\t User ID can not be found !";
        }
    }
}

void bank::transfer(){
    fstream file, file1;
    string sID,rID;
    float amount;
    int found=0;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t           Transfer Amount             \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    file.open("bank.txt", ios :: in);
    if(!file){
        cout<<"\n\t\t File opening error";
    }
    else{
        cout<<"\n\t\t Enter Sender User ID : ";
        cin>>sID;
        cout<<"\n\t\t Enter Reciever User ID : ";
        cin>>rID;
        cout<<"\n\t\t Enter the amount : ";
        cin>>amount;
        file1.open("bank1.txt", ios::app | ios::in);
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(sID == id && amount <= balance){
            found++;
            cout<<"\n\t\t Money Transfer Successfull !";
            }
            else if(rID == id)
            found++;
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();

        if(found == 2){
            file.open("bank.txt", ios::in);
            file1.open("bank1.txt", ios::app | ios::out);
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
            while(!file.eof()){
                if(sID == id ){
                    balance -= amount;
                    file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                else if(rID == id){
                    balance += amount;
                    file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                else{
                    file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                }
                file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
            }
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
        }
        else{
            cout<<"\n\t\t  Invalid ! ";
        }
    }
}

void bank::payment() {
    fstream file, file1;
    string eID, bname;
    float amount;
    int found = 0;
    SYSTEMTIME x; // It is used for showing current time

    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t           Payment Option              \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";

    file.open("bank.txt", ios::in);
    if(!file){
        cout<<"\n\t\t File Doesn't exist";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        cout<<"\n\t\t Enter Bill Name : ";
        cin>>bname;
        cout<<"\n\t\t Enter amount : ";
        cin>>amount;
        file1.open("bank1.txt", ios::app | ios::out);
        file>>id>>name>> Fathername>>address>>pin>>pass>>phone>>balance;

        while(!file.eof()){
            if(eID == id && amount <= balance){
                balance -= amount;
                file1<< " "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                found++;
            } else {
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance; 
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found == 1){
            GetSystemTime(&x);
            file.open("bill.txt", ios::app | ios::out);
            file<<eID<<" "<<bname<<" "<<amount<<" "<<x.wDay<<"/"<<x.wMonth<<"/"<<x.wYear<<"\n";
            file.close();
            cout<<"\n\t\t Bill payment is successful";
        }
        else{
            cout<<"\n\t User ID or Amount Invalid !";
        }
    }
}

void bank::search(){
    fstream file;
    string eID;
    int found=0;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t         Search User Record            \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    file.open("bank.txt", ios::in);
    if(!file){
        cout<<"\n\t\t File opening error !";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(eID == id){
                cout<<"\n\n\t\t Search User Record";
                cout<<"User ID: "<<id<<"Name: "<<name<<"Father Name: "<<Fathername<<"\n";
                cout<<"\n Address : "<<address<<" Pin : "<<pin<<"Password : "<<pass<<"\n";
                cout<<"\n Phone : "<<phone<<" Current Balance : "<<balance;
                found++;
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found==0){
            cout<<"\n\t\t User ID not found..........";
        }
    }
}

void bank::edit(){
    fstream file,file1;
    string eID;
    int found=0;
    string n,f,a,p,ph;
    int pi;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t           Edit User Record            \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\t\t File opening error........";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        file1.open("bank1.txt", ios::app | ios::out);
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(eID == id){
               cout<<"\n\t\t Enter your name : ";
                cin>>n;
                cout<<"\n\t\t Enter your Father Name : ";
                cin>>f;
                cout<<"\n\t\t Enter your Address : ";
                cin>>a;
                cout<<"\n\t\t Enter your Pin Code(5 digit) : ";
                cin>>pi;
                cout<<"\n\t\t Enter your Password : ";
                cin>>p;
                cout<<"\n\t\t Enter your Phone Number : ";
                cin>>ph;
                file1<<" "<<id<<" "<<n<<" "<<f<<" "<<a<<" "<<pi<<" "<<p<<" "<<ph<<" "<<balance<<"\n";
                cout<<"\n\t\t Record Edited Successfully !";
                found++;
            }
            else{
                cout<<"\n\t\t Invalid User ID !";
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found=0){
            cout<<"\n\t\t User ID not found..........";
        }
    }
}

void bank:: Delete(){
    fstream file,file1;
    string eID;
    int found=0;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t          Delete User Record           \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    file.open("bank.txt",ios::in);
    if(!file){
        cout<<"\n\t\t File opening error........";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        file1.open("bank1.txt", ios::app | ios::out);
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(eID == id){
                
                cout<<"\n\t\t Record Deleted Successfully !";
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found=0){
            cout<<"\n\t\t User ID not found..........";
        }
    }
}

void bank:: showrecords(){
    fstream file;
    int found=0;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t            Show All Records           \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    file.open("bank.txt", ios::in);
    if(!file){
        cout<<"\n\t\t File Opening error........";
    }
    else{
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            cout<<"\n\n\t User ID : "<<id;
            cout<<"\n\n\t Name : "<<name;
            cout<<"\n\n\t Father Name : "<<Fathername;
            cout<<"\n\n\t Address : "<<address;
            cout<<"\n\n\t Pin : "<<pin;
            cout<<"\n\n\t Password : "<<pass;
            cout<<"\n\n\t Phone : "<<phone;
            cout<<"\n\n\t Current Balance : "<<balance;
            cout<<"\n\n\t ================================";
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
            found++;
        }
        file.close();
        if(found==0){
            cout<<"\n\t\t Database is empty.........";
        }
    }
}

void bank::showpayments(){
    fstream file;
    int found=0;
    string eID;
    float amount;
    int cdate;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t           Show All Payments           \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
     file.open("bill.txt",ios::in);
    if(!file){
        cout<<"\n\t\t File opening error........";
    }
    else{
        file>>id>>name>>amount>>cdate;
        while(!file.eof()){
            cout<<"\n\n\t User ID : "<<id;
            cout<<"\n\n\t Bill Name : "<<name;
            cout<<"\n\n\t Amount : "<<amount;
            cout<<"\n\n\t Date : "<<cdate;
            cout<<"\n\n\t ================================";
            file>>id>>name>>amount>>cdate;
            found++;
        }
        file.close();
        if(found=0){
            cout<<"\n\t\t User ID not found..........";
        }
    }
}

void bank::userbalance(){
    fstream file;
    string eID,ePASS,ePIN;
    char ch;
    int found=0;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t    User Login and Check Balance       \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";
    file.open("bank.txt", ios::in);
    if(!file){
        cout<<"\n\n\t File openiong error !";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        cout<<"\n\t\t Enter Pin Code : ";
        for(int i=1; i<6; i++){ // Method to hide password in
            ch=getch();         // the form of "*".
            ePIN +=ch;
            cout<<"*";
        }
        cout<<"\n\t\t Enter Password : ";
        for(int i=1; i<11; i++){
            ch=getch();
            ePASS += ch;
            cout<<"*";
        }
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        while(!file.eof()){
            if(eID == id && ePIN == pin && ePASS == pass){
                cout<<"\n\t\t Your current balance is "<<balance;
                found++;
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found==0){
            cout<<"\n\t\t User ID, pin and password invalid !";
        }
    }

}

void bank:: withdrawatm(){
    fstream file,file1;
    string eID,ePIN, ePASS; 
    int found=0;
    float withdraw;
    char ch;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t         Withdrawl from ATM            \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";

    file.open("bank.txt", ios :: in);
    if(!file){
        cout<<"\n\t\t File opening error";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        cout<<"\n\t\t Enter Pin Code : ";
        for(int i=1; i<6; i++){
            ch=getch();
            ePIN +=ch;
            cout<<"*";
        }
        cout<<"\n\t\t Enter Password : ";
        for(int i=1; i<11; i++){
            ch=getch();
            ePASS += ch;
            cout<<"*";
        }
        file1.open("bank1.txt", ios::app | ios::out);
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;

        while(!file.eof()){
            if(eID == id && ePIN == pin && ePASS == pass){
                cout<<"\n\t\t Enter amount for withdraw : ";
                cin>>withdraw;
                if(withdraw <= balance){
                balance -= withdraw;
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                cout<<"\n\t\t The amount "<<withdraw<<" has been successfully withdrawn !";
                cout<<"\n\t\t Your current balance : "<<balance;
                }
                else{
                    file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
                    cout<<"\n\t\t The amount you entered is larger than the current balance !";
                }
                found++;
            }
            else{
                file1<<" "<<id<<" "<<name<<" "<<Fathername<<" "<<address<<" "<<pin<<" "<<pass<<" "<<phone<<" "<<balance<<"\n";
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");
        if(found==0){
            cout<<"\n\t User ID can not be found !";
        }
    }
}

void bank::checkdetail(){
    fstream file;
    string eID,ePIN, ePASS; 
    int found=0;
    char ch;
    cout<<"\n\n\t\t\t_______________________________________\n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t        Check detail for ATM           \n";
    cout<<"\n\n\t\t\t                                       \n";
    cout<<"\n\n\t\t\t_______________________________________\n";

    file.open("bank.txt", ios :: in);
    if(!file){
        cout<<"\n\t\t File opening error";
    }
    else{
        cout<<"\n\t\t Enter User ID : ";
        cin>>eID;
        cout<<"\n\t\t Enter Pin Code : ";
        for(int i=1; i<6; i++){
            ch=getch();
            ePIN +=ch;
            cout<<"*";
        }
        cout<<"\n\t\t Enter Password : ";
        for(int i=1; i<11; i++){
            ch=getch();
            ePASS += ch;
            cout<<"*";
        }
        file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;

        while(!file.eof()){
            if(eID == id && ePIN == pin && ePASS == pass){
            cout<<"\n\n\t User ID : "<<id;
            cout<<"\n\n\t Name : "<<name;
            cout<<"\n\n\t Father Name : "<<Fathername;
            cout<<"\n\n\t Address : "<<address;
            cout<<"\n\n\t Pin : "<<pin;
            cout<<"\n\n\t Password : "<<pass;
            cout<<"\n\n\t Phone : "<<phone;
            cout<<"\n\n\t Current Balance : "<<balance;
                found++;
            }
            file>>id>>name>>Fathername>>address>>pin>>pass>>phone>>balance;
        }
        file.close();
        if(found==0){
            cout<<"\n\t User ID can not be found !";
        }
    }
}

int main(){
    bank b;
    b.menu();
}