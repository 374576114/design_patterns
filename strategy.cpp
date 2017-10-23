/*
 * Stategy Pattern
 * 策略模式
 *
 * 意图：定义一系列的算法，把它们一个个封装起来，并且使它们可以相互替换
 *
 * 主要解决：在有多种算法相似的情况下，使用if...else所带来的复杂和难以维护
 *
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Strategy
{
public:
    virtual int doOperation(int n1, int n2) = 0;
};

class OperationAdd: public Strategy
{
public:
    int doOperation(int n1, int n2) override
    {
        return (n1 + n2);
    }
};

class OperationSub: public Strategy
{
public:
    int doOperation(int n1, int n2) override
    {
        return (n1 - n2);
    }
};

class Context
{
private:
    Strategy *strategy;
public:
    Context(Strategy* _p):strategy(_p) {}
    int executeStrategy(int n1, int n2)
    {
        return strategy->doOperation(n1, n2);
    }
};


int main()
{
    Context *pcontext = new Context(new OperationAdd());
    cout<<"3 add 4:"<<pcontext->executeStrategy(3,4)<<endl;

    pcontext = new Context(new OperationSub());
    cout<<"4 sub 3:"<<pcontext->executeStrategy(4,3)<<endl;

    return 0;
}
    
