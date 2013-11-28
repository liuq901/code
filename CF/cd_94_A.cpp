#include <cstdio>
#include <string>
using namespace std;
char buf[100];
string s,a[20];
int main()
{
    gets(buf);
    s=buf;
    for (int i=0;i<10;i++)
    {
        gets(buf);
        a[i]=buf;
    }
    for (int i=0;i<8;i++)
        for (int j=0;j<10;j++)
            if (s.substr(i*10,10)==a[j])
            {
                printf("%d",j);
                break;
            }
    printf("\n");
    return(0);
}

