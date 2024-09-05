//
// Created by noam on 1/11/23.
//

#ifndef CPP_WORK2_REPUBLICAN_POLITICIAN_H
#define CPP_WORK2_REPUBLICAN_POLITICIAN_H
#include "Politician.h"


class Republican_politician : public Politician{
public:
    virtual bool is_democrat() const{return false;} // virtual func checks if democrat.
    virtual bool is_republic() const{return true;} // virtual func checks if republic.
    Republican_politician(string _name, string _last_name, int _id);
    virtual ~Republican_politician() {}; // destructor.

};


#endif //CPP_WORK2_REPUBLICAN_POLITICIAN_H
