#include <iostream>
#include "Calculation.h"

Calculation::Calculation() : operand_1(0), operand_2(1), solution(0), operation('M') {}

    void Calculation::doCalculation(){
        switch(this->operation) {
        case 'A':
        case 'a':
            this->solution = this->operand_1 + this->operand_2;
            break;
        case 'S':
        case 's':
            this->solution = this->operand_1 - this->operand_2;
            break;
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
        case 'M':
        case 'm':
            this->solution = this->operand_1 * this->operand_2;
            break;
        default:
            break;
        }
    }


    void Calculation::setOperation(){
        std::cout << "What kind of operation would you like to do? [A]ddition, [S]ubtraction, [D]ivision or [M]ultiplication? ";
        std::cin >> operation;
        switch(this->operation) {
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
            std::cout << "You need to choose one of the following: A, S, D or M\n";
            this->setOperation();
            break;
        }
    }

    void Calculation::setOperands(){
        std::cout << "What is the first operand? ";
        std::cin >> this->operand_1;
        std::cout << "What is the second operand? ";
        std::cin >> this->operand_2;
    }

    void Calculation::printSolution(){
        std::cout << "The solution is: " << this->solution;
    }
