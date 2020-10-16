#ifndef BANQUETHALL_H
#define BANQUETHALL_H

#include "Client.h"
using namespace std;

class banquethall : virtual public Client
{
    public:
        void check()                                                            //Check banquet hall availability
    {
        ifstream inf("banquethall.txt");
        if(!inf) cout<<endl<<"Unable to open banquethall file"<<endl;
        string day,time,hall_book,booking_day,booking_time,res="Not booked";
        cout<<endl<<"Please enter the date of Booking(Ex: 2/10/2020):";cin>>booking_day;
        cout<<endl<<"Please enter the time of booking(07:00 / 11:00):";cin>>booking_time;

        while(!inf.eof())
        {
            inf>>day>>time>>hall_book;
            cout<<day<<" "<<time<<" "<<hall_book<<endl;
            if(day==booking_day && time==booking_time) res="booked";
        }

        cout<<endl<<res<<endl;
        inf.close();
    }

    int update()                                            //Updating the status to booked
    {
        string booking_day,booking_time;int c_id;             //Taking client details for the booking
        cout<<"Please enter Booking date:";
        cin>>booking_day;
        cout<<"Please enter Booking time:";
        cin>>booking_time;
        cout<<"Please enter the client id:";
        cin>>c_id;

        cost_count+=20000;
        //opening the text file to append and returning the cost
        ofstream outf("banquethall.txt",ios::app);
        outf<<endl<<booking_day<<" "<<booking_time<<" "<<c_id;
        outf.close();
        return cost_count;
    }
    virtual void display_cost(){};
};

#endif // BANQUETHALL_H
