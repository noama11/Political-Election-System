//
// Created by noam on 1/11/23.
//

#ifndef CPP_WORK2_DEMOCRATIC_POLITICIAN_H
#define CPP_WORK2_DEMOCRATIC_POLITICIAN_H
#include "Politician.h"

class Democratic_Politician: public Politician{
public:
    virtual bool is_democrat() const{return true;} // this pol is democrat so return true .
    virtual bool is_republic() const{return false;} // this pol is democrat so return false.
    Democratic_Politician(string _name, string _last_name, int _id); // constructor of this class
    virtual ~Democratic_Politician() {}; // destructor of this class.

};


#endif //CPP_WORK2_DEMOCRATIC_POLITICIAN_H
