#include <iostream>

using namespace std;

void func(int arr[], int sum , int val , int index)
{
    if (sum==val)
    {
        cout<<"YES"<<endl;
        return ;
    }
    if (index==sizeof(arr) && sum!=val)
    {
        cout<<index<<sum<<endl;
        cout<<"NO"<<endl;
        return;

    }

    func(arr , sum+arr[index],val,index+1);
    func(arr , sum,val,index+1);
}

int main()
{
    cout << "Hello world!" << endl;
    int arr[5]={2,3,7,8,10};
    func(arr,0,199,0);
    return 0;
}
