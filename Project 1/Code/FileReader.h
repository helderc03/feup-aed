//
//

#ifndef AEDTP1_FILEREADER_H
#define AEDTP1_FILEREADER_H

#include "Student.h"
#include "Turma.h"
#include "Slot.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <limits>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <vector>

/**
 * The studentComparator is a function that compares two students and allows sorting in multiple ways.
 * Complexity: O(log(n))
 */
struct studentComparator
{
    bool operator()(Student* s1, Student* s2) const {
        if (s1->get_student_Code() != s2->get_student_Code()) return (s1->get_Name() < s2->get_Name());
        return false;
    }
};

/**
 * The turmaComparator is a function that compares two classes and allows sorting in multiple ways.
 * Complexity: O( log(n))
 */
struct turmaComparator
{
    bool operator()(Turma* t1, Turma* t2) const {
        if (t1->get_ucCode() != t2->get_ucCode()) return (t1->get_ucCode() < t2->get_ucCode());
        else if (t1->get_turmaCode() != t2->get_turmaCode()) return (t1->get_turmaCode() < t2->get_turmaCode());
        return false;
    }
};


class FileReader{

        std::set<Student*, studentComparator> students;
        std::set<Turma*, turmaComparator> allTurmas;
        std::vector<Turma*> turmaAluno;
        std::vector<Slot *> allSlots;

    public:
        /**
         * Initializer that starts the reading of files.
         * Complexity: O(n⁴ log(n))
         * @param studentsinfo_file Path to to student's info file
         * @param aulas_file Path to lesson's info file
         */
        FileReader(std::istream &studentsinfo_file,std::istream &aulas_file);

        /**
         * The getStudents function is getter for all students.
         * Complexity: O(1)
         * @return All students
         */
        std::set<Student *, studentComparator> getStudents() const;

        /**
         * The getTurmas function is a getter for all classes.
         * Complexity: O(1)
         * @return All classes
         */
        std::set<Turma*, turmaComparator> getTurmas() const;

        /**
         * The getSlots is a getter for all lesson slots.
         * Complexity: O(1)
         * @return All lessons slots
         */
        std::vector<Slot*> getSlots() const;
};

#endif //AEDTP1_FILEREADER_H
