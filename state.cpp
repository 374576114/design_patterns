/*
 * State Pattern
 * 状态模式
 *
 * 意图：允许对象在内部状态发生改变时改变它的行为，对象看起来好像修改了它的类
 *
 * 主要解决：对象的行为依赖于它的状态改变（属性），并且可以根据
 *   它的状态改变而改变它的相关行为
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class State;

class Context
{
private:
    State *state;

public:
    Context():state(NULL) {}
    void setState(State *state)
    {
        this->state = state;
    }
    State* getState()
    {
        return state;
    }
};

class State
{
public:
    virtual void doAction(Context *context) = 0;
};

class StartState: public State
{
public:
    void doAction(Context *context) override
    {
        cout<<"State:[start]"<<endl;
        context->setState(this);
    }

    string toString()
    {
        return "start action";
    }
};

class StopState: public State
{
public:
    void doAction(Context *context) override
    {
        cout<<"State:[stop]"<<endl;
        context->setState(this);
    }
    string toString()
    {
        return "stop action";
    }
};

int main()
{
    Context *context = new Context();

    StartState *start = new StartState();
    start->doAction(context);
    cout<<start->toString()<<endl;

    StopState *stop = new StopState();
    stop->doAction(context);
    cout<<stop->toString()<<endl;

    return 0;
}
