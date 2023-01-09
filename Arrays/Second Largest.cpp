class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    // code here
	    sort(arr, arr+n);
	    vector<int>s;
	    s.push_back(arr[0]);
	    for(int i=1;i<n;i++){
	       if(arr[i]!=arr[i-1]){
	           s.push_back(arr[i]);
	       }
	    }
	    if(s.size()==1)return -1;
	    return s[s.size()-2];
	}
};
