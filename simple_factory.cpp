/**
 * Simple factory pattern
 * 抽象产品->具体产品
 * 具体工厂(switch 去确定生产哪个产品)
 */
#include <iostream>

using namespace std;

/**
 * 抽象产品
 */
class Shape
{
    public:
	virtual void draw() = 0;
};
/**
 * 具体产品
 */
class Rect: public Shape
{
    public:
	virtual void draw() override
	{
	    cout<<"paint Rect"<<endl;
	}
};
/**
 * 具体产品
 */
class Circle: public Shape{
    public:
	virtual void draw() override
	{
	    cout<<"paint Circle"<<endl;
	}
};

/**
 * 具体工厂
 */
class ShapeFactory
{
    public:
	Shape * create(int type)
	{

	    switch(type){
		case 0: return new Rect(); break;
		case 1: return new Circle(); break;
		default: return 0;
	    }
	}
};

int main()
{
    ShapeFactory factory;
    Shape *p = factory.create(0);
    p->draw();
    delete p;

    p = factory.create(1);
    p->draw();
    delete p;

    return 0;
}
