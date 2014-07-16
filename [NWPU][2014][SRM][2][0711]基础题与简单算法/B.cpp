/*****************************************************************************
#       COPYRIGHT NOTICE
#       Copyright (c) 2014 All rights reserved
#       ----Stay Hungry Stay Foolish----
#
#       @author       :Shen
#       @name         :[NWPU][SRM][2] B
#       @file         :G:\My Source Code\【ACM】训练\0711 - [NWPU][SRM][2]\B.cpp
#       @date         :2014-07-11 19:23
#       @algorithm    :Hash
******************************************************************************/

#include <cstdio>
#include <algorithm>
using namespace std;

char s[31];

int Hash(){
    int sum=0;
    for (int i = 0, k = 0; k < 7; ++i){
        if(s[i] >= '0' && s[i] <= '9'){
            sum *= 10;
            ++k;
            sum += (s[i] - '0');
        }
        else if(s[i] >= 'A' && s[i] < 'Z'){
            sum *= 10;
            ++k;
            sum += ((s[i] - 'A' - ( s[i] > 'Q' )) / 3 + 2);
        }
    }
    return sum;
}

void solve(){
    int n;
    scanf("%d",&n);
    int data[n];getchar();
    for(int tmp = 0; tmp < n; ++tmp){
        gets(s);
        data[tmp] = Hash();
    }
    sort(data, data + n);
    bool p = 0;
    n--;
    for (int i = 0,num = 1; i < n; i += num = 1){
        while (data[i] == data[i+1]){
            num++;
            i++;
        }
        if (num>1){
            printf("%03d-%04d %d\n", data[i] / 10000, data[i] % 10000, num);
            p = 1;
        }
    }
    if (!p) printf("No duplicates.\n");
    printf("\n");
}

int main(){
    solve();
    return 0;
}
