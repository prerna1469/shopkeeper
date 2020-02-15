//============================================================================
// Name        : shopkeeper.cpp
// Author      : prerna
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
using namespace std;
class item
{
	int itemno;
	char name[30];//to store item name
	float price;
	int available_quantity;
public:
	friend class purchase;
	void accept_item();//accepts item details
	void display_item();//displays item details
};
void item::accept_item()
{
	cout<<"\n Enter item number ";
	cin>>itemno;
	cout<<"\n Enter name of item ";
	cin>>name;
	cout<<"\n Enter price ";
	cin>>price;
	cout<<"\n Enter available quantity ";
	cin>>available_quantity;
}
void item::display_item()
{
	cout<<"\n Item number: "<<itemno;
	cout<<"\n Name of item: "<<name;
	cout<<"\n Price: Rs "<<price;
	cout<<"\n Available quantity: "<<available_quantity<<" kg";
}
class purchase
{
	int nitem,ncust;
	item stock[20];//stores stock details
	int cust[5][20];//stores quantity purchased
	
public:
	purchase()//constructor
	{
		nitem=0;
		ncust=0;
	}
	void get_stock();//accepts stock details
	void display_stock();
	void get_purchase();//accepts quantity purchased
	void display_purchase();
	void top_cust();//displays top customer
	void highest_item();//displays highest item by each customer
	void highest_item1();//displays highest_item of entire day
	void highest_quantity();//displays highest quantity of each item
	void display_bill();//displays bill of all customers
	void display_bill1();//displays bill of any customer

};
void purchase::get_stock()
{
	int i=0;
	cout<<"\n Enter no of items ";
	cin>>nitem;
	for(i=0;i<nitem;i++)//loop for items
	{
		stock[i].accept_item();
	}

}
void purchase::display_stock()
{

	int i=0;
	cout<<"\n No of items are: "<<nitem;
	for(i=0;i<nitem;i++)
	{
		stock[i].display_item();
	}
}

void purchase::get_purchase()
{
	int i=0;
	int j=0;
	cout<<"\n Enter no of customers ";
	cin>>ncust;
	for(i=0;i<ncust;i++)//loop for customers
	{
		cout<<"\n Customer "<<i+1;
		for(j=0;j<nitem;j++)//loop for items
		{
			cout<<"\n For item "<<j+1;
			do
			{
			    cout<<"\n Enter quantity purchased: ";
			    cin>>cust[i][j];
			    //if quantity purchased entered is more than quantity available enter again
			    if(stock[j].available_quantity<cust[i][j])
			    {
			        cout<<"\n Available quantity = "<<stock[j].available_quantity;
			        cout<<"\n Enter quantity purchased again";
			    }
			}while(stock[j].available_quantity<cust[i][j]);
			stock[j].available_quantity=stock[j].available_quantity-cust[i][j];//change quantity available after each purchase
		}
	}
}

