#include "rs232_comm.h"
#include "rs232.h"
#include <stdio.h>
#include <stdlib.h>


rs232_comm::rs232_comm()
{
}


rs232_comm::~rs232_comm() 
{ 
}

void rs232_comm::init(int id)
{
  cport_nr = 16; // ACP220
  bdrate = 9600;

  message.id_home = ID_HOME;
  message.id_window = id;
  message.command = POWER_NULL;
  message.time = 0;
  message.status = NULL_STATUS;
  message.ack = NO_OK;

  window_id = id;
  status = NULL_STATE;
  memset(intervalo.timetable.hour_open, '\0', sizeof(intervalo.timetable.hour_open));
  memset(intervalo.timetable.hour_close, '\0', sizeof(intervalo.timetable.hour_close));
  init_window_id(id, window_id_string);
  for(int i=0; i < PROFILE_ELEMENTS; i++)
    memset(profile.data.element[i].hour, '\0', 6);
  profile.data.indexInXmlFile = 0;
}


/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
bool rs232_comm::power_up(int porcentaje_apertura)
{

  bool return_value;
  if(RS232_OpenComport(cport_nr, bdrate))
  {
    printf("Can not open comport\n");
    return(false);
  }


  t_message message_aux;

  message.id_window = window_id;
  message.command = POWER_UP;
  message.time = porcentaje_apertura*TIME_100*10; // milisegundos
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
  
  if (message.ack == OK)
  {
    printf("Opened window %d\n", message.id_window);
    memcpy(text,"OPEN_STATE", sizeof("OPEN_STATE"));
    status = OPEN_STATE;
    return_value = true;
  }
  else
  {
    printf("Failed to open window %d\n", message.id_window);
    memcpy(text,"Opened window - Fail", sizeof("Opened window - Fail"));
    return_value = false;
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
bool rs232_comm::power_down(int porcentaje_apertura)
{
  message.command = POWER_DOWN;
  message.time = porcentaje_apertura*TIME_100*10; // milisegundos
  message.ack = NO_OK;

  t_message message_aux;

  if(RS232_OpenComport(cport_nr, bdrate))
  {
    printf("Can not open comport\n");
    return(false);
  }
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
    memcpy(text,"CLOSE_STATE", sizeof("CLOSE_STATE"));
    status = CLOSE_STATE;
    return (true);
  }
  else
  {
    printf("Failed to close window %d\n", message.id_window);
    memcpy(text,"Closed window - Fail", sizeof("Closed window - Fail"));
    return (false);
  }
}

/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
bool rs232_comm::is_open()
{
   if(status == OPEN_STATE)
      return(true);
   else
      return(false);
}

/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
rs232_comm::e_status rs232_comm::read_xml_status()
{
  char window_status[100];

  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
      strcpy(window_status, AuxElement->Attribute("Status"));
      if (!strcmp(window_status, "OPEN_STATE"))
      {
        status = OPEN_STATE;
        memcpy(text, "OPEN_STATE", sizeof("OPEN_STATE"));
      }
      if (!strcmp(window_status, "CLOSE_STATE"))
      {
        status = CLOSE_STATE;
        memcpy(text, "CLOSE_STATE", sizeof("CLOSE_STATE"));
      }
      if (!strcmp(window_status, "NULL_STATE"))
      {
        status = NULL_STATE;
        memcpy(text, "NULL_STATE", sizeof("NULL_STATE"));
      }
    }
  }

  return status;
}
  
/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
bool rs232_comm::write_xml_status(void)
{
  char window_status[100];

  if (status == OPEN_STATE)
    strcpy(window_status, "OPEN_STATE");
  else if (status == CLOSE_STATE)
    strcpy(window_status, "CLOSE_STATE");
  else if (status == NULL_STATE)
    strcpy(window_status, "NULL_STATE");

  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
        AuxElement->SetAttribute("Status", window_status);

  }
  doc.SaveFile(FILE_STATE);

  return true;
}

char* rs232_comm::get_text(void)
{
   return text;
}

bool rs232_comm::put_open_hour(char* hour)
{
   strcpy(intervalo.timetable.hour_open, hour);
   write_xml_hours();
   return true;
}
bool rs232_comm::put_close_hour(char* hour)
{
   strcpy(intervalo.timetable.hour_close, hour);
   write_xml_hours();
   return true;
}

