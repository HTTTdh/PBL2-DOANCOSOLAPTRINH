#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept> 
#include "mylib.h"
using namespace std;
class Date
{
public:
    int day, month, year;
    int sizedate()
    {
        int m = 6;
        if (day < 10)
            m++;
        else
            m += 2;
        if (month < 10)
            m++;
        else
            m = m + 2;
        return m;
    }
    Date(int day=0,int month=0, int year=0):day(day), month(month),year(year){}
};

class Person
{
    string cccd;
    string name;
    Date date;
    string address;
    string gt;
    public:
    void setcccd(string cccd);
    void setname(string name);
    void setdate(int, int, int);
    void setaddress(string address);
    void setgt(string gt);
    string getcccd();
    string getname();
    Date getdate();
    string getaddress();
    string getgt();
    Person();
    Person(string cccd, string name, Date date, string address, string gt);
    void nhapthongtin();
};
 void Person::setcccd(string cccd){
    this->cccd = cccd;
 }
void Person::setname(string name){
    this->name = name;
}
void Person::setdate(int day, int month, int year){
    this->date.day = day;
    this->date.month = month;
    this->date.year = year;
}
    void Person:: setaddress(string address){
        this->address = address;
}
void Person::setgt(string gt){
    this->gt = gt;
}
    string Person:: getcccd(){
        return cccd;
    }
    string Person:: getname(){
        return name;
    }
    Date Person:: getdate(){
        return date;
    }
    string Person::getaddress(){
        return address;
    }
    string Person:: getgt(){
        return gt;
    }
Person::Person()
{
    cccd = "";
    name = "";
    date.day = 0;
    date.month = 0;
    date.year = 0;
    address = "";
    gt ="";
}
Person::Person(string cccd, string name, Date date, string address, string gt) : cccd(cccd), name(name), date(date), address(address), gt(gt){};
void Person::nhapthongtin()
{
    fflush(stdin);
	gotoXY(22, 4);
    SetColor1(8, 4);
    cout  << "Ho ten: ";
     gotoXY(22, 5);
    cout  << "So cccd: ";
      gotoXY(22, 6);
    cout <<  "Ngay sinh: ";
      gotoXY(22,7);
    cout << "Thang sinh: ";
      gotoXY(22,8);
    cout  << "Nam sinh: ";
     gotoXY(22,9);
    cout  << "Dia chi (chi nhap tinh): ";
     gotoXY(22,10);
    cout << "Gioi tinh (Nam/Nu): ";
    gotoXY(22, 11);
    cout << "So bao danh: ";
     gotoXY(22, 12);
    cout << "Diem toan: ";
     gotoXY(22, 13);
    cout << "Diem ly: ";
    gotoXY(22, 14);
    cout << "Diem hoa: ";
    gotoXY(22, 15);
    cout << "Diem van: ";
    gotoXY(22,16);
    cout << "Diem anh: ";
    gotoXY(22,17);
    cout << "Diem sinh: ";
    gotoXY(22,18);
    cout << "So nguyen vong dang ki : ";
    gotoXY(31,4);
    SetColor1(8, 3);
    getline(cin, name);
   gotoXY(32,5);
    getline(cin, cccd);
   gotoXY(35,6);
    cin >> date.day;
   gotoXY(35,7);
    cin >> date.month;
   gotoXY(35, 8);
    cin >> date.year;
        cin.ignore(1);
    gotoXY(48,9);
    getline(cin, address);
    gotoXY(42,10);
    getline(cin,gt);
}
