/*
 * Chain of Responsibility Pattern
 * 职责链模式
 *
 * 意图：避免请求发送者和接受者耦合在一起，
 *   让多个对象都有可能接受请求，将这些对象连
 *   成一条链，并且沿着这条链传递请求，直到有
 *   对象处理它为止。
 *
 */
#include <iostream>
#include <string>
using namespace std;

class AbstractLogger
{
protected:
	int level;
	AbstractLogger *nextLogger;
	virtual void write(string msg) = 0;

public:
	static int INFO;
	static int DEBUG;
	static int ERROR;

	void setNextLogger(AbstractLogger *nextLogger) { this->nextLogger = nextLogger; }
	void logMessage(int level, string msg)
	{
		if (this->level <= level)
			write(msg);
		else
			nextLogger->logMessage(level, msg);
	}
};

class ConsoleLogger: public AbstractLogger
{
protected:
	virtual void write(string msg) override
	{
		cout<<"Console log:"<<msg<<endl;
	}
public:
	ConsoleLogger(int _level) { this->level = _level; }
};

class ErrorLogger: public AbstractLogger
{
protected:
	virtual void write(string msg) override
	{
		cout<<"Error: "<<msg<<endl;
	}
public:
	ErrorLogger(int _level) { this->level = _level; }
};

class FileLogger: public AbstractLogger
{
protected:
	virtual void write(string msg) override
	{
		cout<<"File :"<<msg<<endl;
	}
public:
	FileLogger(int _level) {this->level = _level; }
};

int AbstractLogger::INFO  = 1;
int AbstractLogger::DEBUG = 2;
int AbstractLogger::ERROR = 3;

AbstractLogger* getChainOfLoggers()
{
	AbstractLogger* error = new ErrorLogger(AbstractLogger::ERROR);
	AbstractLogger* file  = new FileLogger(AbstractLogger::DEBUG);
	AbstractLogger* console = new ConsoleLogger(AbstractLogger::INFO);

	error->setNextLogger(file);
	file->setNextLogger(console);

	return error;
}

int main()
{
	string info(" --INFO");
	string debug(" --DEBUG");
	string error(" --ERROR");
	AbstractLogger* loggerChain = getChainOfLoggers();

	loggerChain->logMessage(AbstractLogger::INFO, info);
	loggerChain->logMessage(AbstractLogger::DEBUG, debug);
	loggerChain->logMessage(AbstractLogger::ERROR, error);
	
	return 0;
}
