//
// Created by tu on 25-11-29.
//

#ifndef PRINTSTL_H
#define PRINTSTL_H
#include <iostream>
#include <list>
#include <stdexcept>

#include "printSTL.h"
namespace print_stl
{
    template<typename list_class=int>
    void printList(const std::list<list_class>& l)
    {
        if (l.empty())
        {
            std::runtime_error("list is empty");
            return;
        }
        for (typename std::list<list_class>::const_iterator it = l.begin(); it != l.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    template<typename vector=int>
    void printVector(const std::vector<vector>& l)
    {
        if (l.empty()) return;
        for (typename std::vector<vector>::const_iterator it = l.begin(); it != l.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    template<typename Container>
    void print(const Container& c)
    {
        if (c.empty())
        {
            std::cout << "container empty" << std::endl;
            return;
        }
        for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

    }
}

#endif //PRINTSTL_H
