//
// Created by noam on 1/11/23.
//

#include "Democratic_Politician.h"

// constructor of this class.
Democratic_Politician::Democratic_Politician(string _name, string _last_name, int _id) : Politician(_name,
                                                                                                       _last_name,_id){
    this->name = _name;
    this->last_name = _last_name;
    this->id = _id;
}
