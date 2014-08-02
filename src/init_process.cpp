#include <string.h>
#include "init_process.h"

void init_window_id(int id, char* window_id)
{
  
  if (id == ID_HABITACION_1) 
    strcpy(window_id, "ID_HABITACION_1");
  else if (id == ID_HABITACION_2)
    strcpy(window_id, "ID_HABITACION_2");
  else if (id == ID_HABITACION_3)
    strcpy(window_id, "ID_HABITACION_3");
  else if (id == ID_HABITACION_4)
    strcpy(window_id, "ID_HABITACION_4");
  else if (id == ID_HABITACION_5)
    strcpy(window_id, "ID_HABITACION_5");
  else if (id == ID_HABITACION_6)   
    strncpy(window_id, "ID_HABITACION_6", strlen("ID_HABITACION_3"));
  else if (id == ID_HABITACION_7)      
    strcpy(window_id, "ID_HABITACION_7");
  else if (id == ID_HABITACION_8)      
    strcpy(window_id, "ID_HABITACION_8");
  else if (id == ID_HABITACION_9)
    strcpy(window_id, "ID_HABITACION_9");
  else if (id == ID_HABITACION_10)
    strcpy(window_id, "ID_HABITACION_10");
  else if (id == ID_HABITACION_11)
    strcpy(window_id, "ID_HABITACION_11");
  else if (id == ID_HABITACION_12)
    strcpy(window_id, "ID_HABITACION_12");
  else if (id == ID_HABITACION_13)
    strcpy(window_id, "ID_HABITACION_13");
  else if (id == ID_HABITACION_14)
    strcpy(window_id, "ID_HABITACION_14");
  else if (id == ID_HABITACION_15)
    strcpy(window_id, "ID_HABITACION_15");
  else if (id == ID_HABITACION_16)
    strcpy(window_id, "ID_HABITACION_16");
}
