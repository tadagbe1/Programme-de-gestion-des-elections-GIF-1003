/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   PersonneDejaPresent.h
 * Author: Besta
 *
 * Created on 8 décembre 2024, 14 h 06
 */

#ifndef PERSONNEDEJAPRESENTEEXCEPTION_H
#define PERSONNEDEJAPRESENTEEXCEPTION_H
#include "PersonneException.h"

namespace elections
{
    class PersonneDejaPresenteException : public PersonneException
    {
    public:
        /**
         * \brief Constructeur de la classe PersonneDejaPresenteException.
         * \param[in] p_raison La raison de l'exception.
         */
        explicit PersonneDejaPresenteException(const std::string& p_raison);
    };
}

#endif /* PERSONNEDEJAPRESENTEEXCEPTION_H */

