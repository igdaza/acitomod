import xml.etree.ElementTree as ET
from rs232_Module import *

class Window:
  def __init__(self, name):
    self.tree = ET.parse('state.xml')

    self.attributes = {"Name": name, "Status": "None", "TimeOpen": "None", "TimeClose": "None", "Auto": "False", "AutoSolar": "False", "AutoProfile": "False", "ProfileName": "None", "ProfileIndex": None}

  def update_window_with_xml(self):
    self.tree = ET.parse('state.xml')
    data = self.tree.getroot()
    for window in data:
      if window.attrib['Name'] == self.attributes['Name']:
        self.attributes['Status'] = window.attrib['Status']
        self.attributes['TimeOpen'] = window.attrib['TimeOpen']
        self.attributes['TimeClose'] = window.attrib['TimeClose']
        self.attributes['Auto'] = window.attrib['Auto']
        self.attributes['AutoSolar'] = window.attrib['AutoSolar']
        self.attributes['AutoProfile'] = window.attrib['AutoProfile']
        self.attributes['ProfileIndex'] = window.attrib['ProfileIndex']
        self.attributes['ProfileName'] = window.attrib['ProfileName']

  def update_xml(self, attribute):
    self.tree = ET.parse('state.xml')
    data = self.tree.getroot()
    for window in data:
      if window.attrib['Name'] == self.attributes['Name']:
        window.set(attribute, str(self.attributes[attribute]))
        self.tree.write('state.xml')
    return False

  def get_name(self):
    return self.attributes['Name']

  def get_profile_name(self):
    return self.attributes['ProfileName']

  def get_auto(self):
    if self.attributes['Auto'] == "True":
        return True
    else:
        return False

  def get_auto_solar(self):
    if self.attributes['AutoSolar'] == "True":
        return True
    else:
        return False

  def get_auto_profile(self):
    if self.attributes['AutoProfile'] == "True":
        return True
    else:
        return False

  def get_index_time_open(self):
    hora_subida = self.attributes['TimeOpen']
    if hora_subida != "None":
      hour = hora_subida.split(':')[0]
      minuto = hora_subida.split(':')[1]
      index_subida = int(hour)*2 + int(minuto)/30
    else:
      index_subida = -1
    return int(index_subida)

  def get_index_time_close(self):
    hora_bajada = self.attributes['TimeClose']
    if hora_bajada != "None":
      hour = hora_bajada.split(':')[0]
      minuto = hora_bajada.split(':')[1]
      index_bajada = int(hour)*2 + int(minuto)/30
    else:
      index_bajada = -1
    return int(index_bajada)

  def get_index_profile(self):
    profile_index = self.attributes['ProfileIndex']
    return int(profile_index)

  def write_time_open(self, time_open):
    self.attributes['TimeOpen'] = time_open
    self.update_xml("TimeOpen")
    return False

  def write_time_close(self, time_close):
    self.attributes['TimeClose'] = time_close
    self.update_xml("TimeClose")
    return False

  def write_auto_state(self, auto_flag):
    self.attributes['Auto'] = str(auto_flag)
    self.update_xml("Auto")
    return False

  def write_auto_solar_state(self, auto_solar_flag):
    self.attributes['AutoSolar'] = str(auto_solar_flag)
    self.update_xml("AutoSolar")
    return False

  def write_auto_profile_state(self, auto_profile_flag):
    self.attributes['AutoProfile'] = str(auto_profile_flag)
    self.update_xml("AutoProfile")
    return False

  def write_profile_name_index(self, profile_name):
    self.attributes['ProfileName'] = str(profile_name)
    self.update_xml("ProfileName")
    return False

  def write_profile_index(self, profile_index):
    self.attributes['ProfileIndex'] = str(profile_index)
    self.update_xml("ProfileIndex")
    return False

  def open(self, porcentaje):
    result = myPowerUP(int(self.attributes['Name'][14:]), porcentaje, 1)
    return result

  def close(self, porcentaje):
    result = myPowerDown(int(self.attributes['Name'][14:]), porcentaje, 1)
    return result

