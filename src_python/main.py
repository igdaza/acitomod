#! /usr/bin/env python
# -*- coding: UTF-8 -*-
# /home/pi/Desktop/domotica-python.desktop
# ln -s /home/pi/Desktop/domotica-python.desktop ~/.config/autostart/

# Importamos los módulos necesarios
from gi.repository import Gtk
import sys
import pygtk
import window
import profile
from year_time import *
from riego import * 
import gobject
import time;
import xml.etree.ElementTree as ET
import xml.dom.minidom


# Interfaz gráfica (gtk-glade), Clase para el Loop principal (de la GUI)
class MainGui:
    "GTK/Glade User interface. This is a pyGTK window"
    def __init__(self):

        # Tablas de widgets name
        windows_labels = {
          "ID_HABITACION_1": ["auto_habitacion_1","hora_subida_habitacion_1","hora_bajada_habitacion_1","auto_perfil_habitacion_1","perfil_habitacion_1", "text_habitacion_1", "auto_solar_1"],
          "ID_HABITACION_2": ["auto_habitacion_2","hora_subida_habitacion_2","hora_bajada_habitacion_2","auto_perfil_habitacion_2","perfil_habitacion_2", "text_habitacion_2", "auto_solar_2"],
          "ID_HABITACION_3": ["auto_habitacion_3","hora_subida_habitacion_3","hora_bajada_habitacion_3","auto_perfil_habitacion_3","perfil_habitacion_3", "text_habitacion_3", "auto_solar_3"],
          "ID_HABITACION_4": ["auto_habitacion_4","hora_subida_habitacion_4","hora_bajada_habitacion_4","auto_perfil_habitacion_4","perfil_habitacion_4", "text_habitacion_4", "auto_solar_4"],
          "ID_HABITACION_5": ["auto_habitacion_5","hora_subida_habitacion_5","hora_bajada_habitacion_5","auto_perfil_habitacion_5","perfil_habitacion_5", "text_habitacion_5", "auto_solar_5"],
          "ID_HABITACION_6": ["auto_habitacion_6","hora_subida_habitacion_6","hora_bajada_habitacion_6","auto_perfil_habitacion_6","perfil_habitacion_6", "text_habitacion_6", "auto_solar_6"],
          "ID_HABITACION_7": ["auto_habitacion_7","hora_subida_habitacion_7","hora_bajada_habitacion_7","auto_perfil_habitacion_7","perfil_habitacion_7", "text_habitacion_7", "auto_solar_7"],
          "ID_HABITACION_8": ["auto_habitacion_8","hora_subida_habitacion_8","hora_bajada_habitacion_8","auto_perfil_habitacion_8","perfil_habitacion_8", "text_habitacion_8", "auto_solar_8"],
          "ID_HABITACION_9": ["auto_habitacion_9","hora_subida_habitacion_9","hora_bajada_habitacion_9","auto_perfil_habitacion_9","perfil_habitacion_9", "text_habitacion_9", "auto_solar_9"],
          "ID_HABITACION_10": ["auto_habitacion_10","hora_subida_habitacion_10","hora_bajada_habitacion_10","auto_perfil_habitacion_10","perfil_habitacion_10", "text_habitacion_10", "auto_solar_10"],
          "ID_HABITACION_11": ["auto_habitacion_11","hora_subida_habitacion_11","hora_bajada_habitacion_11","auto_perfil_habitacion_11","perfil_habitacion_11", "text_habitacion_11", "auto_solar_11"],
          "ID_HABITACION_12": ["auto_habitacion_12","hora_subida_habitacion_12","hora_bajada_habitacion_12","auto_perfil_habitacion_12","perfil_habitacion_12", "text_habitacion_12", "auto_solar_12"],
          "ID_HABITACION_13": ["auto_habitacion_13","hora_subida_habitacion_13","hora_bajada_habitacion_13","auto_perfil_habitacion_13","perfil_habitacion_13", "text_habitacion_13", "auto_solar_13"],
          "ID_HABITACION_14": ["auto_habitacion_14","hora_subida_habitacion_14","hora_bajada_habitacion_14","auto_perfil_habitacion_14","perfil_habitacion_14", "text_habitacion_14", "auto_solar_14"],
          "ID_HABITACION_15": ["auto_habitacion_15","hora_subida_habitacion_15","hora_bajada_habitacion_15","auto_perfil_habitacion_15","perfil_habitacion_15", "text_habitacion_15", "auto_solar_15"],
          "ID_HABITACION_16": ["auto_habitacion_16","hora_subida_habitacion_16","hora_bajada_habitacion_16","auto_perfil_habitacion_16","perfil_habitacion_16", "text_habitacion_16", "auto_solar_16"],
          "PROFILE": ["profile_name", "perfil_selection_combo", "00:00","01:00" ,"02:00" ,"03:00" ,"04:00" ,"05:00" ,"06:00" ,"07:00","08:00" ,"09:00" ,"10:00" ,"11:00" ,"12:00" ,"13:00" ,"14:00" ,"15:00" ,"16:00" ,"17:00" ,"18:00" ,"19:00" ,"20:00","21:00" ,"22:00", "23:00", "lunes", "martes", "miercoles", "jueves", "viernes", "sabado", "domingo"]}

        horas_persianas = ["00:00","00:30", "01:00", "01:30" ,"02:00", "02:30" ,"03:00", "03:30" ,"04:00", "04:30" ,"05:00", "05:30" ,"06:00", "06:30" ,"07:00","07:30", "08:00", "08:30" ,"09:00", "09:30" ,"10:00", "10:30" ,"11:00", "11:30" ,"12:00", "12:30" ,"13:00", "13:30" ,"14:00", "14:30" ,"15:00", "15:30" ,"16:00", "16:30" ,"17:00", "17:30" ,"18:00", "18:30" ,"19:00", "19:30" ,"20:00", "20:30","21:00", "21:30" ,"22:00", "22:30", "23:00", "23:30"]

        # index persianas widgets
        self.index_auto = windows_labels['ID_HABITACION_1'].index('auto_habitacion_1')
        self.index_hora_subida = windows_labels['ID_HABITACION_1'].index('hora_subida_habitacion_1')
        self.index_hora_bajada = windows_labels['ID_HABITACION_1'].index('hora_bajada_habitacion_1')
        self.index_auto_perfil = windows_labels['ID_HABITACION_1'].index('auto_perfil_habitacion_1')
        self.index_perfil = windows_labels['ID_HABITACION_1'].index('perfil_habitacion_1')
        self.index_message_text = windows_labels['ID_HABITACION_1'].index('text_habitacion_1')
        self.index_auto_solar = windows_labels['ID_HABITACION_1'].index('auto_solar_1')

        # index perfiles widgets
        self.index_profile_name = windows_labels['PROFILE'].index('profile_name')
        self.index_perfil_selection_combo = windows_labels['PROFILE'].index('perfil_selection_combo')
        index_00_00 = windows_labels['PROFILE'].index('00:00')
        index_01_00 = windows_labels['PROFILE'].index('01:00')
        index_02_00 = windows_labels['PROFILE'].index('02:00')
        index_03_00 = windows_labels['PROFILE'].index('03:00')
        index_04_00 = windows_labels['PROFILE'].index('04:00')
        index_05_00 = windows_labels['PROFILE'].index('05:00')
        index_06_00 = windows_labels['PROFILE'].index('06:00')
        index_07_00 = windows_labels['PROFILE'].index('07:00')
        index_08_00 = windows_labels['PROFILE'].index('08:00')
        index_09_00 = windows_labels['PROFILE'].index('09:00')
        index_10_00 = windows_labels['PROFILE'].index('10:00')
        index_11_00 = windows_labels['PROFILE'].index('11:00')
        index_12_00 = windows_labels['PROFILE'].index('12:00')
        index_13_00 = windows_labels['PROFILE'].index('13:00')
        index_14_00 = windows_labels['PROFILE'].index('14:00')
        index_15_00 = windows_labels['PROFILE'].index('15:00')
        index_16_00 = windows_labels['PROFILE'].index('16:00')
        index_17_00 = windows_labels['PROFILE'].index('17:00')
        index_18_00 = windows_labels['PROFILE'].index('18:00')
        index_19_00 = windows_labels['PROFILE'].index('19:00')
        index_20_00 = windows_labels['PROFILE'].index('20:00')
        index_21_00 = windows_labels['PROFILE'].index('21:00')
        index_22_00 = windows_labels['PROFILE'].index('22:00')
        index_23_00 = windows_labels['PROFILE'].index('23:00')
        index_lunes =     windows_labels['PROFILE'].index('lunes')
        index_martes =    windows_labels['PROFILE'].index('martes')
        index_miercoles = windows_labels['PROFILE'].index('miercoles')
        index_jueves =    windows_labels['PROFILE'].index('jueves')
        index_viernes =   windows_labels['PROFILE'].index('viernes')
        index_sabado =    windows_labels['PROFILE'].index('sabado')
        index_domingo =   windows_labels['PROFILE'].index('domingo')

        self.list_hours_profile = [index_00_00, index_01_00, index_02_00, index_03_00 ,index_04_00 ,index_05_00 ,index_06_00 ,index_07_00 ,index_08_00 ,index_09_00 ,index_10_00 ,index_11_00 ,index_12_00 ,index_13_00 ,index_14_00 ,index_15_00 ,index_16_00 ,index_17_00 ,index_18_00 ,index_19_00 ,index_20_00 ,index_21_00 ,index_22_00 ,index_23_00]

        self.list_days_profile = [index_lunes, index_martes, index_miercoles, index_jueves, index_viernes, index_sabado, index_domingo]

        #meses
        self.meses = {'Jan': TimeByDay('enero'), 'Feb': TimeByDay('febrero'), 'Mar': TimeByDay('marzo'), 'Apr': TimeByDay('abril'), 'May': TimeByDay('mayo'), 'Jun': TimeByDay('junio'), 'Jul': TimeByDay('julio'), 'Aug': TimeByDay('agosto'), 'Sep': TimeByDay('septiembre'), 'Oct': TimeByDay('octubre'), 'Nov': TimeByDay('noviembre'), 'Dec': TimeByDay('diciembre')}

        # Le indicamos al programa que archivo XML de glade usar
        filename = "../src/gui/main_gui.glade"
        self.builder = Gtk.Builder()
        self.builder.add_from_file(filename)
        self.domotica_win = self.builder.get_object ("domotica_win")
        self.edit_profiles_win = self.builder.get_object ("edit_profiles_win")


        if self.domotica_win:
          self.domotica_win.connect("destroy", Gtk.main_quit)

        self.builder.connect_signals(self)

        # Lista de gtk widgets.
        self.gtk_widget_new = {}
        for window_label in windows_labels.values():
          for name_widget in window_label:
             self.gtk_widget_new[name_widget] = self.builder.get_object(name_widget)

        lista_index_persianas = ["ID_HABITACION_1", "ID_HABITACION_2", "ID_HABITACION_3", "ID_HABITACION_4", "ID_HABITACION_5", "ID_HABITACION_6", "ID_HABITACION_7", "ID_HABITACION_8", "ID_HABITACION_9", "ID_HABITACION_10", "ID_HABITACION_11", "ID_HABITACION_12", "ID_HABITACION_13", "ID_HABITACION_14", "ID_HABITACION_15", "ID_HABITACION_16"]

        lista_abrir_boton = ["abrir_habitacion_1", "abrir_habitacion_2", "abrir_habitacion_3", "abrir_habitacion_4", "abrir_habitacion_5", "abrir_habitacion_6", "abrir_habitacion_7", "abrir_habitacion_8", "abrir_habitacion_9", "abrir_habitacion_10", "abrir_habitacion_11", "abrir_habitacion_12", "abrir_habitacion_13", "abrir_habitacion_14", "abrir_habitacion_15", "abrir_habitacion_16"]

        for (abrir_boton, indice_persiana) in zip(lista_abrir_boton, lista_index_persianas):
          self.builder.get_object(abrir_boton).connect("clicked", self.on_abrir_persiana, indice_persiana)

        lista_cerrar_boton = ["cerrar_habitacion_1", "cerrar_habitacion_2", "cerrar_habitacion_3", "cerrar_habitacion_4", "cerrar_habitacion_5", "cerrar_habitacion_6", "cerrar_habitacion_7", "cerrar_habitacion_8", "cerrar_habitacion_9", "cerrar_habitacion_10", "cerrar_habitacion_11", "cerrar_habitacion_12", "cerrar_habitacion_13", "cerrar_habitacion_14", "cerrar_habitacion_15", "cerrar_habitacion_16"]

        for (cerrar_boton, indice_persiana) in zip(lista_cerrar_boton, lista_index_persianas):
          self.builder.get_object(cerrar_boton).connect("clicked", self.on_cerrar_persiana, indice_persiana)

        lista_auto = ["auto_habitacion_1", "auto_habitacion_2", "auto_habitacion_3", "auto_habitacion_4", "auto_habitacion_5", "auto_habitacion_6", "auto_habitacion_7", "auto_habitacion_8", "auto_habitacion_9", "auto_habitacion_10", "auto_habitacion_11", "auto_habitacion_12", "auto_habitacion_13", "auto_habitacion_14", "auto_habitacion_15", "auto_habitacion_16"]

        for (auto, indice_persiana) in zip(lista_auto, lista_index_persianas):
          self.gtk_widget_new[auto].connect("toggled", self.on_auto, indice_persiana)

        lista_auto_perfil = ["auto_perfil_habitacion_1", "auto_perfil_habitacion_2", "auto_perfil_habitacion_3", "auto_perfil_habitacion_4", "auto_perfil_habitacion_5", "auto_perfil_habitacion_6", "auto_perfil_habitacion_7", "auto_perfil_habitacion_8", "auto_perfil_habitacion_9", "auto_perfil_habitacion_10", "auto_perfil_habitacion_11", "auto_perfil_habitacion_12", "auto_perfil_habitacion_13", "auto_perfil_habitacion_14", "auto_perfil_habitacion_15", "auto_perfil_habitacion_16"]

        for (auto_perfil, indice_persiana) in zip(lista_auto_perfil, lista_index_persianas):
          self.gtk_widget_new[auto_perfil].connect("toggled", self.on_auto_perfil, indice_persiana)

        lista_auto_solar = ["auto_solar_1", "auto_solar_2", "auto_solar_3", "auto_solar_4", "auto_solar_5", "auto_solar_6", "auto_solar_7", "auto_solar_8", "auto_solar_9", "auto_solar_10", "auto_solar_11", "auto_solar_12", "auto_solar_13", "auto_solar_14", "auto_solar_15", "auto_solar_16"]

        for (auto_solar, indice_persiana) in zip(lista_auto_solar, lista_index_persianas):
          self.gtk_widget_new[auto_solar].connect("toggled", self.on_auto_solar, indice_persiana)

        lista_hora_subida_combo = ['hora_subida_habitacion_1', 'hora_subida_habitacion_2', 'hora_subida_habitacion_3', 'hora_subida_habitacion_4', 'hora_subida_habitacion_5', 'hora_subida_habitacion_6', 'hora_subida_habitacion_7', 'hora_subida_habitacion_8', 'hora_subida_habitacion_9', 'hora_subida_habitacion_10', 'hora_subida_habitacion_11', 'hora_subida_habitacion_12', 'hora_subida_habitacion_13', 'hora_subida_habitacion_14', 'hora_subida_habitacion_15', 'hora_subida_habitacion_16']

        for (hora_subida, indice_persiana) in zip(lista_hora_subida_combo, lista_index_persianas):
          self.gtk_widget_new[hora_subida].connect("changed", self.hora_subida, indice_persiana)

        lista_hora_bajada_combo = ['hora_bajada_habitacion_1', 'hora_bajada_habitacion_2', 'hora_bajada_habitacion_3', 'hora_bajada_habitacion_4', 'hora_bajada_habitacion_5', 'hora_bajada_habitacion_6', 'hora_bajada_habitacion_7', 'hora_bajada_habitacion_8', 'hora_bajada_habitacion_9', 'hora_bajada_habitacion_10', 'hora_bajada_habitacion_11', 'hora_bajada_habitacion_12', 'hora_bajada_habitacion_13', 'hora_bajada_habitacion_14', 'hora_bajada_habitacion_15', 'hora_bajada_habitacion_16']

        for (hora_bajada, indice_persiana) in zip(lista_hora_bajada_combo, lista_index_persianas):
          self.gtk_widget_new[hora_bajada].connect("changed", self.hora_bajada, indice_persiana)

        lista_perfil_combo = ['perfil_habitacion_1', 'perfil_habitacion_2', 'perfil_habitacion_3', 'perfil_habitacion_4', 'perfil_habitacion_5', 'perfil_habitacion_6', 'perfil_habitacion_7', 'perfil_habitacion_8', 'perfil_habitacion_9', 'perfil_habitacion_10', 'perfil_habitacion_11', 'perfil_habitacion_12', 'perfil_habitacion_13', 'perfil_habitacion_14', 'perfil_habitacion_15', 'perfil_habitacion_16']

        for (perfil, indice_persiana) in zip(lista_perfil_combo, lista_index_persianas):
          self.gtk_widget_new[perfil].connect("changed", self.perfil, indice_persiana)
        self.gtk_widget_new['perfil_selection_combo'].connect("changed", self.on_perfil_selection_combo_changed)

        for items in horas_persianas:
          for hora_subida in lista_hora_subida_combo:
            self.gtk_widget_new[hora_subida].append_text(items)
          for hora_bajada in lista_hora_bajada_combo:
            self.gtk_widget_new[hora_bajada].append_text(items)

        self.persianas = windows_labels

        # Objetos de perfiles.
        self.tree_profile = ET.parse('profile.xml')
        data_xml = self.tree_profile.getroot()
        self.profile_name_list = []

        self.profile = {}
        for profile_xml in data_xml:
          profile_name = profile_xml.attrib['Name']
          self.profile[profile_name] = profile.Profile(profile_name)
          self.profile[profile_name].update_object_with_xml()
          self.profile_name_list.append(profile_name)
        
        for items in self.profile_name_list:
          for perfil in lista_perfil_combo:
            self.gtk_widget_new[perfil].append_text(items)
          self.gtk_widget_new['perfil_selection_combo'].append_text(items)
        
        # Objetos de ventana.
        self.window = {}
        for window_id in windows_labels:
          if window_id != 'PROFILE':
            self.window[window_id] = window.Window(window_id)
            self.window[window_id].update_window_with_xml()

        # Objetos sectores de riego
        self.lista_sectores = ['sector_1', 'sector_2', 'sector_3', 'sector_4', 'sector_5', 'sector_6', 'sector_7', 'sector_8', 'sector_9']

        lista_treeview_sector = ['treeviewsector1', 'treeviewsector2', 'treeviewsector3', 'treeviewsector4', 'treeviewsector5', 'treeviewsector6', 'treeviewsector7', 'treeviewsector8', 'treeviewsector9']
        lista_encender_sector = ['encender_sector1', 'encender_sector2', 'encender_sector3', 'encender_sector4', 'encender_sector5', 'encender_sector6', 'encender_sector7', 'encender_sector8', 'encender_sector9']
        lista_apagar_sector = [ 'apagar_sector1', 'apagar_sector2', 'apagar_sector3', 'apagar_sector4', 'apagar_sector5', 'apagar_sector6', 'apagar_sector7', 'apagar_sector8', 'apagar_sector9']
        lista_auto_sector = [ 'auto_sector1', 'auto_sector2', 'auto_sector3', 'auto_sector4', 'auto_sector5', 'auto_sector6', 'auto_sector7', 'auto_sector8', 'auto_sector9']

        self.dic_sectores ={}

        for (sector, treeview, encender_boton, apagar_boton, auto_sector) in zip(self.lista_sectores, lista_treeview_sector, lista_encender_sector, lista_apagar_sector, lista_auto_sector):
          self.dic_sectores[sector] = Sector(self.builder.get_object(treeview), sector, self.builder.get_object(encender_boton), self.builder.get_object(apagar_boton), self.builder.get_object(auto_sector))

        # Inicialización de la interface inicial. Depende del estado en el que se cerró la aplicación.
        for window_obj in self.window.values():
          persiana_name = window_obj.get_name()
          self.gtk_widget_new[self.persianas[persiana_name][self.index_auto]].set_active(window_obj.get_auto())
          self.gtk_widget_new[self.persianas[persiana_name][self.index_auto_solar]].set_active(window_obj.get_auto_solar())
          self.gtk_widget_new[self.persianas[persiana_name][self.index_hora_subida]].set_active(int(window_obj.get_index_time_open()))
          self.gtk_widget_new[self.persianas[persiana_name][self.index_hora_bajada]].set_active(int(window_obj.get_index_time_close()))
          self.gtk_widget_new[self.persianas[persiana_name][self.index_auto_perfil]].set_active(window_obj.get_auto_profile())
          self.gtk_widget_new[self.persianas[persiana_name][self.index_perfil]].set_active(window_obj.get_index_profile())

        # Periodic function
        gobject.timeout_add(60*1000, self.time_handler, self.window)

        # Open log file
        self.f=open("log_status.txt","w")

    def time_handler(self, windows):

        string = time.asctime()
        words = str.split(string)

        day = words[0] 
        mouth = words[1]
        number_day = str('%02d' % int(words[2]))
        hora_minutos = string[11:16]

        print("------------------")
        print hora_minutos
        print day
        print number_day

        for sector in self.lista_sectores:
          self.dic_sectores[sector].is_time_to_start(hora_minutos)

        for window in windows.values():

          name = window.get_name()
          name_widget_message_text = self.persianas[name][self.index_message_text]

          if window.attributes['AutoSolar'] == 'True':
            print("Apertura solar")
            if self.meses[mouth].is_time_to_open(str(number_day), str(hora_minutos)):
              print("Apertura ventana sol")
              result = window.open(100)
              self.gtk_widget_new[name_widget_message_text].set_text(result)
            elif self.meses[mouth].is_time_to_close(str(number_day), str(hora_minutos)):
              print("Cierre ventana sol")
              result = window.close(100)
              self.gtk_widget_new[name_widget_message_text].set_text(result)

          elif window.attributes['Auto'] == 'True':
            if hora_minutos == window.attributes['TimeOpen']:
              print("Apertura ventana")
              result = window.open(100)
              self.gtk_widget_new[name_widget_message_text].set_text(result)
            elif hora_minutos == window.attributes['TimeClose']:
              print("Cierre ventana")
              result = window.close(100)
              self.gtk_widget_new[name_widget_message_text].set_text(result)

          elif window.attributes['AutoProfile'] == 'True':
            if hora_minutos != "00:00":
              hora_minutos_aux = str('%02d' % (int(hora_minutos[0:2])-1))+":"+str('%02d' % int(hora_minutos[3:5]))
            else:
              hora_minutos_aux = "23:00"

            if window.get_profile_name() != "None":
              print self.profile[window.get_profile_name()].get_day(day)
              if self.profile[window.get_profile_name()].get_day(day) == "True":
                print ("Dentro de dia")
                if hora_minutos in self.profile[window.get_profile_name()].time.keys():
                  if self.profile[window.get_profile_name()].time[hora_minutos] != self.profile[window.get_profile_name()].time[hora_minutos_aux]:
                    dif = int(self.profile[window.get_profile_name()].time[hora_minutos]) - int(self.profile[window.get_profile_name()].time[hora_minutos_aux])
                    if dif > 0:
                      print("Apertura ventana auto profile")
                      print(abs(dif))
                      result = window.open(abs(dif))
                      self.gtk_widget_new[name_widget_message_text].set_text(result)
                      content = "Apertura ventana: "+str(abs(dif))+" "+result+"\n"
                    elif dif <= 0:
                      print("Cierre ventana auto profile")
                      result = window.close(abs(dif))
                      print(abs(dif))
                      self.gtk_widget_new[name_widget_message_text].set_text(result)
                      content = "Cierre ventana: "+str(abs(dif))+" "+result+"\n"

                    self.f.write(content)
                    
        return True

    # Edited profile section
    def edit_profiles_clicked_cb(self, widget):

        self.edit_profiles_win.show()
        return 0

    def on_perfil_selection_combo_changed(self, widget):

        profile_name = self.gtk_widget_new[self.persianas['PROFILE'][self.index_perfil_selection_combo]].get_active_text()
        if profile_name != None:
          self.gtk_widget_new[self.persianas['PROFILE'][self.index_profile_name]].set_text(profile_name)
          dic_time = self.profile[profile_name].get_all_time()
          dic_day = self.profile[profile_name].get_all_days()

          for dic_index in dic_time:
            index_hour = self.persianas['PROFILE'].index(dic_index)
            self.gtk_widget_new[self.persianas['PROFILE'][index_hour]].set_text(dic_time[dic_index])

          for dic_index in dic_day:
            index_days = self.persianas['PROFILE'].index(dic_index)
            self.gtk_widget_new[self.persianas['PROFILE'][index_days]].set_active(dic_day[dic_index] == "True")

        return 0

    def save_profile_clicked_cb(self, widget):
        hour_dic = {}
        day_dic = {}

        profile_name = self.gtk_widget_new[self.persianas['PROFILE'][self.index_profile_name]].get_text()

        for index in self.list_hours_profile:
             hour_dic[self.persianas['PROFILE'][index]] = self.gtk_widget_new[self.persianas["PROFILE"][index]].get_text()
        for index in self.list_days_profile:
             day_dic[self.persianas['PROFILE'][index]] = str(self.gtk_widget_new[self.persianas["PROFILE"][index]].get_active())

        if profile_name not in self.profile.keys():
          self.profile[profile_name] = profile.Profile(profile_name)

        self.profile[profile_name].put_time(hour_dic)
        self.profile[profile_name].put_day(day_dic)
        self.profile[profile_name].write_profile_on_xml()

        if profile_name not in self.profile_name_list:
          self.profile_name_list.append(profile_name)
          for perfil in lista_perfil_combo:
            self.gtk_widget_new[perfil].append_text(profile_name)
          self.gtk_widget_new['perfil_selection_combo'].append_text(profile_name)

        self.edit_profiles_win.hide()
        return 0

    def cancel_profile_clicked_cb(self, widget):
        self.edit_profiles_win.hide()
        return 0

    def on_abrir_persiana(self, widget, window_id):
        result = self.window[window_id].open(100)
        name_widget_message_text = self.persianas[window_id][self.index_message_text]
        self.gtk_widget_new[name_widget_message_text].set_text(result)
        return 0

    def on_cerrar_persiana(self, widget, window_id):
        result = self.window[window_id].close(100)
        name_widget_message_text = self.persianas[window_id][self.index_message_text]
        self.gtk_widget_new[name_widget_message_text].set_text(result)
        return 0

    def hora_subida(self, widget, window_id):
        name_widget_hora_subida = self.persianas[window_id][self.index_hora_subida]
        self.window[window_id].write_time_open(self.gtk_widget_new[name_widget_hora_subida].get_active_text())
        return 0

    def hora_bajada(self, widget, window_id):
        name_widget_hora_bajada = self.persianas[window_id][self.index_hora_bajada]
        self.window[window_id].write_time_close(self.gtk_widget_new[name_widget_hora_bajada].get_active_text())
        return 0

    def perfil(self, widget, window_id):
        name_widget_perfil = self.persianas[window_id][self.index_perfil]
        self.window[window_id].write_profile_name_index(self.gtk_widget_new[name_widget_perfil].get_active_text())
        self.window[window_id].write_profile_index(self.gtk_widget_new[name_widget_perfil].get_active())
        return 0

    def on_auto(self, widget, window_id):

        name_widget_auto = self.persianas[window_id][self.index_auto]
        name_widget_auto_solar = self.persianas[window_id][self.index_auto_solar]
        name_widget_auto_perfil = self.persianas[window_id][self.index_auto_perfil]
        name_widget_perfil = self.persianas[window_id][self.index_perfil]

        self.window[window_id].write_auto_state(self.gtk_widget_new[name_widget_auto].get_active())

        if self.gtk_widget_new[name_widget_auto].get_active() == True:
          self.gtk_widget_new[name_widget_auto_solar].set_sensitive(False)
          self.gtk_widget_new[name_widget_auto_perfil].set_sensitive(False)
          self.gtk_widget_new[name_widget_perfil].set_sensitive(False)
        else:
          self.gtk_widget_new[name_widget_auto_solar].set_sensitive(True)
          self.gtk_widget_new[name_widget_auto_perfil].set_sensitive(True)
          self.gtk_widget_new[name_widget_perfil].set_sensitive(True)
        return 0

    def on_auto_solar(self, widget, window_id):

        name_widget_auto = self.persianas[window_id][self.index_auto]
        name_widget_auto_solar = self.persianas[window_id][self.index_auto_solar]
        name_widget_auto_perfil = self.persianas[window_id][self.index_auto_perfil]
        name_widget_perfil = self.persianas[window_id][self.index_perfil]
        name_widget_hora_subida = self.persianas[window_id][self.index_hora_subida]
        name_widget_hora_bajada = self.persianas[window_id][self.index_hora_bajada]

        self.window[window_id].write_auto_solar_state(self.gtk_widget_new[name_widget_auto_solar].get_active())

        if self.gtk_widget_new[name_widget_auto_solar].get_active() == True:
          self.gtk_widget_new[name_widget_auto].set_sensitive(False)
          self.gtk_widget_new[name_widget_auto_perfil].set_sensitive(False)
          self.gtk_widget_new[name_widget_perfil].set_sensitive(False)
          self.gtk_widget_new[name_widget_hora_subida].set_sensitive(False)
          self.gtk_widget_new[name_widget_hora_bajada].set_sensitive(False)
        else:
          self.gtk_widget_new[name_widget_auto].set_sensitive(True)
          self.gtk_widget_new[name_widget_auto_perfil].set_sensitive(True)
          self.gtk_widget_new[name_widget_perfil].set_sensitive(True)
          self.gtk_widget_new[name_widget_hora_subida].set_sensitive(True)
          self.gtk_widget_new[name_widget_hora_bajada].set_sensitive(True)
        return 0

    def on_auto_perfil(self, widget, window_id):

        name_widget_auto = self.persianas[window_id][self.index_auto]
        name_widget_auto_perfil = self.persianas[window_id][self.index_auto_perfil]
        name_widget_auto_solar = self.persianas[window_id][self.index_auto_solar]
        name_widget_hora_subida = self.persianas[window_id][self.index_hora_subida]
        name_widget_hora_bajada = self.persianas[window_id][self.index_hora_bajada]

        self.window[window_id].write_auto_profile_state(self.gtk_widget_new[name_widget_auto_perfil].get_active())

        if self.gtk_widget_new[name_widget_auto_perfil].get_active() == True:
          self.gtk_widget_new[name_widget_auto_solar].set_sensitive(False)
          self.gtk_widget_new[name_widget_auto].set_sensitive(False)
          self.gtk_widget_new[name_widget_hora_subida].set_sensitive(False)
          self.gtk_widget_new[name_widget_hora_bajada].set_sensitive(False)
        else:
          self.gtk_widget_new[name_widget_auto_solar].set_sensitive(True)
          self.gtk_widget_new[name_widget_auto].set_sensitive(True)
          self.gtk_widget_new[name_widget_hora_subida].set_sensitive(True)
          self.gtk_widget_new[name_widget_hora_bajada].set_sensitive(True)

        return 0

    def cerrar_todas_clicked_cb(self, widget):
        return 0
    def abrir_todas_clicked_cb(self, widget):
        return 0
    def window1_destroy_cb(self, widget):
        print "Bye, bye ....."
        self.f.close()
        Gtk.main_quit
        return 0

    def PrettyPrintXML(self, file_name):
      '''This function converts an XML file to a pretty print XML 
      and delete its empty lines'''
      x=xml.dom.minidom.parse(file_name)
      a=x.toprettyxml(indent="  ")

      p=open("ivan.xml",'w')
      p.write(a)
      p.close()    

      p=open("ivan.xml",'r')    
      contents = p.readlines()
      new_contents= []
      p.close()
      
      for line in contents:
          if line.find('element') >= 0: 
              print "line"
              print line
#         if not line.strip():
#             continue
#         else:
#             new_contents.append(line)
#     p=open("ivan.xml",'w')
#     p.write("".join(new_contents))
#     p.close()

    def on_domotica_win_show(self, widget):
      return 0


if __name__== "__main__":
    gui = MainGui()
    gui.domotica_win.show()
    Gtk.main()
