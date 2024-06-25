//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    int s=1;
	    int e=m;
	    while(s<=e){
	        int mid=s+(e-s)/2;
	        long long ans=1;
	        for(int i=0;i<n;i++){
	            ans=ans*mid;
	            if(ans>m) break;
	            
	        }
	        if(ans>m){
	            e=mid-1;
	        }
	        else if(ans<m){
	            s=mid+1;
	        }
	        else{
	            return mid;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends