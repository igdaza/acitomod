#ifndef RS232_COMM_H
#define RS232_COMM_H


#define TIME_100 19
#define PROFILE_ELEMENTS 15

#include <unistd.h>
#include "motor_arduino/message_def.h"
#include "tinyxml.h"
#include "string.h"
#include "init_process.h"

class rs232_comm
{
public:
  enum e_status
  {
     OPEN_STATE = 0,
     CLOSE_STATE = 1,
     NULL_STATE = 2,
  };

  struct t_element
  {
     char hour[6];
     int porcentaje;
  };

  rs232_comm();
  virtual ~rs232_comm();

  void init(int id);
  bool power_up(int porcentaje_apertura);
  bool power_down(int porcentaje_apertura);
  bool is_open();
  e_status read_xml_status();
  bool write_xml_status();
  bool is_active();
  void put_text(char*);
  char* get_text(void);

  // Intervalo functions
  // Init process
  void readFromXmlIntervalo(void);

  // All process
  bool put_open_hour(char*); //Modified state xml file and object
  bool put_close_hour(char*); //Modified state xml file and object
  void put_auto_intervalo_flag(bool); //Modified state xml file and object

  int get_hour_open(void);
  int get_hour_close(void);
  bool isActiveIntervalo(void);

  void checkIntervalo(char*);

  // Profile functions
  // Init process
  void readFromXmlAutoProfileFlag(void);
  void readFromXmlProfileNameIndex(void);

  // All process
  void writeToXmlAutoProfileFlag(bool);
  bool writeToXmlProfileNameIndex(int);

  t_element* readFromXmlProfileElements(const char* profile_name);

  int getIndexProfile(void);
  bool isActiveProfile(void);
  void checkProfileElement(char*);
  void checkHeaterProfileElement(char* current_time);

private:
  bool write_xml_hours(void);

  int cport_nr;
  int bdrate;

  struct t_message
  {
     int id_home;
     int id_window;
     int command;
     int time;
     int status;
     int ack;
  };

  t_message message;
  e_status status;
  int window_id;
  char text[20];
  char window_id_string[20];


  // Profile parameters
  struct t_profile_data {
    char name[20];
    int indexInXmlFile;
    t_element element[PROFILE_ELEMENTS];
  };

  struct t_profile {
    bool autoFlag;
    t_profile_data data;
  };

  t_profile profile;

  // Intervalo parameters
  struct t_timetable {
     char hour_open[6];
     char hour_close[6];
  };

  struct t_intervalo {
    bool autoFlag;
    t_timetable timetable;
  };

  t_intervalo intervalo;

};

#endif

