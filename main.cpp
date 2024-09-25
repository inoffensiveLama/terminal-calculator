#include "Calculation.h"
#include <iostream>
#include <list>

int askIfContinue(int, int, const std::list<Calculation*>&);

int main(){
    //Variable to see if the user wants to continue
    int shouldWeContinue = 0;
    //list of calculations
    std::list<Calculation*> calcs;

    //loop to go over the steps: getting operands and operation, doing the calculation, printing it out and then adding it to a list and asking if the user wants to continue
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


//function to ask the user if they want to continue, also if they dont all previous calculations are being printed out.
int askIfContinue(int shouldWeContinue, int lengthOfCalcs, const std::list<Calculation*>& calcs) {
    //printing out the question and storing the answer as a char
    std::cout << "\nDo you want to continue (y/n)? ";
    char c = 'y';
    std::cin >> c;
    if (c == 'n')
    {
        //if they dont want to continue we will iterate over each previous calculation and printing them out with the corresponding symbol
        shouldWeContinue = 1;
        std::cout << "Here are your calculations: ";
        std::cout << "\n";
        for (const Calculation* calc : calcs)
        {
            switch(calc->operation) {
                //addition
            case 'A':
            case 'a':
                std::cout << calc->operand_1 << "+" << calc->operand_2 << "=" << calc->solution;
                break;
                //subraction
            case 'S':
            case 's':
                std::cout << calc->operand_1 << "-" << calc->operand_2 << "=" << calc->solution;
                break;
                //division
            case 'D':
            case 'd':
                std::cout << calc->operand_1 << "/" << calc->operand_2 << "=" << calc->solution;
                break;
                //multiplication
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
    //return if the user wants to continue or not
    return shouldWeContinue;
}