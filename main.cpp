#include <iostream>
#include "BankAccount.h"
#include "CheckingAccount.h"

int main() {  // sandbox to play with objects
    // std::cout<<"\n------------------BANK--------------------\n";
    // //VstaticV - autodestroyed
    // BankAccount customer1("Mick Mouse","1234567",2350.50);
    // customer1.display();
    // customer1.withdraw(500);
    // customer1.display();
    // //VdynamicV - we must delete it
    // BankAccount*  customer2 = new BankAccount("Don Duck","7654321",1250.75);
    // customer2->display();
    // delete customer2;
    std::cout<<"\n------------------CHECK-------------------\n";
    CheckingAccount customer3("Minnie Mouse","3456789",3000.00,300.00);
    customer3.display();
    customer3.withdraw(3200);
    customer3.display();
    BankAccount* customer4 = new CheckingAccount ("Daisy Duck","9876543",1000.00,200.00);
    customer4->display();
    customer4->withdraw(1100);
    customer4->display();
    delete customer4;
    return 0;
}
