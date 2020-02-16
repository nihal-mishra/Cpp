#include<cmath>
#include<iostream>
#include<climits>
using namespace std;

int Max_Subarray_Sum(int arr[],int n)	
{   
	if(n==1)
	{
		return arr[0];
	}
	int m = n/2;
	
	int left_MSS = Max_Subarray_Sum(arr,m);
	cout<<"Left MSS :: " <<left_MSS;
	int right_MSS = Max_Subarray_Sum(arr+m,n-m);
	cout<<"Left MSS :: "<<right_MSS;
	int leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
	for(int i=m;i < n; i++)
	{
		sum += arr[i];
		cout<<"\nsum(left) : "<<sum<<"\n";
		rightsum = max(rightsum,sum);
		cout<<"\nright sum : "<<rightsum<<"\n";
	}
	sum = 0;
	for(int i= (m-1);i >= 0; i--)
	{
		sum += arr[i];
		cout<<"\nsum(right) : "<<sum<<"\n";
		leftsum = max(leftsum,sum);
		cout<<"\nright sum : "<<rightsum<<"\n";
	}
	int ans = max(left_MSS,right_MSS);
	cout<<"\nans : "<<ans;
	cout<<"\nmax(ans,leftsum+rightsum) :: "<<max(ans,leftsum+rightsum);
	return max(ans,leftsum+rightsum);
}


int main(int argc, char const *argv[])
{
	int arr[] = {112,1,243,-125,234,-343,-10,100,234,-43};
	cout<<Max_Subarray_Sum(arr,10)<<"\n";
	return 0;
}