void rs232_comm::checkIntervalo(char* current_time)
{
    printf("current_time: %s\n", current_time);
    printf("hour_open: %s\n", intervalo.timetable.hour_open);
    printf("hour_close: %s\n", intervalo.timetable.hour_close);
    if(strcmp(current_time, intervalo.timetable.hour_open) == 0)
    {
      printf("Automatica open window acction.\n");
      power_up(100);
    }
    else if(strcmp(current_time, intervalo.timetable.hour_close) == 0)
    {
      printf("Automatica close window acction.\n");
      power_down(100);
    }
}


bool rs232_comm::write_xml_hours(void)
{
  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);
  char aux_1[10];
  memcpy(aux_1, intervalo.timetable.hour_open, sizeof(intervalo.timetable.hour_open));
  aux_1[sizeof(intervalo.timetable.hour_open)]='\0';
  char aux_2[10];
  memcpy(aux_2, intervalo.timetable.hour_close, sizeof(intervalo.timetable.hour_close));
  aux_2[sizeof(intervalo.timetable.hour_close)]='\0';

  printf("hora: %s %s %s\n", aux_1, aux_2, window_id_string);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
        AuxElement->SetAttribute("TimeOpen", aux_1);
        AuxElement->SetAttribute("TimeClose", aux_2);
    }

  }
  doc.SaveFile(FILE_STATE);

  return true;
}

bool rs232_comm::writeToXmlProfileNameIndex(int combo_index)
{
  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);
  char index[3];
  sprintf(index, "%d", combo_index);

  TiXmlNode* Node = NULL;
  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
        AuxElement->SetAttribute("ProfileNameIndex", index);
    }

  }
  doc.SaveFile(FILE_STATE);

  profile.data.indexInXmlFile = combo_index;

  return true;
}

void rs232_comm::readFromXmlIntervalo(void)
{

  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
      memcpy(intervalo.timetable.hour_open, AuxElement->Attribute("TimeOpen"), sizeof(intervalo.timetable.hour_open));
      memcpy(intervalo.timetable.hour_close, AuxElement->Attribute("TimeClose"), sizeof(intervalo.timetable.hour_close));

      if(strncmp(AuxElement->Attribute("Auto"), "True", 4) == 0)
         intervalo.autoFlag = true;
      else
         intervalo.autoFlag = false;
    }
  }
}


int rs232_comm::get_hour_open(void)
{
   int hour = 0;
   int minute = 0;

   char aux[10];
   memcpy(aux, intervalo.timetable.hour_open, sizeof(intervalo.timetable.hour_open));
   aux[sizeof(intervalo.timetable.hour_open)]='\0';

   sscanf(aux, "%d : %d", &hour, &minute);
   if(minute == 0)
     return hour*2;
   else
     return hour*2+1;
}

int rs232_comm::get_hour_close(void)
{
   int hour = 0;
   int minute = 0;

   char aux[10];
   memcpy(aux, intervalo.timetable.hour_close, sizeof(intervalo.timetable.hour_close));
   aux[sizeof(intervalo.timetable.hour_close)]='\0';

   sscanf(aux, "%d : %d", &hour, &minute);
   if(minute == 0)
     return hour*2;
   else
     return hour*2+1;
}

void rs232_comm::put_auto_intervalo_flag(bool status)
{
  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
        if(status)
        {
          AuxElement->SetAttribute("Auto", "True");
          intervalo.autoFlag = true;
        }
        else
        {
          AuxElement->SetAttribute("Auto", "False");
          intervalo.autoFlag = false;
        }
    }

  }
  doc.SaveFile(FILE_STATE);
}

void rs232_comm::writeToXmlAutoProfileFlag(bool status)
{
  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
        if(status)
        {
          AuxElement->SetAttribute("AutoProfile", "True");
          profile.autoFlag = true;
        }
        else
        {
          AuxElement->SetAttribute("AutoProfile", "False");
          profile.autoFlag = false;
        }
    }

  }
  doc.SaveFile(FILE_STATE);
}

void rs232_comm::readFromXmlAutoProfileFlag(void)
{

  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
      if(strncmp(AuxElement->Attribute("AutoProfile"), "True", 4) == 0)
         profile.autoFlag = true;
      else
         profile.autoFlag = false;
    }
  }
}

