# include <iostream>
# include <string>
class Tea
{
public:
    virtual double getCost() = 0;
    virtual std::string getIngredient() = 0;
};
// Plain coffee without ingredient
class SimpleTea:public Tea
{
private:
    double cost;
    std::string ingredient;
public:
    SimpleTea()
    {
        cost = 30;
        ingredient = std::string("Pure Tea");
    }
  double getCost()
    {
        return cost;
    }
    std::string getIngredient()
    {
        return ingredient;
    }
};
// Abstract decorator class
class TeaDecorator:public Tea
{
protected:
    Tea & decoratedTea;
public:
    TeaDecorator(Tea & decoratedTea):decoratedTea(decoratedTea){}
};
class Milk:public TeaDecorator
{
private:
    double cost;
public:
    Milk(Tea & decoratedTea):TeaDecorator(decoratedTea)
    {
        cost = 5;
    }
    double getCost()
    {
        return cost + decoratedTea.getCost();
    }
    std::string getIngredient()
    {
        return "Milk "+decoratedTea.getIngredient();
    }
};
class Bubble:public TeaDecorator
{
private:
    double cost;
public:
    Bubble(Tea & decoratedTea):TeaDecorator(decoratedTea)
    {
        cost = 7;
    }
    double getCost()
    {
        return cost + decoratedTea.getCost();
    }
    std::string getIngredient()
    {
        return "Bubble "+decoratedTea.getIngredient();
    }
};
class Suger:public TeaDecorator
{
private:
    double cost;
public:
    Suger(Tea & decoratedTea):TeaDecorator(decoratedTea)
    {
        cost = 4;
    }
    double getCost()
    {
        return cost + decoratedTea.getCost();
    }
    std::string getIngredient()
    {
        return "Suger "+decoratedTea.getIngredient();
    }
};
int main()
{
    Tea* sample;
    sample = new SimpleTea();
    sample = new Milk(*sample);
    sample = new Bubble(*sample);
    sample = new Suger(*sample);
    std::cout << sample->getIngredient() << std::endl;
    std::cout << "Cost: " << sample->getCost() << std::endl;
}
