#include <iostream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <fstream>
#include <iomanip>
#include <stdexcept>
#include "linklist.h"
#include "Nganh.h"
#include "mylib.h"
using namespace std;

void n_box(int x, int y, int w, int h, int t_color, int b_color, string nd[], int n)
{
    for (int i = 0; i < n; i++)
    {
        box(x, y + i * 2, w, h, t_color, b_color, nd[i]);
        if (i != 0)
        {
            gotoXY(x, y + i * 2);
            std::cout << char(195);
            gotoXY(x + 40, y + (i * 2));
            std::cout << char(180);
        }
    }
}
void thanh_sang(int x, int y, int w, int h, int b_color, string tieude)
{
    textcolor(b_color);
    for (int iy = y + 1; iy <= y + h - 1; iy++)
    {
        for (int ix = x + 1; ix <= x + w - 1; ix++)
        {
            gotoXY(ix, iy);
            std::cout << " ";
        }
    }
    SetColor(7);
    gotoXY(x + 1, y + 1);
    std::cout << tieude;
}
void inMenu(int x, int y, int w, int h, int t_color, int b_color, int b_color_sang, string nd[], int n)
{
        ShowCur(0);
    n_box(x, y, w, h, t_color, b_color, nd, n);
    thanh_sang(x, y, w, h, b_color_sang, nd[0]);
}
typedef bool (*CompareFunc)(ThiSinh &, string &);

bool CompareByName(ThiSinh &ts, string &name)
{
    return (ts.getname().find(name) != string::npos);
}

bool CompareByAddress(ThiSinh &ts, string &address)
{
    return (ts.getaddress().find(address) != string::npos);
}

bool CompareByCCCD(ThiSinh &ts, string &cccd)
{
    return (ts.getcccd().find(cccd) != string::npos);
}

bool CompareBySBD(ThiSinh &ts, string &sbd)
{
    return (ts.getsbd().find(sbd) != string::npos);
}

bool CompareByYear(ThiSinh &ts, string &yearStr)
{
    int year = stoi(yearStr);
    return (ts.getdate().year == year);
}

bool CompareByGender(ThiSinh &ts, string &gender)
{

    return (ts.getgt().find(gender) != string::npos);
}

void DisplayFilteredData(LinkedList &list, const string &message, CompareFunc compareFunc, string compareValue)
{
    fflush(stdin);
    node *p = list.getHead();
    gotoXY(60, 3);
    cout << message + ": ";
    getline(cin, compareValue);
    gotoXY(0, 7);
    Form();
    while (p != NULL)
    {
        if (compareFunc(p->data, compareValue))
        {
            cout << "|";
            for (int i = 0; i < 180; i++)
                cout << "-";
            p->data.display();
            cout << endl;
        }
        p = p->next;
    }
    cout << "|";
    for (int i = 0; i < 180; i++)
    {
        cout << "-";
    }
    cout << "|" << endl;
    system("pause");
}

