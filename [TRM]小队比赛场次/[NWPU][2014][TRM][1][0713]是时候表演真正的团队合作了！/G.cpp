/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][2014][TRM][1] G
#       @file         :G.cpp
#       @date         :2014/07/13 20:00
#       @algorithm    :Simulation
******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

inline int isLeapyear(int yy) { return yy % (yy % 100? 4: 400)? 0: 1; }

int day[2][12]={{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
				{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int calday(int yy, int mm, int dd)
{
    int sum=0;
    for (int i = 1900; i < yy; i++)
        if (isLeapyear(i))  sum += 366;
        else                sum += 365;
    int p = isLeapyear(yy);
    for (int i = 1; i < mm; i++)
        sum += day[p][i - 1];
    sum += dd;
    return sum;
}

int days(string a)
{
    int yy = (a[0] - '0') * 1000 + (a[1] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0');
    int mm = (a[5] - '0') * 10 + (a[6] - '0');
    int dd = (a[8] - '0') * 10 + (a[9] - '0');
    return calday(yy, mm, dd);
}

int main(){
    string a, b;
    while (cin >> a >> b)
        cout << abs(days(a) - days(b)) << endl;
    return 0;
}
