//
// Created by noam on 1/12/23.
//

#include "PoliticalSys.h"
#include "algorithm"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Leader_Democretic.h"
#include "social_denocrat.h"
#include "Leader_republic.h"
#include "social_republic.h"
#include "Republican_Party.h"
#include "Democratic_Party.h"
#include "Exception.h"


PoliticalSys::PoliticalSys() : party_list(), politics(){}

// functor for find the right politician by string name.
class find_pol{
public:
    find_pol(const int id): id_(id){}
    bool operator()(Politician* p)const{
        return id_ == p->get_id();
    }
private:
    int id_;
};



// functor for find the right party by string name.
class find_party_by_name{
public:
    find_party_by_name(const std::string& name): name(name){}
    bool operator()(Party* p)const{
        return name == p->get_name();
    }
    const string &name;
};

// helper function for taking the biggest party.
class compare_size_class{
public:
    bool operator()(Party* p1, Party* p2)const{
        if(p1->get_party_size() == p2->get_party_size()){
           return (p1->get_name() < p2->get_name());
        }
        else {
            return (p1->get_party_size() < p2->get_party_size());
        }
    }

};



void PoliticalSys::add_pol_with_params(string name, string last_name, int ID, string republic_or_democrar, string leader_or_social, int power) {
    Politician* new_pol;
    // check wich party to go.
    vector<Party*>::iterator it;
    vector<Party*>::iterator it1;
    string party_name;
    vector<Party*> temp;
    int power_check = 0;
    if(republic_or_democrar == "D") {
        if(leader_or_social == "L")
            new_pol = new Leader_Democretic(name, last_name, ID) ;// create new leader democrat.
        else {
            new_pol = new social_democrat(name, last_name, ID);//create new social democrat
        }
        politics.push_back(new_pol);
//        democrat_politics.push_back(new_pol);
    }
    else{
        if(leader_or_social == "L")
            new_pol = new Leader_republic(name, last_name, ID) ;// create new leader democrat.
        else {
            new_pol = new social_republic(name, last_name, ID);//create new social democrat
        }
        politics.push_back(new_pol);
//        republic_politics.push_back(new_pol);
    }
    new_pol->set_power(power);
//    Party * cur_party;
    // find the right party and then if have no party so go there, if i have and the new party smaller so go there.
    add_pol_to_party(new_pol, party_list);
}


void PoliticalSys::add_pol_to_party(Politician *new_pol, vector<Party *> party_list) {
    if(!new_pol)
        return;
    Party * cur_party;
    vector<Party*>::iterator it;
    // find the right party and then if have no party so go there, if i have and the new party smaller so go there.
    for (it = party_list.begin(); it != party_list.end(); ++it) {
        if(!(*it)->is_fit(new_pol)){ // if the pol is not suit to this party continue.
            continue;
        }
        if(new_pol->get_party() == "None") {
            (*it)->add(new_pol);
            new_pol->set_party((*it)->get_name());
            cur_party = *it; // keep the party that the pol join in.
            continue;
        }
        if((*it)->get_party_size() < cur_party->get_party_size()) {
            string cur_name = new_pol->get_party();
            (cur_party)->remove(new_pol);
            new_pol->set_party((*it)->get_name());
            (*it)->add(new_pol);
            cur_party = *it; // keep the party that the pol join in.
        }
    }
}


