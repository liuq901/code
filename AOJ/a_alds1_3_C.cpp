#include <cstdio>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
int a[11];
int main()
{
    list <int> a;
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[20];
        scanf("%s",op);
        int len=strlen(op);
        if (op[0]=='i')
        {
            int x;
            scanf("%d",&x);
            a.push_front(x);
        }
        else if (len==6)
        {
            int x;
            scanf("%d",&x);
            list <int>::iterator k=find(a.begin(),a.end(),x);
            if (k!=a.end())
                a.erase(k);
        }
        else if (len==11)
            a.pop_front();
        else
            a.pop_back();
    }
    for (list <int>::iterator k=a.begin();k!=a.end();k++)
    {
        if (k!=a.begin())
            printf(" ");
        printf("%d",*k);
    }
    printf("\n");
    return(0);
}

