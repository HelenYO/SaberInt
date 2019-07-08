//
// Created by Елена on 2019-06-29.
//

#ifndef DYNAMICCAST_DYNAMIC_CAST_BIT_MASK_H
#define DYNAMICCAST_DYNAMIC_CAST_BIT_MASK_H

#include <map>

class DynamicCastObject {
private:
    uint64_t mask;
    void *begin;

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
        mask |= 1 << temp;
    }

public:
    DynamicCastObject() {
        add(this);
        begin = this;
    }

    virtual ~DynamicCastObject() {}

    template<class T>
    T *dynamiccast() {
        auto temp = MetaTypeInfo<T>::getTypeInfo();
        if(mask & (1 << temp)) {
            return reinterpret_cast<T  *>(begin);
        }
        else { return nullptr; }
    }

    template<class T>
    T const *dynamiccast() const {
        auto temp = MetaTypeInfo<T>::getTypeInfo();
        if(mask & (1 << temp)) {
            return reinterpret_cast<T const *>(begin);
        }
        else { return nullptr; }
    }

    friend bool operator==(DynamicCastObject const &lhs, DynamicCastObject const &rhs)
    {
        return (lhs.mask == rhs.mask) & (lhs.begin == rhs.begin);
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

#endif //DYNAMICCAST_DYNAMIC_CAST_BIT_MASK_H
