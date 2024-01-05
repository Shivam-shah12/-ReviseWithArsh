class DataStream {
public:
    int count;
    queue<int>dq;
    int value;
    int sz;
    DataStream(int value, int k) {
        this->value=value;
        count=0;
        this->sz=k;
    }
    
    bool consec(int num) {
        dq.push(num);
        if(num==value)
        count++;
        if(dq.size()<sz)
        return false;
        else
        {
          while(!dq.empty() && dq.size()>sz)
          {
              if(dq.front()==value)
              {
                  count--;
              }
              dq.pop();
          }
        }
        if(dq.size()==sz && count==sz)
        return true;
        return false;
        
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
