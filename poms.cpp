/*****************************************************************************************************
 *                            TATA.COM PURCHASE ORDER MANAGEMENT SYSTEMS
 ******************************************************************************************************/

/****************************************
 * Included Files
 ***************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <stdlib.h>
#include <set>

using namespace std;
/*****************************************
 *         USER CLASS
 *****************************************/
class User{
    /**************
     *  DATA MEMBERS
     **************/
    protected:
        std::string username, password, u, p;
    
    /****************
     * PUBLIC FUNCTIONS
     * **************/
    public:
         void SetLogins(std:: string s1, std:: string s2);
        void Login();
};
 /****************************************
  * DEFINE USER CLASS PUBLIC FUNCTIONS
  * **************************************/
  /****************************************
  * SetLogins(): PUBLIC FUNCTIONS
  * **************************************/
 void User :: SetLogins(std:: string s1, std:: string s2){
    u = s1;
    p = s2;
    //std::cout<<u<<"\t"<<p;
}
 /****************************************
  * DEFINE USER CLASS PUBLIC FUNCTIONS
  * **************************************/
void User::Login(){
    system("cls");
   std::cout<<"\n \t\t\t\tEnter your username and password to continue!"<<" ";
    std::cout<<"\n \t\t\t\t USERNAME: ";
    std::cin>>username;
    std::cout<<" \n \t\t\t\t PASSWORD: ";
    std::cin>>password;
    if(u == username && p == password){
        std::cout<<"\n"<<"\t\tYou have successfully Logged into the system!"<< " ";
        system("pause");
    }else{
        std::cout<<"\n \t\tAccess Denied! Unauthorized credentials! Please try again!!"<<" ";
        system("pause");
        Login();
    }
}
/*****************************************
 *         PURCHASE CLASS
 *****************************************/
class Purchase {
    /**************
     *  DATA MEMBERS
     **************/
    protected:
        /*********************************
         * PRE- HARD CODED ORDERS
         *********************************/
        std:: set<std::string> uniqueElement;
        std:: vector <vector <std::string>> orders =
        {
            {"Fridge", "Qnty : 5", "order_date: 2022-07-01", "order_id: 1", "customer_name: nathan" },
            {"cooker", "Qnty : 3", "order_date: 2022-07-02", "order_id: 2", "customer_name: bucky" },
            {"Frying_pan", "Qnty : 1", "order_date: 2022-07-03", "order_id: 3", "customer_name: robert" },
            {"Washing_machine", "Qnty : 1", "order_date: 2022-07-04", "order_id: 4", "customer_name: ontario" },
            {"fridge", "Qnty : 1", "order_date: 2022-07-05", "order_id: 5", "customer_name: joe" },
            {"fridge", "Qnty : 3", "order_date: 2022-07-06", "order_id: 6", "customer_name: geovane" },
            {"home_theatre", "Qnty : 1", "order_date: 2022-07-07", "order_id: 7", "customer_name: collins" },
            {"cooker", "Qnty : 1", "order_date: 2022-07-08", "order_id: 8", "customer_name: abdi" },
            {"cooker", "Qnty : 3", "order_date: 2022-07-09", "order_id: 9", "customer_name: rama" },
            {"fridge", "Qnty : 1", "order_date: 2022-07-10", "order_id: 10", "customer_name: peter" },
            {"home_theatre", "Qnty : 1", "order_date: 2022-07-11", "order_id: 11", "customer_name: gracei" },
            {"fridge", "Qnty : 5", "order_date: 2022-07-01", "order_id: 1", "customer_name: mercy" },
            {"mattress", "Qnty : 7", "order_date: 2022-07-12", "order_id: 12", "customer_name: nashon" },
            {"cup_board", "Qnty : 1", "order_date: 2022-07-13", "order_id: 13", "customer_name: irinee" },
            {"dinning_set", "Qnty : 5", "order_date: 2022-07-14", "order_id: 14", "customer_name: synthia" }
        
        };
       /****************
     * PUBLIC FUNCTIONS
     * **************/
    public:
        void DisplayPurchase();
        void UpdatePurchase();
        void SortPurchase();
        void SearchPurchase();
        void SalesReport();
        void RemoveItem();
};

 /****************************************
  * DEFINE USER CLASS PUBLIC FUNCTIONS
  * **************************************/
 /*****************************************
  * DisplayPurchase()
  *****************************************/
