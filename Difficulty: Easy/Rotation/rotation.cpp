//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int s=0;
	    int e=n-1;
	    int ans=INT_MAX;
	    int i=-1;
	    while(s<=e){
	        int mid=s+(e-s)/2;
	        if(arr[s]<=arr[mid]){
	            if(arr[s]<ans){
	                ans=arr[s];
	                i=s;
	            }
	            s=mid+1;
	        }
	        else{
	            if(arr[mid]<ans){
	                ans=arr[mid];
	                i=mid;
	            }
	            e=mid-1;
	        }
	    }
	    return i;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends