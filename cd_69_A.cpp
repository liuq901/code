#include <cstdio>
int main()
{
    int a,b,c;
    a=b=c=0;
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        a+=x,b+=y,c+=z;
    }
    printf("%s\n",a==0 && b==0 && c==0?"YES":"NO");
    return(0);
}

