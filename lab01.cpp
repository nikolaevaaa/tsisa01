#include <iostream>
#include <cmath>

double func( double x)
{
    double f;
    f=cos(x)*tanh(x);
    return f;
}

int F(int f)
{
    if (f==1) return 1;
    if (f==2) return 1;
    if (f>2)
        return (F(f-1)+F(f-2));
}


int main()
{
    int N=1;
    double eps,a=7.00,b=11.00,resx,resy;
    std::cout<<"Fibonacci:"<<std::endl;
    N=13;
    double v,v1,m,m1,a1=7.00,b1=11.00,a2,b2;
    eps=0.1;
    int k=1;

    while (k<N)
    {
        std::cout << "ak: " << a1 << "   bk: " << b1;
        std::cout << "   l: " << b1 - a1 << "   f(ak): " << func(a1) << "   f(bk): " << func(b1) << std::endl;
        v=a1+(double)F(N-k-1)/F(N-k+1)*(b1-a1);
        m=a1+(double)F(N-k)/F(N-k+1)*(b1-a1);
        if (func(v)<func(m)) a1=v;
        else b1=m;
        k++;
    }
    resx=(a1+b1)/2;
    eps=(b1-a1)/2;

        std::cout<<"Min in point: "<<resx<<"   Error: "<<eps<<std::endl;

    std::cout<<"Passive search: "<<std::endl;
    eps=(double)((b-a)/(N+1));
    while (eps>=0.1)
    {
        double m=0.00;
        resy=func(a);
        for(int j=1;j<N+1;j++)
        {

            resx=(double)(j*(b-a)/(N+1)+a);
            if (func(resx)<=resy)
            {
                resy=func(resx);
                m=resx;
            }

        }
        std::cout<<"Amount of points N: "<<N<<"   ";
        std::cout<<"Min in point: "<<m<<" +- "<<eps<<std::endl;

        N++;
        eps=(double)((b-a)/(N+1));

    }


    return 0;
}
