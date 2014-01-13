#include <cstdio>
#include <string>
#include <set>
using namespace std;
int main()
{
    set <string> S;
    int Q;
    scanf("%d",&Q);
    while (Q--)
    {
        char op[10],buf[20];
        scanf("%s%s",op,buf);
        if (op[0]=='i')
            S.insert(buf);
        else
            printf("%s\n",S.count(buf)?"yes":"no");
    }
    return(0);
}

