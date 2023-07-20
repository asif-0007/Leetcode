//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int nums[],int n) {
        int cnt=0,ele;
        for(int i=0;i<n;i++){
            if(cnt==0){
                ele=nums[i];
            }
            if(ele==nums[i])cnt+=1;
            else cnt-=1;
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==ele)cnt++;
        }
        return (cnt>n/2) ? ele : -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends