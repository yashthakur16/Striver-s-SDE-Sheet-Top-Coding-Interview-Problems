#include <bits/stdc++.h> 

long long cnt=0;
void merge(long long *arr,int s, int e)
{
    int mid=s+((e-s)/2);

    int length1=mid-s+1;
    int length2=e-mid;

    int *arr1=new int[length1];
    int *arr2=new int[length2];

    int k=s;

    for(int i=0;i<length1;i++)
    {
        arr1[i]=arr[k++];
    }



    for(int i=0;i<length2;i++)
    {
        arr2[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    k=s;

    while(index1<length1&&index2<length2)
    {
        if(arr1[index1]<arr2[index2])
        {
            arr[k++]=arr1[index1++];
        }
        else
        {
            cnt=cnt+length1-index1;
            arr[k++]=arr2[index2++];
        }
    }

    while(index1<length1)
    {
        arr[k++]=arr1[index1++];
    }

    while(index2<length2)
    {
        arr[k++]=arr2[index2++];
    }

    delete arr1;
    delete arr2;

    return;

    

}



void solve(long long *arr,int s, int e)
{
    if(s>=e)
    {
        return;
    }

    int mid=s+((e-s)/2);

    solve(arr,s,mid);

    solve(arr,mid+1,e);

    merge(arr,s,e);
}





long long getInversions(long long *arr, int n)
{
    solve(arr,0,n-1);
   return cnt;
}
