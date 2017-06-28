#include<iostream>
using namespace std;
int main()
{
    int a[7]={10,20,25,30,40,50,63};
    int lb=0,ub=6;
    int n,mid;
    cout<<"Enter the number to search: ";
    cin>>n;
    while(lb<=ub)
    {
        mid=(lb+ub)/2;
        //cout<<mid;
        if(a[mid]>n)
        {
            ub=mid-1;
        }else if(a[mid]==n)
        {
            cout<<"number found at: "<<mid;
            break;
        }else{
            lb=mid+1;
        }
    }
    return 0;
}