void Purchase::DisplayPurchase(){
    for(int i=0; i<orders.size(); i++){
        for(int j= 0; j<orders[i].size(); j++){
        std::cout<<orders[i][j]  << " ";
        }
        std::cout<<"\n" << std::endl;
    }
}
 /*****************************************
  * UpdatePurchase()
  * 
  * ********NOTE: ***************************
  * In the Systems, Users are only allowed to
  *  update the quantityfiled of the orders
  * 
  * User can only have one pending purchase at a time;
  * No user can have more than one pending purchase at a time
  * in this system.
  * 
  *****************************************/
 void Purchase::UpdatePurchase(){
    std:: string nameOfCustomerToUpdate;
    std:: string newQuantity;
    std::cout<<"\n Enter the customer name whom you  wish to update their order :" << std::endl;
    std:cin>>nameOfCustomerToUpdate;
    for(int i=0; i<orders.size(); i++){
        for(int j=0; j< orders[i].size(); j++){
            if(orders[i][j] == "customer_name: " + nameOfCustomerToUpdate)
                {
                    std::cout<<"\n The current quantity for : "<<nameOfCustomerToUpdate << " order for: "<<orders[i][j-4]<<" ," <<" is :"<<orders[i][j-3]  << std::endl;
                    std::cout<<"\n Enter the new quantity : "<< std::endl;
                    std::cin>> newQuantity;
                    orders[i][j-3] = "Qnty : " + newQuantity;
                    std::cout <<"Order updated successfully \n";
            }
        } 
    }
 }
 /*****************************************
 * PUBLIC FUNCTIONS
 * ***************************************/
/*****************************************
 * SORTING FUCTIONS: Sort BY FIRST COLUMN
 * ***************************************/
bool SortByColumn(std:: vector<std::string>& v1, std:: vector<std::string>& v2){
        return  v1[0] > v2[0];
}
  /*****************************************
  * SortPurchase()
  *****************************************/
 void Purchase::SortPurchase() {
    std::string tmp;
    std :: string orderName;
    /*****************************************
     * SORTING THE PURCHASE ORDERS
     * [[[0]]]
     * ****************************************/
    sort(orders.begin(), orders.end(), SortByColumn);
    /*****************************************
     * DISPLAYING SORTED ORDER
     * ***************************************/
    for(int k = 0; k < orders.size(); k++){
      for(int n = 0; n < orders[k].size(); n++){
            std::cout << orders[k][n]  << " "; 
        }
        std::cout<< std::endl;
    }
 }
   /*****************************************
  * SearchPurchase()
  *****************************************/
 void Purchase::SearchPurchase(){
    std:: string itemToSearch;
    std::cout<<"\n Enter the item to search for... : "<<std::endl;
    std:cin >> itemToSearch;
    sort(orders.begin(), orders.end(), SortByColumn);
    std::cout<<"\n Search result: ";
    for(int k = 0; k < orders.size(); k++){
        if(orders[k][0] == itemToSearch){
            for(int n = 0; n < orders[k].size(); n++){
                std::cout<<"\n"<<orders[k][n]<<" ";
                break;
            }
            std::cout<<std::endl;
        }
    }
 }
/*****************************************
  * SalesPurchase()
*****************************************/
 void Purchase::SalesReport() {
    std::vector <std::string> newList;
    int totalOrders = orders.size();
    int counter;
    std:: cout<<"\n Total Orders: "<<totalOrders;
    std:: cout<<"\n Frequently ordered items are: ";
    for(int j=0; j< orders.size(); j++){
         newList.push_back(orders[j][0]);
    }
    std:: cout<<"\n"<<newList.size()<<" items are frequently ordered"<<std::endl;
    std:: cout<<"\n The following items are frequently ordered"<<std::endl;
    for(auto el= newList.begin(); el !=newList.end(); el++){
        int counter = count(newList.begin(), newList.end(), *el);
    }
    std::copy(newList.begin(), newList.end(), inserter(uniqueElement, uniqueElement.end()));
    for (auto items = uniqueElement.cbegin(); items != uniqueElement.cend(); items++)
        {
           std::cout << "\n \n"<<*items << "\t " << counter  << " times.\n";
        }
 }
