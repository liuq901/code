#include <cstdio>
#include <cstring>
using namespace std;
char s[1000000];
int main()
{
    scanf("%s",s);
    int n=strlen(s),k;
    for (int i=0;i<n;i++)
        if (s[i]=='.')
        {
            k=i;
            break;
        }
    if (s[k-1]=='9')
        printf("GOTO Vasilisa.\n");
    else
    { 
        if (s[k+1]>='5')
            s[k-1]++;
        s[k]='\0';
        printf("%s\n",s);
    }
    return(0);
}