void PoliticalSys::addPolitician() {
    int flag = 0;
    Politician *new_pol;
    string name;
    string last_name;
    int ID;
    string republic_or_democrar; // just - R/D
    string leader_or_social; // just - R/L
    int power;
    cout << "---Create Politician---" << endl;
    while (true) {
        try {
            cout << "First name:\n";
            cin >> name;
            cout << "Last name:\n";
            cin >> last_name;
            cout << "ID:\n";
            cin >> ID;
            if (ID < 0) {
                throw ID_NOT_VALID();
            }
            vector<Politician *>::iterator it_pol;
            if (politics.size() != 0) {
                for (it_pol = politics.begin(); it_pol != politics.end(); ++it_pol) {
                    if ((*it_pol)->get_id() == ID) {
                        throw ID_NOT_VALID();
                    }
                }
            }
            cout << "Power:\n";
            cin >> power;
            if (power < 0) {
                throw invalid_details();
            }
            cout << "Republican or Democratic person\n";
            cin >> republic_or_democrar;
            if (republic_or_democrar != "D" && republic_or_democrar != "R") {
                throw invalid_details();
            }
            cout << "Leader or Social\n";
            cin >> leader_or_social;
            if (leader_or_social != "L" && leader_or_social != "S") {
                throw invalid_details();
            }
            break;
        }
        catch (invalid_details& e){
            cout << e.what() << endl;
        }
        catch (name_not_valid& e){
            cout << e.what() << endl;
        }
        catch (ID_NOT_VALID& e){
            cout << e.what() << endl;
        }

    }
        // check which party to go.
        // call the func that add this new politician by getting his data from the user.
        add_pol_with_params(name, last_name, ID, republic_or_democrar, leader_or_social, power);
}

void PoliticalSys::add_party_with_params(string party_name, string R_or_D) {
    Party* party_new;
    if(R_or_D == "D") {
        party_new = new Democratic_Party(party_name); // add to general and democrat parties lists.
        party_list.push_back(party_new);
    }
    else {
        party_new = new Republican_Party(party_name);  // add to general and republic parties lists.
        party_list.push_back(party_new);
    }
    int size_new_party = 0;
    vector<Politician*>::iterator it_pol;
    vector<Party*>::iterator it_party;
    for (it_pol = politics.begin(); it_pol != politics.end(); ++it_pol){
        Politician* temp_pol = (*it_pol);
        if(!party_new->is_fit(temp_pol)){ // check if this pol is suit to this party.
            continue;
        }
        if(temp_pol->get_party() == "None"){
            party_new->add(temp_pol); // add the politician to the new party
            temp_pol->set_party(party_new->get_name()); // set his party name field to the new one.
            continue;
        }
        // check if this politician can join this party by the other rules.
        it_party = std::find_if(party_list.begin(), party_list.end(), find_party_by_name(temp_pol->get_party()));
        if((it_party) == party_list.end()) // "*it_party" is the pointer to the party that temp_pol join her.
            return; // not found the party.
        Party* found_par = *it_party;
        if((found_par)->get_party_size() > party_new->get_party_size()){
            party_new->add(temp_pol); // add the politician to the new party
            temp_pol->set_party(party_new->get_name()); // set his party name field to the new one.
            found_par->remove(temp_pol); // remove him from his previous party.
        }
    }
}


void PoliticalSys::addParty() {
    string party_name, R_or_D;
    Party *party_new;
    cout << "---Create Party---" << endl;
    while (true) {
        try {
            cout << "Name:\n";
            cin >> party_name;
            vector<Party *>::iterator it_par;
            if (party_list.size() != 0) {
                for (it_par = party_list.begin(); it_par != party_list.end(); ++it_par) {
                    if ((*it_par)->get_name() == party_name) {
                        throw name_not_valid();
                    }
                }
            }
            cout << "Republican or Democratic party\n";
            cin >> R_or_D;
            if (R_or_D != "D" && R_or_D != "R") {
                throw invalid_details();
                continue;
            }
            break;
        }
        catch( name_not_valid& e){
            cout << e.what() << endl;
        }
        catch( invalid_details& e){
            cout << e.what() << endl;
        }
    }

    // call the helper func that add party by getting params.
    add_party_with_params(party_name, R_or_D);
}

// helper func for find politician by his id.
Politician* find_pol_by_id(int id, vector<Politician*>general_pol_list){
    vector<Politician*>::iterator it_pol; // iterator point on politician*.
    Politician* pol_remove; // for keeping the politician.
    for(it_pol = general_pol_list.begin(); it_pol != general_pol_list.end(); ++it_pol){
        if(!(*it_pol))
            return NULL;
        pol_remove = *it_pol;
        if(pol_remove->get_id() == id){
            return pol_remove; // found the politician.
        }
    }
    return NULL;
}


