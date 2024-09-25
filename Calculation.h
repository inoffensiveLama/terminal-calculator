#ifndef CALCULATION_H
#define CALCULATION_H

class Calculation {
  public:

    Calculation();

    void doCalculation();

    void setOperation();

    void setOperands();

    void printSolution();

    float operand_1 = 0;
    float operand_2 = 1;
    float solution;
    char operation;
};

#endif 