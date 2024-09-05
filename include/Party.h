//
// Created by noam on 1/9/23.
//

#ifndef CPP_WORK2_PARTY_H
#define CPP_WORK2_PARTY_H
#include "Politician.h"
#include "string"
#include <vector>
#include <iostream>
using namespace std;

// An abstract class of Party, this ckass are the observable of polticians. this class holds
// vector of polticians that belongs to this party.
class Party {
protected:
    string party_name; // party name field.
    string chairman;  // the chairman party.
    vector<Politician*> pol_list;  // vector of the politicians that in this party.
public:
    virtual bool is_fit(Politician* pol)const=0; // pure func that checks if this politician is fit to specific party.
//    virtual bool is_republic()const = 0; // pure func that checks if this politician is fit to republican party.
//    virtual bool is_democrat()const = 0; // pure func that checks if this politician is fit to democrat party.
    Party(string name); // constructor the recived the party name.
    Party(const Party& p); // copy constructor
    virtual ~Party(); // virtual destructor.
    bool add( Politician* pol);  // func that recived pointer to pol and join him to the vector.
    bool remove(Politician* pol); // func recieved pointer to pol and remove him from the vector.
    void primaries(); // in this func wi selects the leader with the biggest power,
    int election_intensity(); // func that calculate the party power.
    virtual void print_my_info()const = 0; // virtual function
    bool notify_chairman(string pol); // the party sent an apdate of the new chairman to all the politicians in the vactor.
    string get_name()const; // return the party name
    int get_party_size()const; // return the party size.
    Party& operator=(const Party& other); // implemnetion of "=" operator.
    vector<Politician*> get_pol_list()const;  // return vector of the pol_list.
    string get_chairman()const; // return the party chairman.


};



#endif //CPP_WORK2_PARTY_H

