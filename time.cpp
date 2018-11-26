#include <iostream>
#include "time.h"
Time::Time()
{
    hour=0;
    minute=0;
    daynight=" ";
}
Time::Time(int hour,int minute,string daynight)
{
    this->hour=hour;
    this->minute=minute;
    this->daynight=daynight;
}
istream &operator>>(istream&cin,Time&time)
{
    cout<<"Enter hour:"<<" ";
    cin>>time.hour;
    cout<<"Enter minute:"<<" ";
    cin>>time.minute;
    cout<<"Enter daynight:"<<" ";
    cin>>time.daynight;
    return cin;
}
ostream &operator<<(ostream&out,const Time&time)
{
    out<<time.hour<<":"<<time.minute<<" "<<time.daynight;
    return out;
}
bool Time::operator>(Time time)
{
    if(daynight=="PM" &&time.daynight=="AM")
    {
        return true;
    }
    else if(daynight=="AM" &&time.daynight=="PM")
    {
        return false;
    }
    else if(hour>time.hour)
    {
        return true;
    }

    else if(hour<time.hour)
    {
        return false;
    }
    else
    {
        if(minute>time.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
bool Time::operator<(Time time)
{
    if(daynight=="PM" &&time.daynight=="AM")
    {
        return false;
    }

    else if(daynight=="AM" &&time.daynight=="PM")
    {
        return true;
    }
    else if(hour>time.hour)
    {
        return false;
    }

    else if(hour<time.hour)
    {
        return true;
    }
    else
    {
        if(minute>time.minute)
        {
            return false;
        }
        else
        {

            return true;
        }
    }
}
bool Time::operator==(Time time)
{
    if(daynight=="AM" && time.daynight=="AM" ||daynight=="PM" &&time.daynight=="PM")
    {
        if(hour==time.hour &&minute==time.minute)
        {

            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}
bool Time::operator!=(Time time)
{
    if( (daynight=="AM" &&time.daynight=="AM") || (daynight=="PM" &&time.daynight=="PM"))
    {
        if(hour==time.hour &&minute==time.minute)
        {
            return false;
        }
        else
        {
            return true;
        }

    }
    else
    {
        return true;
    }
}
ostream &operator<<(ostream &out,const Appointment&appointment)
{
    cout<<"the appointment from  ";
    cout<<appointment.starttime;
    cout<<"to  ";
    cout<<appointment.endtime<<endl;
    cout<<"---------------------------------"<<endl;
    return cout;
}
istream &operator>>(istream &cin,Appointment&appointment)
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
    return cin;
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
DayAppointment ::DayAppointment()
{
    numOfAppointments=100;
    weekDay=" ";
    appointments=new Appointment[numOfAppointments];
}
DayAppointment::DayAppointment (const DayAppointment& day)
{
    weekDay=day.weekDay;
    numOfAppointments=day.numOfAppointments;
    appointments=new Appointment[day.numOfAppointments];
    for(int i=0; i<numOfAppointments; ++i)
    {
        appointments[i]=day.appointments[i];
    }
}
istream &operator>>(istream& cin, DayAppointment& d)
{

    cout<<"Enter the day "<<endl;
    cin>>d.weekDay;
    cout<<"Enter Number Of Appointments : ";
    cin>>d.numOfAppointments;
    d.appointments = new Appointment[d.numOfAppointments];
    for(int i=0; i < d.numOfAppointments ; i++)
    {
        cout<<"Appointment "<<i+1<<endl;
        cin>>d.appointments[i];
        cout<<"--------------------------------------"<<endl;
    }
    return cin;
}
ostream& operator << (ostream& cout, const DayAppointment& d)
{
    cout <<d.weekDay<<endl;
    cout<<"---------------------------------------"<<endl;
    for(int i=0; i < d.numOfAppointments ; i++)
    {
        cout <<d.appointments[i]<<i+1;
        cout<<"------------------------------------"<<endl;
    }
    return cout;
}
bool DayAppointment::operator==(DayAppointment& day)
{
    if(numOfAppointments==day.numOfAppointments)
    {
        bool flag=true;
        for(int i=0; i<day.numOfAppointments; ++i)
        {
            if(appointments[i]!=day.appointments[i])
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
            return true;
        else
            return false;
    }
    else
        return false;
}
bool DayAppointment::operator!=(DayAppointment &day)
{
    if(numOfAppointments==day.numOfAppointments)
    {
        bool flag=false;
        for(int i=0; i<day.numOfAppointments; ++i)
        {
            if(appointments[i]==day.appointments[i])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            return true;
        else
            return false;
    }
    else
        return false;
}
void DayAppointment::del(){
    delete appointments;
}
Appointment DayAppointment:: operator[](int i)
{
    appointments[i]=*(appointments+i);
    return appointments[i];
}
Calendar ::Calendar(){
    numOfDays=7;
    days=new DayAppointment[numOfDays];
}
DayAppointment Calendar::operator[](int n)
{
    days[n]=*(days+n);
    return days[n];
}
istream& operator >> (istream& cin, Calendar& calendar)
{
    cout<<"Enter the number of days :"<<endl;
    cin>>calendar.numOfDays;
    calendar.days=new DayAppointment[calendar.numOfDays];
    for(int i=0;i<calendar.numOfDays;++i)
    {
        cin>>calendar.days[i];
        cout<<"-------------------------------------------------------------"<<endl;
    }
    return cin;
}
ostream& operator << (ostream& cout, const Calendar& calendar)
{
    for(int i=0;i<calendar.numOfDays;++i)
    {
        cout<<calendar.days[i]<<endl;
    }
    cout<<endl;
    return  cout;
}
void Calendar::add_day(DayAppointment& appointment,int i)
{
    days[i]=appointment;
}
void Calendar::del(int day){
    days[day].del();
}
void Calendar::equality(int day1,int day2)
{
        days[day2]=days[day1];
}
