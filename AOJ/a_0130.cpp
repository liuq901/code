#include <cstdio>
#include <deque>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        deque <char> a;
        char ch,dir[10];
        scanf(" %c",&ch);
        a.push_back(ch);
        int now=0;
        while (scanf("%[-<>]%c",&dir,&ch)==2)
        {
            if (dir[0]=='<')
                now--;
            else
                now++;
            if (now==a.size())
                a.push_back(ch);
            if (now==-1)
            {
                a.push_front(ch);
                now=0;
            }
        }
        for (int i=0;i<a.size();i++)
            printf("%c",a[i]);
        printf("\n");
    }
    return(0);
}

