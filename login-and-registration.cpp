#include <iostream>
// #include <vector>
#include <fstream>
#include <string.h>

using namespace std;

void login();
void registration();
void forgot();

int main(){
    int c;
    cout<<"\t\t\t________________________________________________\n\n\n";
    cout<<"\t\t\t           Welcome to the login page            \n\n\n";
    cout<<"\t\t\t__________           MENU           _____________\n\n";
    cout<<"                                                       \n\n";

    cout<<"\t| Enter 1 to login                       |"<<endl;
    cout<<"\t| Enter 2 to register                    |"<<endl;
    cout<<"\t| Enter 3 if you forgot your password    |"<<endl;
    cout<<"\t| Enter 4 to exit                        |"<<endl;
    cin>>c;
    cout<<endl;

    switch (c)
    {
    case 1:
        login();
        break;
    
    case 2:
        registration();
        break;
    
    case 3:
        forgot();
        break;

    case 4:
        cout<<"\t\t\t Thank you! \n\n";
        break;
    
    default:
    system("cls");
        cout<<"\t\t\t Please select from the options given above \n"<<endl;
        main();
    }
}

void login(){
    int count;
    string userID, password, id, pass;
    system("cls");
    cout<<"\t\t\t Please enter the username & password:"<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userID;
    cout<<"\t\t\t PASSWORD: ";

    ifstream input("records.txt");

    while(input>>id>>pass){
        if(id==userID && pass==password){
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count==1){
        cout<<userID<<"\n Successfully logged in"<<endl;
        main();
    }
    else{
        cout<<"\n Please check your username & password"<<endl;
    }
}

void registration(){
    string ruserID, rpassword, rid, rpass;
    system("cls");
    cout<<"\t\t\t Enter the username: ";
    cin>>ruserID;
    cout<<"Enter the password: ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    f1<<ruserID<<' '<<rpassword<<endl;
    system("cls");
    cout<<"\n\t\t\t Registration is successfull! \n";
    main();
}

void forgot(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password? \n";
    cout<<"Enter 1 to search for your ID by your username"<<endl;
    cout<<"Enter 2 to go back to the main menu"<<endl;
    cout<<"Enter: ";
    cin>>option;

    switch (option)
    {
    case 1:{
        int count = 0;
        string suserID, sID, spass;
        cout<<"\n\t\t Enter the username you can remember: ";
        cin>>suserID;

        ifstream f2("records.txt");
        while(f2>>sID>>spass){
            if (sID == suserID)
            {
                count=1;
            }
            
        }
        f2.close();
        if (count == 1){
            cout<<"\n\n Your account is found! \n";
            cout<<"\n\n Your password is: "<<spass;
            main();
        }
        else{
            cout<<"\n\t Sorry! Your account is not found!\n";
        }

        break;
    }
    case 2:

        main();
        break;
    
    default:
        cout<<"\t\t\t Wrong choice! Please try again "<<endl;
        forgot();
    }
}




