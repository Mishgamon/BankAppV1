//
// Created by Mishael Garrett on 10/22/26.
//

#ifndef BANKAPPV1_CHECKINGACCOUNT_H
#define BANKAPPV1_CHECKINGACCOUNT_H
#include "BankAccount.h"
#include "iostream"
class CheckingAccount: public BankAccount{
private:
    double m_overdraftLimit;
public:
  CheckingAccount(const std::string &accHolder, const std::string &accNum, double balance, double overdraftLimit):BankAccount(accHolder, accNum, balance) {
      m_overdraftLimit = overdraftLimit;
  };
    ~CheckingAccount() {//RIP
        std::cout<<"\nCheckingAccount object deconstructed\n";
    }
    bool withdraw(double amount) {
        if (amount <= m_balance + m_overdraftLimit) {
            if (amount > m_balance) {
                m_overdraftLimit-=(amount-m_balance);
                m_balance -=amount;

            }
            else m_balance-=amount;
            return true;
        }
        if (m_balance<0 && amount <= m_overdraftLimit) {
            m_overdraftLimit-=amount;
            m_balance-=amount;
            return true;
        }
        return false;
    }
    void display() {
        BankAccount::display();
        std::cout<<"Overdraft Limit: $"<<m_overdraftLimit<<std::endl;
    }
};
#endif //BANKAPPV1_CHECKINGACCOUNT_H
