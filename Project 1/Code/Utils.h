//
// Created by Jaime on 29/10/2022.
//

#ifndef PROJECT_AED_UTILS_H
#define PROJECT_AED_UTILS_H

#include <string>
#include <vector>
#include <map>
#include <list>

class Slot;
class Turma;

/**
 * The GetFinishTime function returns the time that a class ends.
 * Complexity: O(log(n))
 * @param horarioInicio Class start time
 * @param duracao Class duration
 * @return Class ending time
 */

std::string GetFinishTime(std::string horarioInicio,std::string duracao);

/**
 * The Fixer function returns the time provided in the files in a more readable way.
 * Complexity: O(log(n))
 * @param horarioInicio Start time
 * @return More readable time
 */

std::string Fixer(std::string horarioInicio);

/**
 * The sorterHorario function is used to compare two schedules and return them in order.
 * Complexity: O(log(n))
 * @param s1 Pair containing class and schedule 1.
 * @param s2 Pair containing class and schedule 2.
 * @return
 */

bool sorterHorario(std::pair <Slot *, Turma *> s1, std::pair <Slot *, Turma *> s2);

/**
 * The sorterHorarioSlot function is used to compare two classes and return the one earliest one.
 * Complexity: O(log(n))
 * @param s1 Class 1
 * @param s2 Class 2
 * @return
 */

bool sorterHorarioSlot(Slot* s1,Slot* s2);

/**
 * The auxMenu function is used to limit the input that users can make in the menu.
 * Complexity: O(n log(n))
 * @param maxOption User input has to be < than this variable
 * @param minOption User input has to be > than this variable
 * @return User input
 */

int auxMenu(int maxOption, int minOption);

/**
 * The PrintVector function prints either the number of students in a class or the free spots in a class.
 * Complexity: O(n)
 * @param v Vector containing the classes to print.
 * @param option Option chosen, either the number of students or free spots.
 */

void PrintVector(std::vector<Turma*> v , char option);

/**
 * The tolowerString function returns a string in lower case.
 * Complexity: O(n)
 * @param s String received.
 * @return String in lower case
 */

std::string tolowerString(std::string s);

/**
 * The isCompatible function verifies is the schedule of a student is compatible with the one of another class.
 * Complexity: O(n²)
 * @param listSlot the slot to be verified.
 * @param vector Student schedule.
 * @param turma the class to compare to.
 * @return
 */

bool isCompatible(std::list<Slot *>, std::vector< std::pair <Slot * , Turma *>> , Turma* turma = nullptr);

#endif //PROJECT_AED_UTILS_H

