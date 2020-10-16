#ifndef CLIENT_H
#define CLIENT_H

using namespace std;

class Client
{
public:
    static int Client_Id_count;
    int cost_count;
        //using csv file to store & check the user data
    virtual void check()
    {   //Here searching if a client has his / her account
        fstream fin;
        fin.open("client.csv", ios::in);
        double Client_phone,phone,count = 0;
        cout << endl<<"Enter the phone number of the client to display details: ";
        cin >> Client_phone;
        //using vector to get a line at a time
        vector<string> row;
        string line, word;
        while (fin >> line)
        {
            row.clear();
            stringstream s(line);
            while (getline(s,word,','))
            {
                row.push_back(word);
            }
            phone = atoi(row[2].c_str());
            if (Client_phone == phone)
            {
                count = 1;
                //printing the client data
                cout << "\n\t\t\tClient ID: " << row[0] << "\n";
                cout << "\t\t\tName: " << row[1] << "\n";
                cout << "\t\t\tPhone No: " << row[2] << "\n";
                cout << "\t\t\tAddress: " << row[3] << "\n";
                cout << "\t\t\tNID: " << row[4] << "\n";
                break;
            }
        }
        //if the client isn't registered
        if (count == 0)
           {
               cout << "Client is not registered with the Hotel. Please register the client details\n";
              update();
           }

    }

    virtual int update()
    {
        fstream fout;                                             //open file to append new client data
        fout.open("client.csv", ios::out | ios::app);
        int Client_id;                                            //getting the client informations
        string Client_name;
        string Client_phone_no;
        string Client_address;
        cout<<"\nEnter Client ID:";cin>>Client_id;
        cout<<endl<<"Enter Client Name:";cin>>Client_name;
        cout<<endl<<"Enter Client Phone No:";cin>>Client_phone_no;
        cout<<endl<<"Enter Client Address:";cin>>Client_address;


        fout << Client_id << ","                                         //printing the client details in csv file
        << Client_name << ","
        << Client_phone_no << ","
        << Client_address << " " ;
        fout.close();
    }
};
#endif // CLIENT_H
