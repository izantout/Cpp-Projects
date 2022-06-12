#include "bankAccount.h"
#include <iostream>

using namespace std;

   /**
      Constructs a bank account with a $2000 balance.
   */
   BankAccount::BankAccount(string mid){
     set_id(mid);
     balance = 2000;
   }
   /**
      Deposits money into this account.
      @param amount the amount to deposit.
   */
   void BankAccount::deposit(double amount){
     balance += amount;
   }
   /**
      Withdraws money from this account.
      @param amount the amount to withdraw.
   */
   void BankAccount::withdraw(double amount){
     balance -= amount;
   }
   /**
      Gets the balance of this account.
      @return the balance
   */
   double BankAccount::get_balance() const{
     return balance;
   }
   /**
     Gets the id of this account.
     @return the balance
  */
    string BankAccount::get_id() const{
      return id;
    }
   /**
     Set id for bank account.
     @return the balance
  */
    void BankAccount::set_id(string mid){
      id = mid;
    }
