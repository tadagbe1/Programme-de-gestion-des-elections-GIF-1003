/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PersonneException.h
 * Author: Besta
 *
 * Created on 8 décembre 2024, 14 h 04
 */

#ifndef PERSONNEEXCEPTION_H
#define PERSONNEEXCEPTION_H

#include <stdexcept>
#include <string>

namespace elections
{
    class PersonneException : public std::runtime_error
    {
    public:
        explicit PersonneException(const std::string& p_raison); // Déclaration uniquement
    };
}

#endif /* PERSONNEEXCEPTION_H */