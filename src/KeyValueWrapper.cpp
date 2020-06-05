#include "KeyValueWrapper.h"


KeyValueWrapper::KeyValueWrapper(long key, string value){
    this->key = key;
    this->value = value;
}


long KeyValueWrapper::getKey(){
    return key;
}


string KeyValueWrapper::getValue(){
    return value;
}