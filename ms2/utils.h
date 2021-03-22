#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_

#include <iostream>////needed???????

namespace sdds {

    int getInt(const char* prompt = nullptr);   

    int getInt(
        int min,   
        int max,   
        const char* prompt = nullptr,  
        const char* errorMessage = nullptr, 
        bool showRangeAtError = true    
    );



}



#endif