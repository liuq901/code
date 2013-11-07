#include <cstdio>
#include <sstream>
using namespace std;
char buf[100000];
int main()
{
    while (gets(buf))
    {
        stringstream sin(buf);
        int n=0,sum=0;
        char ch;
        bool flag=true;
        while (sin>>ch)
        {
            n++;
            if (ch>='A' && ch<='D')
                sum+='E'-ch;
            else if (ch!='F')
            {
                flag=false;
                break;
            }
        }
        if (n==0)
            break;
        if (!flag)
            printf("Unknown letter grade in input\n");
        else
            printf("%.2f\n",double(sum)/n);
    }
    return(0);
}

