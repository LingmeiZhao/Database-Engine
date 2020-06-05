#include "DeleteResult.h"

DeleteResult::DeleteResult(long key, string* value){
    this->key = key;
    if(value != nullptr){
        values.push_back(value);
        this->found = true;
    }else{
        this->found = false;
    }
}

DeleteResult::DeleteResult(long key, list<string> values){
    this->key = key;
    this->values = values;
    if(values.empty()){
        this->found = true;
    }else{
        this->found = false;
    }
}

list<string> DeleteResult::getValues(){
    return values;
}

long DeleteResult::getKey(){
    return key;
}

bool DeleteResult::isFound(){
    return found;
}   