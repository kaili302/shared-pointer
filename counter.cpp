#include "counter.h"

namespace kli
{

Counter::Counter()
    : d_count{0}
    {} 
    
int Counter::increase()
{
    return ++d_count;
}
    
int Counter::decrease()
{
    return --d_count;
}

};
