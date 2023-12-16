#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "person.h"
#include "Thisinh.h"
#include "mylib.h"
using namespace std;

class node
{
public:
    ThiSinh data;
    node *next;
    node(ThiSinh ts)
    {
        data = ts;
        next = NULL;
    }
};

void Form()
{
    cout << "+";
    for (int i = 0; i < 180; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(14) << "Ten" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(14) << "Ngay Sinh" << setw(5) << "|";
    cout << setw(12) << "Dia Chi" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(7) << "Toan" << setw(3) << "|";
    cout << setw(5) << "Ly" << setw(3) << "|";
    cout << setw(6) << "Hoa" << setw(3) << "|";
    cout << setw(6) << "Van" << setw(3) << "|";
    cout << setw(6) << "Anh" << setw(3) << "|";
    cout << setw(6) << "Sinh" << setw(3) << "|";
    cout << setw(7) << "Tong" << setw(3) << "|" << endl;
}
void Form2()
{
    cout << "+";
    for (int i = 0; i < 192; i++)
        cout << "-";
    cout << "+" << endl;
    cout << "|" << setw(14) << "Ten" << setw(20) << "|";
    cout << setw(10) << "CCCD" << setw(10) << "|";
    cout << setw(5) << "GT" << setw(3) << "|";
    cout << setw(14) << "Ngay Sinh" << setw(5) << "|";
    cout << setw(12) << "Dia Chi" << setw(8) << "|";
    cout << setw(8) << "SBD" << setw(8) << "|";
    cout << setw(7) << "Toan" << setw(3) << "|";
    cout << setw(5) << "Ly" << setw(3) << "|";
    cout << setw(6) << "Hoa" << setw(3) << "|";
    cout << setw(6) << "Van" << setw(3) << "|";
    cout << setw(6) << "Anh" << setw(3) << "|";
    cout << setw(6) << "Sinh" << setw(3) << "|";
    cout << setw(7) << "Tong" << setw(3) << "|";
    cout << "Ma Nganh" << setw(4) << "|" << endl;
}
class LinkedList
{
    node *head;

public:
    node *getHead()
    {
        return head;
    }
    LinkedList()
    {
        head = NULL;
    }

    ~LinkedList()
    {
    }
    void insert(ThiSinh sv)
    {
        node *newNode = new node(sv);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    LinkedList sapxepdiem()
    {
        LinkedList ds = *this;
        int count = 0;
        node *p = ds.head;
        while (p != NULL)
        {
            count++;
            p = p->next;
        }
        bool swapped;
        node *ptr1;

        for (int i = 0; i < count - 1; i++)
        {
            swapped = false;
            ptr1 = ds.head;

            for (int j = 0; j < count - i - 1; j++)
            {
                if (ptr1->data.getsum() < ptr1->next->data.getsum())
                {
                    ThiSinh temp = ptr1->data;
                    ptr1->data = ptr1->next->data;
                    ptr1->next->data = temp;
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }

            if (swapped == false)
                break;
        }
        ds.xuat();
        return ds;
    }

    void xuat()
    {
        Form();
        node *temp = head;
        while (temp != NULL)
        {
            cout << "|";
            for (int i = 0; i < 180; i++)
                cout << "-";
            temp->data.display();
            cout << endl;
            temp = temp->next;
        }
        cout << "|";
        for (int i = 0; i < 180; i++)
            cout << "-";
        cout << "|" << endl;
    }
    node *search(string sbd, string name)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data.getsbd().find(sbd) != string::npos && temp->data.getname().find(name) != string ::npos)
                return temp;
            else
                temp = temp->next;
        }
        return NULL;
    }
    bool Delete(string sbd, string name)
    {
        node *p = search(sbd, name);
        if (p != NULL)
        {
            node *pre;
            node *temp = head;
            while (temp != NULL && p->data.getsbd() != temp->data.getsbd())
            {
                pre = temp;
                temp = temp->next;
            }
            pre->next = temp->next;
            delete (temp);
            return true;
        }
        else
            return false;
    }

    bool testempty()
    {
        return (head == NULL);
    }
    bool ktra(string cccd)
    {
        node *p = head;
        while (p != NULL)
        {
            if (p->data.getcccd().find(cccd) != string::npos)
                return true;
            p = p->next;
        }
        return false;
    }
    void docfile();
    void ghifile();
};

