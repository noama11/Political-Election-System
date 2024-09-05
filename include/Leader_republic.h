//
// Created by noam on 1/12/23.
//

#ifndef CPP_WORK2_LEADER_REPUBLIC_H
#define CPP_WORK2_LEADER_REPUBLIC_H
#include "Republican_politician.h"

class Leader_republic : public Republican_politician{
public:
    Leader_republic(string _name, string _last_name, int _id); //constructor.
    ~Leader_republic() {}; // destructor.
    virtual void print_my_info() const; // function prints this class info
    virtual int get_primaries_power()const; // return thr primeries power
    virtual int get_election_power()const; // return the election power.


};


#endif //CPP_WORK2_LEADER_REPUBLIC_H
