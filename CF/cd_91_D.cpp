#include <cstdio>
#include <vector>
using namespace std;
vector <vector <int> > two,three;
int sum,a[100010],pos[100010],ans[2][100010][8];
bool f[100010];
void work(vector <int> now)
{
    while (1)
    {
        if (now.size()==2)
        {
            two.push_back(now);
            return;
        }
        if (now.size()==3)
        {
            three.push_back(now);
            return;
        }
        if (now.size()<=5)
        {
            sum++;
            ans[0][sum][0]=now.size();
            for (int i=0;i<now.size();i++)
            {
                ans[0][sum][i+1]=pos[now[i]];
                ans[1][sum][i+1]=i==0?pos[now.back()]:pos[now[i-1]];
            }
            return;
        }
        int b[10];
        for (int i=1;i<=5;i++)
        {
            b[i]=now.back();
            now.pop_back();
        }
        sum++;
        ans[0][sum][0]=5;
        for (int i=5;i;i--)
        {
            ans[0][sum][6-i]=pos[b[i]];
            ans[1][sum][6-i]=i==5?pos[b[1]]:pos[b[i+1]];
        }
        pos[b[1]]=pos[b[5]];
        now.push_back(b[1]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pos[a[i]]=i;
    }
    for (int i=1;i<=n;i++)
        if (i!=a[i] && !f[i])
        {
            vector <int> tmp;
            for (int j=a[i];j!=i;j=a[j])
            {
                tmp.push_back(j);
                f[j]=true;
            }
            tmp.push_back(i);
            f[i]=true;
            if (tmp.size()==2)
                two.push_back(tmp);
            else if (tmp.size()==3)
                three.push_back(tmp);
            else
                work(tmp);
        }
    while (!two.empty() && !three.empty())
    {
        sum++;
        ans[0][sum][0]=5;
        for (int i=0;i<two.back().size();i++)
        {
            ans[0][sum][i+1]=pos[two.back()[i]];
            ans[1][sum][i+1]=i==0?pos[two.back().back()]:pos[two.back()[i-1]];
        }
        for (int i=0;i<three.back().size();i++)
        {
            ans[0][sum][i+3]=pos[three.back()[i]];
            ans[1][sum][i+3]=i==0?pos[three.back().back()]:pos[three.back()[i-1]];
        }
        two.pop_back();
        three.pop_back();
    }
    while (!three.empty())
    {
        if (three.size()>=3)
        {
            sum++;
            ans[0][sum][0]=5;
            for (int i=0;i<three.back().size();i++)
            {
                ans[0][sum][i+1]=pos[three.back()[i]];
                ans[1][sum][i+1]=i==0?pos[three.back().back()]:pos[three.back()[i-1]];
            }
            three.pop_back();
            for (int i=0;i<2;i++)
            {
                ans[0][sum][i+4]=pos[three.back()[i]];
                ans[1][sum][i+4]=i==0?pos[three.back()[1]]:pos[three.back()[0]];
            }
            sum++;
            ans[0][sum][0]=5;
            ans[0][sum][1]=pos[three.back()[0]];
            ans[0][sum][2]=pos[three.back()[2]];
            ans[1][sum][1]=pos[three.back()[2]];
            ans[1][sum][2]=pos[three.back()[0]];
            three.pop_back();
            for (int i=0;i<three.back().size();i++)
            {
                ans[0][sum][i+3]=pos[three.back()[i]];
                ans[1][sum][i+3]=i==0?pos[three.back().back()]:pos[three.back()[i-1]];
            }
            three.pop_back();
            continue;
        }
        sum++;
        ans[0][sum][0]=3;
        for (int i=0;i<three.back().size();i++)
        {
            ans[0][sum][i+1]=pos[three.back()[i]];
            ans[1][sum][i+1]=i==0?pos[three.back().back()]:pos[three.back()[i-1]];
        }
        three.pop_back();
    }
    while (!two.empty())
    {
        if (two.size()==1)
        {
            sum++;
            ans[0][sum][0]=2;
            for (int i=0;i<two.back().size();i++)
            {
                ans[0][sum][i+1]=pos[two.back()[i]];
                ans[1][sum][i+1]=i==0?pos[two.back().back()]:pos[two.back()[i-1]];
            }
            break;
        }
        sum++;
        ans[0][sum][0]=4;
        for (int i=0;i<two.back().size();i++)
        {
            ans[0][sum][i+1]=pos[two.back()[i]];
            ans[1][sum][i+1]=i==0?pos[two.back().back()]:pos[two.back()[i-1]];
        }
        two.pop_back();
        for (int i=0;i<two.back().size();i++)
        {
            ans[0][sum][i+3]=pos[two.back()[i]];
            ans[1][sum][i+3]=i==0?pos[two.back().back()]:pos[two.back()[i-1]];
        }
        two.pop_back();
    }
    printf("%d\n",sum);
    for (int i=1;i<=sum;i++)
    {
        printf("%d\n",ans[0][i][0]);
        for (int j=1;j<=ans[0][i][0];j++)
            printf("%d%c",ans[1][i][j],j==ans[0][i][0]?'\n':' ');
        for (int j=1;j<=ans[0][i][0];j++)
            printf("%d%c",ans[0][i][j],j==ans[0][i][0]?'\n':' ');
    }
    return(0);
}

