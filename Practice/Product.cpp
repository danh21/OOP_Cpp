#include <bits/stdc++.h>
using namespace std;

class Product {
protected:
    long barcode;
    string name;

public:
    Product(long b = 0, const string& n = "")
        : barcode(b), name(n) {}

    virtual ~Product() {}   

    long getBarCode() const { return barcode; }

    void setBarCode(long b) { barcode = b; }

    const string& getName() const { return name; }

    void setName(const string& n) { name = n; }

    virtual void scanner() {
        cout << "Barcode : ";
        cin >> barcode;
        cout << "Name : ";
        cin >> name;
    }

    virtual void printer() const {
        cout << "\n[" << barcode << "]\n";
        cout << "Name : " << name << endl;
    }

    virtual double getPrice() const = 0;  // pure virtual
};

class PrepackedFood : public Product {
private:
    double pcePrice;

public:
    PrepackedFood(double p = 0,
                  long b = 0,
                  const string& n = "")
        : Product(b, n), pcePrice(p) {}

    double getPrice() const override {
        return pcePrice;
    }

    void setPrice(double p) {
        pcePrice = p;
    }

    void scanner() override {
        Product::scanner();
        cout << "Price/piece: ";
        cin >> pcePrice;
    }

    void printer() const override {
        Product::printer();
        cout << "Price/piece: "
             << fixed << setprecision(2)
             << pcePrice << endl;
    }
};

class FreshFood : public Product {
private:
    double weight;
    double lbsPrice;

public:
    FreshFood(double w = 0,
              double p = 0,
              long b = 0,
              const string& n = "")
        : Product(b, n), weight(w), lbsPrice(p) {}

    double getPrice() const override {
        return weight * lbsPrice;
    }

    void setPrice(double p) { lbsPrice = p; }

    void setWeight(double w) { weight = w; }

    double getWeight() const { return weight; }

    void scanner() override {
        Product::scanner();
        cout << "Price/lbs : ";
        cin >> lbsPrice;
        cout << "Weight : ";
        cin >> weight;
    }

    void printer() const override {
        Product::printer();
        cout << "Price/lbs : "
             << fixed << setprecision(2)
             << lbsPrice << endl;
        cout << "Weight : "
             << fixed << setprecision(2)
             << weight << endl;
        cout << "Total : "
             << fixed << setprecision(2)
             << getPrice() << endl;
    }
};

int main() {
    vector<Product*> products;
    products.push_back(new PrepackedFood(0.52, 12345, "Salt"));
    products.push_back(new FreshFood(1.2, 1.45, 56789, "Grapes"));
    Product* p = new PrepackedFood();
    p->scanner();
    products.push_back(p);
    
    cout << "\n\nList of products:";
    for (unsigned int i = 0; i < products.size(); ++i)
        products[i]->printer();

    for (auto p : products)
        delete p;
}