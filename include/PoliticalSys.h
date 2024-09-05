//
// Created by noam on 1/12/23.
//

#ifndef CPP_WORK2_POLITICALSYS_H
#define CPP_WORK2_POLITICALSYS_H
#include "Politician.h"
#include "Party.h"

class PoliticalSys {
protected:
    // parties fields
    vector<Party*> party_list; // vector of all objects of Party type.
    // politicians fields
    vector<Politician*> politics; // vector of all politicians of Politician type
public:
    PoliticalSys(); // default constructor, initializes an empty system.
    PoliticalSys(const char* file);  // copy constructor
    ~PoliticalSys(); // destructor
    void add_party_with_params(string party_name, string R_or_D); // helper func that recived arguments for add party to system.
    void add_pol_with_params(string name, string last_name, int id, string R_or_D, string L_or_S, int power); // helper func that recived arguments for add politician to system.
    void add_pol_to_party(Politician* p, vector<Party*> party_list);  // helper func that adding politician to party by the rules.
    void addPolitician(); // Add politician to the system by getting the pointer.
    void addParty(); // add party to the system.
    void removePolitician(); // remove politician from the system.
    void removeParty();  // func that remove party from the system.
    void elections();  // func that elect chairman to every party and select the biggest party.
    void printPoliticians()const;  // func that prints all politician in the system with all their info.
    void printParties()const;  // func that prints all politician in the system with all their info.
    void BiggestParty()const;  // selects the biggest party.
};


#endif //CPP_WORK2_POLITICALSYS_H
