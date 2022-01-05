cmake_minimum_required(VERSION 3.19)
project(Assignment)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment fp3Tester.cpp utils.cpp Time.cpp Time.h Menu.cpp IOAble.h IOAble.cpp CovidPatient.cpp CovidPatient.h TriagePatient.cpp TriagePatient.h Ticket.cpp Ticket.h  Patient.cpp Patient.h PreTriage.cpp PreTriage.h)