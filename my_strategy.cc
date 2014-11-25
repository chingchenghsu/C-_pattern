#include <iostream>

class Strategy
{
public:
     virtual double operation (double a, double b) = 0;
};

class Add:public Strategy
{
public:
    double operation(double a, double b)
    {
        std::cout << "Add ()\n";
        return a + b;
    }
};

class Mult:public Strategy
{
public:
    double operation(double a, double b)
    {
        std::cout << "Mult()\n";
        return a * b;
    }
};

class Substract:public Strategy
{
public:
    double operation(double a, double b)
    {
        std::cout << "Sub()\n";
        return a - b;
    }
};
class Context
{
private:
    Strategy* pStrategy;

public:

    Context (Strategy& strategy)
        : pStrategy(&strategy)
    {
    }
 
    void SetStrategy(Strategy& strategy)
    {
        pStrategy = &strategy;
    }
 
    int operationStrategy(int a, int b)
    {
        return pStrategy->operation(a,b);
    }
};
int main()
{
    Add add;
    Substract substract;
    Mult  mult;

    Context context(add);
    int resultA = context.operationStrategy(3,4);

    context.SetStrategy(substract);
    int resultB = context.operationStrategy(3,4);

    context.SetStrategy(mult);
    int resultC = context.operationStrategy(3,4);

    std::cout << "resultA: " << resultA << "\tresultB: " << resultB << "\tresultC: " << resultC << "\n";
}
