#include <iostream>
using namespace std;

class item{
int id;
    public:
    
item*next;
string name;
float price;
int stock;
int getid(){
    return id;
}
void setid(int m){
    id = m;
}
void getdata(){
    cout<<"The name of the item is :"<<name<<endl;
    cout<<"The Price of the item is :"<<price<<endl;
    cout<<"The number of items in the stock is :"<<stock<<endl;

}
void setdata(string s,float m,int stck){
    name = s;
    price = m;
    stock = stck; 

}
void alert(item*i,int n);

};
class inventory{
    public:
    int size;//size of inventory
    item*head;
    item*tail;
   

inventory() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~inventory() {
        // Destructor to delete all items in the inventory
        item* current = head;
        while (current != NULL) {
            item* nextItem = current->next;
            delete current;  // Free the memory for the current item
            current = nextItem;  // Move to the next item
        }
        cout << "Inventory deleted. All items freed from memory." << endl;
    }

    
};
void delete1(item**z,inventory*in){
    if(in->head==NULL){
        cout<<"EMPTY"<<endl;

    }
    else if(*z == in->head){
        
    }

 else if(*z!=NULL && (*z)->next != NULL){item*y = ((*z))->next;

    (*z)->next=(((*z))->next)->next; 
  
    delete(y);
      in->size++;
    }
    else{
        cout<<"Empty inventory";
    }

}
void display(item*i){

    if(i!=NULL){while(i != NULL){
        i->getdata();
        i = i->next;
    }
    }
}
void item:: alert(item*i,int n){
 
    while(i != NULL){//alert case is 10 items
        if(i->stock <10){
            cout<<"The amount of"<<i->name<<"is less in stock ,please buy more!"<<endl;
          

        }
          i = i->next;
    }
}
item*reachtail(item*h){
    item*tail = h;

    while(tail->next!=NULL){
        tail = tail->next;
    }
  
return tail;


}
void additem(item*i,item*it,inventory*in){
   if(i!=NULL){item*tail = reachtail(i);
    tail->next = it;
    it->next = NULL;}
    else{
        i = it;
    }
      in->size--;
}
int main(){

    inventory*dukaan = new inventory();
   
    item*start = new item();
    item*start1 = new item();
    item*start2 = new item();
    start->setid(13333);
    start->name = "Mile";
    start->price = 1000000000;
    start->stock = 19;
    start->next = start1;
    start->getdata();


    
    start1->setid(13334);
    start1->name = "Mile1";
    start1->price = 1000000001;
    start1->stock = 15;
    start1->next = start2;
    start2->next = NULL;
    start1->getdata();
 dukaan->head = start;
 dukaan->tail = start2;
 delete(dukaan);
 delete(start);
 delete(start1);
 delete(start2);

    return 0;
}