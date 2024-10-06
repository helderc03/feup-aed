//
// Created by danielrebelo1 on 17-10-2022.
//

#include "FileReader.h"

using namespace std;

FileReader::FileReader(std::istream &studentsinfo_file, std::istream &aulas_file) {

    aulas_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (aulas_file.good()) {
        string line, data;
        vector<string> line_vector;

        getline(aulas_file, line);

        if (line.empty() || line == "\r") break;
        stringstream ss(line);

        while (getline(ss, data, ',')) line_vector.push_back(data);

        string turmaCode = line_vector[0]
                , ucCode = line_vector[1];;

        Turma *turma = new Turma(turmaCode, ucCode);
        auto itr = allTurmas.find(turma);
        if (itr != allTurmas.end()) {
            turma = *itr;
        } else {
            allTurmas.insert(turma);
        }

        string diaSemana = line_vector[2],
        horarioInicio = line_vector[3],
        duracao = line_vector[4],
        tipoAula = line_vector[5].substr(0 , line_vector[5].find("\r"));

        Slot *slot = new Slot(diaSemana, horarioInicio, duracao, tipoAula);
        allSlots.push_back(slot);
        turma->AddSlot(slot);

    }

    studentsinfo_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (studentsinfo_file.good()) {
        string line, data;
        vector<string> line_vector;

        getline(studentsinfo_file, line);

        if (line.empty()) break;

        stringstream ss(line);

        while (getline(ss, data, ','))line_vector.push_back(data);

        string studentCode = line_vector[0],
        studentName = line_vector[1],
        ucCode = line_vector[2],
        turmaCode = line_vector[3].substr(0, line_vector[3].find("\r"));
        Turma *turma = new Turma(turmaCode, ucCode);
        auto itr = allTurmas.find(turma);
        if (itr != allTurmas.end()) {
            turma = *itr;
            Student *student = new Student(studentName, studentCode);
            auto it = students.find(student);
            if (it != students.end()) {
                student = *it;
            } else students.insert(student);
            turma->AddStudent(student);
            student->UpdateTurmas(turma);
        } else {
            cout << "error : no class found";
        }
    }
}

set<Student *, studentComparator> FileReader::getStudents() const {
    return students;
}

std::set<Turma *, turmaComparator> FileReader::getTurmas() const {
    return allTurmas;
}

vector<Slot *> FileReader::getSlots() const {
    return this->allSlots;
}


