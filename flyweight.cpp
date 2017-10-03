/*
 * Flyweight Pattern
 * 享元模式
 *
 * 意图：运用共享技术有效地支持大量细粒度的对象
 * 优点：考虑系统性能，节省内存
 * 
 */
#include <iostream>
#include <string>
#include <map>  // 为了方便我们建立享元索引
using namespace std;

class Shape
{
	public:
		virtual void draw() = 0;
};

class Circle: public Shape
{
	private:
		string color;
		int x;
		int y;
		int r;

	public:
		Circle(string _color): color(_color) {}
		void set(int x, int y, int r) 
		{
			this->x = x;
			this->y = y;
			this->r = r;
		}

		void draw() override
		{
			cout<<color<<x<<":"<<y<<":"<<r<<endl;
		}

};

class ShapeFactory
{
	private:
		map<string, Shape*> hash;

	public:
		Shape* get(string color)
		{
			map<string, Shape*>::iterator it = hash.find(color);
			if( it == hash.end() ){
				Shape* p = new Circle(color);
				hash.insert(make_pair(color, p));
				return p;
			}else{
				return it->second;
			}
		}
};

int main()
{
	ShapeFactory factory;
	string colors[] = {"red", "black", "blue"};

	Circle *c = dynamic_cast<Circle*>(factory.get(colors[0]));
	c->set(1,2,3);
	c = (Circle*)factory.get(colors[1]);
	c->set(2,3,4);
	c = (Circle*)factory.get(colors[2]);
	c->set(3,4,5);

	Shape *p = factory.get(colors[1]);
	p->draw();

	return 0;
}




