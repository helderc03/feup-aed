//
// Created by jaimefrf on 18-10-2022.
//

#include "Slot.h"

Slot::Slot(std::string& diaSemana,std::string& horarioInicio,std::string& duracao,std::string& tipoAula) {
    this->diaSemana = diaSemana;
    this->horarioInicio = horarioInicio;
    this->duracao = duracao;
    this->tipoAula = tipoAula;
}

std::string Slot::getDiaSemana() const {
    return diaSemana;
}

std::string Slot::getHorarioInicio() const {
    return horarioInicio;
}

std::string Slot::getDuracao() const {
    return duracao;
}

std::string Slot::getTipo() const {
    return tipoAula;
}
