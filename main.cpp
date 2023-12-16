#include <iostream>
#include <windows.h>
#include <string>
#include <unistd.h>
#include "mylib.h"
#include "main.h"

using namespace std;
int x = 30;
int y = 5;

void menu()
{
    system("cls");
    creatbox(0, 0, 90, 48);
    LinkedList danhsach;
    LinkedList ds;
    danhsach.docfile();
    ThiSinh ts;
    string sbd;
    string name;
    int option;
    int w = 40;
    int h = 2;
    SetColor(14);
    gotoXY(25, 3);
    cout << "QUAN LI CAC THI SINH DU THI VAO MOT TRUONG DAI HOC";
    string nd[10] = {"      XUAT DANH SACH CAC THI SINH", "         THEM MOT THI SINH", "         XOA MOT THI SINH", "        SUA THONG TIN THI SINH", "    TIM KIEM THONG TIN THI SINH", "     SAP XEP DANH SACH THEO DIEM", "        DANH DACH DAU DAI HOC", "       DANH SACH DAU THEO NGANH", "                THOAT"};
    int n = 9;
    bool kt = false;
    int b_color = 1;
    int pointer = 0;
    int t_color = 11;
    int b_color_sang = 75;
    inMenu(x, y, w, h, t_color, b_color, b_color_sang, nd, n);
    int xp = x;
    int yp = y;
    int xcu = xp;
    int ycu = yp;
    int i = 0;
    int d = 0;
    while (true)
    {
        if (kt == true)
        {
            gotoXY(xcu, ycu);
            thanh_sang(xcu, ycu, w, h, b_color, nd[i]);
            xcu = xp;
            ycu = yp;
            thanh_sang(xp, yp, w, h, b_color_sang, nd[d]);
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
                system("COLOR 8F");
                switch (d)
                {
                case 0:
                {
                    gotoXY(45, 2);
                    cout << "DANH SACH CAC THI SINH DU THI VAO MOT TRUONG DAI HOC";
                    gotoXY(0, 4);
                    danhsach.xuat();
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 1:
                {
                    output();
                     gotoXY(10,40);
                    SetColor1(4, 4);
                    cout << "** Vui long nhap ten nganh co trong bang ben canh";
                    ShowCur(1);
                    ts.input();
                   
                    if (danhsach.ktra(ts.getcccd()) == true)
                    {
                        //draw(25, 10, 60, 20);
                        tbao(25,10,35,10);
                        gotoXY(30, 12);
                        cout << "Da ton tai thi sinh nay!!" << endl;
                    }
                    else
                    {
                        danhsach.insert(ts);
                        ts.wishes.clear();
                        danhsach.ghifile();
                        draw1(25, 10, 60, 20);
                        gotoXY(30, 12);
                        cout << "Da them thanh cong";
                    }
                    gotoXY(28, 15);
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 2:
                {
                    draw(60, 2, 90, 10);
                    SetColor1(8, 2);
                    gotoXY(62, 4);
                    cout << "Nhap thong tin ban muon xoa:" << endl;
                    SetColor1(8, 4);
                    gotoXY(62, 5);
                    cout << "Ten: ";
                     gotoXY(62, 6);
                    cout << "sbd: ";
                    SetColor1(8, 3);
                    gotoXY(68, 5);
                    getline(cin, name);
                   gotoXY(67, 6);
                    getline(cin, sbd);
                    if (danhsach.search(sbd, name) != NULL)
                    {
                        if (danhsach.Delete(sbd, name) == true)
                        {
                            draw1(62, 15, 97, 25);
                            gotoXY(66, 17);
                            cout << "Da xoa thanh cong";
                            gotoXY(65, 19);
                            system("pause");
                        }
                        else
                        {
                            draw1(62, 15, 97, 25);
                            gotoXY(66, 17);
                            cout << "Khong xoa duoc thong tin nay";
                            gotoXY(65, 19);
                            system("pause");
                        }
                    }
                    else
                    {
                        tbao(25,10,35,10);
                      //  draw(62, 15, 97, 25);
                        gotoXY(66, 17);
                        cout << "Khong tim thay thong tin" << endl;
                        gotoXY(65, 19);
                        system("pause");
                    }
                    danhsach.ghifile();
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 3:
                {
                    draw(60, 1, 90, 9);
                    SetColor1(8, 4);
                    gotoXY(62, 4);
                    cout << "Nhap thong tin ban muon sua:" << endl;
                    fflush(stdin);
                    SetColor1(8, 4);
                    gotoXY(62, 6);
                    cout << "Ten: ";
                     gotoXY(62, 7);
                    SetColor1(8, 4);
                    cout << "sbd: ";
                    SetColor1(8, 3);
                    gotoXY(68,6);
                    getline(cin, name);
                   gotoXY(67, 7);
                    SetColor1(8, 3);
                    getline(cin, sbd);
                    system("cls");
                    if (danhsach.search(sbd, name) != NULL)
                    {
                        edit_infor(danhsach, sbd, name);
                        danhsach.ghifile();
                    }
                    else
                    {
                        draw1(62, 15, 97, 25);
                        gotoXY(66, 17);
                        cout << "Khong tim thay thong tin" << endl;
                        gotoXY(65, 19);
                        system("pause");
                    }
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 4:
                {
                    search_info(danhsach);
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 5:
                {
                    gotoXY(45, 2);
                    cout << "DANH SACH THI SINH DA DUOC SAP XEP DIEM THEO THU TU GIAM DAN";
                    gotoXY(0, 4);
                    danhsach.sapxepdiem();
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 6:
                {
                    gotoXY(60, 2);
                    cout << "DANH SACH THI SINH DAU DAI HOC";
                    gotoXY(0, 4);
                    ds = check_dau(danhsach);
                    Form2();
                    node *temp = ds.getHead();
                    string tenganh;
                    while (temp != NULL)
                    {
                        cout << "|";
                        for (int i = 0; i < 192; i++)
                            cout << "-";
                        temp->data.display();
                        tenganh = temp->data.wishes.front();
                        cout << tim_ma_nganh(tenganh);
                        cout << setw(5) << "|";
                        cout << endl;
                        temp = temp->next;
                    }
                    cout << "|";
                    for (int i = 0; i < 192; i++)
                        cout << "-";
                    cout << "|" << endl;
                    system("pause");
                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 7:
                {
                    string tennganh, str, s;
                    float dc;
                    gotoXY(45, 1);
                    cout << "Ban muon tra danh sach cua nganh nao? ";
                    SetColor1(8, 4);
                    getline(cin, tennganh);
                    str = tennganh;
                    str[0] = toupper(str[0]);
                    s = tim_nganh(&dc, str);
                    if (dc)
                    {
                        ds = check_dau(danhsach);
                        gotoXY(50, 3);
                        for (int i = 0; i < tennganh.size(); i++)
                        {
                            str[i] = toupper(str[i]);
                        }
                        SetColor1(8, 3);
                        cout << "DANH SACH CAC THI SINH DAU NGANH " + str << endl;
                        gotoXY(0, 4);
                        Form2();
                        node *temp = ds.getHead();
                        string tenganh1;
                        while (temp != NULL)
                        {
                            tenganh1 = temp->data.wishes.front();
                            tenganh1[0] = toupper(temp->data.wishes.front()[0]);
                            if (tim_nganh(&dc, tenganh1) == s )
                            {
                                cout << "|";
                                for (int i = 0; i < 192; i++)
                                    cout << "-";
                                temp->data.display();
                                cout << tim_ma_nganh(tenganh1);
                                cout << setw(5) << "|";
                                cout << endl;
                            }
                            temp = temp->next;
                        }
                        cout << "|";
                        for (int i = 0; i < 192; i++)
                            cout << "-";
                        cout << "|" << endl;
                        system("pause");
                    }
                    else
                    {
                        draw1(62, 15, 97, 25);
                        gotoXY(66, 17);
                        cout << "Khong co ten nganh nay!!" ;
                        gotoXY(63, 19);
                        system("pause");
                    }

                    system("COLOR 0A");
                    system("cls");
                    break;
                }
                case 8:
                {
                    gotoXY(65, 3);
                    cout << "TRUONG DAI HOC BACH KHOA - KHOA CONG NGHE THONG TIN";
                    gotoXY(80, 7);
                    cout << "DO AN CO SO LAP TRINH";
                    gotoXY(58, 10);
                    cout << "Ten de tai: QUAN LI DIEM THI CAC THI SINH DU THI VAO MOT TRUONG DAI HOC";
                    gotoXY(70,15);
                    cout << "Nguoi huong dan: THS. NGUYEN VAN NGUYEN";
                    gotoXY(70,16);
                    cout << "Sinh vien thuc hien: " ;
                    gotoXY(75,17);
                    cout << "Ho Thi Thu Thanh - 22T_DT1";
                    gotoXY(75,18);
                    cout << "Nguyen Thi Toan  - 22T_DT1";
                    gotoXY(85, 23);
                    SetColor1(8,7);
                    std::string text = "Thank you";
                    for (char c : text)
                    {
                        SetColor1(14,7);
                        std::cout << c;
                        std::flush(std::cout);
                        usleep(200000);
                    }
                    gotoXY(0,26);
                    SetColor1(8,3);
                    exit(0);
                    break;
                }
                }
                n_box(x, y, w, h, t_color, b_color, nd, n);
            }
        }
    }
}
int main()
{
    SetConsoleOutputCP(437);
    menu();
    
    return 0;
}
