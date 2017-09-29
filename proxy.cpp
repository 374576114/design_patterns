/*
 * Proxy Pattern
 *
 * 意图:为其它对象提供一种代理以控制对这个对象的访问
 *
 */
#include <iostream>
#include <string>
using namespace std;


class Image
{
	public:
		virtual void display() = 0;
};

class RealImage: public Image
{
	private:
		string name;

	public:
		RealImage(string& _name): name(_name) 
		{ 
			loadFromDisk(name); 
		}

		void display() override 
		{ 
			cout<<"Display:"<<name<<endl; 
		}

		void loadFromDisk(string &_name)
		{
			cout<<"Loading:"<<_name<<endl;
		}
};

class ProxyImage: Image
{
	private:
		RealImage* pR;
		string name;

	public:
		ProxyImage(string &_name): pR(NULL), name(_name){ }
		void display() override 
		{
			if( pR == NULL) 
				pR = new RealImage(name);
			
			pR->display();
		}
};

int main()
{
	string name("hello");
	ProxyImage proxy(name);
	proxy.display();

	return 0;
}
