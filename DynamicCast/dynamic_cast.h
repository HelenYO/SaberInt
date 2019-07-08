//
// Created by Елена on 2019-06-26.
//

#ifndef DYNAMICCAST_DYNAMIC_CAST_H
#define DYNAMICCAST_DYNAMIC_CAST_H

#include <map>

class DynamicCastObject {
private:
    std::map<int, void *> address_map;

    static int generateId() {
        static int typeID;
        return ++typeID;
    }

    template<typename T>
    struct MetaTypeInfo {
        static int getTypeInfo() {
            static const int typeID = generateId();
            return typeID;
        };
    };

protected:
    template<typename T>
    void add(T *t) {
        auto temp = MetaTypeInfo<T>::getTypeInfo();
        address_map[temp] = t;
    }

public:
    DynamicCastObject() {
        add(this);
    }

    virtual ~DynamicCastObject() {}

    template<class T>
    T *dynamiccast() {
        auto temp = MetaTypeInfo<T>::getTypeInfo();
        auto it = address_map.find(temp);
        if (it == address_map.end()) { return 0; }
        else { return reinterpret_cast<T *>(it->second); }
    }

    template<class T>
    T const *dynamiccast() const {
        auto temp = MetaTypeInfo<T>::getTypeInfo();
        auto it = address_map.find(temp);
        if (it == address_map.end()) { return 0; }
        else { return reinterpret_cast<T const *>(it->second); }
    }

    friend bool operator==(DynamicCastObject const &lhs, DynamicCastObject const &rhs)
    {
        return lhs.address_map == rhs.address_map;
    }
};

template<class T>
T *dynamiccast(DynamicCastObject *o) { return o ? o->dynamiccast<T>() : 0; }

template<class T>
T const *dynamiccast(DynamicCastObject const *o) { return o ? o->dynamiccast<T>() : 0; }

template<class T>
T &dynamiccast(DynamicCastObject &o) {
    if (T *t = o.dynamiccast<T>()) { return *t; }
    else { throw std::bad_cast(); }
}

template<class T>
T const &dynamiccast(DynamicCastObject const &o) {
    if (T const *t = o.dynamiccast<T>()) { return *t; }
    else { throw std::bad_cast(); }
}

#endif //DYNAMICCAST_DYNAMIC_CAST_H
