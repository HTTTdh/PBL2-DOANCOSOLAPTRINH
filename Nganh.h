#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct Nganhdaotao
{
    string TenNganh;
    string MaNganh;
    float DiemChuan;
    Nganhdaotao *next;
};

Nganhdaotao *pHead = NULL;

void insertnganh(Nganhdaotao *p)
{
    if (pHead == NULL)
    {
        pHead = p;
    }
    else
    {
        Nganhdaotao *temp = pHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
    }
}
string tim_ma_nganh(string ten_nganh)
{
    Nganhdaotao *current = pHead;
    while (current != NULL)
    {
        if (ten_nganh == current->TenNganh)
        {
            return current->MaNganh;
        }
        current = current->next;
    }
    return "";
}

void mofile()
{
    ifstream inputfile;
    inputfile.open("nganhdaotao.txt", ios::in);
    if (inputfile.is_open())
    {
        string line;
        while (getline(inputfile, line))
        {
            Nganhdaotao *p = new Nganhdaotao;

            size_t pos = line.find(",");
            p->TenNganh = line.substr(0, pos);
            line.erase(0, pos + 1);

            pos = line.find(",");
            p->MaNganh = line.substr(0, pos);
            line.erase(0, pos + 1);

            p->DiemChuan = stof(line);

            p->next = NULL;
            insertnganh(p);
        }
        inputfile.close();
    }
    else
    {
        cout << "Khong the mo file." << endl;
    }
}

void output()
{
    mofile();
    Nganhdaotao *temp = pHead;
    gotoXY(113,1);
    cout  << "DANH SACH CAC NGANH DAO TAO" << endl;
    gotoXY(40,2);
    cout << setw(41) << "+";
    for (int i = 0; i < 87; i++)
        cout << "-";
    cout << "+" << endl;
    gotoXY(80,3);
    cout << "|" << setw(24) << "Ten Nganh" << setw(15) << "|";
    cout << setw(17) << "Ma Nganh" << setw(11) << "|";
    cout << setw(18) << "Diem Chuan" << setw(3) << "|" << endl;
    int j=0;
    while (temp != NULL)
    {
        gotoXY(80,4+j);
        cout << "|";
        for (int i = 0; i < 87; i++)
            cout << "-";
        cout << "|" ;
        gotoXY(80,5+j);
        cout << "|" << temp->TenNganh << setw(39 - (temp->TenNganh).length()) << "|";
        cout << setw(16) << temp->MaNganh << setw(12) << "|";
        cout << setw(12) << temp->DiemChuan << setw(9) << "|" ;
        j=j+2;
        temp = temp->next;
    }
    pHead = NULL;
    gotoXY(80,j+2);
    cout << "|";
    for (int i = 0; i < 87; i++)
        cout << "-";
    cout << "|" << endl;
     gotoXY(80,j+4);
    cout << "+";
    for (int i = 0; i < 87; i++)
        cout << "-";
    cout << "+" << endl;
}

string capitalizeFirstLetter(string str)
{
    int len = str.length();
    if (len == 0 || str[0] == ' ')
    {
        return str;
    }
    str[0] = toupper(str[0]);
    for (int i = 1; i < len; i++)
    {
        if (str[i] == ' ' && isalpha(str[i + 1]))
        {
            str[i + 1] = toupper(str[i + 1]);
        }
    }
    return str;
}