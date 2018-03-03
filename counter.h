#pragma once

namespace kli
{
class Counter
{
  private: 
    int d_count;
  
  public:
    Counter();
        // constructor
        
    int increase();
        // increase counter by 1 and return final count 
        
    int decrease();
        // decrease counter by 1 and return final count 
};
    
}
