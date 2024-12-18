#ifndef _TEXTDAO_H_
#define _TEXTDAO_H_
#include <vector>

#include "IDao.h"

class TextDao : public IDao {
public:
    TextDao();
    vector<Song> getAll() override;
};

#endif