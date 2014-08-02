//gcc -shared -I/usr/include/python2.6/ -lpython2.6 -o rs232_comm.so rs232_comm.c

#include "rs232_comm.h"
#include "rs232.h"
#include <stdio.h>
#include <stdlib.h>

/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
int power_up(int window_id, int porcentaje_apertura, int is_persiana)
{

  int return_value = 0;
  int cport_nr = 16;
  int bdrate = 9600;

  if(RS232_OpenComport(cport_nr, bdrate))
  {
    printf("Can not open comport\n");
    return 1;
  }

  t_message message;
  t_message message_aux;

  message.id_home = ID_HOME;
  message.id_window = window_id;
  message.command = POWER_UP;
  if (is_persiana == 1)
    message.time = porcentaje_apertura*TIME_100*10; // milisegundos
  else
    message.time = porcentaje_apertura; // Segundos
  message.status = NULL_STATUS;
  message.ack = NO_OK;
  
  sleep(2);
  
  // Comienza a girar motor
  printf("Send (Home, Id_Window, Command, Ack): (%d, %d, %d, %d)\tSize: %d\n", message.id_home, message.id_window, message.command, message.ack, sizeof(message));
  
  RS232_SendBuf(cport_nr, (unsigned char*)&message, sizeof(message));
  printf("Sended message.\n");
  
  sleep(3);
  
  // Wait the motor ack message
  int read_bytes = 0;
  while(read_bytes < 24)
  {
    int aux = RS232_PollComport(cport_nr, (unsigned char*) &(message_aux), sizeof(message_aux));
    printf("Aux: %d\n", aux);

    if (aux == -1)
      break;
    else if(read_bytes == 0)
      memcpy(&message, &message_aux, aux);
    else
      memcpy(&message+(read_bytes-1), &message_aux, aux);

    read_bytes = read_bytes + aux;
  }
  
  if (message.ack == OK)
  {
    printf("Opened window %d\n", message.id_window);
    return_value = -1;
  }
  else
  {
    printf("Failed to open window %d\n", message.id_window);
    return_value = 0;
  }

  RS232_CloseComport(cport_nr);

  return (return_value);
}
  
/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
int power_down(int window_id, int porcentaje_apertura, int is_persiana)
{
  int cport_nr = 16;
  int bdrate = 9600;

  if(RS232_OpenComport(cport_nr, bdrate))
  {
    printf("Can not open comport\n");
    return 1;
  }

  t_message message;
  t_message message_aux;

  message.id_home = ID_HOME;
  message.id_window = window_id;
  message.command = POWER_DOWN;
  if (is_persiana == 1)
    message.time = porcentaje_apertura*TIME_100*10; // milisegundos
  else
    message.time = porcentaje_apertura; // Segundos
  message.status = NULL_STATUS;
  message.ack = NO_OK;

  sleep(2);

  // Comienza a girar motor
  printf("Send (Id, Command, Ack): (%d, %d, %d)\tSize: %d\n", message.id_window, message.command, message.ack, sizeof(message));

  RS232_SendBuf(cport_nr, (unsigned char*)&message, sizeof(message));
  printf("Sended message.\n");

  sleep(3);

  // Wait the motor ack message
  int read_bytes = 0;
  while(read_bytes < 24)
  {
    int aux = RS232_PollComport(cport_nr, (unsigned char*) &(message_aux), sizeof(message_aux));
    printf("Aux: %d\n", aux);

    if (aux == -1)
      break;
    else if(read_bytes == 0)
      memcpy(&message, &message_aux, aux);
    else
      memcpy(&message+(read_bytes-1), &message_aux, aux);

    read_bytes = read_bytes + aux;
  }

  RS232_CloseComport(cport_nr);

  if (message.ack == OK)
  {
    printf("Closed window %d\n", message.id_window);
    return -1;
  }
  else
  {
    printf("Failed to close window %d\n", message.id_window);
    return 0;
  }
}
