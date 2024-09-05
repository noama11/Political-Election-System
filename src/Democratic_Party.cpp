//
// Created by noam on 1/10/23.
//

#include "Democratic_Party.h"


// constructor that receved the party name.
Democratic_Party::Democratic_Party(string name1) : Party(name1) {
   this->party_name = name1;
   this->chairman = "None";
}
// implement of the pure vitrual func of the father class.
void Democratic_Party::print_my_info() const{
    cout << "Democrat Party: " << party_name << ", chairman:" << chairman << ", Size:" << pol_list.size() << endl;
    vector<Politician*>::const_iterator it;
    for (it = pol_list.begin(); it != pol_list.end(); ++it){
        cout << "\t";
        (*(*it)).print_my_info();
        cout << "\n";
    }
}
// copy constructor.
Democratic_Party::Democratic_Party(const Democratic_Party &p): Party(p.party_name) {
    this->party_name = p.party_name;
    this->chairman = p.chairman;
    this->pol_list = p.pol_list;

}
