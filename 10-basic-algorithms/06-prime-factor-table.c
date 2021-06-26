int prime[5000],k=0;
void buildprime(int maxn)
{int i,j,square1,square2,a[45826]={0};
 square1=sqrt(maxn);
 square2=sqrt(square1)+1;
 for(i=2;i<=square2;i++)
    if(!a[i])
       for(j=i*i;j<=square1;j=j+i)
          a[j]=1;
 for(i=2;i<=square1;i++)
    {if(!a[i])
       prime[++k]=i;
    }
}
