/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][1] C
#       @file         :C.cpp
#       @date         :2014/07/10 19:44
#       @algorithm    :luan gao
******************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

struct time{
    int hh,mm;
    time(){hh = 0; mm = 0;}
    time(int _h,int _m){hh = _h; mm = _m;}
    friend ostream& operator<<(ostream& os, const time& t){
        os << setw(2) << setfill('0') << t.hh;
        os << ":";
        os << setw(2) << setfill('0') << t.mm;
        return os;
    }
    friend istream& operator>>(istream& is, time& t){
        char ch;
        is >> t.hh >> ch >> t.mm;
        return is;
    }
    friend bool operator<(const time& a, const time& b){
        if (a.hh > b.hh) return 0;
        else if (a.hh < b.hh) return 1;
        else if (a.hh == b.hh) return a.mm < b.mm;
    }
    friend time operator-(const time& a, const time& b){
        time ta, tb;
        if (a < b) ta.hh = a.hh + 24, ta.mm = a.mm, tb = b;
        else ta = a, tb = b;
        int sa = ta.hh * 60 + ta.mm;
        int sb = tb.hh * 60 + tb.mm;
        int h = (sa - sb) / 60;
        int m = (sa - sb) % 60;
        time ans(h, m);
        return ans;
    }
};

time t1, t2;

int main(){
    while (cin >> t1 >> t2)
        cout << t1 - t2 << endl;
    return 0;
}
