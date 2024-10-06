//
// Created by Daniel Rebelo on 11/10/2022.
//

#ifndef AEDTP1_PEDIDOALTERACAO_H
#define AEDTP1_PEDIDOALTERACAO_H

#include "Student.h"
#include "Turma.h"
#include "FileReader.h"

#include <cmath>
#include <iostream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

class PedidoAlteracao {

public:
    /**
     * Constructor for class PedidoAlteracao in case only 1 student is involved.
     * Complexity: O(1)
     * @param student The student that requests the trade
     * @param turma The class that he whiches to be added/removed.
     * @param typeRequest The type of request
     */
    PedidoAlteracao(Student *student , Turma* turma , int typeRequest);

    /**
     * Constructor for class PedidoAlteracao in case 2 students are involved.
     * Complexity: O(1)
     * @param student Student 1 involved in trade
     * @param student2 Student 2 involved in trade
     * @param turma Class 1 involved in trade
     * @param turma2 Class 2 involved in trade
     * @param typeRequest
     */
    PedidoAlteracao(Student *student , Student *student2 , Turma *turma , Turma *turma2, int typeRequest);

    /**
     * The TrocaTurma function switched a student from 1 class to another.
     * Complexity: O(n² log(n))
     * @param student The student to be traded
     * @param turmaOrigem Original class
     * @param turmaDestino Final class
     * @return 1 if possible, 0 if not
     */
    int TrocaTurma(Student *student , Turma* turmaOrigem , Turma* turmaDestino);

    /**
     * The AddtoClass function adds a student to a class.
     * Complexity: O(n² log(n)
     * @param student1 The student to be added
     * @param turma The class to be added to
     * @return 1 if possible, 0 if not
     */
    int AddtoClass(Student *student1 , Turma* turma );

    /**
     * The RemoveFromClass function removes a student from a class.
     * Complexity: O(n²)
     * @param student The student to be removed
     * @param turma The class to be remvoed from
     * @return 1 if possible, 0 if not
     */
    int RemoveFromClass(Student *student, Turma *turma);

    /**
     * The TrocaDiretaTurma makes a direct trade between 2 student's classes.
     * Complexity: O(n³ log(n))
     * @param student1 Student1 involved
     * @param student2 Student2 involved
     * @param turma1 Student1 class
     * @param turma2 Student2 class
     * @return 1 if possible, 0 if not
     */
    int TrocaDiretaTurma(Student *student1 , Student *student2 , Turma *turma1 , Turma *turma2 );

    /**
     * The getStudent function is a getter for the first student.
     * Complexity: O(1)
     * @return The first student
     */
    Student* getStudent();

    /**
     * The getStudent function is a getter for the second student.
     * Complexity: O(1)
     * @return The second student
     */
    Student* getStudent2();

    /**
     * The getTurma function is a getter for the first student's class.
     * Complexity: O(1)
     * @return First student's class
     */
    Turma* getTurma();

    /**
     * The getTurma2 function is a getter for the second student's class.
     * @return Second student's class
     */
    Turma* getTurma2();

    /**
     * The getTypeRequest function is a getter for the type of request.
     * Complexity: O(1)
     * @return Request type
     */
    int getTypeRequest();
private:
    Student* student;
    Student* student2;
    Turma* turma;
    Turma* turma2;
    int typeRequest;

};


#endif //AEDTP1_PEDIDOALTERACAO_H
