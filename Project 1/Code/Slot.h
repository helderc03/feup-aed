//
// Created by jaimefrf on 18-10-2022.
//

#ifndef AEDTP1_SLOT_H
#define AEDTP1_SLOT_H

#include <iostream>

class Slot {
private:
    std::string diaSemana;
    std::string horarioInicio;
    std::string duracao;
    std::string tipoAula;

public:
    /**
     * Constructor for class Slot.
     * Complexity: O(1)
     * @param diaSemana The week day
     * @param horarioInicio Slot's start time
     * @param duracao Slot's duration
     * @param tipoAula Class type
     */
    Slot(std::string& diaSemana,std::string& horarioInicio,std::string& duracao,std::string& tipoAula);

    /**
     * The getDiaSemana function is getter for the week day.
     * Complexity: O(1)
     * @return Week day
     */
    std::string getDiaSemana() const;

    /**
     * The getHorarioInicio function is a getter for the slot's start time.
     * Complexity: O(1)
     * @return Slot's start time
     */
    std::string getHorarioInicio() const;

    /**
     * The getDuracao function is a getter for the slot's duration.
     * Complexity: O(1)
     * @return Slot's duration
     */
    std::string getDuracao() const;

    /**
     * The getTipo function is a getter for the class type.
     * Complexity: O(1)
     * @return Class type
     */
    std::string getTipo() const;

};


#endif //AEDTP1_SLOT_H
