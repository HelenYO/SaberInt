//
// Created by Елена on 2019-06-28.
//

//
// Created by Елена on 2019-05-26.
//

#include <sstream>
#include <random>
#include "gtest/gtest.h"

//#include "dynamic_cast.h"
#include "dynamic_cast_bit_mask.h"

struct Base : DynamicCastObject {
public:
    Base() { this->add(this); }
    virtual std::string hello() {
        std::cout << "Hello from Base\n";
        return "Hello from Base\n";
    }
};

struct Derived : Base {
    Derived() : Base(){}

    std::string hello () {
            std::cout << "Hello from Derived\n";
            return "Hello from Derived\n";
    }
};

TEST(correctness, pointer_test) // NOLINT
{
    try
    {
        DynamicCastObject b;
        Base *a1 = b.dynamiccast<Base>();
        Base *a2 = dynamiccast<Base>(&b);
        Base *a3 = dynamic_cast<Base *>(&b);
        EXPECT_EQ(a3, a1);
        EXPECT_EQ(a3, a2);
    } catch (std::bad_cast &e)
    {
        std::cout << e.what() << std::endl;
    }
}

TEST(correctness, const_pointer_test) // NOLINT
{
    DynamicCastObject const b;
    try
    {
        Base const *a1 = b.dynamiccast<Base>();
        Base const *a2 = dynamiccast<Base>(&b);
        Base const *a3 = dynamic_cast<Base const *>(&b);
        EXPECT_EQ(a3, a1);
        EXPECT_EQ(a3, a2);
    } catch (std::bad_cast &e)
    {
        std::cout << e.what() << std::endl;
    }
}

TEST(correctness, ref_test_bad_cast) //NOLINT
{
    DynamicCastObject b;
    try
    {
        Base a1 = dynamiccast<Base>(b);
        Base a2 = dynamic_cast<Base &>(b);
        EXPECT_EQ(a2, a1);
    } catch (std::bad_cast &e)
    {
        std::cout << e.what() << std::endl;
    }
}

TEST(correctness, ref_test) //NOLINT
{
    Base b;
    try
    {
        DynamicCastObject a1 = dynamiccast<DynamicCastObject>(b);
        DynamicCastObject a2 = dynamic_cast<DynamicCastObject &>(b);
        EXPECT_EQ(a2, a1);
    } catch (std::bad_cast &e)
    {
        std::cout << e.what() << std::endl;
    }
}

TEST(correctness, test_self) //NOLINT
{
    Base b;
    try
    {
        DynamicCastObject* a1 = dynamiccast<DynamicCastObject>(&b);
        DynamicCastObject* a2 = dynamic_cast<DynamicCastObject *>(&b);
        EXPECT_EQ(a2, a1);
    } catch (std::bad_cast &e)
    {
        std::cout << e.what() << std::endl;
    }
}