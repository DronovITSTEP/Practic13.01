#include <iostream>

using namespace std;

/*
Написать функцию, которая принимает две даты
(т.е. функция принимает шесть параметров) и вычисляет
разность в днях между этими датами. Для решения этой
задачи необходимо также написать функцию, которая
определяет, является ли год високосным.
*/
bool IsLeapYear(int year){
    return (year % 4 == 0 ||( year % 100 == 0 && year % 400 == 0)) ?
        true : false;
}

int CountDay(int m, int y) {
    switch (m)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;
    case 2:
        return IsLeapYear(y) ? 29 :  28;
        break;
    default:
        break;
    }
}

int DaysOfMonth(int month, int year) {
    int sum = 0;
    for (int i = 1; i < month; i++) {
        sum += CountDay(i, year);       
    }
    return sum;
}

void DiffOfDays(int fDay, int sDay,
                int fMonth, int sMonth,
                int fYear, int sYear) {
    int fSum = 0, sSum = 0;

    for (int i = fYear; i < sYear; i++) {
        if (IsLeapYear(i)) sSum += 366;
        else sSum += 365;
    }

    fSum += IsLeapYear(fYear) ? DaysOfMonth(fMonth, fYear):
                                DaysOfMonth(fMonth, fYear);

    sSum += DaysOfMonth(sMonth, sYear);

    fSum += fDay;
    sSum += sDay;


    cout << sSum - fSum;
}


int main()
{
    DiffOfDays(5, 15, 2, 1, 2018, 2019);

}