void LinkedList::docfile()
{
    ThiSinh ts;
    ifstream infile("dsthisinh.txt");
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            stringstream ss(line);
            string field;
            vector<string> fields;
            while (getline(ss, field, ','))
            {
                fields.push_back(field);
            }
            if (fields.size() >= 13)
            {
                string name = fields[0];
                string cccd = fields[1];
                string gt = fields[2];
                string dob = fields[3];
                stringstream ss_dob(dob);
                string day_str, month_str, year_str;
                getline(ss_dob, day_str, '/');
                getline(ss_dob, month_str, '/');
                getline(ss_dob, year_str, '/');
                int day = stoi(day_str);
                int month = stoi(month_str);
                int year = stoi(year_str);

                string address = fields[4];
                string sbd = fields[5];
                float to;
                try
                {
                    to = stof(fields[6]);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "Loi chuyen doi chuoi thanh so float: " << e.what() << endl;
                    to = 0.0f; 
                }

                float li;
                try
                {
                    li = stof(fields[7]);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "Loi chuyen doi chuoi thanh so float: " << e.what() << endl;
                    li = 0.0f; 
                }
                float ho;
                try
                {
                    ho = stof(fields[8]);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "Loi chuyen doi chuoi thanh so float: " << e.what() << endl;
                    ho = 0.0f; 
                }
                float van;
                try
                {
                    van = stof(fields[9]);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "Loi chuyen doi chuoi thanh so float: " << e.what() << endl;
                    van = 0.0f;
                }
                float anh;
                try
                {
                    anh = stof(fields[10]);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "Loi chuyen doi chuoi thanh so float: " << e.what() << endl;
                    anh = 0.0f; 
                }
                float sinh;
                try
                {
                    sinh = stof(fields[11]);
                }
                catch (const std::invalid_argument &e)
                {
                    cout << "Loi chuyen doi chuoi thanh so float: " << e.what() << endl;
                    sinh = 0.0f; 
                }
                 string k = fields[12];
                vector<string> wishes;

                if (fields.size() >= 13)
                {
                    stringstream ss_major(fields[13]);
                    string major;

                    while (getline(ss_major, major, ';'))
                    {
                        wishes.push_back(major);
                    }
                }
                else
                {
                    cout << "Dong khong du truong: " << line << endl;
                    continue;
                }
                           

                ThiSinh candidate(cccd, name, Date(day, month, year), address, gt, sbd, to, li, ho, van, anh, sinh, wishes, k);
                insert(candidate);
            }
        }

        infile.close();
    }
    else
    {
        cout << "Khong the mo file." << endl;
    }
}

void LinkedList::ghifile()
{
    ofstream outputFile;
    outputFile.open("dsthisinh.txt", ios::out);
    if (outputFile.is_open())
    {
        node *current = head;
        while (current != NULL)
        {
            outputFile << current->data.getname() << "," << current->data.getcccd() << "," << current->data.getgt() << ","
                       << current->data.getdate().day << "/" << current->data.getdate().month << "/" << current->data.getdate().year
                       << "," << current->data.getaddress() << "," << current->data.getsbd() << "," << current->data.getto()
                       << "," << current->data.getli() << "," << current->data.getho() << "," << current->data.getvan() << ","
                       << current->data.getanh() << "," << current->data.getsinh() << "," << current->data.getkhoi() << ",";
            for (string wish : current->data.wishes)
            {
                outputFile << wish << ";";
            }
            outputFile << endl;
            current = current->next;
        }
        outputFile.close();
    }
    else
    {
        cout << "Khong the mo file." << endl;
    }
}
