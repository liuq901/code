#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char a[100000],b[100000];
int main()
{
    scanf("%s%s",a,b);
    int n=strlen(a),m=strlen(b);
    reverse(a,a+n);
    reverse(b,b+m);
    n--,m--;
    while (n>=0 && m>=0)
    {
        if (a[n]!=b[m])
        {
            n--,m--;
            continue;
        }
        n++,m--;
        a[n]='A'+'B'-a[n-1];
    }
    printf("%s\n",n==-1 && m==-1?"YES":"NO");
    return(0);
}

