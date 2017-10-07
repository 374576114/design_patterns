/*
 * Observer Pattern
 * 观察者模式
 *
 * 意图：定义对象间的一种一对多的依赖关系，当一个对象的状态发生
 *   改变时，所有依赖于它的对象都得到通知并被自动更新
 *
 * 主要解决：一个对象状态改变给其它对象通知的问题，而且考虑到易用和低耦合，
 *   保证高度的协作
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//class Observer;
class Subject;

class Observer
{
protected:
   Subject* subject;

public:
   Observer(Subject *_subject): subject(_subject) {}
   virtual void update() = 0;
};

class Subject
{
private:
	vector<Observer*> v;
	int state;

public:
	//Subject():state(0) {}
	int getState() { return state; }

	void setState(int state)
    { 
		this->state = state;
		notifyAllObservers();
	}

	void attach(Observer* observer)
	{
		v.push_back(observer);
	}

	void notifyAllObservers()
	{
		for(int i=0, len=v.size(); i<len; i++){
			v[i]->update();
		}
	}
};

class BinaryObserver: public Observer
{
public:
	BinaryObserver(Subject* subject): Observer(subject)
   	{
		this->subject->attach(this);
	}
	
	void update() override
	{
		cout<<"binary state:"<<this->subject->getState()<<endl;
	}
};

class OctalObserver: public Observer
{
public:
	OctalObserver(Subject* subject): Observer(subject)
	{
		this->subject->attach(this);
	}
	void update() override
	{
		cout<<"octal state:"<<this->subject->getState()<<endl;
	}
};

int main()
{
	Subject subject;

	new BinaryObserver(&subject);
	new OctalObserver(&subject);

	subject.setState(15);
	subject.setState(10);

	return 0;
}
