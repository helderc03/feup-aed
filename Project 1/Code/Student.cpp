//
// Created by Daniel Rebelo on 14/10/2022.
//

#include "Student.h"
using namespace std;

Student::Student(std::string& studentName, std::string& studentCode ){
    this->studentName = studentName;
    this->studentCode = studentCode;
}

std::string Student::get_Name() const {
    return studentName;
}

std::string Student::get_student_Code() const {
    return studentCode;
}

std::vector<Turma*> Student::get_TurmasAluno() {
    sort(turmas.begin(), turmas.end(),[](Turma* t1 , Turma* t2) {return t1->get_ucCode() < t2->get_ucCode();});
    return turmas;
}

void Student::UpdateTurmas(Turma *turma){
    turmas.push_back(turma);
}

void Student::RemoveFromTurma(Turma *turma) {
    // std::remove(turmas.begin(), turmas.end(),turma);
    auto iterator = std::remove_if(turmas.begin(),turmas.end(),[turma] (const Turma* t){ return (turma->get_ucCode() == t->get_ucCode()) && (turma->get_turmaCode() == t->get_turmaCode());});
    turmas.erase(iterator, turmas.end());
}

void Student::PrintStudentTurmas(){
    if (turmas.empty()){cout << "\n Estudante não está inscrito em nenhuma turma." << endl; return;}
    std::sort(turmas.begin(),turmas.end(),[] (Turma *t1 , Turma *t2) -> bool {if (t1->get_ucCode() != t2->get_ucCode()) return (t1->get_ucCode() < t2->get_ucCode());
    else if (t1->get_turmaCode() != t2->get_turmaCode()) return (t1->get_turmaCode() < t2->get_turmaCode());
        return false;}); // default sort ,  talvez implementar sort por turmas

    std::cout << "\nA/O estudante " << this->get_Name() << " com o número de estudante " << this->get_student_Code() << " encontra-se nas seguintes UC/Turmas:" << std::endl;
    for (Turma *turma : turmas){
        std::cout << "UC: " << turma->get_ucCode() << " Turma: " << turma->get_turmaCode() << std::endl;
    }
    cout << endl;
}

std::vector< std::pair <Slot * , Turma *>> Student::createHorario() {
    for(Turma *turma : turmas){
        for (Slot *slot : turma->getHorarioUcTurma()){
            if (std::find(horarioStudent.begin(), horarioStudent.end(),make_pair(slot, turma)) == horarioStudent.end()) horarioStudent.push_back(make_pair(slot, turma));
        }
    }
    sort(horarioStudent.begin(), horarioStudent.end(), sorterHorario);
    return horarioStudent;
}

void Student::PrintHorario() {
    if (turmas.empty()){cout << "\n Horario do estudante vazio." << endl; return;}
    horarioStudent = createHorario();
    cout << "\nHorário de " << studentName << ":" << endl;
    cout << setw(9) << left << "Day" << '\t' << setw(12) << "Class Type" << '\t' << setw(3) << "Time" << '\t' << '\t'
         << setw(10) << "UcCode" << '\t' << setw(5) << "TurmaCode" << std::endl;
    for (pair<Slot *, Turma *> it: horarioStudent) {
        cout << setw(9) << left << it.first->getDiaSemana() << '\t' << setw(9) << it.first->getTipo() << '\t' << setw(3)
             << Fixer(it.first->getHorarioInicio()) << setw(1) <<
             "-" << setw(8) << GetFinishTime(it.first->getHorarioInicio(), it.first->getDuracao()) << '\t'
             << (it.second->get_ucCode()) << '\t'
             << setw(3) << it.second->get_turmaCode() << endl;
    }
}


