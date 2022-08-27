#include <iostream>

class Base
{
public:
    virtual ~Base() {}
};

class A : public Base
{
public:
    virtual ~A() {}
};
class B : public Base
{
public:
    virtual ~B() {}
};
class C : public Base
{
public:
    virtual ~C() {}
};

Base *generate(void)
{
    srand(time(NULL));
    int x = rand() % 3;

    if (x == 1)
        return new A();
    else if (x == 0)
        return new B();
    return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p) != NULL)
        std::cout << "B" << std::endl;
    else
        std::cout << "C" << std::endl;
}

void identify(Base &p)
{

    try
    {
        A &ref = dynamic_cast<A &>(p);
        (void)ref;
        std::cout << "A" << std::endl;
    }
    catch (const std::exception &e)
    {
        try
        {
            B &ref = dynamic_cast<B &>(p);
            (void)ref;
            std::cout << "B" << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "C" << std::endl;
        }
    }
}

int main()
{
    Base *x  = generate();

    
    std::cout << "Using Pointer:" << std::endl;
    identify(x);
    
    std::cout << "Using Ref:" << std::endl;
    identify(*x);
}