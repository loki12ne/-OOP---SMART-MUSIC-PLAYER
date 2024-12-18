#ifndef _IDAO_H_
#define _IDAO_H_

#include <vector>
#include <memory>
using namespace std;
#include "../../Models/Song.h"

class IDao {
public:
    virtual vector<Song> getAll() = 0;
};



#endif