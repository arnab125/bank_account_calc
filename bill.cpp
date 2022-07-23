#include <iostream>
using namespace std;

class BankAccount
{
public:
    int age;
    string accountholder;
    string address;
    int account_number;
protected:
    int balance;
private:
    string password;
public:
    BankAccount(string accountholder,string address,int age,string password)
    {
      this->accountholder=accountholder;
      this->address=address;
      this->age=age;
      this->password=password;
      this->account_number=rand()%1000000000;
      this->balance=0;
      cout<<"Accoount num= "<<this->account_number<<endl;
    }
    int show_balance(string password)
    {
        if(this->password==password)
        {
            return this->balance;
        }
        else
        {
            return -1;
        }
    }
    void add_money(string password,int ammount)
    {
        if(ammount<0)
        {
            cout<<"invalid ammount"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance+=ammount;
            cout<<"success"<<endl;
        }
        else{
            cout<<"Failed"<<endl;
        }
    }
    void deposit_money(string password,int ammount)
    {
        if(ammount<0)
        {
            cout<<"invalid ammount"<<endl;
            return;
        }
        if(this->balance <ammount)
        {
            cout<<"insufficient balance"<<endl;
            return;
        }
        {
            cout<<"invalid ammount"<<endl;
            return;
        }
        if(this->password==password)
        {
            this->balance-=ammount;
            cout<<"success"<<endl;
        }
        else{
            cout<<"Failed"<<endl;
        }
    }
    friend class Mycash;
};
class Mycash
{
protected:
    int balance;
public:
    Mycash()
    {
        this->balance=0;
    }
    void add_money_from_bank(BankAccount *myAccount,string password,int ammount)
    {
        if(ammount<0)
        {
            cout<<"invalid ammount"<<endl;
            return;
        }
        if(myAccount->balance<ammount)
        {
            cout<<"insufficient balance"<<endl;
        }
        {
            cout<<"invalid ammount"<<endl;
            return;
        }
        if(myAccount->password == password)
        {
        this->balance+=ammount;
        myAccount->balance-=ammount;
        cout<<"Add money from bank is successful"<<endl;
        }
        else{
            cout<<"failed"<<endl;
        }
    }
    int show_balance()
    {
        return balance;
    }
};
BankAccount* create_account()
{
    string accountholder,password,address;
    int age;
    cout<<"Create Account"<<endl;
    cin>>accountholder>>address>>age>>password;
    BankAccount *myAccount=new BankAccount(accountholder,address,age,password);
    return myAccount;
}
void add_money(BankAccount *myAccount)
{
    string password;
    int ammount;
    cout<<"ADD MONEY"<<endl;
    cin>>password,ammount;
    myAccount->add_money(password,ammount);
    cout<<"Balance is "<<myAccount->show_balance("abc")<<endl;
}
void deposit_money(BankAccount *myAccount)
{
    string password;
    int ammount;
    cout<<"Deposit MONEY"<<endl;
    cin>>password,ammount;
    myAccount->deposit_money(password,ammount);
    cout<<"Balance is "<<myAccount->show_balance("abc")<<endl;
}
void add_money_from_bank(Mycash *mycash,BankAccount *myAccount)
{
    string password;
    int ammount;
    cout<<"Add money from bank"<<endl;
    cin>>password>>ammount;
    mycash->add_money_from_bank(myAccount,password,ammount);
    cout<<"Mycash balance :"<<endl;
}

int main()
{
   BankAccount *myAccount = create_account();
   Mycash *mycash = new Mycash();
   Flag:
       cout<<"Select options :"<<endl;
       cout<<"Add money to bank"<<endl;
       cout<<"Deposit money from bank"<<endl;
       cout<<"Add money from mycash from bank"<<endl;
       int option;
       cin>>option;
       if(option==1)
       {
           add_money(myAccount);
       }
       else if(option==2)
       {
           deposit_money(myAccount);
       }
       else if(option==3)
       {
            add_money_from_bank(mycash,myAccount);
       }
       else
       {
           cout<<"invalid option"<<endl;
       }
       goto Flag;
    return 0;
}
