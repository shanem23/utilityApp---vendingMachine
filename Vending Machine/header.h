#include <iostream>
using namespace std;

class Product { // Creates class of Product w/ public attributes and a constructor
public:
    string name;
    int cost;
    int stock;
    Product(string x, int y, int z) : name(x), cost(y), stock(z) {}
};

