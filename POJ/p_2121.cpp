#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;
map <string,int> S;
vector <int> a;
char buf[1000000];
int main()
{
    S["zero"]=0;
    S["one"]=1;
    S["two"]=2;
    S["three"]=3;
    S["four"]=4;
    S["five"]=5;
    S["six"]=6;
    S["seven"]=7;
    S["eight"]=8;
    S["nine"]=9;
    S["ten"]=10;
    S["eleven"]=11;
    S["twelve"]=12;
    S["thirteen"]=13;
    S["fourteen"]=14;
    S["fifteen"]=15;
    S["sixteen"]=16;
    S["seventeen"]=17;
    S["eighteen"]=18;
    S["nineteen"]=19;
    S["twenty"]=20;
    S["thirty"]=30;
    S["forty"]=40;
    S["fifty"]=50;
    S["sixty"]=60;
    S["seventy"]=70;
    S["eighty"]=80;
    S["ninety"]=90;
    S["hundred"]=100;
    S["thousand"]=1000;
    S["million"]=1000000;
    while (1)
    {
        gets(buf);
        stringstream sin(buf);
        string s;
        if (!(sin>>s))
            break;
        int flag;
        if (s=="negative")
            flag=-1;
        else
            flag=1;
        a.clear();
        if (flag==1)
            a.push_back(S[s]);
        while (sin>>s)
            a.push_back(S[s]);
        int ans=0,now=1;
        for (int i=a.size()-1;i>=0;i--)
            if (a[i]<100)
                ans+=a[i]*now;
            else if (a[i]==100)
                now*=100;
            else
                now=a[i];
        printf("%d\n",ans*flag);
    }
    return(0);
}

