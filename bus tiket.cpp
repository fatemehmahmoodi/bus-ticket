#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

static int t = 0;

class a
{
    char bus_number[5], bus_driver[10], bus_arrival[5], bus_depart[5], bus_from[10], dus_to[10], bus_seat[8][4][10];
public:
    void add();
    void reservation();
    void empty();
    void view();
    void avail();
    void result();
    void position(int i);
}
bus[5];

void a::add()
{
    cout<<"Enter Bus Number: ";
    cin>>bus[t].bus_number;
    cout<<"\nEnter Driver's Name: ";
    cin>>bus[t].bus_driver;
    cout<<"\nArrival Time: ";
    cin>>bus[t].bus_arrival;
    cout<<"\nDeparture: ";
    cin>>bus[t].bus_depart;
    cout<<"\nFrom:";
    cin>>bus[t].bus_from;
    cout<<"\nTo:";
    cin>>bus[t].dus_to;
    bus[t].empty();
    cout<<"\New Bus Added Successfully";
    t++;

}
void a::reservation()
{
    int bus_seat;
    char no[5];
top:
    cout<<"Bus Number: ";
    cin>>no;
    int y;
    for(y=0; y<=t; y++)
    {
        if(strcmp(bus[y].bus_number, no)==0)
            break;
    }
    while(y<=t)
    {
        cout<<"\nSeat Number: ";
        cin>>bus_seat;
        if(bus_seat>32)
        {
            cout<<"\nThere are only 32 Seats Available in this Bus.";
        }
        else
        {
            if (strcmp(bus[y].bus_seat[bus_seat/4][(bus_seat%4)-1], "Empty")==0)
            {
                cout<<"Enter Passenger's Name: ";
                cin>>bus[y].bus_seat[bus_seat/4][(bus_seat%4)-1];
                break;
            }
            else
                cout<<"The Seat Number. is Already Reserved.\n";
        }
    }
    if(y>t)
    {
        cout<<"Enter Correct Bus Number.\n";
        goto top;
    }
}
void a::empty()
{
    for(int x=0; x<8; x++)
    {
        for(int z=0; z<4; z++)
        {
            strcpy(bus[t].bus_seat[x][z], "Empty");
        }
    }
}
void a::view()
{
    int m;
    char number[5];
    cout<<"Enter Bus Number: ";
    cin>>number;
    for(m=0; m<=t; m++)
    {
        if(strcmp(bus[m].bus_number, number)==0)
            break;
    }
    while(m<=t)
    {
        cout<<"Bus Number: "<<bus[m].bus_number
            <<"\nDriver: "<<bus[m].bus_driver<<"\t\tArrival Time: "
            <<bus[m].bus_arrival<<"\tDeparture Time:"<<bus[m].bus_depart
            <<"\nFrom: "<<bus[m].bus_from<<"\t\tTo: "<<
            bus[m].dus_to<<"\n";
        bus[0].position(m);
        int d=1;
        for (int x=0; x<8; x++)
        {
            for(int y=0; y<4; y++)
            {
                d++;
                if(strcmp(bus[m].bus_seat[x][y],"Empty")!=0)
                    cout<<"\nThe Seat no "<<(d-1)<<" is Reserved for "<<bus[m].bus_seat[x][y]<<".";
            }
        }
        break;
    }
    if(m>t)
        cout<<"Enter Correct Bus Number: ";
}
void a::position(int l)
{
    int r=0;
    t=0;
    for (int x =0; x<8; x++)
    {
        cout<<"\n";
        for (int z = 0; z<4; z++)
        {
            r++;
            if(strcmp(bus[l].bus_seat[x][z], "Empty")==0)
            {
                cout.width(5);
                cout.fill(' ');
                cout<<r<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].bus_seat[x][z];
                t++;
            }
            else
            {
                cout.width(5);
                cout.fill(' ');
                cout<<r<<".";
                cout.width(10);
                cout.fill(' ');
                cout<<bus[l].bus_seat[x][z];
            }
        }
    }
    cout<<"\n\nThere are "<<t<<" Seats Empty in Bus Number: "<<bus[l].bus_number;
}
void a::avail()
{
    for(int y=0; y<t; y++)
    {
        cout<<"Bus Number: "<<bus[y].bus_number<<"\nDriver: "<<bus[y].bus_driver
            <<"\t\tArrival Time: \t"<<bus[y].bus_arrival<<"\tDeparture Time: "
            <<bus[y].bus_depart<<"\nFrom: "<<bus[y].bus_from<<"\t\tTo: "
            <<bus[y].dus_to<<"\n";
    }
}
void a::result()
{
    ofstream result("result.txt");
    if (result.is_open())
    {
    int m;
    char number[5];
    cout<<"Enter Bus Number: ";
    cin>>number;
    for(m=0; m<=t; m++)
    {
        if(strcmp(bus[m].bus_number, number)==0)
            break;
    }
    while(m<=t)
    {
        result<<"Bus Number: "<<bus[m].bus_number
            <<"\nDriver: "<<bus[m].bus_driver<<"\t\tArrival Time: "
            <<bus[m].bus_arrival<<"\tDeparture Time:"<<bus[m].bus_depart
            <<"\nFrom: "<<bus[m].bus_from<<"\t\tTo: "<<
            bus[m].dus_to<<"\n";
        bus[0].position(m);
        int d=1;
        for (int x=0; x<8; x++)
        {
            for(int y=0; y<4; y++)
            {
                d++;
                if(strcmp(bus[m].bus_seat[x][y],"Empty")!=0)
                    result<<"\nThe Seat no "<<(d-1)<<" is Reserved for "<<bus[m].bus_seat[x][y]<<".";
            }
        }
        break;
    }
    result.close();
    if(m>t)
        cout<<"\nEnter Correct Bus Number: ";
}
}
int main()
{
    system("cls");
    int w;
    while(1)
    {
        cout<<"\n1.Add New Bus Number\n"
            <<"2.Reservation\n"
            <<"3.Show Reservation\n"
            <<"4.Buses Available \n"
            <<"5.insert result into file\n"
            <<"6.Exit\n";
        cout<<"Enter your Choice:- ";
        cin>>w;
        switch(w)
        {
        case 1:
            bus[t].add();
            break;
        case 2:
            bus[t].reservation();
            break;
        case 3:
            bus[0].view();
            break;
        case 4:
            bus[0].avail();
            break;
        case 5:
            bus[0].result();
        case 6:
            exit(0);
        }
    }
    return 0;
}

