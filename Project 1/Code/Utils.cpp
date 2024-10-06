//
// Created by Jaime on 29/10/2022.
//

#include "Utils.h"
#include "FileReader.h"


using namespace std;

map<string , int> weekDays{{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};

bool sorterHorarioSlot(Slot* s1,Slot* s2){
    if(weekDays[s1->getDiaSemana()] != weekDays[s2->getDiaSemana()]) return (weekDays[s1->getDiaSemana()] < weekDays[s2->getDiaSemana()]);
    if(s1->getHorarioInicio() != s2->getHorarioInicio()) return (stof(s1->getHorarioInicio()) < stof(s2->getHorarioInicio()));
    return false;
}


bool sorterHorario(pair <Slot *, Turma *> s1, pair <Slot *, Turma *> s2){
    if(weekDays[s1.first->getDiaSemana()] != weekDays[s2.first->getDiaSemana()]) return (weekDays[s1.first->getDiaSemana()] < weekDays[s2.first->getDiaSemana()]);
    if(s1.first->getHorarioInicio() != s2.first->getHorarioInicio()) return (stof(s1.first->getHorarioInicio()) < stof(s2.first->getHorarioInicio()));
    return false;
}

std::string GetFinishTime(std::string horarioInicio,std::string duracao) {
    float hInicio_f = std::stof(horarioInicio);
    float duracao_f = std::stof(duracao);
    hInicio_f += duracao_f;
    if ((float) (hInicio_f - (int)hInicio_f) != 0){
        horarioInicio = std::to_string((int)hInicio_f) + ":30h";
        return horarioInicio;
    }
    else {
        horarioInicio = std::to_string((int)hInicio_f) + "h";
        return horarioInicio;
    }
}

std::string Fixer(std::string horarioInicio) {
    float hInicio_f = std::stof(horarioInicio);
    if ((float) (hInicio_f - (int)hInicio_f) != 0){
        return std::to_string((int)hInicio_f) + ":30h";
    }
    else {
        return std::to_string((int)hInicio_f) + "h";
    }
}

void PrintVector(std::vector<Turma*> v , char option){
    char orderType;
    cout << "1.Ordenacao crescente\n";
    cout << "2.Ordenacao decrescente\n";
    cin >> orderType;
    switch(orderType){
        case '1':
            break;
        case '2':
            reverse(v.begin(),v.end());
            break;
    }

    switch (option) {
        case '1':
            cout << "Turma" << "\t" << "Nº de alunos" << endl;
            for (Turma* t : v){cout << t->get_turmaCode() << "\t" << t->get_nrStudentsTurma() << endl;}
            break;
        case '2':
            cout << "Turma" << "\t" << "Nº de vagas" << endl;
            for (Turma* t : v){cout << t->get_turmaCode() << "\t" << 24 - (int)(t->get_nrStudentsTurma()) << endl;}
            break;
    }
}

int auxMenu(int maxOption, int minOption){
    int op;
    do{
        cin >> op;
        if( op > maxOption || op < minOption)
            cout << "Número inválido. Introduza um valor válido: ";
    } while(op > maxOption || op < minOption);
    return op;
}

std::string tolowerString(std::string s){
    string lowername;
    for (char c : s){
        if (c == ' '){lowername.push_back(' ');}
        lowername.push_back(tolower(c));
    }
    return lowername;
}

bool isCompatible(std::list<Slot *> horarioUcTurma , std::vector< std::pair <Slot * , Turma *>> horarioStudent , Turma* turma ){
    if (turma == nullptr) {
        for (Slot *novaAula: horarioUcTurma) {
            std::vector<std::pair<Slot *, Turma *>> hs = horarioStudent;
            auto it = std::remove_if(hs.begin(), hs.end(),
                                     [&novaAula](const std::pair<Slot *, Turma *> aula) {
                                         return novaAula->getDiaSemana() != aula.first->getDiaSemana();
                                     });
            hs.erase(it, hs.end());
            for (pair<Slot *, Turma *> p: hs) {
                Slot *aula = p.first;
                if (aula->getTipo() == "T" || novaAula->getTipo() == "T") continue;
                float begTimeAula = stof(aula->getHorarioInicio());
                float finishTimeAula = begTimeAula + stof(aula->getDuracao());
                float begTimenovaAula = stof(novaAula->getHorarioInicio());
                float finishTimenovaAula = begTimenovaAula + stof(novaAula->getDuracao());
                if (!(begTimenovaAula >= finishTimeAula || finishTimenovaAula <= begTimeAula)) {
                    return false;
                }
            }
        }
        return true;
    }

    else{
        for (Slot *novaAula: horarioUcTurma) {
            std::vector<std::pair<Slot *, Turma *>> hs = horarioStudent;
            auto it = std::remove_if(hs.begin(), hs.end(),
                                     [&novaAula](const std::pair<Slot *, Turma *> aula) {
                                         return novaAula->getDiaSemana() != aula.first->getDiaSemana();
                                     });
            hs.erase(it, hs.end());
            for (pair<Slot *, Turma *> p: hs) {
                Slot *aula = p.first;
                Turma* t = p.second;
                if (t->get_ucCode() == turma->get_ucCode() || aula->getTipo() == "T" || novaAula->getTipo() == "T"){continue;}
                float begTimeAula = stof(aula->getHorarioInicio());
                float finishTimeAula = begTimeAula + stof(aula->getDuracao());
                float begTimenovaAula = stof(novaAula->getHorarioInicio());
                float finishTimenovaAula = begTimenovaAula + stof(novaAula->getDuracao());
                if (!(begTimenovaAula >= finishTimeAula || finishTimenovaAula <= begTimeAula)) {
                    return false;
                }
            }
        }
        return true;
    }
}
