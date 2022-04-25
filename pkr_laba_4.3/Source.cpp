#include<iostream>
#include<locale>
#include<string>
#include<iomanip>
#include<fstream>
#include <sstream>
#include <Windows.h> 
#define TESTING

using namespace std;

#pragma pack(push, 1)

struct Price
{
    string name;
    string shop;
    double price;
};

#pragma pack(pop)

void Create(char* filename, Price* p, int N);
void ADD(char* filename, Price* p, int N);
void Print(char* filename);
void Find(char* filename, char* shop);

#ifdef TESTING
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char filename[100];
    char shop[30];
    Price* p;
    int N;
    int MenuItem;

    cout << "������ ����� �����: "; cin >> filename;

    do{
        cout << endl << endl << endl;
        cout << " ������� ��: " << endl;
        cout << " [1] - ��� ����� � ���������" << endl;
        cout << " [2] - ���� �����" << endl;
        cout << " [3] - ��������� �����" << endl;
        cout << " [4] - ���� ���������� ��� ������, �� ���������� � ������� " << endl;
        cout << " [0] - ���� ������ ���� ������" << endl;
        cout << "������ ��������: "; cin >> MenuItem;
        cout << endl << endl;

        switch (MenuItem)
        {
        case 1:
            cout << "������ ������� ������: "; cin >> N;
            p = new Price[N];
            Create(filename, p, N);
            delete[] p;
            break;
        case 2:
            Print(filename);
            break;
        case 3:
            cout << "������ ������� ������: "; cin >> N;
            p = new Price[N];
            ADD(filename, p, N);
            delete[] p;
            break;
        case 4:
            cout << "������ ����� ��������: "; cin >> shop;
            Find(filename, shop);
            break;
        case 0:
            break;
        default:
            cout << "�� ����� ������ ��������! "
                    "������� ����� � ����. " << endl;
        }
    } while (MenuItem != 0);

    return 0;
}
#endif

void Create(char* filename, Price * p, int N)
{
    ofstream f(filename);
    f << "==============================================================" << endl
        <<  "|  #  |    ����� ������   |    ������� |  ������� ������ |" << endl
        << "------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Price  " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " ����� ������: "; getline(cin, p[i].name);
        cout << " ����� ��������: "; getline(cin, p[i].shop);
        cout << " ������� ������ � ���: "; cin >> p[i].price;

        f << "| " << setw(3) << right << i + 1 << " ";
        f << "| " << setw(13) << left << p[i].name
            << "| " << setw(12) << right << p[i].shop
            << "| " << setw(5) << left << p[i].price << " |" << endl;
        
    }
    f << "=============================================================" << endl;

}

void ADD(char* filename, Price* p, int N)
{
    ofstream f(filename, ios::app);
    f << "=============================================================" << endl
        << "|  #  |    ����� ������   |    ������� |  ������� ������ |" << endl
        << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Price  " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " ����� ������: "; getline(cin, p[i].name);
        cout << " ����� ��������: "; getline(cin, p[i].shop);
        cout << " ������� ������ � ���: "; cin >> p[i].price;
        f << "| " << setw(3) << right << i + 1 << " ";
        f << "| " << setw(13) << left << p[i].name
            << "| " << setw(12) << right << p[i].shop
            << "| " << setw(5) << left << p[i].price << " |" << endl;
       
    }
    f << "=============================================================" << endl;
}

void Print(char* filename)
{
    ifstream fin(filename);
    string s;

    while (getline(fin, s))
    {
        cout << s << endl;
    }
}

void Find(char* filename, char* shop)
{
    ifstream fin(filename);
    string s;
    bool have = 0;
    cout << "==========================================================" << endl;
    cout << "|  #  |    ����� ������   |    ������� |  ������� ������ |" << endl;
    cout << "----------------------------------------------------------" << endl;

    while (getline(fin, s))
    {
        if (s.find(shop, 0) != -1 && s[s.find(shop, 0) - 1] == ' ' && (s.find('|', s.find(shop, 0) - 1) - s.find(shop, 0) == strlen(shop)))
        {
            cout << s << endl;
            have = 1;
        }
    }
    if (have == 0) 
        cout << " ������ �������� �� �������� " << endl;
    cout << "============================================================" << endl;
}
