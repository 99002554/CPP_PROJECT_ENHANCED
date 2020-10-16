#ifndef HOTELROOM_H
#define HOTELROOM_H

#include "Client.h"
using namespace std;

class hotelroom: virtual public Client
{
public:

    void check()                                                                            //Check if a hotel room is vacant
    {
        ifstream inf("hotelroom.txt");                                                     //Read from the text file
        if(!inf) cout<<endl<<"Unable to real the details for the hotelrooms "<<endl;
        int room_no;
        string room_type;
        string room_book;
        cout<<endl<<"Hotel Rooms available currently:"<<endl;

        while(!inf.eof())                                                                   //reading the whole file to print available hotel rooms
        {
            inf>>room_no>>room_type>>room_book;
            if(room_book=="NULL")
            cout<<room_no<<"    "<<room_type<<endl;
        }
        inf.close();
    }
    int update()                                                                            //Function to book a hotel room

    {
                                                                                            //taking the information to book a definite room
        int booking_room_no,c_id;
        cout<<"Please enter the required room id:";
        cin>>booking_room_no;
        cout<<"Please enter the client id:";
        cin>>c_id;
        string client_id;
        stringstream ss;
        ss << c_id;
        client_id = ss.str();
        ifstream inf("hotelroom.txt");
        ofstream outf("hotelroom1.txt");
        if(!inf) cout<<endl<<"Unable to open hotelroom file"<<endl;
        int room_no; string room_type; string room_book;
        //taking all the data to book the required room
        while(!inf.eof())
        {
            inf>>room_no>>room_type>>room_book;
            if(room_no==booking_room_no)
            {
                cost_count+=1000;
                cout<<room_no<<"  "<<room_type<<endl;
                outf<<room_no<<"  "<<room_type<<"  "<<client_id<<endl;
            }
            else
            {
                outf<<room_no<<" "<<room_type<<" "<<room_book<<endl;
            }
        }
        outf.close();
        inf.close();
        remove("hotelroom.txt");
        rename("hotelroom1.txt","hotelroom.txt");
        return cost_count;
    }
    void checkout()                                                                           //Release the booked room
    {
        int c_id;
        cout<<"Please enter the client id:";
        cin>>c_id;
        string client_id;
        stringstream ss;
        ss << c_id;
        client_id = ss.str();
        ifstream inf("hotelroom.txt");
        ofstream outf("hotelroom1.txt");
        if(!inf) cout<<endl<<"Unable to open hotelroom file"<<endl;
        int room_no; string room_type; string room_book;
        while(true)
        {
            inf>>room_no>>room_type>>room_book;
            if(inf.eof()) break;
            if(room_book==client_id)
            {
                cout<<room_no<<" "<<room_type<<endl;
                outf<<room_no<<" "<<room_type<<" "<<"NULL"<<endl;
            }
            else
            {
                outf<<room_no<<" "<<room_type<<" "<<room_book<<endl;
            }
        }
        //closing the file and replacing the previous file
        outf.close();
        inf.close();
        remove("hotelroom.txt");
        rename("hotelroom1.txt","hotelroom.txt");
    }
    virtual void display_cost(){};
};

#endif // HOTELROOM_H
