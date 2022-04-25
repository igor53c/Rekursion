// Rekursion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void r1();
void down(int);
void down1(int);
void down2(int);

int summeIterativ(int);
int summeRekursiv(int);

unsigned long long fakultaetIterativ(int);
unsigned long long fakultaetRekursiv(int);

unsigned long long fibonacciIterativ(int);
unsigned long long fibonacciRekursiv(int);

int main()
{
    locale::global(locale("German_germany"));

    //r1();

    //down(10);

    down1(10); // 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,

    cout << endl;

    down2(10);  // 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,

    cout << endl;

    cout << "Summe: " << summeIterativ(100) << endl;
    cout << "Summe: " << summeRekursiv(100) << endl;

    cout << "Fakultät von 20 Iterativ: " << fakultaetIterativ(20) << endl;
    cout << "Fakultät von 20 Rekursiv: " << fakultaetRekursiv(20) << endl;

    cout << "Fibonacci von 20 Iterativ: " << fibonacciIterativ(20) << endl;
    cout << "Fibonacci von 20 Rekursiv: " << fibonacciRekursiv(20) << endl;

    return EXIT_SUCCESS;
}

void r1()
{
    cout << "r1()..." << endl;
    r1();
}

void down(int i)
{
    cout << i << endl;
    down(i - 1);
}

void down1(int i)
{
    if (i <= 0)
        return;

    cout << i << ", ";

    down1(i - 1);
}

void down2(int i)
{
    if (i <= 0)
        return;

    down2(i - 1);
    cout << i << ", ";
}

int summeIterativ(int max)
{
    int retValue = 0;

    while (max)
    {
        retValue += max;
        max--;
    }

    return retValue;
}

int summeRekursiv(int max)
{
    if (max > 0)
    {
        return summeRekursiv(max - 1) + max;
    }

    return 0;
}

unsigned long long fakultaetIterativ(int zahl)
{
    unsigned long long retValue = 0;

    if (zahl >= 0)
    {
        retValue = 1;

        for (int i = 2; i <= zahl; i++)
        {
            retValue *= i;

            cout << "   " << i << "!\t - " << retValue << endl;
        }
    }

    cout << endl;

    return retValue;
}

unsigned long long fakultaetRekursiv(int zahl)
{
    if (zahl < 0)
        return 0;

    if (zahl <= 1)
        return 1;
    else
        return zahl * fakultaetRekursiv(zahl - 1);
}

unsigned long long fibonacciIterativ(int n)
{
    unsigned long long retValue = 1;
    unsigned long long fib1 = 1, fib2 = 1;

    for (int i = 3; i <= n; i++)
    {
        retValue = fib1 + fib2;

        cout << retValue << endl;

        fib1 = fib2;
        fib2 = retValue;
    }

    return retValue;
}

unsigned long long fibonacciRekursiv(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacciRekursiv(n - 1) + fibonacciRekursiv(n - 2);
}

