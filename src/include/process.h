/*  Simple OS for AUCA OS course
    Author: Gladkikh Artem
    Email: gladkikh_artem@mail.ru
*/
#pragma once

enum Process_State {RUNNING, STOPPED, WAITING, TERMINATED};


struct PCB
{

};

struct Process
{
    struct Process* next_process;
    struct PCB pcb;
    int id;
    int priority;
    int cycles_left;
    long process_state;
};

