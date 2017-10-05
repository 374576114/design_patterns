/*
 * Iterator Pattern
 * 迭代器模式
 *
 * 意图：提供一种方法顺序访问一个聚合对象中各个元素，而又无需暴露该对象的内部表示
 */
#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

/*
 * 迭代器接口
 * next()函数返回容器内部的内容，但是用指针的方式返回
 */
class Iterator
{
public:
	virtual bool hasNext() = 0;
	virtual void* next() = 0;
};
/*
 * 容器的接口
 */
class Container
{
public:
	virtual Iterator* getIterator() = 0;
};

class NameResp: Container
{
private:
	vector<string> name;
	class NameIterator: public Iterator
	{
	private:
		int index;
		vector<string> &name; // 注意引用的初始化
	public:
		NameIterator(vector<string>& _name): index(0), name(_name) {}
		bool hasNext() override
		{
			if (index < name.size() )
				return true;
			else
				return false;
		}

		void* next() override
		{
			if(this->hasNext())
			{
				return &name[index++];
			}
			return NULL;
		}
	};
public:
	NameResp()
	{
		name.push_back("Robert");
		name.push_back("Tom");
		name.push_back("John");
		name.push_back("Lora");
	}

	Iterator* getIterator() override
	{
		return new NameIterator(name);
	}
};


int main()
{
	NameResp name;
	for(Iterator* it = name.getIterator(); it->hasNext(); )
	{
		cout<<*(static_cast<string*>(it->next()))<<endl;
	}

	return 0;
}


