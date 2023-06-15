/*Алгоритм Дейкстры
построения очередной перестановки
Дано: Р = (P1, P2, …, Pn) – некоторая перестановка
натуральных чисел от 1 до n.
Получить: следующую перестановку в P*/

#include <iostream>
#include <ctime>
using namespace std;

int* transposition(int n, int x[])
{
    for (int i = n - 2; i >= 0; i--)
    {
        if (x[i] < x[i + 1])
            for (int j = n - 1; j > i; j--)
            {
                if (x[i] < x[j])
                {
                    swap(x[i], x[j]);
                    for (int k = i + 1, l = n - 1; k < l; k++, l--) //invertir hvost
                    {
                        swap(x[k], x[l]);
                    }
                    return x;
                }
            }
    }
}

void print(int n, int x[]) //вывод массива
{
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "zadat kolvo element" << endl;
    cin >> n;
    int* x = new int[n];
    srand(time(0));
    for (int i = 0; i < n; i++) //инициализация массива
    {
        x[i] = -1 + rand() % 100;
    }
    /*x[0] = 3;
    x[1] = 5;
    x[2] = 4;
    x[3] = 2;
    x[4] = 1;*/
    print(n, x);
    for (int i = 0; i < 45; i++) //проверить что массив отсортирован по убыванию, если да, то выходить из цикла
    {
      transposition(n, x);
      print(n, x);
    }
}

