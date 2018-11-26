#include <iostream>
#include "time.h"
using namespace std;
int main()
{
    Time time1(03,9,"AM");
    Time time2(03,10,"AM");
    Appointment appointment1;
    Appointment appointment2;
    DayAppointment day1;
    DayAppointment day2=day1;
    Calendar week;
    while(true)
    {
        cout<<"Enter the operation do you want "<<endl;
        cout<<"1-to insert appointments for specific day  "<<endl;
        cout<<"2-to insert appointments for multiual days  "<<endl;
        cout<<"3-to display the appointments for aday "<<endl;
        cout<<"4-to display the appointments for aweek"<<endl;
        cout<<"5-to make appointments of day equal to another day "<<endl;
        cout<<"6-to delete an appointment "<<endl;
        cout<<"7-to check if the appointments of two days are equal :"<<endl;
        cout<<"8-to end the program "<<endl;
        int choice;
        cin>>choice;
        int counter1=0,counter2=0;
        if(choice==1)
        {
            int i;
            cout<<"Enter the number of day do you want";
            cin>>i;
            cin>>day1;
            week.add_day(day1,i);
        }
        else if(choice==2)
        {
            int counter,numofthedays;
            cout<<"Enter the number of days :";
            cin>>numofthedays;
            cout<<"Enter the number of the day :";
            cin>>counter;
            cout<<"Enter the appointments of this day:"<<endl;
            cin>>day1;
            week.add_day(day1,counter);
            cout<<"Enter the number of each day do you want to insert these appointments :";
            for(int i=0;i<numofthedays;++i)
            {
                cin>>counter;
                week[counter]=day1;
            }
        }
        else if(choice==3)
        {
            cout<<"what day do you want to display ? "<<endl;
            int day;
            cin>>day;
            cout<<week[day];
        }
        else if(choice==4)
        {
            for(int i=0;i<7;++i)
                cout<<week[i]<<endl;
        }
         else if(choice==5)
        {
            cout<<"Enter the two days :"<<endl;
            int firstday,secondday;
            cin>>firstday>>secondday;
            week.equality(firstday,secondday);
        }
        else if(choice==6)
        {
            int day;
            cout<<"Enter the day do you want to delete :";
            cin>>day;
            week.del(day);
        }
        else if(choice==7)
        {
            int day1,day2;
            cout<<"Enter the two days :"<<endl;
            cin>>day1>>day2;
            if(week.days[day1]==week.days[day2])
                cout<<"yes they have the same appointments " <<endl;
            else
                cout<<"no they haven't the same appointments "<<endl;
        }
        else if(choice==8)
        {
            cout<<"End "<<endl;
            break;
        }
    }
    return 0;
}
