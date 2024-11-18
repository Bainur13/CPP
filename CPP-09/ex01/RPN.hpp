#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <vector>

class RPN
{
    public:
        RPN();
        RPN(const RPN &to_cpy);

        RPN &operator=(const RPN &to_cpy);

        ~RPN();

        void handleString(std::string str);
        

    private :
        std::vector<long> _stackNumbers;
        char _op;
        void throwError();
        int handleOperator(char c);
        bool handleNumber(char c);
        void execCalcul();
};

#endif