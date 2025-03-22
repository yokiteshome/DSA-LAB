#include <iostream>
#include <string>
#define TAX_RATE 0.15
using namespace std;
int main() {
    cout<<"This is a C++ program that analyzes product sales and inventory for a store"<<endl;

    string product_name;
    product_name;//declaration before assignment
    int category;
    int initial_inventory;//direct initialization
    float price_per_unit;
    int items_sold;

    decltype(initial_inventory) number_of_workers;

    int new_inventory {initial_inventory};
    new_inventory-=items_sold;
    //list initialization

    cout<<"enter the number of workers: "<<endl;
    cin>>number_of_workers;

    cout<<"What is your product name?"<<endl;
    cin>>product_name;

    cout<<"What is your product category?"<<endl;
    cin>>category;

    cout<<"What is your initial inventory quantity?"<<endl;
    cin>>initial_inventory;

    cout<<"What is your product price?"<<endl;
    cin>>price_per_unit;
    

    cout<<"What is the number of items sold?"<<endl;
    cin>>items_sold;
   
  
    cout<<"INVENTORY SALES REPORT"<<endl;
    cout<<endl;

    cout << "The number of workers is: " << number_of_workers << endl;
    cout<<"Your product name is: "<<product_name<<endl;
    cout<<"Your product category: "<<category<<endl;
    cout<<"Your initial inventory quantity is: "<<initial_inventory<<endl;;
    string inventory_status =(new_inventory<10)?"Low inventory!":"Sufficient inventory!";
    cout<<inventory_status<<endl;
    cout<<"Your product price per item is: "<<price_per_unit<<endl;
    cout<<"The number of items sold is: "<<items_sold<<endl;
    auto total_sales_amount =price_per_unit*items_sold;
    const double const_tax_rate=0.15;
    cout<<"\n";
    cout << "The constant tax rate is: " << const_tax_rate << endl;
    cout << "The tax rate is: " << TAX_RATE << endl;
    cout<<"\n";
    if (category >= 1 && category <= 5) {
        cout << "You entered a valid category: "<< category << endl;
        switch(category) {
            case 1:
            cout<<"Category 1: Electronics";
            break;
            case 2:
            cout<<"Category 2: Groceries";
            break;
            case 3:
            cout<<"Category 3: Clothing";
            break;
            case 4:
            cout<<"Category 4: Stationery";
            break;
            case 5:
            cout<<"Category 5: Miscellaneous";
            break;
        }
    } else {
        cout << "The category is out of range. Please enter a category between 1 and 5(including)." << endl;
    }
    cout<<"\n";
    cout<<" Reciept:"<<endl;
    for(int i=1; i<=items_sold; i++) {
        cout<<"Item: "<<i<<":"<<price_per_unit<<" Birr"<<endl;
    }
    cout<<"\n";
    cout << "The total sales amount is (WITHOUT TAX): " << total_sales_amount<< endl;
    cout << "The total sales amount is: " << total_sales_amount+(total_sales_amount*TAX_RATE)<< endl;

    cout<<"\nProcessing complete! Thank you for using the product sales and inventory analyzer.";



}