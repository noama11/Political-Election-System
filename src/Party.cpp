//
// Created by noam on 1/9/23.
//

#include "string"
#include <vector>
#include <algorithm>

using namespace std;
#include "Party.h"
#include "Politician.h"

// create a functor for compare between two parties by them power.
class compare_primaries_class{
public:
    bool operator()(Politician* p1, Politician* p2)const{
        if (p1->get_primaries_power() == p2->get_primaries_power())
            return (p1->get_age() > p2->get_age());
        else {
            return (p1->get_primaries_power() < p2->get_primaries_power());
        }
    }

};

// return true if secces to add the politician.
bool Party::add(Politician *pol) {
    if(!pol)
        return false;
    pol_list.push_back(pol);
    return true;
}
//constructor
Party::Party(const string name) : pol_list(){
    party_name = name;
    chairman = "None";
}
// removing politicain from the vector.
bool Party::remove(Politician *pol) {
    if (!pol){
        return false;
    }
   vector<Politician*>::iterator it;
   it = std::find(pol_list.begin(), pol_list.end(), pol); // if we remove the chairman.
   if((*it)->get_name() == chairman){
       notify_chairman("None");
   }
   if(it != pol_list.end()){
       pol_list.erase(it);
       //delete pol;
       return true;
   }
    return false;
}

// calc the power of each politician in this party together and return it.
int Party::election_intensity()  {
    vector<Politician*>::iterator it;
    int power = 0;
    for(it = pol_list.begin(); it != pol_list.end(); ++it){
        power += (*(*it)).get_election_power();
    }
    return power;
}

// party destructor.
Party::~Party() {
    pol_list.clear();
}

//  run update function about the new chairman for each politician in the pol_list vector.
bool Party::notify_chairman(string pol) {
    if(pol_list.size() == 0)
        return false;
    vector<Politician*>::iterator it;
    for(it = pol_list.begin(); it != pol_list.end(); ++it){
        (*(*it)).update_chairman(pol);
    }
    return true;
}

// select the chairman of the party.
void Party::primaries()  {
   Politician* largest_power_pol;
   int max_power = 0;
   vector<Politician*>::iterator it;
   largest_power_pol = *std::max_element(pol_list.begin(), pol_list.end(), compare_primaries_class());
   if(largest_power_pol->get_power() == 0)
       return; // nobody fit
   notify_chairman(largest_power_pol->get_name());
   chairman = largest_power_pol->get_name();
}

// return the party name.
string Party::get_name() const {
    return party_name;
}
// return the party size.
int Party::get_party_size() const {
    return pol_list.size();
}
// copy constructor.
Party::Party(const Party &p) {

    party_name = p.party_name;
    chairman = p.chairman;
    pol_list = p.pol_list;
}

// implement operator "="
Party &Party::operator=(const Party &other) {
    this->party_name = other.party_name;
    this->chairman = other.chairman;
    this->pol_list = other.pol_list;
    return *this;
}

// return the pol vector.
vector<Politician *> Party::get_pol_list() const {
    return pol_list;
}

// return the chairman name.
string Party::get_chairman() const {
    return chairman;
}




