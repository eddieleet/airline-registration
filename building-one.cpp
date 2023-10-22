#include<iostream>
#include<fstream>
#include<iomanip>


using namespace std;

void mainMenu();

class Management
{
    public:
     Management(){
       mainMenu();

     };
};

class Details
{
    public:

     static string name,gender;
     int phoneNo;
     int age;
     string add;
     static int cld;
     char arr[100];

     void information()
     {
        cout<<"\nEnter the customer ID:"<<endl;
        cin>>cld;
        cout<<"\nEnter the name :"<<endl;
        cin>>name;
        cout<<"\nEnter the age:"<<endl;
        cin>>age;
        cout<<"\n Address : ";
        cin>>add;
        cout<<"\n Gender :";
        cin>>gender;
        cout<<"Your details are saved with us\n"<<endl;
     };
};

int Details::cld;
string Details::name;
string Details::gender;


class registration
{
    public:
     static int choice;
     int choicel;
     int back;
     static float charge;

     void flights()
     {
        string flightN[]={"Dubai","Canada","Uk","USA","Australis","Europe"};

        for(int a=0;a<6;a++){
            cout<<(a+1)<<".flight to "<<flightN[a]<<endl;
        }

        cout<<"\nWelcome to the Airlines "<<endl;
        cout<<"Press their number of the country which you want to book the flight:";
        cin>>choice;

        switch(choice){
            case 1:
            {
                cout<<"_______________________welcome to Dubai Emirates_____________\n"<<endl;

                cout<<"Your comfort is our  priorty .Enjoy the journey!"<<endl;

                cout<<"Following are the flights \n"<<endl;

                cout<<"1. lONDAN - 498"<<endl;
                cout<<"\t 08-01-2023 8:00AM 10hrs $. 1400"<<endl;
                cout<<"1. lONDAN - 567"<<endl;
                cout<<"\t 09-01-2023 8:00AM 10hrs $. 1400"<<endl;
                cout<<"1. lONDAN - 998"<<endl;
                cout<<"\t 10-01-2023 4:00AM 10hrs $. 1400"<<endl;
              
              cout<<"\n Select the flight you want to book :"<<endl;
              cin>>choicel;

              if(choicel==1)
              {
                charge=1400;
                cout<<"\n You have successfully booked the fight LONDAN-498 "<<endl;
                cout<<"You can go back to menu and take the ticket "<<endl;
              }
              else if(choicel==2)
              {
               charge=1400;
               cout<<"\nYou have successfully booked the flight LONDAN -567 "<<endl;
               cout<<"You can go back to menu and take the ticket "<<endl;
              }
              else{
                cout<<"lnvalid input, shifting to the previous menu "<<endl;
                flights();
              }

              cout<<"press any key to go back to the main menu "<<endl;
              cin>>back;

              if(back==1)
              {
                mainMenu();
              }
              else{
                mainMenu();
              }
            }

            case 2:
             {
                cout<<"_______________________welcome to Canada Airlines_____________\n"<<endl;

                cout<<"Your comfort is our  priorty .Enjoy the journey!"<<endl;

                cout<<"Following are the flights \n"<<endl;

                cout<<"1. CA - 498"<<endl;
                cout<<"\t 08-01-2023 8:00AM 10hrs $. 1400"<<endl;
                cout<<"1. CA- 567"<<endl;
                cout<<"\t 09-01-2023 8:00AM 10hrs $. 1400"<<endl;
                cout<<"1. CA- 998"<<endl;
                cout<<"\t 10-01-2023 4:00AM 10hrs $. 1400"<<endl;
              
              cout<<"\n Select the flight you want to book :"<<endl;
              cin>>choicel;

              if(choicel==2)
              {
                charge=1400;
                cout<<"\n You have successfully booked the fight LONDAN-498 "<<endl;
                cout<<"You can go back to menu and take the ticket "<<endl;
              }
              else if(choicel==2)
              {
               charge=1400;
               cout<<"\nYou have successfully booked the flight CA-567 "<<endl;
               cout<<"You can go back to menu and take the ticket "<<endl;
              }
              else{
                cout<<"lnvalid input, shifting to the previous menu "<<endl;
                flights();
              }

              cout<<"press any key to go back to the main menu "<<endl;
              cin>>back;

              if(back==1)
              {
                mainMenu();
              }
              else{
                mainMenu();
              }
            }

            default :{
                cout<<"Invalid input,Shifting you to the main menu !"<<endl;
                mainMenu();
                break;
            }
        }
     }
};

float registration::charge;
int registration::choice;

class ticket : public registration,Details
{
  public:
   
   void Bill()
   {
    string destination="";
    ofstream outf("records.txt");
    {
      outf<<"____________AIRLINES________"<<endl;
      outf<<"____________Tickets________"<<endl;
      outf<<"___________________________"<<endl;

      outf<<"Customer ID :"<<Details::cld<<endl;
       outf<<"Customer Name :"<<Details::name<<endl;
        outf<<"Customer Gender:"<<Details::gender<<endl;
        outf<<"\tDescription"<<endl<<endl;

        if(registration::choice==1){
          destination="london";
        } 
        else if(registration::choice==2){
           destination="Candan";
        }
        outf<<"Destination\t\t"<<destination<<endl;
        outf<<"Flight cost :\t\t"<<registration::charge<<endl;
    }
    outf.close();
   }
   void display()
   {
    ifstream ifs("records.txt");
    {
      if(!ifs)
      {
        cout<<"File error!"<<endl;
      }
      while(!ifs.eof())
      {
        ifs.getline(arr,100);
        cout<<arr<<endl;
      }
    }
    ifs.close();
   }

};


void mainMenu(){
    int lchoice;
    int schoice;
    int back;

    cout<<"\t      XYZ Airlines \n "<<endl;
    cout<<"______________Main Menu_____"<<endl;
    cout<<"\t_________________________"<<endl;
    cout<<"\t|\t\t\t\t\t\t|"<<endl;

    cout<<"\t|\t Press 1 to add the Customer Detaisl      \t|"<<endl;
    cout<<"\t|\t Press 2 for Fight Registration      \t|"<<endl;
    cout<<"\t|\t Press 3 Ticket and Charges      \t|"<<endl;
    cout<<"\t|\t Press 4 to Exit     \t|"<<endl;
    cout<<"\t|\t\t\t\t\t\t|"<<endl;

    cout<<"Enter the choice : ";
    cin>>lchoice;

    Details d;
    registration r;
    ticket t;

    switch(lchoice){

        case 1:
        {
            cout<<"________Customers________\n"<<endl;
            d.information();
            cout<<"Press any key to go to back to Main menu ";
            cin>>back;

            if(back==1){
             mainMenu();
            }else{
            mainMenu();
            }
            break;
        }

        case 2:
        {
            cout<<"_________Book a fight using this system___________\n"<<endl;
            r.flights();
            break;
        }

        case 3:
        cout<<"_______GET YOUR TICKET______\n"<<endl;
        t.Bill();

        cout<<"Your ticket is printed , you can collect it \n"<<endl;
        cout<<"Press 1 to display your ticket ";
        cin>>back;

        if(back==1){
            t.display();
            cout<<"Press any key to go back to main menu: ";
            cin>>back;
            if(back==1){
                mainMenu();
            }
            else {
                mainMenu();
            }
            break;
        }

        case 4:
        {
            cout<<"\r\n\t_________Thank-you______"<<endl;
            break;
        }
    }
}



int main()
{
    Management Mobj;
    return 0;
}