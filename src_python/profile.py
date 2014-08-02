import xml.etree.ElementTree as ET

class Profile:
  def __init__(self, name):
    self.tree = ET.parse('profile.xml')

    # Profile name
    self.profile_name = name

    # Asociated profile hours
    self.time ={ "00:00": 0, "01:00": 0, "02:00": 0, "03:00": 0, "04:00": 0, "05:00": 0, "06:00": 0, "07:00": 0, "08:00": 0, "09:00": 0, "10:00": 0, "11:00": 0, "12:00": 0, "13:00": 0, "14:00": 0, "15:00": 0, "16:00": 0, "17:00": 0, "18:00": 0, "19:00": 0, "20:00": 0, "21:00": 0, "22:00": 0, "23:00": 0}

    # Applied day in profile
    self.day = {"lunes": "False", "martes": "False", "miercoles": "False", "jueves": "False", "viernes": "False", "sabado": "False", "domingo": "False"}

  def get_name(self):
    return self.profile_name

  def get_all_time(self):
    return self.time

  def get_all_days(self):
    return self.day

  def get_day(self, day):
    if day == "Mon" or day =="lun":
      aux = "lunes"
    elif day == "Tue" or day =="mar":
      aux = "martes"
    elif day == "Wed" or day =="mir":
      aux = "miercoles"
    elif day == "Thu" or day =="jue":
      aux = "jueves"
    elif day == "Fri" or day =="vie":
      aux = "viernes"
    elif day == "Sat" or day =="sab":
      aux = "sabado"
    elif day == "Sun" or day =="dom":
      aux = "domingo"

    return self.day[aux]

  def put_time(self, hour_dic):
    self.time = hour_dic
    return 0 

  def put_day(self, day_dic):
    self.day = day_dic
    return 0 

  def update_object_with_xml(self):
    data_xml = self.tree.getroot()
    for profile_xml in data_xml:
      if profile_xml.attrib['Name'] == self.profile_name:
        self.day['lunes'] = profile_xml.attrib['lunes']
        self.day['martes'] = profile_xml.attrib['martes']
        self.day['miercoles'] = profile_xml.attrib['miercoles']
        self.day['jueves'] = profile_xml.attrib['jueves']
        self.day['viernes'] = profile_xml.attrib['viernes']
        self.day['sabado'] = profile_xml.attrib['sabado']
        self.day['domingo'] = profile_xml.attrib['domingo']
        for element in profile_xml:
          self.time[element.attrib['Hour']] = element.text
  def print_profile(self):
    print self.profile_name
    print self.day
    print self.time
    return 0

  def write_profile_on_xml(self):
    update_profile = False
    data_xml = self.tree.getroot()

    for profile in data_xml:
      if profile.attrib['Name'] == self.profile_name:
        update_profile = True

    if update_profile:
      for profile in data_xml:
        if profile.attrib['Name'] == self.profile_name:
          profile.attrib["lunes"] = str(self.day['lunes'])
          profile.attrib["martes"] = str(self.day['martes'])
          profile.attrib["miercoles"] = str(self.day['miercoles'])
          profile.attrib["jueves"] = str(self.day['jueves'])
          profile.attrib["viernes"] = str(self.day['viernes'])
          profile.attrib["sabado"] = str(self.day['sabado'])
          profile.attrib["domingo"] = str(self.day['domingo'])
          for element in profile: 
            element.text = self.time[element.attrib['Hour']] 
    else:
      profile = ET.SubElement(data_xml, 'Profile')
      profile.set("Name", str(self.profile_name))
      profile.set("lunes", str(self.day['lunes']))
      profile.set("martes", str(self.day['martes']))
      profile.set("miercoles", str(self.day['miercoles']))
      profile.set("jueves", str(self.day['jueves']))
      profile.set("viernes", str(self.day['viernes']))
      profile.set("sabado", str(self.day['sabado']))
      profile.set("domingo", str(self.day['domingo']))

      for key in self.time: 
        element = ET.SubElement(profile, 'element')
        element.set("Hour", key)
        element.text = str(self.time[key]) 

    self.tree.write('profile.xml',encoding="UTF-8", xml_declaration=True)
    return 0

  def remove_profile_on_xml(self):
    return -1

