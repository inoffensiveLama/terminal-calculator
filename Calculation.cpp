#include <iostream>
#include "Calculation.h"

//constructor for the calculation class
Calculation::Calculation() : operand_1(0), operand_2(1), solution(0), operation('M') {}

    //do calculation function it checks which operation should be performed and stores the result in the variable solution
    void Calculation::doCalculation(){
        switch(this->operation) {
            //addition
        case 'A':
        case 'a':
            this->solution = this->operand_1 + this->operand_2;
            break;
            //subtraction
        case 'S':
        case 's':
            this->solution = this->operand_1 - this->operand_2;
            break;
            //division
        case 'D':
        case 'd':
            if (this->operand_2 != 0)
            {
                this->solution = this->operand_1 / this->operand_2;
            } else {
                std::cout << "You can't divide by 0\n";
                this->setOperands();
                this->doCalculation();
            }
            break;
            //multiplication
        case 'M':
        case 'm':
            this->solution = this->operand_1 * this->operand_2;
            break;
        default:
            break;
        }
    }


    //asking the user for which operation should be performed and saving the character in a variable.
    void Calculation::setOperation(){
        std::cout << "What kind of operation would you like to do? [A]ddition, [S]ubtraction, [D]ivision or [M]ultiplication? ";
        std::cin >> operation;
        switch(this->operation) {
            //only if it is a, s, d or m will the code continue
        case 'A':
        case 'a':
        case 'S':
        case 's':
        case 'D':
        case 'd':
        case 'M':
        case 'm':
            break;
        default:
            //otherwise the user will be asked again.
            std::cout << "You need to choose one of the following: A, S, D or M\n";
            this->setOperation();
            break;
        }
    }

    //asking the user for 2 numbers and storing them in variables.
    void Calculation::setOperands(){
        std::cout << "What is the first operand? ";
        std::cin >> this->operand_1;
        std::cout << "What is the second operand? ";
        std::cin >> this->operand_2;
    }

    //outputs the solution
    void Calculation::printSolution(){
        std::cout << "The solution is: " << this->solution;
    }
