/**
 * abstractor factory pattern
 * 抽象产品(多个)->具体产品(多个)
 * 抽象工厂(多个)->具体工厂(多个)
 *
 * 这里一个具体工厂产多个（类型相似，比如都是冰箱)的具体产品
 * 
 */
#include <iostream>

using namespace std;
/*
 * 抽象物品
 */
class Goods
{
    public :
	virtual void usage() = 0;
};
/*
 * 具体物品 
 * gree air-condition
 * gree ice-box
 */
class AirCondition: public Goods
{
    public:
	void usage()
	{
	    cout<<"air-condition"<<endl;
	}
};
class IceBox: public Goods
{
    public:
	void usage()
	{
	    cout<<"ice-box"<<endl;
	}
};
/*
 * 抽象厂商
 */
class Trademark
{
    public:
	virtual Goods* air_condition() = 0;
	virtual Goods* ice_box() = 0;
};
/*
 * 具体厂商
 */
class Gree: public Trademark
{
    public:
	Goods* air_condition() { return new AirCondition();}
	Goods* ice_box() { return new IceBox(); }
};

int main()
{
    Gree factory;
    Goods *p = factory.air_condition();
    p->usage();
    delete p;

    p = factory.ice_box();
    p->usage();
    delete p;

    return 0;
}


