#include<iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

#include "Client.h"
#include "hotelroom.h"
#include "banquethall.h"
#include "restaurant.h"
#include "cost.h"
using namespace std;

int main()
{
    //base class pointer and other class objects
    Client *bptr; int t;
    Client c1;
    banquethall ch1;
    hotelroom h1;
    restaurant r1;
    cost c2;
    //displaying the options
    while(true)
    {	cout<<endl<<"\t\t\t\t HOTEL BOOKING MANAGEMENT SYSTEM";
        //options to create and check client id
        A:cout<<endl<<"\t\t\t\t\n 1. Search for a client id"<<endl<<"\t\t\t\t\n 2. Create a client id"<<endl<<"\t\t\t\t\n 0 Exit"<<endl;cin>>t;
        //base class pointer pointing to a base class object
        bptr=&c1;
        //exception handing if gives unnecessary inputs
        try
        {
            if(t==1) bptr->check();
            else if(t==2) bptr->update();
            else if (t==0) {
                exit(1);
            }
            else throw(t);
        }
        catch(...)
        {
            cout<<endl<<"typed unavailable option"; goto A;
        }
        //options to book and checkout
        B:cout<<endl<<"\t\t\t\t 1. Book a Hotelroom"<<endl<<"\t\t\t\t 2. Book a banquet hall"<<endl<<"\t\t\t\t 3. Reserve a restaurant meal"<<endl<<"\t\t\t\t 4. Check out hotel room"<<endl<<"\t\t\t\t 0. Go back to previous"<<endl;cin>>t;
        //exception handing if gives unnecessary inputs
        try
        {
            //base class pointer pointing to derivved class objects
            //display costs if anything is booked
            if(t==1) {bptr= &h1;bptr->cost_count=0;bptr->check();cout<<endl<<"\t\t\t\t Do you want to checkin ?\n\t\t\t\t 1. Yes \n\t\t\t\t 0. Not"<<endl;cin>>t;
            if(t){int i,d;cout<<endl<<"How many rooms do you need?"<<endl;cin>>i;while(i--) d=bptr->update(); c2.display_cost(d);}}
            else if(t==2) {bptr= &ch1;bptr->cost_count=0; bptr->check();cout<<endl<<"\n\t\t\t\t Do you want to confirm the booking?\n\t\t\t\t 1. Yes \n\t\t\t\t 0. Not"<<endl;cin>>t;if(t) c2.display_cost(bptr->update());}
            else if(t==3) {bptr= &r1;bptr->cost_count=0; bptr->check();cout<<endl<<"\n\t\t\t\t Do you want to confirm the booking?\n\t\t\t\t 1. Yes \n\t\t\t\t 0. Not"<<endl;cin>>t;if(t) c2.display_cost(bptr->update());}
            else if(t==4) {h1.checkout();}
            else if (t==0) {}
            else throw(t);
        }
        catch(...)
        {
            cout<<endl<<"typed unavailable option";
            goto B;
        }
    }
}
