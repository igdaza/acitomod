#ifndef RIEGO_H
#define RIEGO_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <time.h>

class Riego
{
public:

  enum e_status {
     TURN_ON = 0,
     TURN_OFF = 1,
  };

  struct t_horario {
     char hour_start[5];
     unsigned int minutes;
     char hour_stop[5];
  };

  Riego();
  virtual ~Riego();

  void init(int id);
  void turn_on();
  void turn_off();

  bool put_hour_1(char*);
  bool put_hour_2(char*);
  bool put_minutes_1(int);
  bool put_minutes_2(int);

  e_status get_status();

  void check(char*);
  char* get_text();

private:

  struct t_message {
     int id_home;
     int id_sector;
     int command;
     int time;
     int status;
     int ack;
  };

  #define M_TURN_ON "Turn On"
  #define M_TURN_OFF "Turn Off"

  int cport_nr;
  int bdrate;
  t_message message;
  e_status status;
  bool is_auto;
  t_horario timetable_1; 
  t_horario timetable_2; 
  char text_message[10];

};

#endif


