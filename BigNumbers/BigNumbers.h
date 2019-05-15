//
// Created by Kenneth-Matthew Velarde on 2019-05-13.
//

#ifndef BIGNUMBERS_BIGNUMBERS_H
#define BIGNUMBERS_BIGNUMBERS_H

//
// Created by Kenneth-Matthew Velarde on 2019-05-13.
//

#include<vector>
#include <stdio.h>
#include <iostream>



namespace BigNumbers{
    class BigNumbers{
        
        /*! exception class
         * \brief thrown if number of digits is over 1000
         *
         */
        class DigitOverflowException{};
        class DivideByZeroException{};
        
    private:
        
        std::vector<int> values;
        
        std:: string num;
        
        
    public:
        //constructors
        BigNumbers();
        BigNumbers(std::string);
        
        
        /*!operator overload for addition operator
         *
         **/
        void operator +(BigNumbers &val);
        
        /*!operator overload for subtraction operator
         *
         **/
        void operator -(BigNumbers &val);
        
        /*!operator overload for multiplication operator
         *
         **/
        void operator *(BigNumbers &val);
        
        /*!operator overload for division operator
         *
         **/
        void operator /(BigNumbers &val);
        
        /*!operator overload for mod operator
         *
         **/
        void operator %(BigNumbers &val);
        
        bool operator ==(BigNumbers &l);
        bool operator >=(BigNumbers &l);
        
        int size();
        void printer();
        
        std::vector<int> getValues();
        
        
        void adder(int);
        
        bool lesser(BigNumbers);
        
        int At(int i);
    };
    
    
    
}



#endif //BIGNUMBERS_BIGNUMBERS_H