void search_info(LinkedList &list)
{
    system("COLOR 0A");
    string value;
    string thu[] = {"                Ten", "               Dia Chi", "               CCCD",
                    "                SBD", "              Nam Sinh", "              Gioi Tinh", "               Thoat"};
    int x = 30, y = 5;
    int w = 40, h = 2;
    int n = 7;
    int b_color = 4;
    int t_color = 11;
    int b_color_sang = 75;
    inMenu(x, y, w, h, t_color, b_color, b_color_sang, thu, n);
    int xp = x;
    int yp = y;
    int xcu = xp;
    int ycu = yp;
    int i = 0;
    int d = 0;
    bool kt = false;

    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, thu[i]);
            xcu = xp;
            ycu = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, thu[d]);
            kt = false;
            i = d;
        }

        if (_kbhit())
        {
            char cs;
            char c = _getch();
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72)
                {
                    if (yp != y)
                    {
                        yp -= 2;
                        d = i - 1;
                    }
                    else
                    {
                        yp = y + h * (n - 1);
                        d = (i - 1 + (n)) % n;
                    }
                }
                else if (c == 80)
                {
                    if (yp != y + h * (n - 1))
                    {
                        yp += 2;
                        d = i + 1;
                    }
                    else
                    {
                        yp = y;
                        d = (i + 1) % n;
                    }
                }
            }
            else if (c == 13)
            {
                system("cls");
                system("COLOR 80");
                switch (d)
                {
                case 0:
                    DisplayFilteredData(list, "Nhap ten ban muon hien thi?", CompareByName, value);
                    break;
                case 1:
                    DisplayFilteredData(list, "Nhap dia chi ban muon hien thi?", CompareByAddress, value);
                    break;
                case 2:
                    DisplayFilteredData(list, "Nhap so can cuoc cong dan ban muon hien thi?", CompareByCCCD, value);
                    break;
                case 3:
                    DisplayFilteredData(list, "Nhap so bao danh ma ban muon hien thi?", CompareBySBD, value);
                    break;
                case 4:
                {
                    string yearString;
                    DisplayFilteredData(list, "Nhap nam sinh ban muon hien thi?", CompareByYear, value);
                    break;
                }
                case 5:
                    DisplayFilteredData(list, "Ban muon hien thi gioi tinh nao? (Nam/Nu)", CompareByGender, value);
                    break;
                case 6:
                    return;
                    break;
                }
                system("cls");
                system("COLOR 02");
                n_box(x, y, w, h, t_color, b_color, thu, n);
            }
        }
    }
}

void edit_infor(LinkedList &ds, string sbd, string name)
{
    node *p = ds.search(sbd, name);
    system("COLOR 0A");
    string value;
    string thu[] = {"                Ten", "               Dia Chi", "               CCCD",
                    "                SBD", "              Nam Sinh", "              Gioi Tinh", "                 Diem", "               Thoat"};
    int x = 30, y = 5;
    int w = 40, h = 2;
    int n = 8;
    int b_color = 4;
    int t_color = 11;
    int b_color_sang = 75;
    inMenu(x, y, w, h, t_color, b_color, b_color_sang, thu, n);
    int xp = x;
    int yp = y;
    int xcu = xp;
    int ycu = yp;
    int i = 0;
    int d = 0;
    bool kt = false;
    string New;
    string c;
    Date date;
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, thu[i]);
            xcu = xp;
            ycu = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, thu[d]);
            kt = false;
            i = d;
        }

        if (_kbhit())
        {
            char cs;
            char c = _getch();
            if (c == -32)
            {
                kt = true;
                c = _getch();
                if (c == 72)
                {
                    if (yp != y)
                    {
                        yp -= 2;
                        d = i - 1;
                    }
                    else
                    {
                        yp = y + h * (n - 1);
                        d = (i - 1 + (n)) % n;
                    }
                }
                else if (c == 80)
                {
                    if (yp != y + h * (n - 1))
                    {
                        yp += 2;
                        d = i + 1;
                    }
                    else
                    {
                        yp = y;
                        d = (i + 1) % n;
                    }
                }
            }
            else if (c == 13)
            {
                system("cls");
                system("COLOR 80");
                p->data.display1();
                switch (d)
                {
                case 0:
                {
                    gotoXY(80, 4);
                    cout << "Nhap lai ten: ";
                    cin.ignore(0);
                    getline(cin, New);
                    p->data.setname(New);
                    break;
                }
                case 1:
                {
                    gotoXY(80, 4);
                    string newAddress;
                    cout << "Nhap lai dia chi: ";
                    cin.ignore(0);
                    getline(cin, newAddress);
                    p->data.setaddress(newAddress);
                    break;
                }
                case 2:
                {
                    gotoXY(80, 4);
                    string newCCCD;
                    cout << "Nhap so CCCD moi: ";
                    cin.ignore(0);
                    getline(cin, newCCCD);
                    p->data.setcccd(newCCCD);
                    break;
                }
                case 3:
                {
                    gotoXY(80, 4);
                    string sbdnew;
                    cout << "Nhap so bao danh moi: ";
                    cin.ignore(0);
                    getline(cin, sbdnew);
                    p->data.setsbd(sbdnew);
                    break;
                }
                case 4:
                {
                    int day, month, year;
                    gotoXY(80, 4);
                    cout << "Nhap lai ngay/thang/nam sinh: " << endl;
                    gotoXY(85, 5);
                    cout << "Nhap ngay: ";
                    cin >> day;
                    gotoXY(85, 6);
                    cout << "Nhap thang: ";
                    cin >> month;
                    gotoXY(85, 7);
                    cout << "Nhap nam: ";
                    cin >> year;
                    p->data.setdate(day, month, year);
                    break;
                }
                case 5:
                {
                    string newgt;
                    gotoXY(80, 4);
                    cout << "Nhap gioi tinh: (Nam/Nu) ";
                    cin >> newgt;
                    p->data.setgt(newgt);
                    break;
                }
                case 6:
                {
                    float newMath, newPhysics, newChemistry, newvan, newanh, newsinh;
                    gotoXY(80, 4);
                    cout << "Nhap lai diem";
                    gotoXY(85, 6);
                    cout << "Nhap diem toan: ";
                    cin >> newMath;
                    gotoXY(85, 7);
                    cout << "Nhap diem ly: ";
                    cin >> newPhysics;
                    gotoXY(85, 8);
                    cout << "Nhap diem hoa: ";
                    cin >> newChemistry;
                    gotoXY(85, 9);
                    cout << "Nhap diem van: ";
                    cin >> newvan;
                    gotoXY(85,10);
                    cout << "Nhap diem anh: ";
                    cin >> newanh;
                    gotoXY(85, 11);
                    cout << "Nhap diem sinh: ";
                    cin >> newsinh;
                    p->data.setto(newMath);
                    p->data.setli(newPhysics);
                    p->data.setho(newChemistry);
                    p->data.setvan(newvan);
                    p->data.setanh(newanh);
                    p->data.setsinh(newsinh);
                    break;
                }
                case 7:
                    return;
                    break;
                }
                gotoXY(50, 18);
                cout << "THI SINH MOI SUA DA DUOC CAP NHAT";
                gotoXY(0, 20);
                Form();
                cout << "|";
                for (int i = 0; i < 180; i++)
                    cout << "-";
                p->data.display();
                cout << endl
                     << "|";
                for (int i = 0; i < 180; i++)
                    cout << "-";
                cout << "|" << endl;
                system("pause");
                system("cls");
                system("COLOR 02");
                n_box(x, y, w, h, t_color, b_color, thu, n);
            }
        }
    }
}
string tim_nganh(float *dc, string s)
{
    string s1;
    string str = "";
    int result;
    mofile();
     s1= s;
    s1[0] = toupper(s[0]);
    Nganhdaotao *p = pHead;
    while (p != NULL)
    {
        result = strcmp(p->TenNganh.c_str(), s1.c_str());
        if (result == 0)
        {
            *dc = p->DiemChuan;
            return s1;
        }
        p = p->next;
    }
    return str;
}