void PoliticalSys::removePolitician(){
    int id;
    if(politics.size() ==0)
        return;
    cout << "---Remove Politician---\n";
    while (true) {
        try {
            cout << "Enter the ID:\n";
            cin >> id;
            if (id < 0) {
                throw ID_NOT_VALID();
            }
            int flag = 0;
            vector<Politician *>::iterator it_pol;
            it_pol = std::find_if(politics.begin(), politics.end(), find_pol(id));
            if(it_pol == politics.end()){
                throw ID_NOT_VALID();
            }
            break;
        }
        catch (ID_NOT_VALID& e){ // catch the exception.
            cout << e.what() << endl;
            cin.clear();
        }

    }

    vector<Politician*>temp_pol_list;
    vector<Politician*>::iterator it_pol; // iterator point on politician*.
    vector<Party*>::iterator it_party; // iterator point on party*.
    Politician* pol_remove; // for keeping the politician.
    pol_remove = find_pol_by_id(id, politics); // find the pol with the helper func
    if(!pol_remove) {
        return; // not found.
    }
    string party_name_of_pol = pol_remove->get_party();
    // check if this pilitician exist.
    it_pol = std::find(politics.begin(), politics.end(), pol_remove);
        // find his party
        it_party = std::find_if(party_list.begin(), party_list.end(), find_party_by_name(party_name_of_pol));
        if(it_party != party_list.end()) {
            // now remove him from his party.
            (*it_party)->remove(pol_remove);
        }
    politics.erase(std::remove(politics.begin(), politics.end(), pol_remove), politics.end()); // remove the pointer from the politics vector.
    delete pol_remove; // Delete from the memory.
    pol_remove = NULL;

}


void PoliticalSys::removeParty(){
    cout << "---Remove Party---" << endl;
    string party_name;
    if(party_list.size() == 0)
        return;
    if (party_list.size() == 0){
        return;
    }
    while (true) {
        try {
            cout << "Enter party name:\n";
            cin >> party_name;
            if (party_list.size() == 0)
                return;
            int party_found = 0;
            vector<Party *>::iterator it_par;
            it_par = std::find_if(party_list.begin(), party_list.end(), find_party_by_name(party_name));
            if (it_par == party_list.end()){
                throw name_not_valid();
            }

            break;
        }
        catch (name_not_valid& e){
            cout << e.what() << endl;
        }
    }

    // find the party
    vector<Party*>::iterator it_party;
    vector<Politician*>::iterator it_pol;
    vector<Party*>temp_party_list;
    vector<Politician*>temp_pol_list;
    it_party = std::find_if(party_list.begin(), party_list.end(), find_party_by_name(party_name));
    if(it_party == party_list.end()){
        return; // dont here
    }
    Party* remove_par = *it_party; // found it.
    temp_pol_list = (*it_party)->get_pol_list();
    remove_par->notify_chairman("None");
    // remove the party from list.
    party_list.erase(std::remove(party_list.begin(), party_list.end(), remove_par), party_list.end()); // if not null
    // now join this party politicians to the other parties.
    for(it_pol = temp_pol_list.begin(); it_pol != temp_pol_list.end(); ++it_pol){
        Politician* pol = *it_pol;
        pol->set_party("None"); // delete the previous party name.
        if(party_list.size() != 0) {
            add_pol_to_party(pol, party_list); // helper func for add the politician by the rules.
        }
    }
    delete remove_par;
    remove_par = NULL;
}


void PoliticalSys::elections() {
    if(politics.size() == 0 || party_list.size() == 0){
        return; // no parties or no politics.
    }
    vector<Party*>::iterator it_party;
    for(it_party = party_list.begin(); it_party != party_list.end() ; ++it_party){
        Party* party_temp = *it_party;
        party_temp->primaries(); // each party elects chairman
    }
    int flag = 0; // for know when to print "----Primaries----"
    for(it_party = party_list.begin(); it_party != party_list.end() ; ++it_party){
        Party* party_temp = *it_party;
        if (flag == 0 ){
            cout << "----Primaries----" << endl;
        }
        flag ++;
        cout << party_temp->get_chairman() << " is the chairman of " << party_temp->get_name() << endl;
    }
    Party* winner_party;
    int winner_power = 0;
    if( 0 < party_list.size()) {
        winner_power = party_list.at(0)->election_intensity(); // for select the winner party.
        winner_party = party_list.at(0);
    }
    cout << "----Elections----" << endl;
    for(it_party = party_list.begin(); it_party != party_list.end() ; ++it_party) {
        Party *party_temp = *it_party;
        cout << "Party: " << party_temp->get_name() << ",Power: " << party_temp->election_intensity() << endl;
        if (party_temp->election_intensity() > winner_power){
            winner_power = party_temp->election_intensity();
            winner_party = party_temp;
        }
    }
    cout << "----Elections Results----" << endl;
    cout << winner_party->get_name() << " party won the elections and " << winner_party->get_chairman() << " is the prime minister" << endl;

}


