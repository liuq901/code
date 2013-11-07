#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
using namespace std;
char op[100],s[100];
int next(int mem)
{
    scanf("%s",s);
    string S=s;
    if (S=="restore")
        return(mem);
    else
    {
        for (int i=0;i<S.size();i++)
            if (!isdigit(S[i]))
                throw("error");
        int n;
        sscanf(s,"%d",&n);
        return(n);
    }
}
void print(int x)
{
    if (x<0)
        printf("-");
    x=abs(x);
    scanf("%s",s);
    string S=s;
    if (S=="-b")
    {
        int a[100];
        a[0]=0;
        while (x)
        {
            a[++a[0]]=x&1;
            x>>=1;
        }
        for (int i=a[0];i;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    else if (S=="-o")
        printf("%o\n",x);
    else if (S=="-d")
        printf("%d\n",x);
    else if (S=="-x")
        printf("%x\n",x);
}
int main()
{
    while (1)
    {
        int n;
        scanf("%d",&n);
        if (!n)
            break;
        int now=0,mem=0;
        static int id=0;
        if (id)
            printf("\n");
        printf("Case %d:\n",++id);
        for (int i=1;i<=n;i++)
        {
            scanf("%s",op);
            string s=op;
            try
            {
                if (s=="+")
                    now+=next(mem);
                else if (s=="-")
                    now-=next(mem);
                else if (s=="*")
                    now*=next(mem);
                else if (s=="/")
                    now/=next(mem);
                else if (s=="%")
                    now%=next(mem);
                else if (s=="memory")
                    mem=now;
                else if (s=="print")
                    print(now);
            }
            catch(...){}
        }
    }
    return(0);
}

