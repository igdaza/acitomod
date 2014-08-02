#ifndef RS232_COMM_H
#define RS232_COMM_H

#include "message_def.h"
#include "stdbool.h"

typedef struct t_message
{
   int id_home;
   int id_window;
   int command;
   int time;
   int status;
   int ack;
}t_message;

int power_up(int window_id, int porcentaje_apertura, int is_persiana);
int power_down(int window_id, int porcentaje_apertura, int is_persiana);

#endif

