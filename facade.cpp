/*
 * Facade Pattern
 * 外观模式
 *
 * 意图：为子系统中的一组接口提供
 *  一个一致的界面，外观模式定义了
 *  一个高层接口，这个接口使得这一
 *  子系统更加容易使用
 */
#include <iostream>
using namespace std;
/*
 * 抽象物品->具体物品
 */
class Shape
{
	public:
		virtual void draw() = 0;
};

class Rect: public Shape
{
	public:
		virtual void draw() override { cout<<"Rect"<<endl; }
};

class Circle: public Shape
{
	public:
		virtual void draw() override { cout<<"Circle"<<endl; }
};

/*
 * 外观类: 系统提供给外层的接口，屏蔽系统内部的复杂实现
 */
class ShapeMaker
{
	private:
		Shape* pRect;
		Shape* pCircle;

	public:
		ShapeMaker(): pRect(new Rect()), pCircle(new Circle()) {}
		void drawRect() { pRect->draw(); }
		void drawCircle() { pCircle->draw(); }
};

int main()
{
	ShapeMaker shape;

	shape.drawRect();
	shape.drawCircle();

	return 0;
}
