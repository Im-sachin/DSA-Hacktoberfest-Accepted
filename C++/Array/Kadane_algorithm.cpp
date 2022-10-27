lass Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        int csum = arr[0];
        int osum = arr[0];
        for(int i=1; i<n; i++){
            if(csum >= 0){
                csum += arr[i];
            }else{
                csum = arr[i];
            }
            if(csum > osum){
                osum = csum;
            }
        }
        return osum;
        
    }
};
