#ifndef WORKER_H
#define WORKER_H

#include "person.h"

class Worker : public Person
{
public:
    Worker(){};
    bool isWorker() const {return true;};
    Worker(std::string,std::string,std::string,int,std::string,std::string,std::string,std::string);
};

#endif // WORKER_H
