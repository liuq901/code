#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll get(char *s)
{
    int n=strlen(s);
    ll ret=0;
    for (int i=0;i<n;i++)
        ret=ret*10+s[i]-'0';
    return(ret);
}
char s1[1000],s2[1000];
int main()
{
    scanf("%s%s",s1,s2);
    reverse(s2,s2+strlen(s2));
    printf("%I64d\n",get(s1)+get(s2));
    return(0);
}

