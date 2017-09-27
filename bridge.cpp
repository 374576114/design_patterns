/*
 * learn the Bridge Pattern
 *
 * 把抽象与实现分离，让它们分别实现
 *
 * 与适配器对比:
 *  |_适配器：改变接口，让两个类相容
 *  |_桥接：  分离抽象与实现，接口不同，目的是分离
 *
 * 换句话说：
 *  |_如果有两个模块，你想让它们一起工作，就用adapter(后期）
 *  |_如果什么都没有做，只是想分开实现，就用bridge(前期)
 */
#include <iostream>
using namespace std;
/*
 * 抽象画
 */
class DrawAPI
{
    public:
	virtual void drawCircle() = 0;
};
/*
 * 画的具体实现
 */
class RedCircle: public DrawAPI
{
    public:
	void drawCircle() { cout<<"red"<<endl; }
};

class GreenCircle: public DrawAPI
{
    public:
	void drawCircle() { cout<<"green"<<endl; }
};

/*
 * 形状要配合具体画
 */
class Shape
{
    protected:
	DrawAPI *p;
    public:
	Shape(DrawAPI *_p):p(_p){}
	virtual void draw() = 0;
};

class Circle: public Shape
{
    public:
	Circle(DrawAPI* _p):Shape(_p){}
	void draw()
	{
	    p->drawCircle();
	}
};

int main()
{
    Shape *pr = new Circle(new RedCircle());
    Shape *pg = new Circle(new GreenCircle());

    pr->draw();
    pg->draw();

    return 0;
}