void rs232_comm::readFromXmlProfileNameIndex(void)
{

  TiXmlDocument doc;
  doc.LoadFile(FILE_STATE);

  TiXmlNode* Node = NULL;

  for(Node = doc.FirstChild("Window"); Node; Node = Node->NextSibling())
  {
    TiXmlElement* AuxElement = Node->ToElement();
    if (!strcmp(AuxElement->Attribute("Name"), window_id_string))
    {
       sscanf(AuxElement->Attribute("ProfileNameIndex"), "%d", &(profile.data.indexInXmlFile));
    }
  }
}

bool rs232_comm::isActiveIntervalo(void)
{
   return intervalo.autoFlag;
}

bool rs232_comm::isActiveProfile(void)
{
   return profile.autoFlag;
}

int rs232_comm::getIndexProfile(void)
{
   return profile.data.indexInXmlFile;
}

rs232_comm::t_element* rs232_comm::readFromXmlProfileElements(const char* profile_name)
{
  TiXmlDocument doc;
  doc.LoadFile(FILE_PROFILE);
  const char* porcentajes;

  TiXmlNode* Node = doc.FirstChild("Profile");
  if (Node)
  {
    for(Node = doc.FirstChild("Profile"); Node; Node = Node->NextSibling())
    {
      TiXmlElement* element = Node->ToElement();
      if(profile_name != NULL && element->Attribute("Name") != NULL && strcmp(profile_name, element->Attribute("Name")) == 0)
      {
          porcentajes = element->GetText();

          sscanf(porcentajes, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &(profile.data.element[0].porcentaje), &(profile.data.element[1].porcentaje), &(profile.data.element[2].porcentaje), &(profile.data.element[3].porcentaje), &(profile.data.element[4].porcentaje), &(profile.data.element[5].porcentaje), &(profile.data.element[6].porcentaje), &(profile.data.element[7].porcentaje), &(profile.data.element[8].porcentaje), &(profile.data.element[9].porcentaje), &(profile.data.element[10].porcentaje), &(profile.data.element[11].porcentaje), &(profile.data.element[12].porcentaje), &(profile.data.element[13].porcentaje), &(profile.data.element[14].porcentaje));

          for(int i=0; i < PROFILE_ELEMENTS; i++)
          {
            sprintf(profile.data.element[i].hour, "%02d:00", i+7);
          }
          break;
          //sprintf(profile[1].hour, "23:31");
          //sprintf(profile[2].hour, "23:32");
          //sprintf(profile[3].hour, "23:33");
          //for(int i=0; i < PROFILE_ELEMENTS; i++)
          //  printf("Hora: %s\n", profile[i].hour);
      }
    }
  }
  return profile.data.element;
}

void rs232_comm::checkProfileElement(char* current_time)
{
    for(int i= 0; i < PROFILE_ELEMENTS; i++)
    {
      if(memcmp(current_time, profile.data.element[i].hour, 5) == 0)
      {
        printf("Automatica profile open window acction.\n");
        if(profile.data.element[i-1].porcentaje > profile.data.element[i].porcentaje)
        {
          printf("Bajando ... %d\n", profile.data.element[i].porcentaje);
          power_down(profile.data.element[i].porcentaje);
        }
        else if(profile.data.element[i-1].porcentaje < profile.data.element[i].porcentaje)
        {
          printf("Subiendo ...%d\n", profile.data.element[i].porcentaje);
          power_up(profile.data.element[i].porcentaje);
        }
        else
          printf("Igual ...\n");
      }
    }
}

void rs232_comm::checkHeaterProfileElement(char* current_time)
{
  for(int i= 1; i < PROFILE_ELEMENTS; i++)
  {
    if(profile.data.element[i].porcentaje != profile.data.element[i-1].porcentaje)
    {
      if(memcmp(current_time, profile.data.element[i].hour, 5) == 0)
      {
        printf("Automatica heater profile acction.\n");
        if(profile.data.element[i].porcentaje == 0)
        {
          printf("Apagando caldera ... %d\n", profile.data.element[i].porcentaje);
          power_down(profile.data.element[i].porcentaje);
        }
        else
        {
          printf("Encendiendo caldera ...%d\n", profile.data.element[i].porcentaje);
          power_up(profile.data.element[i].porcentaje);
        }
      }
    }
  }
}
