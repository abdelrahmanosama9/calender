#include <iostream>
#include "appointment.h"
#include "DayAppointment.h"
ostream &operator<<(ostream &out,const Appointment&appointment)
{
    cout<<"the appointment from  ";
    cout<<appointment.starttime;
    cout<<"to  ";
    cout<<appointment.endtime<<endl;

}
istream &operator>>(istream &in,Appointment&appointment)
{
start:
    cout<<"Enter start time of appointment"<<" "<<endl;
    cin>>appointment.starttime;
    cout<<"Enter end time of appointment"<<" "<<endl;
    cin>>appointment.endtime;
    while(true)
    {
        if(appointment.starttime>appointment.endtime)
        {
            cout<<"invalid inputs :"<<endl;
            cout<<"Enter the appointment again :"<<endl;
            goto start;
        }
        else
            break;
    }
    return in;
}
bool Appointment:: operator==(Appointment appointment)
{
    if(starttime==appointment.starttime &&endtime==appointment.endtime)
        return true;
    else
        return false;
}
bool Appointment:: operator!=(Appointment appointment)
{
    if(starttime!=appointment.starttime || endtime!=appointment.endtime)
        return true;
    else
        return false;
}
bool Appointment:: operator>(Appointment appointment)
{
    if(starttime >appointment.endtime)
        return true;
    else
        return false;
}
bool Appointment:: operator<(Appointment appointment)
{
    if(endtime<appointment.starttime)
        return true;
    else
        return false;
}
bool Appointment:: operator>=(Appointment appointment)
{
    if(!(starttime>appointment.endtime)&&(endtime>appointment.endtime))
        return true;
    else
        return false;
}
bool Appointment::operator<=(Appointment appointment)
{
    if((starttime<appointment.starttime)&&(!(endtime<appointment.starttime)))
        return true;
    else
        return false;
}
