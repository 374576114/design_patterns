/*
 * Command Pattern
 * 命令模式
 *
 * 意图：将请求封装成一个对象，从而使您可以使用不同的请求对客户进行参数化
 *
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * 请求类
 */
class Stock
{
private:
	string name;
	int quantity;
public:
	Stock(): name("ABC"), quantity(10) {}
	void buy()
	{
		cout<<"buy name:"<<name<<"qu:"<<quantity<<endl;
	}
	void sell()
	{
		cout<<"sell name:"<<name<<"qu:"<<quantity<<endl;
	}
};

/*
 * 命令接口
 */
class Order
{
public:
	virtual void execute() = 0;
};

class BuyStock: public Order
{
private:
	Stock* p;
public:
	BuyStock(Stock *_p): p(_p) {}
	void execute() override
	{
		p->buy();
	}
};

class SellStock: public Order
{
private:
	Stock* p;
public:
	SellStock(Stock* _p): p(_p) {}
	void execute() override
	{
		p->sell();
	}
};
/*
 * 命令调用类
 */
class Broker
{
private:
	vector<Order*> v;
public:
	void takeOrder(Order *p)
	{
		v.push_back(p);
	}

	void placeOrder()
	{
		for(int i=0, len=v.size(); i<len; i++)
		{
			v[i]->execute();
		}
		v.clear();
	}
};

int main()
{
	Stock abcStock;
	BuyStock *pBuy = new BuyStock(&abcStock);
	SellStock *pSell = new SellStock(&abcStock);

	Broker broder;
	broder.takeOrder(pBuy);
	broder.takeOrder(pSell);

	broder.placeOrder();
	cout<<"--------------"<<endl;

	broder.takeOrder(pBuy);
	broder.takeOrder(pSell);
	broder.takeOrder(pBuy);
	broder.takeOrder(pSell);
	broder.placeOrder();

	return 0;
}
