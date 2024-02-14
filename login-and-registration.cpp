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
}