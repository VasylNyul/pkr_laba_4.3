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

    cout << "Введіть назву файлу: "; cin >> filename;

    do{
        cout << endl << endl << endl;
        cout << " Виберіть дію: " << endl;
        cout << " [1] - ввід даних з клавіатури" << endl;
        cout << " [2] - вивід даних" << endl;
        cout << " [3] - додавання даних" << endl;
        cout << " [4] - вивід інформації про товари, що продаються в магазині " << endl;
        cout << " [0] - меню закінчує свою роботу" << endl;
        cout << "Введіть значення: "; cin >> MenuItem;
        cout << endl << endl;

        switch (MenuItem)
        {
        case 1:
            cout << "Введіть кількість товарів: "; cin >> N;
            p = new Price[N];
            Create(filename, p, N);
            delete[] p;
            break;
        case 2:
            Print(filename);
            break;
        case 3:
            cout << "Введіть кількість товарів: "; cin >> N;
            p = new Price[N];
            ADD(filename, p, N);
            delete[] p;
            break;
        case 4:
            cout << "Введіть назву магазину: "; cin >> shop;
            Find(filename, shop);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели невірне значення! "
                    "Виберіть пункт з меню. " << endl;
        }
    } while (MenuItem != 0);

    return 0;
}
#endif

void Create(char* filename, Price * p, int N)
{
    ofstream f(filename);
    f << "==============================================================" << endl
        <<  "|  #  |    Назва товару   |    магазин |  Вартість товару |" << endl
        << "------------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Price  " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " Назва товару: "; getline(cin, p[i].name);
        cout << " Назва магазину: "; getline(cin, p[i].shop);
        cout << " Вартість товару в грн: "; cin >> p[i].price;

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
        << "|  #  |    Назва товару   |    магазин |  Вартість товару |" << endl
        << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "Price  " << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " Назва товару: "; getline(cin, p[i].name);
        cout << " Назва магазину: "; getline(cin, p[i].shop);
        cout << " Вартість товару в грн: "; cin >> p[i].price;
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
    cout << "|  #  |    Назва товару   |    магазин |  Вартість товару |" << endl;
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
        cout << " Такого магазину не знайдено " << endl;
    cout << "============================================================" << endl;
}