LinkedList check_dau(LinkedList &ds)
{
    LinkedList dsdau;
    node *p = ds.getHead();
    while (p != NULL)
    {
        for (int i = 0; i < p->data.wishes.size(); i++)
        {
            float dc;
            string s = tim_nganh(&dc, p->data.wishes[i]);
            if (s != "")
            {
                if (p->data.getkhoi() == "A00" && p->data.getsuma() >= dc)
                {
                    ThiSinh candidate(p->data.getcccd(), p->data.getname(), p->data.getdate(), p->data.getaddress(), p->data.getgt(), p->data.getsbd(), p->data.getto(), p->data.getli(), p->data.getho(), p->data.getvan(), p->data.getanh(), p->data.getsinh(), {s}, p->data.getkhoi());
                    dsdau.insert(candidate);
                    break;
                }
                else if (p->data.getkhoi() == "A01" && p->data.getsuma1() >= dc)
                {
                    ThiSinh candidate(p->data.getcccd(), p->data.getname(), p->data.getdate(), p->data.getaddress(), p->data.getgt(), p->data.getsbd(), p->data.getto(), p->data.getli(), p->data.getho(), p->data.getvan(), p->data.getanh(), p->data.getsinh(), {s}, p->data.getkhoi());
                    dsdau.insert(candidate);
                    break;
                }
            }
        }
        p = p->next;
    }
    return dsdau;
}
