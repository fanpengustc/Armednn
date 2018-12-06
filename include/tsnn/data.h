#ifndef _Data_H
#define _Data_H

#include <iostream>
#include "tsnn/core.h"
#include <string>
typedef std::string string;

class Layer;

class Data_
{
    public:
        virtual void set_value(int){};
        virtual  int& get_(int&){};

        virtual void set_value(string){};
        virtual  string& get_(string&){};

        virtual void set_value(Matrix){};
        virtual  Matrix& get_(Matrix&){};


        template <typename T>
         T& get_value() 
        {
            T _;
            /*
            std::cout<<"================:"<<get_(_)<<&get_(_)<<std::endl;
            */
            return get_(_);
        }

        std::string name;
        Layer* from;
        Layer* to;
        size_t mark;

    protected:
        Data_(){mark=2;};
        Data_(string _name):name(_name){mark=2;};

};

typedef Data_* pData;

template <typename T>
class Data:public Data_
{
    public:
        Data():Data_(){};
        Data(string name):Data_(name){};

        void set_value(T _value)
        {
            value=_value;
        }
        
        T& get_value()
        {
            return value;
        }


         T& get_(T& _value)
        {
            return value;
        }
        
    private:
        T value;
};

template <typename T>
class InputData:public Data<T>
{
    public:

        InputData():Data<T>(){};
        InputData(string name):Data<T>(name){};
    ;
};

#endif