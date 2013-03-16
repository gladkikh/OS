/*  Simple OS for AUCA OS course
    Author: Gladkikh Artem
    Email: gladkikh_artem@mail.ru
*/

#pragma once

#include "process.h"
#include "kernel.h"

#define MAX_PROC_COUNT 10


struct Process* proc_list[MAX_PROC_COUNT];

int init_proc_manager()
{
    puts("Manager Initialized\n");
}

struct Process* roundRobint(struct Process* proc)
{
    puts("RR: switching to ");
    putch('0' + proc->next_process->id);
    puts("\n");
    return proc->next_process;
}

struct Process* shortestJobFirst(struct Process* proc)
{
    int i;
    struct Process* proc_to_change = proc;
    for(i = 0; i < MAX_PROC_COUNT;i++)
    {
        if(proc_list[i]->cycles_left < proc_to_change->cycles_left)
        {
            proc_to_change = proc_list[i];
        }
    }
    puts("SJF: switching to ");
    putch('0' + proc_to_change->id);
    puts("\n");
    return proc_to_change;
}


struct Process* first_come_firt_out(struct Process* proc)
{
    if(proc->process_state == TERMINATED)
    {
            puts("FIFO: switching to ");
            putch('0' + proc->next_process->id);
            puts("\n");
        return proc->next_process;
    }
    else
    {
            puts("FIFO: switching to ");
            putch('0' + proc->id);
            puts("\n");
        return proc;
    }
}


struct Process* priority_sheduling(struct Process* proc)
{
    int i;
    struct Process* proc_to_change = proc;
    for(i = 0; i < MAX_PROC_COUNT;i++)
    {
        if(proc_list[i]->priority > proc_to_change->priority)
        {
            proc_to_change = proc_list[i];
        }
    }


    puts("PS: switching to ");
    putch('0' + proc_to_change->id);
    puts("\n");
    return proc_to_change;
}
