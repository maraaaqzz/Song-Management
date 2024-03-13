#pragma once
#include <iostream>
using namespace std;

class SongException : public std::exception
{
private:
    string m_description;
public:
    SongException(const string& description) : m_description(description) {};

    const char* what() const throw ()
    {
        return m_description.c_str();
    }
};