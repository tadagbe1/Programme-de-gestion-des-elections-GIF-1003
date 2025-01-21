/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PersonneAbsenteException.h
 * Author: Besta
 *
 * Created on 8 décembre 2024, 14 h 10
 */

#ifndef PERSONNEABSENTEEXCEPTION_H
#define PERSONNEABSENTEEXCEPTION_H

#include "PersonneException.h"

namespace elections
{
    class PersonneAbsenteException : public PersonneException
    {
    public:
        /**
         * \brief Constructeur de la classe PersonneAbsenteException.
         * \param[in] p_raison La raison de l'exception.
         */
        explicit PersonneAbsenteException(const std::string& p_raison);
    };
}

#endif /* PERSONNEABSENTEEXCEPTION_H */
