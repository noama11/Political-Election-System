//
// Created by noam on 1/12/23.
//

#include "Republican_Party.h"

// constructor that receved the party name.

Republican_Party::Republican_Party(string name) : Party(name) {
    this->party_name = name;
}

// fincton prints this party info.
void Republican_Party::print_my_info() const{
    cout << "Republican Party: " << party_name << ", chairman:" << chairman << ", Size:" << pol_list.size() << endl;
    vector<Politician*>::const_iterator it;
    for (it = pol_list.begin(); it != pol_list.end(); ++it){
        cout << "\t";
        (*(*it)).print_my_info();
        cout << "\n";
    }
}


