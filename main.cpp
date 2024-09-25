#include "Calculation.h"
#include <iostream>
#include <list>

int askIfContinue(int, int, const std::list<Calculation*>&);

int main(){
    int shouldWeContinue = 0;
    std::list<Calculation*> calcs;

    do
    {
        Calculation* calc = new Calculation;
        calc->setOperation();
        calc->setOperands();
        calc->doCalculation();
        calc->printSolution();
        calcs.push_back(calc);
        shouldWeContinue = askIfContinue(shouldWeContinue, calcs.size(), calcs);
    } while (shouldWeContinue != 1);
    
}

int askIfContinue(int shouldWeContinue, int lengthOfCalcs, const std::list<Calculation*>& calcs) {
    std::cout << "\nDo you want to continue (y/n)? ";
    char c = 'y';
    std::cin >> c;
    if (c == 'n')
    {
        shouldWeContinue = 1;
        std::cout << "Here are your calculations: ";
        std::cout << "\n";
        for (const Calculation* calc : calcs)
        {
            switch(calc->operation) {
            case 'A':
            case 'a':
                std::cout << calc->operand_1 << "+" << calc->operand_2 << "=" << calc->solution;
                break;
            case 'S':
            case 's':
                std::cout << calc->operand_1 << "-" << calc->operand_2 << "=" << calc->solution;
                break;
            case 'D':
            case 'd':
                std::cout << calc->operand_1 << "/" << calc->operand_2 << "=" << calc->solution;
                break;
            case 'M':
            case 'm':
                std::cout << calc->operand_1 << "*" << calc->operand_2 << "=" << calc->solution;
                break;
            default:
                break;
            }

            std::cout << "\n";

            delete calc;
        }
        
    } else {
        shouldWeContinue = 0;
    }
    
    return shouldWeContinue;
}