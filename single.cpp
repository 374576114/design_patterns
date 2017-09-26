/**
 * sigle pattern
 * 只让类有一个实例化对象
 */
#include <iostream>
using namespace std;

class SingleObject
{
    private:
	SingleObject(){}
	static SingleObject* instance ;
    public:
	// 利用公有的静态函数来初始化
	static SingleObject* get() 
	{ 
	    if (instance == NULL ) 
		instance = new SingleObject();
	    return instance; 
	}
	void showMessage() { cout<<"hello world\n"<<endl;}
};

SingleObject* SingleObject::instance = NULL;

int main()
{
    SingleObject* obj = SingleObject::get();
    obj->showMessage();

    return 0;
}
    
