//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
int firstOcc(int arr[],int n,int x){
    int s=0;
    int e=n-1;
    int first=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            first=mid;
            e=mid-1;
        }
        else if(arr[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return first;
}

int lastOcc(int arr[],int n,int x){
    int s=0;
    int e=n-1;
    int last=-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==x){
            last=mid;
            s=mid+1;
        }
        else if(arr[mid]<x){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return last;
}
	int count(int arr[], int n, int x) {
	    int firstI=firstOcc(arr,n,x);
	    int lastI=lastOcc(arr,n,x);
	    if(firstI==-1){
	        return 0;
	    }
	    return {lastI-firstI+1};
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends