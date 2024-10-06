

#include "PedidoAlteracao.h"
#include "FileReader.h"

using namespace std;


PedidoAlteracao::PedidoAlteracao(Student *student , Turma* turma , int typeRequest){
    this->student = student;
    this->turma = turma;
    this->typeRequest = typeRequest;
}

PedidoAlteracao::PedidoAlteracao(Student* student, Student* student2 ,Turma *turma , Turma *turma2, int typeRequest) {
    this->student = student;
    this->student2 = student2;
    this->turma = turma;
    this->turma2 = turma2;
    this->typeRequest = typeRequest;
}

int PedidoAlteracao::TrocaTurma( Student *student ,Turma* turmaOrigem ,  Turma* turmaDestino) {
    std::list<Slot *> horarioUcTurma = turmaDestino->getHorarioUcTurma();
    std::vector< std::pair <Slot * , Turma *>> horarioStudent = student->createHorario();
    bool noDesequilibrium = abs(turmaDestino->get_nrStudentsTurma() - turmaOrigem->get_nrStudentsTurma()) < 4;
    int x;

    if (!noDesequilibrium){
        cout << "Fazer esta mudança poderá gerar desequilíbrio. Deseja continuar?(Y/N) ";
        char response;
        cin >> response;
        response = tolower(response);
        if(response == 'y') noDesequilibrium = true;
    }

    if ( noDesequilibrium && isCompatible(horarioUcTurma,horarioStudent , turmaOrigem) ) {
        x = RemoveFromClass(student, turmaOrigem);
        x = AddtoClass(student,turmaDestino);
        student->UpdateTurmas(turmaDestino);
        turmaDestino->AddStudent(student);
        return 1;
    }
    else {
        x = 0;
        cout << "Impossível adicionar aluno à turma desejada" << endl;
        return 0;
    }
}

int PedidoAlteracao::AddtoClass(Student *student1 , Turma* turma ) {
    std::list<Slot *> horarioUcTurma = turma->getHorarioUcTurma();
    std::vector< std::pair <Slot * , Turma *>> horarioStudent = student1->createHorario();
    bool a = isCompatible(horarioUcTurma , horarioStudent);
    if (turma->get_nrStudentsTurma() < turma->defaultCap && isCompatible(horarioUcTurma , horarioStudent)){
        student1->UpdateTurmas(turma);
        turma->AddStudent(student1);
        return 1;
    }
    return 0;
}


int PedidoAlteracao::RemoveFromClass(Student *student1 , Turma* turmaOrigem ) {
    student1->RemoveFromTurma(turmaOrigem);
    turmaOrigem->RemoveStudent(student1);
    return 1;
}

int PedidoAlteracao::TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2){
    std::list<Slot *> horarioUcTurma1 = turma1->getHorarioUcTurma();
    std::vector< std::pair <Slot *,Turma *>> horarioStudent1 = student1->createHorario();
    std::list<Slot *> horarioUcTurma2 = turma2->getHorarioUcTurma();
    std::vector< std::pair <Slot * , Turma *>> horarioStudent2 = student2->createHorario();
    if (isCompatible(horarioUcTurma1 , horarioStudent2 , turma2) && isCompatible(horarioUcTurma2 , horarioStudent1,turma1)) {
        student1->RemoveFromTurma(turma1);
        student2->RemoveFromTurma(turma2);
        student1->UpdateTurmas(turma2);
        student2->UpdateTurmas(turma1);
        turma1->AddStudent(student2);
        turma2->AddStudent(student1);
        return 1;
    }
    return 0;
}

Student*  PedidoAlteracao::getStudent(){return student;}
Student*  PedidoAlteracao::getStudent2(){return student2;}
Turma*  PedidoAlteracao::getTurma(){return turma;}
Turma*  PedidoAlteracao::getTurma2(){return turma2;}
int  PedidoAlteracao::getTypeRequest(){return typeRequest;}



