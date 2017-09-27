/*
 * Decorator Pattern
 *
 * 意图：动态地给一个对象增加一些额外的职责
 * 解决：如果用继承来处理上述问题，会导致子类臃肿
 *
 */
#include <iostream>
using namespace std;
/*
 * 抽象类->具体产品
 */
class Shape
{
	public:
		virtual void draw() = 0;
};

class Rect: public Shape
{
	public:
		void draw(){ cout<<"Rect"<<endl; }
};

class Circle: public Shape
{
	public:
		void draw(){ cout<<"Circle"<<endl; }
};

/*
 * 抽象装饰器类
 */
class ShapeDecorator: public Shape
{
	protected:
		Shape *p;

	public:
		ShapeDecorator(Shape* _p): p(_p) {}
		virtual void draw() = 0; // 装饰函数
};
/*
 * 具体装饰类，在执行所需类方法之前
 * 先执行该类中定义的修饰方法
 */
class RedShapDecorator: public ShapeDecorator
{
	public:
		RedShapDecorator(Shape *_p): ShapeDecorator(_p) {}
		void draw() // 装饰函数接口
		{
			setRedBorder(ShapeDecorator::p);
		}
	private:
		void setRedBorder(Shape* p) // 装饰函数的具体实现
		{
			cout<<"RedBorder:";
			p->draw();
		}
};


int main()
{
	RedShapDecorator Red(new Rect());
	Red.draw();

	return 0;
}
