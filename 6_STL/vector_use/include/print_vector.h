//
// Created by tu on 25-11-14.
//

#ifndef PRINT_VECTOR_H
#define PRINT_VECTOR_H
#include <iostream>
#include <vector>
template <typename T=int>
std::ostream &operator<<(std::ostream &cout,const std::vector<T> &v)
{
    for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << "\n";
    return cout;
}
#endif //PRINT_VECTOR_H
