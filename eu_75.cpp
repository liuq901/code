#include <cstdio>
#include <map>
using namespace std;
const int N=1500000;
map <int,int> M;
int main()
{
    for (int n=1;n*n<=N;n++)
        for (int m=n+1;m*m<=N;m++)
            for (int k=1;;k++)
            {
                int a=2*m*n*k,b=(m*m-n*n)*k,c=(m*m+n*n)*k,s=a+b+c;
                if (s>N)
                    break;
                if (!M.count(s))
                    M[s]=c;
                if (M[s]!=c)
                    M[s]=-1;
            }
    int ans=0;
    for (map <int,int>::iterator k=M.begin();k!=M.end();k++)
        ans+=k->second!=-1;
    printf("%d\n",ans);
    return(0);
}

