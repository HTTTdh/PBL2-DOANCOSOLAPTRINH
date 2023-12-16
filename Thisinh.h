#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include "person.h"
#include "mylib.h"
using namespace std;
class ThiSinh : public Person
{
    string sbd;
    float to, li, ho;
    float van, anh, sinh;
    float sum;
    string khoi;
public:
    vector<string> wishes;
    ThiSinh();
    ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho, float van, float anh, float sinh, vector<std::string> w, string k);
    void setsbd(string sbd);
    string getsbd();
    void setto(float to);
    float getto();
    void setli(float li);
    float getli();
    void setho(float ho);
    float getho();
    void setvan(float van);
    float getvan();
    void setanh(float anh);
    float getanh();
    void setsinh(float sinh);
    float getsinh();
    float getsuma1();
    float getsuma();
    float getsum();
    void setkhoi(string);
    string getkhoi();
    void input();
    void display();
    void display1();
    ~ThiSinh()
    {
    }
};
void ThiSinh::setvan(float van)
{
    this->van = van;
}
float ThiSinh::getvan()
{
    return van;
}
void ThiSinh::setanh(float anh)
{
    this->anh = anh;
}
float ThiSinh::getanh()
{
    return anh;
}
void ThiSinh::setsinh(float sinh)
{
    this->sinh = sinh;
}
float ThiSinh::getsinh()
{
    return sinh;
}
float ThiSinh::getsuma1()
{
    return to + li + anh;
}
float ThiSinh::getsuma()
{
    return to + li + ho;
}
void ThiSinh::setsbd(string sbd)
{
    this->sbd = sbd;
}
string ThiSinh::getsbd()
{
    return sbd;
}
void ThiSinh::setto(float to)
{
    this->to = to;
}
float ThiSinh::getto()
{
    return to;
}
void ThiSinh::setli(float li)
{
    this->li = li;
}
float ThiSinh::getli()
{
    return li;
}
void ThiSinh::setho(float ho)
{
    this->ho = ho;
}
float ThiSinh::getho()
{
    return ho;
}
float ThiSinh::getsum()
{
    return to + li + ho + van + anh + sinh;
}
void ThiSinh::setkhoi(string m){
    this->khoi = m;
}
string ThiSinh::getkhoi(){
    return khoi;
}
ThiSinh::ThiSinh() : Person()
{
    to = 0;
    sbd = "";
    li = 0;
    ho = 0;
}
ThiSinh::ThiSinh(string cccd, string name, Date date, string address, string gt, string sbd, float to, float li, float ho,  float van, float anh, float sinh, vector<std::string> w, string k) :Person(cccd, name, date, address, gt), sbd(sbd), to(to), li(li), ho(ho), van(van), anh(anh), sinh(sinh)
{
    this->khoi = k;
    wishes = w;
};
void ThiSinh::input()
{
    SetColor1(8, 4);
    gotoXY(30, 1);
    cout << "DIEN THONG TIN THI SINH";
    draw(20, 2, 62, 30);
    nhapthongtin();
    gotoXY(35, 4);
    cin.ignore(0);
    gotoXY(36, 11);
    getline(cin, sbd);
    gotoXY(34, 12);
    cin >> to;
    gotoXY(34, 13);
    cin >> li;
    gotoXY(34, 14);
    cin >> ho;
    gotoXY(34, 15);
    cin >> van;
    gotoXY(34, 16);
    cin >> anh;
    gotoXY(34,17);
    cin >> sinh;
    gotoXY(47, 18);
    int so_nv;
    cin >> so_nv;
    fflush(stdin);
    int i=0;
    for ( i = 0; i < so_nv; i++)
    {
        string nv;
        gotoXY(22, 19 + i);
        cin.ignore(0);
        SetColor1(8, 2);
        cout << "Nguyen vong thu " << i + 1 << " : ";
        SetColor1(8, 3);
        getline(cin, nv);
        wishes.push_back(nv);
    }
       gotoXY(22, 28);
        cout << "Xet khoi nao: " ;
        SetColor1(8, 3);
        getline(cin, khoi);
}
void ThiSinh::display()
{
    cout << "|" << endl;
    cout << "|" << getname() << setw(34 - getname().length()) << "|";
    cout << getcccd() << setw(20 - getcccd().length()) << "|";
    cout << setw(4) << getgt() << setw(4) << "|";
    cout << getdate().day << "/" << getdate().month << "/" << getdate().year << setw(19 - getdate().sizedate()) << "|";
    cout << getaddress() << setw(20 - getaddress().length()) << "|";
    cout << sbd << setw(16 - sbd.length()) << "|";
    cout << setw(7) << to << setw(3) << "|";
    cout << setw(5) << li << setw(3) << "|";
    cout << setw(6) << ho << setw(3) << "|";
    cout << setw(6) << van << setw(3) << "|";
    cout << setw(6) << anh << setw(3) << "|";
    cout << setw(6) << sinh << setw(3) << "|";
    cout << setw(5) << to + li + ho + van + anh + sinh << setw(5) << "|";
}
void ThiSinh::display1()
{
    draw(10, 1, 40, 19);
    SetColor1(8, 3);
    gotoXY(12, 4);
    cout << "Ten: " << getname();
    gotoXY(12, 5);
    cout << "CCCD: " << getcccd();
    gotoXY(12, 6);
    cout << "Gioi tinh: " << getgt();
    gotoXY(12, 7);
    cout << "Nam sinh: " << getdate().day << "/" << getdate().month << "/" << getdate().year;
    gotoXY(12, 8);
    cout << "Dia chi: " << getaddress();
    gotoXY(12, 9);
    cout << "SBD: " << getsbd();
    gotoXY(12, 10);
    cout << "Diem toan: " << getto();
    gotoXY(12, 11);
    cout << "Diem li: " << getli();
    gotoXY(12, 12);
    cout << "Diem hoa: " << getho();
    gotoXY(12, 13);
    cout << "Diem van: " << getvan();
    gotoXY(12,14);
    cout << "Diem anh: " << getanh();
    gotoXY(12, 15);
    cout << "Diem sinh: " << getsinh();
}