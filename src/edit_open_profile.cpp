#include "edit_open_profile.h"

OpenProfile::OpenProfile()
{
  //strncpy(name_xml_file, FILE_PROFILE, strlen("profile_file.xml")+1);
  profile_number = 0;
}

OpenProfile::~OpenProfile()
{

}

int OpenProfile::write_profile_xml(void)
{
  char values[200];
  sprintf(values, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", opened_points[0], opened_points[1], opened_points[2], opened_points[3], opened_points[4], opened_points[5], opened_points[6], opened_points[7], opened_points[8], opened_points[9], opened_points[10], opened_points[11], opened_points[12], opened_points[13], opened_points[14]);

  TiXmlDocument doc;
  doc.LoadFile(FILE_PROFILE);

  TiXmlNode* Node = doc.FirstChild("Profile");
  TiXmlNode* LastNode = doc.LastChild("Profile");
  if (Node)
  {
    for(Node = doc.FirstChild("Profile"); Node; Node = Node->NextSibling())
    {
      TiXmlElement* element = Node->ToElement();
      if (!strcmp(element->Attribute("Name"), profile_name))
      {
        TiXmlText* text = new TiXmlText(values);
        element->Clear();
        element->LinkEndChild(text);
        break;
      }
      if(Node == LastNode)
      {
        TiXmlElement * element = new TiXmlElement("Profile");
        element->SetAttribute("Name", profile_name);
        TiXmlText* text = new TiXmlText(values);
        element->LinkEndChild(text);
        doc.LinkEndChild(element);
      }
    }
  }
  else
  {
    TiXmlElement * element = new TiXmlElement("Profile");
    element->SetAttribute("Name", profile_name);
    TiXmlText* text = new TiXmlText(values);
    element->LinkEndChild(text);
    doc.LinkEndChild(element);
  }

  doc.SaveFile(FILE_PROFILE);

  return 0;
}

int OpenProfile::read_profile_names_from_xml(void)
{
  char values[200];

  TiXmlDocument doc;
  doc.LoadFile(FILE_PROFILE);
  int i = 0;

  TiXmlNode* Node = doc.FirstChild("Profile");
  if (Node)
  {
    for(Node = doc.FirstChild("Profile"); Node; Node = Node->NextSibling())
    {
      TiXmlElement* element = Node->ToElement();
      list_profile_names[i] = (char*) malloc(strlen(element->Attribute("Name"))*sizeof(char)+sizeof(char));
      strcpy(list_profile_names[i], element->Attribute("Name"));
      i++;
      profile_number = i;
    }
  }
  else
  {
     return -1;
  }

  return profile_number;
}

int OpenProfile::set_opened_point(int value, int index)
{
  opened_points[index] = value;
  return 0;
}

int OpenProfile::set_profile_name(const char* profile_name_gui)
{
  strcpy(profile_name, profile_name_gui);
  return 0;
}
