#ifndef COST_H
#define COST_H

#include "hotelroom.h"
#include "banquethall.h"
#include "restaurant.h"
using namespace std;

class cost : public banquethall , public hotelroom , public restaurant
{
public:

    void check(){}
    int update() {}
    void display_cost(int cost)                                 //Total Cost
    {
        int paid;

        cout<<endl<<"Total cost:"<<cost<<endl;
        cout<<endl<<"Paid money:"<<endl; cin>>paid;
        cout<<endl<<"Outstanding Due change:"<<cost-paid<<endl;
        cout<<endl<<"Recievable change:"<<paid-cost<<endl;

    }
   /* cost operator - (cost c)
    {
        cost c3;
        c3.cost_count = c.cost_count - this->cost_count;
        return c3;
    }*/
};

#endif // COST_H
