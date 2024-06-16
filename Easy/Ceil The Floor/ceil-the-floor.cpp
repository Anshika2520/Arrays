//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

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
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr,arr+n);
    int s=0;
    int e=n-1;
    int f=-1;
    int c=-1;
    int mid=0;
    while(s<=e){
     mid=s+(e-s)/2;
        if(arr[mid]==x){
            return make_pair(arr[mid],arr[mid]);
        }
        else if(arr[mid]<x){
            f=arr[mid];
            s=mid+1;
        }
        else{
            c=arr[mid];
            e=mid-1;
        }
    }
    return make_pair(f,c);
}