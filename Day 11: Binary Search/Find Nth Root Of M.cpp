int func(int mid,int n,int m)
{
  long long ans=1;

  for(int i=1;i<=n;i++)
  {
    ans=ans*mid;

    if(ans>m)
    {
      return 2;
    }
  }

  if(ans==m) return 0;

  return 1;
}



int NthRoot(int n, int m) 
{
  int low=1;
  int high=m;
  int mid=low+((high-low)/2);

  while(low<=high)
  {
    int num=func(mid,n,m);
    if(num==0)
    {
      return mid;
    }
    else if(num==1)
    {
      low=mid+1;
    }
    else
    {
      high=mid-1;
    }
    mid=low+((high-low)/2);

  }
  return -1;
  
}
