#ifndef EDIT_OPEN_PROFILE_H
#define EDIT_OPEN_PROFILE_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <stdlib.h>
#include <tinyxml.h>
#include "motor_arduino/message_def.h"

class OpenProfile
{
public:

  OpenProfile();
  virtual ~OpenProfile();

  int write_profile_xml(void);
  int read_profile_names_from_xml(void);
  int set_opened_point(int value, int index);
  int set_profile_name(const char* profile_name);

  char* list_profile_names[20];

private:

  char name_xml_file[17];
  char profile_name[100];
  int opened_points[15];
  int profile_number;

};

#endif
