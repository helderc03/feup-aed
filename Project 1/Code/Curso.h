//
// Created by Jaime on 31/10/2022.
//

#ifndef PROJETO_AED_CURSO_H
#define PROJETO_AED_CURSO_H

#include <fstream>
#include <set>
#include <string>
#include <queue>
#include "Student.h"
#include "FileReader.h"
#include "PedidoAlteracao.h"
#include "Utils.h"
#include <algorithm>
#include "Menu.h"
#include <climits>

/**
 * The studentComparator2 is a function that compares two students and allows sorting in descending alphabetical order.
 * Complexity: O(log(n))
 */
struct studentComparator2{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_Name() < s1->get_Name());
        return false;
    }
};

/**
 * The studentComparatorCode  is a function that compares two students by student code and allows sorting.
 * Complexity: O(log(n))
 * in ascending order.
 */
struct studentComparatorCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_student_Code() < s2->get_student_Code());
        return false;
    }
};
/**
 * The studentComparatorDecreasingCode  is a function that compares two students by student code and allows sorting in descending order.
 * Complexity: O(log(n))
 */
struct studentComparatorDecreasingCode {
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s2->get_student_Code() < s1->get_student_Code());
        return false;
    }
};

class Curso {
    std::set<Student*, studentComparator> allStudents;
    std::set<Turma*, turmaComparator> allTurmas;
    std::vector<Slot *> allSlots;
    std::queue<PedidoAlteracao* > queuePA;
public:
    /**
     * Default constructor for class Curso.
     * Complexity: O(1)
     */
    Curso() = default;

    /**
     * Constructor for class Curso.
     * Complexity: O(1)
     * @param allSlots All lesson slots
     */
    Curso(std::set<Student*, studentComparator> , std::set<Turma*, turmaComparator>, std::vector<Slot *> allSlots );

    /**
     * The getAllStudents function is a getter for all students in a sorted way.
     * Complexity: O(1)
     * @return All students sorted
     */
    std::set<Student*, studentComparator> getAllStudents() const;

    /**
     * The getAllTurmas function is a getter for all classes in a sorted way.
     * Complexity: O(1)
     * @return All classes in a sorted way
     */
    std::set<Turma*, turmaComparator> getAllTurmas() const;

    /**
     * The PrintStudents fuction print students using a user's choice sorting.
     * Complexity: O(n)
     * @param students The students to be printed
     * @param option Type of sorting chosen
     */
    void PrintStudents(std::set<Student* , studentComparator> students , char option);

    /**
     * The PrintHorarioTurma is a function that prints a class schedule.
     * Complexity: O(n²)
     * @param uc Uc chosen is users requests the schedule for a specific UC
     */
    void PrintHorarioTurma(std::vector<Turma*> , std::string uc = "");

    /**
     * The FindTurma is a function that allows user to find a specific class.
     * @param ucCode UC that the class belongs to
     * @return The class requested by the user
     */
    std::vector<Turma*> FindTurma(std::string ucCode = "");

    /**
     * The PrintStudentByName function finds a student by his name and prints it.
     * Complexity: O(n² log(n))
     * @return The student requested by the user
     */
    Student* PrintStudentByName();

    /**
     * The PrintStudentByCode function finds a student by his student code and prints it.
     * Complexity: O(n² log(n))
     * @return The student requested by the user
     */
    Student* PrintStudentByCode();

    /**
     * The getStudentsTurma function returns all students in a certain class.
     * Complexity: O(n² log(n))
     * @param turmas The class the user wants to see the students from
     * @param ucCode In case the user wants, students only a specific UC/Class.
     * @return The students requested by the user
     */
    std::set<Student*, studentComparator> getStudentsTurma(std::vector<Turma*> turmas, std::string ucCode = "");

    /**
     * Function that allows sorting of students in descending alphabetical order.
     * Complexity: O(n log(n))
     * @param students Students to be sorted
     * @param newstudents Sorted students
     * @return Sorted students
     */
    static std::set<Student* , studentComparator2> StudentReverseSortAlpha(std::set<Student *, studentComparator> students, std::set<Student *, studentComparator2> &newstudents);

