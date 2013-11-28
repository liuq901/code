/*
Java:
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static void main(String[] args) throws Exception
    {
        new Main().run();
    }
    void run()
    {
        Scanner in=new Scanner(System.in);
        while (in.hasNextBigInteger())
        {
            BigInteger a;
            a=in.nextBigInteger();
            pair c=decode(a);
            int n=c.a.intValue();
            a=c.b;
            pair p[]=new pair[n+1];
            for (int i=1;i<n;i++)
            {
                c=decode(a);
                p[i]=decode(c.a);
                a=c.b;
            }
            p[n]=decode(a);
            p[0]=p[n];
            BigInteger area;
            area=BigInteger.ZERO;
            for (int i=1;i<=n;i++)
                area=area.add(det(p[i],p[i-1]));
            area=area.abs();
            int tmp;
            if (area.testBit(0))
                tmp=5;
            else
                tmp=0;
            System.out.println(area.divide(BigInteger.valueOf(2))+"."+tmp);
        }
    }
    BigInteger det(pair a,pair b)
    {
        return(a.a.multiply(b.b).subtract(a.b.multiply(b.a)));
    }
    class pair
    {
        BigInteger a,b;
    }
    pair decode(BigInteger x)
    {
        pair ret=new pair();
        BigInteger l=BigInteger.ZERO,r=x,i,j;
        while (true)
        {
            BigInteger mid=l.add(r).divide(BigInteger.valueOf(2));
            BigInteger now=x.subtract(mid.multiply(mid.add(BigInteger.ONE)).divide(BigInteger.valueOf(2)));
            if (now.compareTo(BigInteger.ZERO)<0)
                r=mid.subtract(BigInteger.ONE);
            else if (now.compareTo(mid)>0)
                l=mid.add(BigInteger.ONE);
            else
            {
                j=now;
                i=mid.subtract(now);
                break;
            }
        }
        ret.a=i;
        ret.b=j;
        return(ret);
    }
}
*/
int main(){}

