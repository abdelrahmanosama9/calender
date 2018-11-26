#ifndef TIME_H
#define TIME_H
#include <iostream>
using namespace std;
class Time
{
    private:
        int hour;
        int minute;
        string daynight;
    public:
    Time();
    Time(int hour,int minute,string daynight);
    friend istream &operator>>(istream &in,Time&time);
    friend ostream &operator<<(ostream &out,const Time&time);
    bool operator>(Time time);
    bool operator<(Time time);
    bool operator==(Time time);
    bool operator!=(Time time);
};
class Appointment{
    private:
    Time starttime;
    Time endtime;
    public:
    friend istream &operator>>(istream &in,Appointment&appointment);
    friend ostream &operator<<(ostream &out,const Appointment&appointment);
    bool operator> (Appointment appointment);
    bool operator< (Appointment appointment);
    bool operator==(Appointment appointment);
    bool operator!=(Appointment appointment);
    bool operator>=(Appointment appointment);
    bool operator<=(Appointment appointment);
};
class DayAppointment{
        public:
        Appointment * appointments;
        int numOfAppointments;
        string weekDay;
        DayAppointment();
        void equality(const DayAppointment &day);
        friend istream& operator >> (istream& in, DayAppointment& day);
        friend ostream& operator << (ostream& out, const DayAppointment& day);
        bool operator==(DayAppointment &day);
        bool operator!=(DayAppointment& day);
        DayAppointment(const DayAppointment&day);
        Appointment operator[](int i);
        void del();
};
class Calendar
{
    public:
        DayAppointment * days;
        int numOfDays;
        Calendar();
        DayAppointment operator[](int n);
        friend istream& operator >> (istream& in, Calendar&calendar);
        friend ostream& operator << (ostream& out, const Calendar& calendar);
        void add_day(DayAppointment &appointment,int i);
        void del(int day);
        void equality(int day1,int day2);
};
#endif
