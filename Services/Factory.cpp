#include "Factory.h"
#include "../Models/ConsoleLogger.h"
#include "../Models/AudioPlayer.h"
#include "../Services/DataAccess/TextDao.h"

// Hàm configure - Đăng ký các dịch vụ
void Factory::_configure() {
    _registerService<Observer, ConsoleLogger>();
    _registerService<IDao, TextDao>();

}
Factory::Factory() {
    _configure();
}
shared_ptr<Factory> Factory::instance() {
    if (_instance == nullptr) {
        _instance =  shared_ptr<Factory>(new Factory());
    }
    return _instance;
}
