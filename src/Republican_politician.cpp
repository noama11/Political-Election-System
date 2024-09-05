//
// Created by noam on 1/11/23.
//

#include "Republican_politician.h"
// constructor of this class.
Republican_politician::Republican_politician(string _name, string _last_name, int _id) : Politician(_name,
                                                                                                       _last_name,_id) {
    this->name = _name;
    this->last_name = _last_name;
    this->id = _id;
}



