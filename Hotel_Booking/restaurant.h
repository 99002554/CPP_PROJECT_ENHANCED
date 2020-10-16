#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Client.h"
using namespace std;

class restaurant : public Client
{
public:

    void check()                                                                    //Check the restaurant availability
    {
        ifstream inf("restaurant.txt");
        if(!inf) cout<<endl<<"Unable to open restaurant file"<<endl;
        string day,time,res_book,booking_day,booking_time,res="Not booked";
        cout<<endl<<"Please enter the date(Ex: 2/10/2020):";cin>>booking_day;
        cout<<endl<<"Please enter the time(Ex: 07:00):";cin>>booking_time;

        while(!inf.eof())
        {
            inf>>day>>time>>res_book;
            cout<<day<<" "<<time<<" "<<res_book<<endl;
            if(day==booking_day && time==booking_time) res="booked";
        }
        cout<<endl<<res<<endl;
        inf.close();
    }
    int update()                                                //Updating the booking status
    {
        string booking_day,booking_time;int c_id;                 //Taking client details for booking
        cout<<"Please enter Booking date:";
        cin>>booking_day;
        cout<<"Please enter Booking time:";
        cin>>booking_time;
        cout<<"Please enter the client id:";
        cin>>c_id;
        cost_count+=200;
        ofstream outf("restaurant.txt",ios::app);
        outf<<endl<<booking_day<<" "<<booking_time<<" "<<c_id;
        outf.close();
        return cost_count;
    }
    virtual void display_cost(){};
};

#endif // RESTAURANT_H