/*****************************************
  *SortSales()
  *****************************************/

/*****************************************
 *         ADMINISTRATION CLASS
 *****************************************/
class Administration : public User, public Purchase {
      /******************************
     * username: admin,
     * password: admin
     * ****************************/

      
};
/*****************************************
 *         SALES EXECUTIVE CLASS
 *****************************************/
class Salesexecutive : public User ,public Purchase{
    /******************************
     * username: sales,
     * password: sales
     * ****************************/
};
/*****************************************
 *         MAIN PROGRAM
 *****************************************/
int main(){
     Administration admin;
     Salesexecutive sales;
     int res;
     int ch1 = -1;
     std:: cout<<"\n*****************************************************************************************************";
     std::cout<<"\n*****************---WELCOME TO TATA.COM PURCHASE ORDER MANAGEMENT SYSTEM---*************************";
     std::cout<<"\n*****************************************************************************************************";
     std: cout<<"\n \t\t\t\t To Continue, please \n \t\t\t\t 1. Admin \n  \t\t\t\t 2. Sales executive \n \t\t\t\t ";
     std::cout<<"\n\t\t\t\t Enter your choise : ";
     std::cin >> res;
     if(res == 1){
         admin.SetLogins("admin", "admin");
         admin.Login();
         while(1){
         system("cls");
         std::cout<<"\n \t\t PURCHASE ORDER MANAGEMENT SYSTEM";
         std::cout<<"\n \t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
         std::cout<<"\n \t\t 1 -> Display orders.";
         std::cout<<"\n \t\t 2 -> Modify orders.";
        std::cout<<"\n \t\t 3 -> Sort  orders.";
        std::cout<<"\n \t\t4 -> Search an order";
        std::cout<<"\n \t\t5 -> Sales report";
        cout<<"\n \t\t6 -> Logout.";
        cout<<"\n\t\t Enter your choice: ";
        cin>>ch1;
        switch(ch1){
            case 1: //Display order
                system("cls");
                admin.DisplayPurchase();
                break;
            case 2: //Modify order.
                system("cls");
                admin.UpdatePurchase();
                break;
            case 3://Sort order.
                system("cls");
                admin.SortPurchase();
                break;
            case 4: //Search.
                system("cls");
                admin.SearchPurchase();
                break;
            case 5://Sales report.
                system("cls");
                admin.SalesReport();
                break;
            default:
                exit(1);
            } //end of switch.
        getch();
        } //end of while.
    }
    if(res == 2){
        sales.SetLogins("sales", "sales");
        sales.Login();
        while(1){
        system("cls");
        std::cout<<"\n \t\t PURCHASE ORDER MANAGEMENT SYSTEM";
        std::cout<<"\n \t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        std::cout<<"\n \t\t 1 -> Display orders.";
        std::cout<<"\n \t\t 2 -> Modify orders.";
        std::cout<<"\n \t\t 3 -> Sort  orders.";
        std::cout<<"\n \t\t4 -> Search an order";
        cout<<"\n \t\t5 -> Logout.";
        cout<<"\n Enter your choice: ";
        cin>>ch1;
        switch(ch1){
            case 1: //Display order
                system("cls");
                sales.DisplayPurchase();
                break;
            case 2: //Modify order.
                system("cls");
                sales.UpdatePurchase();
                break;
            case 3: //Sort order.
                system("cls");
                sales.SortPurchase();
                break;
            case 4: //Search.
                system("cls");
                sales.SearchPurchase();
                break;
            default:
                exit(1);
            } //end of switch.
        getch();
        } //end of while.
    }else{
        std::cout<<"Invalid Input!! "<<" Please Try Again.!!!!!!!"<<std::endl;;
        main();
    }
    return 0;
}