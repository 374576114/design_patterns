/*
 * Builder Pattern
 *
 * Builder:抽象建造者
 * ConcreteBuilder:具体建造者
 * Director:指挥者
 * Product:产品角色
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/**
 * 抽象类 Packing Item
 */
class Packing
{
    public:
	virtual void pack() = 0;
};

class Item
{
    public:
	virtual void name() = 0;
	virtual Packing* packing() = 0;
	virtual float price() = 0;
};

/**
 * Packing 的具体实现
 */
class Wrapper : public Packing
{
    public:
	void pack() { cout<<"Wrapper"<<endl; }
};

class Bottle : public Packing
{
    public:
	void pack() { cout<<"Bottel"<<endl; }
};

/**
 * Item 的部分具体实现（抽象类）
 * 即只实现这里的Packing
 */
class Burger : public Item
{
    public:
	Packing* packing(){ return new Wrapper(); }
};
class ColdDrink: public Item
{
    public:
	Packing* packing(){ return new Bottle(); }
};

/**
 * Item 的扩展实现
 * 实现其他，如名字，价格等
 */
class VegBurger: public Burger
{
    public:
	void name(){ cout<<"VegBurger"<<endl; }
	float price() { return 25.0; }
};
class ChickenBurge: public ColdDrink
{
    public:
	void name(){ cout<<"ChickenBurge"<<endl; }
	float price(){ return 30.0; }
};

/**
 * Meal 类
 */
class Meal
{
    private:
	vector<Item*> items;

    public:
	void addItem(Item *item) { items.push_back(item); }
	void getCost()
	{
	    float cost = 0.0;
	    for(int i=0, len=items.size(); i<len; i++){
		cost += items[i]->price();
	    }
	    cout<<"Price:"<<cost<<endl;
	}
	void showItems()
	{
	    for(int i=0, len=items.size(); i<len; i++){
		items[i]->name();
	    }
	}
};

/**
 * MealBuilder
 * 将东西放入套餐
 */
class MealBuilder
{
    public:
	Meal* prepareVegMeal()
	{
	    Meal *meal = new Meal();
	    meal->addItem(new VegBurger());
	    meal->addItem(new ChickenBurge());

	    return meal;
	}
};

int main()
{
    MealBuilder mealBuilder;
    Meal* meal = mealBuilder.prepareVegMeal();
    
    meal->showItems();
    meal->getCost();

    return 0;
}
