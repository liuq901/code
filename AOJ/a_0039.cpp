#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map <char,int> M;
char a[100000];
void init()
{
    M['I']=1;
    M['V']=5;
    M['X']=10;
    M['L']=50;
    M['C']=100;
    M['D']=500;
    M['M']=1000;
}
int main()
{
    init();
    while (scanf("%s",a)==1)
    {
        int len=strlen(a);
        int ans=0;
        for (int i=0;i<len;i++)
            ans+=i+1<len && M[a[i]]<M[a[i+1]]?-M[a[i]]:M[a[i]];
        printf("%d\n",ans);
    }
    return(0);
}

