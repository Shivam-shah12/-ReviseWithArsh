class Solution{
public:
    vector<int> findTwoElement(vector<int> arr, int n) {
    // we need to find missing or repeating as well, so we used xor operation
      int xor1=0;
      int xor2=0;
      int result=0;
     // firstly do xor of 1toN and all array element
     // result = repeating ^ missing || missing ^ repeating
      for(int i=0;i<n;i++)
      {
          int ans=arr[i]^(i+1);
          result^=ans;
      }
      // now we try to know which is repeating or missing
      int c=0;
      while(result)
      {
          if(result&(1<<c))
          {
              break;
          }
          c++;
      }
      /*
      we see result , those bit are set in result, these are definetely
      form when-----------> (1^0) or (0^1)
      so we try to segregate our array , in which first part contain set bit 
      or second part contain unset bits
      */
      for(int i=0;i<n;i++)
      {
          int curr_num=i+1;
          if(curr_num&(1<<c))
          {
              xor1^=curr_num;
          }
          else
          {
             xor2^=curr_num;
          }
          if(arr[i]&(1<<c))
          {
              xor1^=arr[i];
          }
          else
          {
              xor2^=arr[i];
          }
      }
      
    //   cout<<xor1 <<" "<<xor2<<endl;
      // check the result
      for(int i=0;i<n;i++)
      {
          if(arr[i]==xor1)
          {
              return {xor1,xor2};
          }
          else if(arr[i]==xor2)
          {
              return {xor2,xor1};
          }
      }
        
    return {-1,-1};
    }
};