    /**
    * Function that allows sorting of students by their student code in ascending order.
     * Complexity: O(n log(n))
    * @param students Students to be sorted
    * @param newstudents Sorted students
    * @return Sorted students
    */
    static std::set<Student* , studentComparatorCode> StudentSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorCode> &newstudents);

    /**
    * Function that allows sorting of students by their student code in descending order.
     * Complexity: O(n log(n))
    * @param students Students to be sorted
    * @param newstudents Sorted students
    * @return Sorted students
    */
    static std::set<Student* , studentComparatorDecreasingCode> StudentReverseSortCode(std::set<Student* , studentComparator> students, std::set<Student *, studentComparatorDecreasingCode> &newstudents);

    /**
     * The SortbyTurmaCapacity function allows sorting of classes in a certain Uc by user choice.
     * Complexity: O(n log(n))
     * @param ucCode classes' UC
     * @param option Sorting option
     */
    void SortbyTurmaCapacity( std::string ucCode , int option);

    /**
     * The getStudentsYears function returns all students enrolled in a certain year.
     * Complexity: O(n² log(n))
     * @param students The set of all students
     * @param year The year chosen by the user
     * @return All students in a certain year
     */
    std::set<Student* , studentComparator> getStudentsYear(std::set<Student* , studentComparator> students , int year);

    /**
     * The getTurmasYear function returns all classes in a certain year/ in all years.
     * Complexity: O(n² log(n))
     * @param year The year chosen by the user
     */
    void getTurmasYear( int year = INT_MAX);

    /**
     * The SortByEnrolledUC function allows sorting by the number of students enrolled in the UC.
     * Complexity: O(n² log(n))
     * @param op Controlled for user's choices
     * @param ucCode The UC chosen by the user
     */
    void SortByEnrolledUC( int op = 1 , std::string ucCode= "");

    /**
     * The ucCodeNormalizer function facilitates the user input for UcCodes, automatically making the input in the form given by the files.
     * Complexity: O(n² log(n))
     * @return A normalized UcCode
     */
    std::string ucCodeNormalizer();

    /**
     * The AddPA function add a request change to the request change queue.
     * Complexity: O(n² log(n))
     * @param s Student involved in the change
     * @param t Class that the student will be changed to / class where he is now
     * @param typeRequest The type of request
     */
    void AddPA(Student* s, Turma* t  , int typeRequest);

    /**
     * The FindTurmaLowestCapacity function returns the class with the most remaining vacancies that is compatible with a student's schedule.
     * Complexity: O(n² log(n))
     * @param s Student
     * @param ucCode UC code
     * @return The class with the most vacancies that is compatible with the student's schedule
     */
    Turma* FindTurmaLowestCapacity(Student* s , std::string ucCode);

    /**
     * The GetTurma function returns the student's class for that UC.
     * Complexity: O(n)
     * @param s Student
     * @param ucCode UC Code
     * @return Class in which the student is enrolled
     */
    Turma* GetTurma(Student* s , std::string ucCode);

    /**
     * The setDefaultCap function allows modifying of the class size cap.
     * Complexity: O(n)
     * @param newCap The new cap to be set
     */
    void setDefaultCap(int newCap);

    /**
     * The getDefaultCap function is a getter for the current class size cap.
     * Complexity: O(1)
     * @return
     */
    int getDefaultCap();

    /**
     * The ProcessPA function processes all change requests made by the user.
     * Complexity: O(n³ log(n))
     */
    void ProcessPA();

    /**
     * The Save function saves all the changes made, must be user called.
     * Complexity: O(n²)
     */
    void Save();

    /**
     * The WriteArchive function makes note of all the change request that did not get accepted.
     * Complexity: O(log(n))
     * @param p The request that was denied
     */
    void WriteArchive(PedidoAlteracao* p);

    /**
     * The getTurmaMostStudents return the number of students in the class with the most students.
     * Complexity: O(n)
     * @return The number os students in the biggest class
     */
    int getTurmaMostStudents();

    /**
     * The findListStudentsUC function finds and prints all students enrolled in more than/exactly/less than n UCs.
     * Complexity: O(n log(n))
     * @param n The number of UCs chosen by the user
     * @param exactN The user's choice ( more than / exactly / less than )
     * @param orderType The type of sorting to use in the print
     */
    void findListStudentsUC(int n, int exactN, int orderType);

};

#endif //PROJETO_AED_CURSO_H