void PoliticalSys::printPoliticians()const  {
    if(politics.size() == 0){
        return; // no pilitics.
    }
    cout << "----Politicians----" << endl;
    vector<Politician*>::const_iterator it_pol;
    for(it_pol = politics.begin(); it_pol != politics.end(); ++it_pol){
        Politician* pol = (*it_pol);
        pol->print_my_info();
        cout << "\n";
    }
}

void PoliticalSys::printParties() const {
    if(party_list.size() == 0){
        return; // no parties in the system.
    }
    cout << "----Parties----" << endl;
    vector<Party*>::const_iterator it_party;
    for(it_party = party_list.begin(); it_party != party_list.end(); ++it_party){
        Party* party = (*it_party);
        party->print_my_info();
    }
}




void PoliticalSys::BiggestParty() const {
    if(party_list.size() == 0){
        return; // no parties in the list.
    }
    // using functor for it.
    Party* party = *std::max_element(party_list.begin(), party_list.end(), compare_size_class());
    cout << "----Biggest Party----" << endl;
    cout << "[" << party->get_name() << "," << party->get_party_size() << "]" << endl;
}


// destructor of this class, clean all the memory that made.
PoliticalSys::~PoliticalSys() {
    vector<Politician*>::iterator it_pol;
    vector<Party*>::iterator it_party;
    for(it_pol = politics.begin(); it_pol != politics.end(); ++it_pol){
        delete (*it_pol);
    }
    for(it_party = party_list.begin(); it_party != party_list.end(); ++ it_party){
        delete (*it_party);
    }
    politics.clear();
    party_list.clear();

}

// reading from file, we get the file path.

PoliticalSys::PoliticalSys(const char* file1) {
    if(!file1)
        return;
    int num_line = 0;
    string text_line; // initialize string for keeping the line I am working on.
    fstream sys_file;
    ifstream file(file1);
    if(file.is_open()){ // check if the file open
        while(getline(file, text_line)) { // get the next line from the file.
            text_line.erase(std::remove(text_line.begin(), text_line.end(), '\r'), text_line.end());
            if (num_line == 0) {
                num_line++;
                continue;
            }
            if (text_line != "Parties") { // check if the line is "party"
                int id;
                int power;
                string name, last_name, block, Classification; // Classification = social or leader.
                stringstream ss(text_line);
                ss >> name >> last_name >> id >> power >> block >> Classification;
                if (block == "D") {
                    if (Classification == "L") {
                        Politician *p = new Leader_Democretic(name, last_name, id); // create a new politician of the type.
                        p->set_power(power);
                        politics.push_back(p);
                        continue;
                    }
                    if (Classification == "S") {
                        Politician *p = new social_democrat(name, last_name, id); // create a new polician
                        p->set_power(power);
                        politics.push_back(p);
                        continue;
                    }
                }
                if (block == "R") {
                    if (Classification == "L") {
                        Politician *p = new Leader_republic(name, last_name, id); // create a new politician
                        p->set_power(power);
                        politics.push_back(p);
                        continue;
                    }
                    if (Classification == "S") {
                        Politician *p = new social_republic(name, last_name, id);  // crate a new politician.
                        p->set_power(power);
                        politics.push_back(p);
                        continue;
                    }
                }


            }
            if (text_line.substr(0, text_line.length()-1) == "Parties"){
                while (getline(file, text_line)) {
                    string party_name, block;
                    stringstream ss(text_line);
                    ss >> party_name >> block;
                    add_party_with_params(party_name, block); // create a new party using helper function that takes an argument.
                    continue;
                }
            }

        }
    }
}

