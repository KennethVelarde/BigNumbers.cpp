#include <stdio.h>
#include <iostream>
#include <vector>
#include "BigNumbers.h"

namespace BigNumbers {
    
    /*! default constructor for BigNumbers
     *
     *initializes vector with 0's
     */
    BigNumbers::BigNumbers() {
        
        values.push_back(0);
    }
    /*!
     * constructor of BigNumbers with a string representing the value to be manipulated
     * @param val representing value being inputted and to be manipulated
     */
    BigNumbers::BigNumbers(std::string val) {
        
        std::string str = val;
        
        //check if user input is less than 1000 digits
        if (str.length() > 1000)
            for (int i = str.length() - 1; i >= 0; i--) {
                values.insert(values.begin(), values[i] - '0');
            }
        
    }//end constructor
    
    /*!operator overloaded for addition operator
     *
     * Adding of BigNumbers implementation.
     * \brief if both numbers are negative, then answer is negative,
     * \brief else the answer is positive
     **/
    void BigNumbers::operator+(BigNumbers &val) {
        
        int current = values.size() -1;
        int next = val.size() -1;
        
        while( current >= 0 && next >+ 0 ){
            
            values.at(current) += val.At(next);
            adder(current);
            current--;
            next--;
            
        }
        while( next >=0 ){
            values.insert(values.begin(),val.At(next));
            current++;
            next++;
            
            adder(current);
            
        }
        
        
        
    } // operator +
    
    /*!
     * \brief operator overload for subtraction operator
     * @param val other value in operation
     * @return subtracted value
     */
    void BigNumbers:: operator-(BigNumbers &val){
        std::vector<int> vect1 = val.values;
        
        int v1 = values.size() - 1;
        int v2 = val.size() -1;
        
        int swapper = 0;
        
        if(lesser(val)){
            values.swap(vect1);
            swapper = v1;
            v1 = v2;
            v2 = swapper;
        }
        //while vector is not empty
        while(v1 >=0 && v2 >=0)
        {
            values.at(v1) -= val.At(v2);
            if(values.at(v1) < 0){
                values.at(v1) += 10;
                values.at(v1 - 1) -= 1;
            }
            
            v1--;
            
            v2--;
        }
        
    }// operator -
    
    /*!
     *  \brief Operator overload for multiplication operator
     * @param val
     * @return
     */
    void BigNumbers:: operator *(BigNumbers &val){
        std::vector<int> vect1 = val.values;
        int t = values.size() + val.size();
        
        vect1.assign(t,0);
        
        int over = 0;
        
        int c = t -1;
        
        int off = 1;
        
        for(int i = values.size() -1; i >=0; i--){
            over = 0;
            for(int j = val.size() -1; j >=0; j--) {
                
                vect1.at(c) += over+(values.at(i) * val.At(j));
                over = vect1.at(c) / 10;
                vect1.at(c) = vect1.at(c) % 10;
                c--;
                
            }
            vect1.at(c) = over;
            off++;
            c = t - off;
        }
        values.swap(vect1);
        
    }// operator *
    
    
    /*!
     * \brief operator overload for division operator
     * @param val
     * @return
     */
    void BigNumbers:: operator /(BigNumbers &val){
        
//        BigNumbers div("0");
//        BigNumbers f("0");
//        f.values = values;
//
//        BigNumbers l("0");
//
//        while(f >= val && !(f==l)){
//            div = div + BigNumbers("1");
//            f = f-val;
//        }
//
    }
    
    
    /*!
     * \brief operator overload for mod operator
     * @param val
     * @return
     */
    void BigNumbers:: operator %(BigNumbers &val){
//
//        BigNumbers div("0");
//        BigNumbers f("0");
//        f.values = values;
//        BigNumbers l("0");
//
//        while(f >= val && !(f==l)){
//            div = div + BigNumbers("1");
//            f = f-l;
//        }
//
    }
    
    /*!
     * \brief a method that prints out a number at a specific index
     */
    void BigNumbers::printer() {
        int size = values.size();
        
        for(int j = 0; j < size; j++){
            std::cout<< " "<< values.at(j) << " ";
        }
    }
    
    
    
    
    
    /*!
     * \brief method for vector addition
     * @param index
     */
    void BigNumbers::adder(int index) {
        while(values.at(index) > 9){
            values.at(index) -=10;
            if(index - 1 < 0){
                //insert element at start of vector
                values.insert(values.begin(), 1);
                index++;
            }else{
                values.at(index - 1) +=1;
            }
            
        }
    }
    
    /*!
     * \brief method that returns a value at an index of the vector
     * @param index place of specific element in vector
     * @return a value in the vector
     */
    int BigNumbers::At(int index) {
        return values.at(index);
    }
    /*!
     * \brief method that returns the size of the BigNumber
     * @return an int of the size of the BigNumber
     */
    int BigNumbers:: size(){
        return values.size();
    }
    
    
    /*!
     * \brief method that compares the size of two vectors
     * @param other a BigNumber to be compared to the one calling function
     * @return bool determing whether v1 or v2 is of smaller size
     */
    bool BigNumbers::lesser(BigNumbers other) {
        int v1size = values.size();
        int v2size = other.size();
        
        if (v1size < v2size) { return true; }
        if (v2size < v1size) { return false; }
        for (int i = 0; i < v1size; i++){
            if (values[i] < other.At(i)) { return true;}
            else{return false;}
        }
        return false;
    }
    
    
    
    bool BigNumbers:: operator ==(BigNumbers &l){return false;}
    bool BigNumbers:: operator >=(BigNumbers &l){return false;}
    
    
    
    
    
    
    
    
    
    
    
}//end namespace
