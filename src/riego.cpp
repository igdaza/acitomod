#include "riego.h"

Riego::Riego(){

  strcpy(timetable_1.hour_start, "0");
  strcpy(timetable_1.hour_stop, "0");
  timetable_1.minutes = 0;
  strcpy(timetable_2.hour_start, "0");
  strcpy(timetable_2.hour_stop, "0");
  timetable_2.minutes = 0;

}

Riego::~Riego(){

}

void Riego::init(int id)
{

}

void Riego::turn_on()
{
   strcpy(text_message, M_TURN_ON); 
   printf("Encendido sector.\n");

}

void Riego::turn_off()
{
   strcpy(text_message, M_TURN_OFF); 
   printf("Apagado sector.\n");
}

char* Riego::get_text()
{
   return text_message;
}

bool Riego::put_hour_1(char* hour)
{
   strncpy(timetable_1.hour_start, hour, sizeof(timetable_1.hour_start));

   if(strcmp(timetable_1.hour_start, "0") != 0)
   {
      int hora = 0;
      int minutos = 0;
      sscanf(timetable_1.hour_start, "%d:%d", &hora, &minutos);
      if((minutos + timetable_1.minutes) >= 60)
      {
        hora = hora + 1;
        minutos = (minutos + timetable_1.minutes)%60; 
      }
      else
        minutos = minutos + timetable_1.minutes;

      printf("Timetable_Start: %s\n", timetable_1.hour_start);
      sprintf(timetable_1.hour_stop, "%02d:%02d", hora, minutos);
      printf("Timetable_Stop: %s\n", timetable_1.hour_stop);
   }
   return true;
}

bool Riego::put_minutes_1(int minutes)
{
   timetable_1.minutes = minutes;
   if(strcmp(timetable_1.hour_start, "0") != 0)
   {
      int hora = 0;
      int minutos = 0;
      sscanf(timetable_1.hour_start, "%d:%d", &hora, &minutos);
      if((minutos + timetable_1.minutes) >= 60)
      {
        hora = hora + 1;
        minutos = (minutos + timetable_1.minutes)%60; 
      }
      else
        minutos = minutos + timetable_1.minutes;

      printf("Timetable_Start: %s\n", timetable_1.hour_start);
      sprintf(timetable_1.hour_stop, "%02d:%02d", hora, minutos);
      printf("Timetable_Stop: %s\n", timetable_1.hour_stop);
   }

   return true;
}

bool Riego::put_hour_2(char* hour)
{
   strncpy(timetable_2.hour_start, hour, sizeof(timetable_2.hour_start));

   if(strcmp(timetable_2.hour_start, "0") != 0)
   {
      int hora = 0;
      int minutos = 0;
      sscanf(timetable_2.hour_start, "%d:%d", &hora, &minutos);
      if((minutos + timetable_2.minutes) >= 60)
      {
        hora = hora + 1;
        minutos = (minutos + timetable_2.minutes)%60; 
      }
      else
        minutos = minutos + timetable_2.minutes;

      printf("Timetable_Start: %s\n", timetable_2.hour_start);
      sprintf(timetable_2.hour_stop, "%02d:%02d", hora, minutos);
      printf("Timetable_Stop: %s\n", timetable_2.hour_stop);
   }

   return true;
}

bool Riego::put_minutes_2(int minutes)
{
   timetable_2.minutes = minutes;
   if(strcmp(timetable_2.hour_start, "0") != 0)
   {
      int hora = 0;
      int minutos = 0;
      sscanf(timetable_2.hour_start, "%d:%d", &hora, &minutos);
      if((minutos + timetable_2.minutes) >= 60)
      {
        hora = hora + 1;
        minutos = (minutos + timetable_2.minutes)%60; 
      }
      else
        minutos = minutos + timetable_2.minutes;

      printf("Timetable_Start: %s\n", timetable_2.hour_start);
      sprintf(timetable_2.hour_stop, "%02d:%02d", hora, minutos);
      printf("Timetable_Stop: %s\n", timetable_2.hour_stop);
   }

   return true;
}

Riego::e_status Riego::get_status()
{
   Riego::e_status aux;
   return aux;
}

void Riego::check(char* current_time)
{
    if(strcmp(current_time,timetable_1.hour_start) == 0 || strcmp(current_time,timetable_2.hour_start) == 0)
      turn_on();
    else if(strcmp(current_time,timetable_1.hour_stop) == 0 || strcmp(current_time,timetable_2.hour_stop) == 0)
      turn_off();

}
