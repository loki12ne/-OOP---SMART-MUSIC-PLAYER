#ifndef _FACTORY_H_
#define _FACTORY_H_

#include <string>
#include <map>
#include <memory>
#include <functional>
#include <typeinfo>
using namespace std;

class Factory {
private:
    // Singleton instance
    inline static shared_ptr<Factory> _instance = nullptr;

    // Hàm khởi tạo private để ngăn việc tạo trực tiếp từ bên ngoài

    // Lưu trữ các service và hàm khởi tạo
    map<string, function<shared_ptr<void>()>> _serviceCreators;
    map<string, shared_ptr<void>> _services; // Lưu trữ các instance đã được khởi tạo

    void _configure();

    // Đăng ký hàm khởi tạo service
    template <typename Parent, typename Child>
    void _registerService() {
        _serviceCreators[typeid(Parent).name()] = []() -> shared_ptr<void> {
            return make_shared<Child>();
        };
    }

    Factory();

public:
    // Trả về instance của Factory
    static shared_ptr<Factory> instance();

    // Lấy service theo kiểu T
    template <typename T>
    shared_ptr<T> getService() {
        string name = typeid(T).name();

        // Kiểm tra nếu đã khởi tạo service
        if (_services.find(name) != _services.end()) {
            return static_pointer_cast<T>(_services[name]);
        }

        // Nếu chưa khởi tạo, tạo mới từ serviceCreators
        if (_serviceCreators.find(name) != _serviceCreators.end()) {
            auto service = _serviceCreators[name]();
            _services[name] = service;
            return static_pointer_cast<T>(service);
        }

        // Nếu không tìm thấy, trả nullptr
        return nullptr;
    }

    // Ngăn copy và gán
    Factory(const Factory&) = delete;
    Factory& operator=(const Factory&) = delete;
};

#endif
