/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "PersonneDejaPresenteException.h"

namespace elections
{
    /**
     * \brief Constructeur de la classe PersonneDejaPresenteException.
     *        Initialise une exception avec une raison donnée.
     * \param[in] p_raison La raison de l'exception.
     */
    PersonneDejaPresenteException::PersonneDejaPresenteException(const std::string& p_raison)
        : PersonneException(p_raison)
    {
    }
}