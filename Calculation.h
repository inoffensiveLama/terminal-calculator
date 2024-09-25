//check if this has already been included during the compilation and skip if it has
#ifndef CALCULATION_H
#define CALCULATION_H

//definition of calculation class 
class Calculation {
  public:

    //constructor
    Calculation();

    //functions
    void doCalculation();

    void setOperation();

    void setOperands();

    void printSolution();

    //variables
    float operand_1 = 0;
    float operand_2 = 1;
    float solution;
    char operation;
};

#endif 