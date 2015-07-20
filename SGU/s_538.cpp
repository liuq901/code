#include <cstdio>
#include <cstring>
#include <cctype>
char a[100010];
int main()
{
    gets(a);
    int n=strlen(a),ans=0;
    bool flag=false;
    for (int i=0;i<n;i++)
        if (a[i]=='(')
        {
            ans++;
            flag=true;
        }
        else if (a[i]==')')
        {
            ans++;
            if (flag)
            {
                ans-=2;
                flag=false;
            }
        }
        else if (!isalpha(a[i]) && a[i]!=' ')
            flag=false;
    printf("%d\n",ans);
    return(0);
}

