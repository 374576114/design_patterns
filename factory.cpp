/**
 * factory pattern
 * 抽象产品->具体产品
 * 抽象工厂->具体工厂
 * 一个工厂产一种产品
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
 * 抽象工厂
 */
class Factory
{
    public:
	virtual Shape * create() = 0;
};
/**
 * 具体工厂
 */
class RectFactory: public Factory
{
    public:
	Shape * create() { return new Rect(); }
};
/**
 * 具体工厂
 */
class CircleFactory: public Factory
{
    public:
	Shape * create() { return new Circle(); }
};



int main()
{
    Shape *p = 0;

    auto prect = new RectFactory();
    p = prect->create();
    p->draw();
    
    return 0;
}
