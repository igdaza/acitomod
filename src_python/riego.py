from gi.repository import Gtk
from rs232_Module import *
import gobject
import json

class List_Time:
  def __init__(self, treeviewsector, riego_file):

    self.time_table = {'0': ['', -1, False, 0, False],
                       '1': ['', -1, False, 0, False],
                       '2': ['', -1, False, 0, False],
                       '3': ['', -1, False, 0, False],
                       '4': ['', -1, False, 0, False]}

    contenido = riego_file.read()
    aux = json.loads(contenido, encoding='utf-8')
    for (key, a) in zip(self.time_table.keys(), aux.values()):
       self.time_table[key] = a

    self.lista=Gtk.ListStore(str, int, bool, int, bool)
    treeviewsector.set_model(self.lista)

    self.lista.append(self.time_table['0'])
    self.lista.append(self.time_table['1'])
    self.lista.append(self.time_table['2'])
    self.lista.append(self.time_table['3'])
    self.lista.append(self.time_table['4'])

    def edited_hour(widget, path, text, lista, riego_file):
      lista[path][0] = text
      self.time_table[path][0] = text
      riego_file.seek(0)
      riego_file.write(json.dumps(self.time_table, encoding='utf-8'))
      riego_file.write("                             ")

    def edited_duration(widget, path, text, lista, riego_file):
      lista[path][1] = int(text)
      self.time_table[path][1] = int(text)
      riego_file.seek(0)
      riego_file.write(json.dumps(self.time_table, encoding='utf-8'))
      riego_file.write("                             ")

    def on_start(widget, path):
      for (index_lista, key) in zip(range(len(lista)), self.time_table.keys()):
        lista[index_lista][2] = False
        self.time_table[key][2] = False

      lista[path][2] = True
      self.time_table[path][2] = True

      riego_file.seek(0)
      riego_file.write(json.dumps(self.time_table, encoding='utf-8'))
      riego_file.write("                             ")

    def on_delete(widget, path):
      lista[path][2] = not lista[path][2]
      lista[path][0] = "" 
      lista[path][1] = -1
      lista[path][2] = not lista[path][2]

      self.time_table[path] = ['', -1, False, 0, False]

      riego_file.seek(0)
      riego_file.write(json.dumps(self.time_table, encoding='utf-8'))
      riego_file.write("                             ")

    render_hour=Gtk.CellRendererText()
    render_hour.set_property("editable", True)
    render_hour.connect("edited", edited_hour, self.lista, riego_file)
    columna_hora=Gtk.TreeViewColumn("Hora Inicio",render_hour, text=0)
    treeviewsector.append_column(columna_hora)

    render_duration=Gtk.CellRendererText()
    render_duration.set_property("editable", True)
    render_duration.connect("edited", edited_duration, self.lista, riego_file)
    columna_duracion=Gtk.TreeViewColumn("Duracion (minutos)",render_duration,text=1)
    treeviewsector.append_column(columna_duracion)

    renderer_toggle = Gtk.CellRendererToggle()
    renderer_toggle.connect("toggled", on_start)
    column_toggle = Gtk.TreeViewColumn("Manual", renderer_toggle, active=2)
    treeviewsector.append_column(column_toggle)

    renderer_progress = Gtk.CellRendererProgress()
    column_progress = Gtk.TreeViewColumn("Progress", renderer_progress, value=3, inverted=2)
    treeviewsector.append_column(column_progress)

    renderer_toggle = Gtk.CellRendererToggle()
    renderer_toggle.connect("toggled", on_delete)
    column_toggle = Gtk.TreeViewColumn("Delete", renderer_toggle, active=4)
    treeviewsector.append_column(column_toggle)

  def get_time_table(self):
    return self.time_table

  def get_manual_time(self):
    duration = -1
    for index in self.time_table.keys():
      if self.time_table[index][2] == True:
        duration = self.time_table[index][1]
        break

    return [index, int(duration)]

  def set_time_progress(self, path, value):
    self.lista[path][3] = value
    self.time_table[path][3] = value
    return False

class Sector:
  def __init__(self, treeviewsector, sector, encender_button, apagar_button, auto_sector):
    file_name = str(sector)+'.txt'
    self.riego_file = open(file_name, 'r+')
    self.time_table = List_Time(treeviewsector, self.riego_file)
    self.sector_string = sector
    self.sector_id = 100+int(sector.split('_')[1])
    self.relative_time = 0
    self.counter = 0
    self.duration = 0
    self.key = 0
    self.auto_sector = auto_sector

    def set_auto_sector(self, auto_sector):
      self.auto_sector = auto_sector 
      return auto_sector;

    def on_apagar(self, sector_string, sector_id, time_table):
      print ("Apagado sector: "+ sector_string)
      self.key = 0
      self.duration = 0
      result = myPowerDown(int(sector_id), 0, 0)

    encender_button.connect("clicked", self.on_encender, self.sector_string, self.sector_id, self.time_table)
    apagar_button.connect("clicked", on_apagar, self.sector_string, self.sector_id, self.time_table)

  def on_encender(self, data, sector_string, sector_id, time_table):
    print ("Regando sector: "+ sector_string)
    [self.key, self.duration] = time_table.get_manual_time()
    print ("Key: "+ str(self.key))
    print ("Minutos: "+ str(self.duration))
    result = myPowerUP(int(sector_id), self.duration, 0)


  def is_time_to_start(self, time):
    ret = False

    if self.auto_sector.get_active() == True:
      for (key, element) in zip(self.time_table.get_time_table().keys(), self.time_table.get_time_table().values()):
        if element[0] == time:
          ret = True
          self.duration = element[1]
          self.key = key
          print(self.key + ' key')
          print(self.sector_string +' encendido')
          result = myPowerUP(int(self.sector_id), self.duration, 0)
          print(time)
          print(self.duration)
      
      print("Relative_time: "+ str(self.relative_time))
      print("Duration: "+ str(self.duration))
      if self.duration != 0:
        value = (float(self.relative_time)/self.duration)*100
        self.relative_time = self.relative_time + 1
      
        self.time_table.set_time_progress(str(self.key), int(value))
      
      if self.relative_time == self.duration:
        self.duration = 0
        value = 0
        self.relative_time = 0

        self.time_table.set_time_progress(str(self.key), int(value))


    return [ret, self.duration]

  def close_file(self):
    self.riego_file.close
    return 0
