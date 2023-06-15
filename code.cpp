
#include <iostream>

using namespace std;
class Item{
private:
    int quantity,price;
    string name;
    int ID;
public:
    static int num_of_items;
    //default constructor
    Item(){
    quantity=0;
    price=0;
    name="no name";
    ID=num_of_items;
    num_of_items++;

    }

    //parameterized constructor
    Item(int q,int p,string n){
    quantity=q;
    price=p;
    name=n;
    ID=num_of_items;
    num_of_items++;

    }

    //copy constructor
    Item(const Item& obj){
    name=obj.name;
    price=obj.price;
    quantity=obj.quantity;
    ID=num_of_items;
    num_of_items++;
    }

    void set_name(string  n){name=n;}
    string get_name(){return name;}
    void set_price(int p){price=p;}
    int get_price(){return price;}
    void set_quantity(int q){quantity=q;}
    int get_quantity(){return quantity;}

    bool operator==(Item obj){
    return (name==obj.name);
   }

   void operator+=(Item obj){
   quantity+=obj.quantity;
   }
    void operator-=(int x){
   quantity-=x;
   }
   friend istream&operator>>(istream&in,Item&obj){
   in>>obj.name>>obj.price>>obj.quantity;
   return in;
   }
   friend ostream&operator<<(ostream&out,Item&obj){
   out<<"name: "<<obj.get_name()<<"  "<<"price: "<<obj.get_price()<<"  "<<"quantity: "<<obj.get_quantity()<<endl;
   return out;
   }
 friend class Seller;
};

//******************************************************************************************************

class Seller{
private:
    string email,seller_name;
    int max_items;
    Item *items;
public:
    //parameterize constructor
   Seller(string n="no name",string e="no mail",int m=0){
   seller_name=n;
   email=e;
   max_items=m;
       items= new Item[max_items];
   }

   void set_max_items(int x){
   max_items=x;
   }

   friend istream&operator>>(istream&in,Seller&obj){
   in>>obj.seller_name>>obj.email;
   return in;}

   friend ostream&operator<<(ostream&out,Seller&obj){
   out<<obj.seller_name<<"  "<<obj.email<<"  "<<endl;
   return out;}

bool Add_An_Item(Item obj){
    if (Item::num_of_items<max_items){

        for(int i=0;i<Item::num_of_items;i++){
        if(items[i]==obj)
          items[i]+=obj;
        else
          items[Item::num_of_items]==obj;
        }
        return true;
    }

     else
        return false;

}









bool Sell_An_Item(string name,int q){
for(int i=0;i<max_items;i++){
        if (items[i].name==name){

              if(q<=items[i].quantity)
                 items[i]-=q;
           else
              cout<<"There is only {"<<q<<"} left for this item"<<endl;

              return true;
        }

}
return false;


};


void print_items(){
for(int i=0;i<max_items;i++){
    cout<<items[i];}
}

Item Find_an_Item_by_ID(int id){
for(int i=0;i<max_items;i++){
    if(items[i].ID==id)
    {
        return items[i];
    }
    cout<<"this id is not exist";}
}

~Seller(){
delete [] items;
}

};

int Item::num_of_items=1;

int main()
{
    int x;
    string n;
    Seller seller;
    Item item;
    cout<<"please enter your name and email: "<<endl;
    cin>>seller;
    cout<<"please enter maximum number of items: "<<endl;
    cin>>x;
    seller.set_max_items(x);
    cout<<" 1. Print My Info. \n 2. Add An Item. \n 3. Sell An Item. \n 4. Print Items. \n 5. Find an Item by ID \n 6. Exit \n";

    while(true){
        cout<<"please choose number \n";
        cin>>x;
    if(x==1) cout<<seller;
    else if(x==2) seller.Add_An_Item(item);
    else if(x==3){
        cout<<"please enter the item name and quantity: \n";
        cin>>n>>x;
        seller.Sell_An_Item(n,x);
    }
    else if(x==4) seller.print_items();
    else if(x==5)
    {
        cout<< "please enter the id: \n";
        cin>>x;
        seller.Find_an_Item_by_ID(x);
    }
    else if(x==6) return 0;

    }

}