void purchase::display_purchase()//displays the purchase details for each customer
{
	int i=0;
	int j=0;
	for(i=0;i<ncust;i++)
	{
		cout<<"\n Customer "<<i+1;
		for(j=0;j<nitem;j++)
		{
			cout<<"\n Quantity purchased for stock "<<stock[j].name;
            cout<<" = "<<cust[i][j]<<" kg";
		}
	}
}
void purchase::top_cust()//displays the top Customer of the day
{
    int i=0;
    int j=0;
    double total;
    int ncust1=0;
    double max=0.0;
    for(i=0;i<ncust;i++)
    {
        total=0.0;
        for(j=0;j<nitem;j++)
        {
            total=total+(stock[j].price*cust[i][j]);//total amount of each customer
        }
        
        if(total>max)//comparing total of the customer with max
        {
            max=total;
            ncust1=i+1;
        }
    }
    cout<<"\n Customer with highest bill is Customer no "<<ncust1<<" with a total of Rs "<<max;
}
void purchase::highest_item()
{
    int i=0;
    int max=0;
    int cst_no=0;
    int itemno1=0;
    cout<<"\n Enter Customer no whose highest item is to be displayed";
    cin>>cst_no;
    for(i=0;i<nitem;i++)//loop for items
    {
        if(cust[cst_no-1][i]>max)//since customer no is taken from user
        {
            max=cust[cst_no-1][i];
            itemno1=stock[i].itemno;
        }
    }
    cout<<"\n Item no of highest purchase = "<<itemno1;
    cout<<"\n Quantity= "<<max;
}
void purchase::highest_quantity()
{
    int i=0;
    int j=0;
    int max=0;
   
    for(j=0;j<nitem;j++)//loop for items
    {
        i=0;
        max=cust[i][j];
        for(i=0;i<ncust;i++)//loop for customers
        {
            if(cust[i][i]>max)//comparing quantity
            {
                max=cust[i][j];
            }
        }
        cout<<"\n Highest quantity of the item "<<stock[j].name<<" is "<<max;
        
    }
}
void purchase::highest_item1()
{
    int i=0;
    int j=0;
    int max=0;
    int total=0;
    char *name1;
    for(j=0;j<nitem;j++)
    {
        i=0;
        total=0;
        for(i=0;i<ncust;i++)
        {
            total=total+cust[i][i];//calculating total quantity
            
        }
        if(total>max)//comparing total quantity with max
        {
            max=total;
            name1=stock[j].name;//storing name of highest item
        }
    }
    cout<<"\n The highest item purchased in the entire day is "<<name1<<" whose quantity = "<<max;
}
void purchase::display_bill1()//for all customers
{
    int i=0;
    int j=0;
    double total=0.0;
    for(i=0;i<ncust;i++)
    {
        total=0.0;
        cout<<"\n For customer "<<i+1;
        cout<<"\n Item ";
        cout<<"\t Quantity ";
        cout<<"\t Price ";
        cout<<"\t\t Amount ";
        for(j=0;j<nitem;j++)
        {
            cout<<"\n "<<stock[j].name;
            cout<<"\t "<<cust[i][j]<<" kgs ";
            cout<<"\t\t Rs "<<stock[i].price;
            cout<<"\t\t Rs "<<(cust[i][j]*stock[j].price);
            total=total+(cust[i][j]*stock[j].price);
        }
        cout<<"\n-----------------------------------------------------------------------";
        cout<<"\n Total = Rs "<<total;
    }
}
void purchase::display_bill()//for one customer
{
    int i=0;
    int j=0;
    int cst_no=0;
    double total=0.0;
    cout<<"\n Enter Customer no whose bill is to be displayed ";
    cin>>cst_no;
    cout<<"\n Item ";
    cout<<"\t Quantity ";
    cout<<"\t Price ";
    cout<<"\t\t Amount ";
    for(i=0;i<nitem;i++)
    {
        cout<<"\n "<<stock[i].name;
        cout<<"\t "<<cust[cst_no-1][i]<<" kgs ";
        cout<<"\t\t Rs "<<stock[i].price;
        cout<<"\t\t Rs "<<(cust[cst_no-1][i]*stock[i].price);
        total=total+(cust[cst_no-1][i]*stock[i].price);
    }
    cout<<"\n-----------------------------------------------------------------------";
    cout<<"\n Total = Rs "<<total;
}
int main()
{
	purchase ob1;
	int choice=0;
	do
	{
	    do
	    {
	        cout<<"\n Menu";
	        cout<<"\n 1.Accept stock details";
	        cout<<"\n 2.Display stock details";
	        cout<<"\n 3.Accept purchase details";
	        cout<<"\n 4.Display purchase details";
	        cout<<"\n 5.Display Customer with highest bill ";
	        cout<<"\n 6.Display quantity of highest item purchased by a customer";
	        cout<<"\n 7.Display highest quantity of each item purchased ";
	        cout<<"\n 8.Display highest item purchased in the entire day";
	        cout<<"\n 9.Display bill of all customers";
	        cout<<"\n 10.Display bill of a customer";
	        cout<<"\n 0.Exit";
	        cout<<"\n Enter choice ";
	        cin>>choice;
	        
	    }while(choice<0 && choice>10);
	    switch(choice)
	    {
	        case 1: ob1.get_stock();
	                break;
	        case 2: ob1.display_stock();
	                break;
	        case 3: ob1.get_purchase();
	                break;
	        case 4: ob1.display_purchase();
	                break;
	        case 5: ob1.top_cust();
	                break;
	        case 6: ob1.highest_item();
	                break;
	        case 7: ob1.highest_quantity();
	                break;
	        case 8: ob1.highest_item1();
	                break;
	        case 9: ob1.display_bill1();
	                break;
	        case 10: ob1.display_bill();
	                break;
	        case 0: cout<<"\n End of program. Thank you";
	                break;
	        default:cout<<"Invalid input,enter again";
	                break;
	    }
	}while(choice!=0);
	
}
/*
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 1

 Enter no of items 2

 Enter item number 1

 Enter name of item wheat

 Enter price 20

 Enter available quantity 3

 Enter item number 2

 Enter name of item rice

 Enter price 10

 Enter available quantity 3

 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 2

 No of items are: 2
 Item number: 1
 Name of item: wheat
 Price: Rs 20
 Available quantity: 3 kg
 Item number: 2
 Name of item: rice
 Price: Rs 10
 Available quantity: 3 kg
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 3

 Enter no of customers 2

 Customer 1
 For item 1
 Enter quantity purchased: 4

 Available quantity = 3
 Enter quantity purchased again
 Enter quantity purchased: 2

 For item 2
 Enter quantity purchased: 1

 Customer 2
 For item 1
 Enter quantity purchased: 1

 For item 2
 Enter quantity purchased: 1

 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 4

 Customer 1
 Quantity purchased for stock wheat = 2 kg
 Quantity purchased for stock rice = 1 kg
 Customer 2
 Quantity purchased for stock wheat = 1 kg
 Quantity purchased for stock rice = 1 kg
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 5

 Customer with highest bill is Customer no 1 with a total of Rs 50
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 6

 Enter Customer no whose highest item is to be displayed1

 Item no of highest purchase = 1
 Quantity= 2
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 7

 Highest quantity of the item wheat is 2
 Highest quantity of the item rice is 1
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 8

 The highest item purchased in the entire day is wheat whose quantity = 3
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 9

 For customer 1
 Item 	 Quantity 	 Price 		 Amount 
 wheat	 2 kgs 		 Rs 20		 Rs 40
 rice	 1 kgs 		 Rs 20		 Rs 10
-----------------------------------------------------------------------
 Total = Rs 50
 For customer 2
 Item 	 Quantity 	 Price 		 Amount 
 wheat	 1 kgs 		 Rs 10		 Rs 20
 rice	 1 kgs 		 Rs 10		 Rs 10
-----------------------------------------------------------------------
 Total = Rs 30
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 10

 Enter Customer no whose bill is to be displayed 1

 Item 	 Quantity 	 Price 		 Amount 
 wheat	 2 kgs 		 Rs 20		 Rs 40
 rice	 1 kgs 		 Rs 10		 Rs 10
-----------------------------------------------------------------------
 Total = Rs 50
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 14
Invalid input,enter again
 Menu
 1.Accept stock details
 2.Display stock details
 3.Accept purchase details
 4.Display purchase details
 5.Display Customer with highest bill 
 6.Display quantity of highest item purchased by a customer
 7.Display highest quantity of each item purchased 
 8.Display highest item purchased in the entire day
 9.Display bill of all customers
 10.Display bill of a customer
 0.Exit
 Enter choice 0

 End of program. Thank you*/



