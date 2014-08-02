#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <time.h>

#include "callbacks.h"
#include "rs232_comm.h"
#include "Interface.h"
#include "edit_open_profile.h"

#define WINDOW_MAX 50
#define ASPERSOR_MAX 50
#define WINDOW_NUM 1

#define ARRAY_SIZE 100

using namespace std;

extern "C" {
  
// Window objects list
rs232_comm window[WINDOW_MAX];
OpenProfile profile;

/** 
  This function is executed in the init process
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
void on_domotica_win_show(GtkButton *button, gpointer  user_data)
{
   g_timeout_add(60*1000, (GSourceFunc)time_handler, user_data);


  // Profiles related with XML file
  int profile_number = profile.read_profile_names_from_xml();
  for(int i = 1; i < profile_number+1; i++)
  {
    gtk_combo_box_insert_text (GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[0]), i, (const gchar*) profile.list_profile_names[i-1]);
  }

  for(unsigned int i = 0; i< ENTRIES; i++)
  {
    window[i].init(i);
    put_init_window_status(i, user_data);
  }
}
   
/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
void put_init_window_status(int id, gpointer user_data)
{
   // Read xml files
   window[id].read_xml_status();
   window[id].readFromXmlIntervalo();
   window[id].isActiveIntervalo();
   window[id].readFromXmlAutoProfileFlag();
   window[id].readFromXmlProfileNameIndex();

   // Load data in interface
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->textWidget[id]), (gchar*)window[id].get_text());
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->autoHourWidget[id]), window[id].isActiveIntervalo());
   gtk_combo_box_set_active(GTK_COMBO_BOX(((ventana*)user_data)->openHourWidget[id]), window[id].get_hour_open());
   gtk_combo_box_set_active(GTK_COMBO_BOX(((ventana*)user_data)->closeHourWidget[id]), window[id].get_hour_close());
   gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->autoProfileWidget[id]), window[id].isActiveProfile());
   gtk_combo_box_set_active(GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[id]), window[id].getIndexProfile());

}

/** 
  Brieft coment about the function. 
  @param x x coment
  @param y y coment
  @param st st coment

  @return Void value is returned. 
**/ 
bool time_handler(GtkWidget *user_data)
{
  static char current_time[256];
  time_t curtime;
  struct tm *loctime;

  curtime = time(NULL);
  loctime = localtime(&curtime);
  strftime(current_time, 256, "%R", loctime);
  printf("Current time: %s\n", current_time);

  //Windows
  for(int i = 0; i<ENTRIES; i++)
  {
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->autoHourWidget[i])))
    {
       window[i].checkIntervalo(current_time);
       gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->textWidget[i]), (gchar*)window[i].get_text());
    }

    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->autoProfileWidget[i])))
    {
       if(i == ENTRIES - 1) 
         window[i].checkHeaterProfileElement(current_time);
       else
         window[i].checkProfileElement(current_time);

       gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->textWidget[i]), (gchar*)window[i].get_text());
    }
  }

  //Riego
  //Sector_1
  //if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->auto_sector_1)))
  //{
  //   sector_1.check(current_time);
  //   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_1), (gchar*)sector_1.get_text());
  //}

  return TRUE;
}

void abrir_todas_clicked_cb (GtkButton *button, gpointer user_data)
{
   for(int i=0; i<ENTRIES; i++)
     abrir_ventana(i, user_data);
}

void cerrar_todas_clicked_cb  (GtkButton *button, gpointer user_data)
{
   for(int i=0; i<ENTRIES; i++)
     cerrar_ventana(i, user_data);
}

// Open button window
void abrir_ventana(int id, gpointer user_data)
{
  if(window[id].power_up(100))
  {
    window[id].write_xml_status();
    gtk_widget_set_sensitive(((ventana*)user_data)->openWidget[id],false);
    gtk_widget_set_sensitive(((ventana*)user_data)->closeWidget[id],true);
  }

  gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->textWidget[id]), (gchar*)window[id].get_text());
}
void on_abrir_habitacion_1_clicked (GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_1, user_data);
}
void on_abrir_habitacion_2_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_2, user_data);
}
void on_abrir_habitacion_3_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_3, user_data);
}
void on_abrir_habitacion_4_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_4, user_data);
}
void on_abrir_habitacion_5_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_5, user_data);
}
void on_abrir_habitacion_6_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_6, user_data);
}
void on_abrir_habitacion_7_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_7, user_data);
}
void on_abrir_habitacion_8_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_8, user_data);
}
void on_abrir_habitacion_9_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_9, user_data);
}
void on_abrir_habitacion_10_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_10, user_data);
}
void on_abrir_habitacion_11_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_11, user_data);
}
void on_abrir_habitacion_12_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_12, user_data);
}
void on_abrir_habitacion_13_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_13, user_data);
}
void on_abrir_habitacion_14_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_14, user_data);
}
void on_abrir_habitacion_15_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_15, user_data);
}
void on_abrir_habitacion_16_clicked(GtkButton *button, gpointer user_data)
{
  abrir_ventana(ID_HABITACION_16, user_data);
}

// Close button window
void cerrar_ventana(int id, gpointer user_data)
{
  if(window[id].power_down(100))
  {
    window[id].write_xml_status();
    gtk_widget_set_sensitive(((ventana*)user_data)->openWidget[id],true);
    gtk_widget_set_sensitive(((ventana*)user_data)->closeWidget[id],false);
  }

  gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->textWidget[id]), (gchar*)window[id].get_text());
}
void on_cerrar_habitacion_1_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_1, user_data);
}
void on_cerrar_habitacion_2_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_2, user_data);
}
void on_cerrar_habitacion_3_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_3, user_data);
}
void on_cerrar_habitacion_4_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_4, user_data);
}
void on_cerrar_habitacion_5_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_5, user_data);
}
void on_cerrar_habitacion_6_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_6, user_data);
}
void on_cerrar_habitacion_7_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_7, user_data);
}
void on_cerrar_habitacion_8_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_8, user_data);
}
void on_cerrar_habitacion_9_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_9, user_data);
}
void on_cerrar_habitacion_10_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_10, user_data);
}
void on_cerrar_habitacion_11_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_11, user_data);
}
void on_cerrar_habitacion_12_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_12, user_data);
}
void on_cerrar_habitacion_13_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_13, user_data);
}
void on_cerrar_habitacion_14_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_14, user_data);
}
void on_cerrar_habitacion_15_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_15, user_data);
}
void on_cerrar_habitacion_16_clicked(GtkButton *button, gpointer user_data)
{
  cerrar_ventana(ID_HABITACION_16, user_data);
}


// Windows hours managment
// Open
void hora_subida_funcion(int id, gpointer user_data)
{
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->openHourWidget[id]));
   window[id].put_open_hour(hour);

}
void on_hora_subida_habitacion_1_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_1, user_data);
}
void on_hora_subida_habitacion_2_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_2, user_data);
}
void on_hora_subida_habitacion_3_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_3, user_data);
}
void on_hora_subida_habitacion_4_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_4, user_data);
}
void on_hora_subida_habitacion_5_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_5, user_data);
}
void on_hora_subida_habitacion_6_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_6, user_data);
}
void on_hora_subida_habitacion_7_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_7, user_data);
}
void on_hora_subida_habitacion_8_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_8, user_data);
}
void on_hora_subida_habitacion_9_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_9, user_data);
}
void on_hora_subida_habitacion_10_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_10, user_data);
}
void on_hora_subida_habitacion_11_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_11, user_data);
}
void on_hora_subida_habitacion_12_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_12, user_data);
}
void on_hora_subida_habitacion_13_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_13, user_data);
}
void on_hora_subida_habitacion_14_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_14, user_data);
}
void on_hora_subida_habitacion_15_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_15, user_data);
}
void on_hora_subida_habitacion_16_changed(GtkButton *button, gpointer user_data)
{
    hora_subida_funcion(ID_HABITACION_16, user_data);
}

// Close
void hora_bajada_funcion(int id, gpointer user_data)
{
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->closeHourWidget[id]));
   window[id].put_close_hour(hour);
}

void on_hora_bajada_habitacion_1_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_1, user_data);
}
void on_hora_bajada_habitacion_2_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_2, user_data);
}
void on_hora_bajada_habitacion_3_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_3, user_data);
}
void on_hora_bajada_habitacion_4_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_4, user_data);
}
void on_hora_bajada_habitacion_5_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_5, user_data);
}
void on_hora_bajada_habitacion_6_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_6, user_data);
}
void on_hora_bajada_habitacion_7_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_7, user_data);
}
void on_hora_bajada_habitacion_8_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_8, user_data);
}
void on_hora_bajada_habitacion_9_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_9, user_data);
}
void on_hora_bajada_habitacion_10_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_10, user_data);
}
void on_hora_bajada_habitacion_11_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_11, user_data);
}
void on_hora_bajada_habitacion_12_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_12, user_data);
}
void on_hora_bajada_habitacion_13_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_13, user_data);
}
void on_hora_bajada_habitacion_14_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_14, user_data);
}
void on_hora_bajada_habitacion_15_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_15, user_data);
}
void on_hora_bajada_habitacion_16_changed(GtkButton *button, gpointer user_data)
{
  hora_bajada_funcion(ID_HABITACION_16, user_data);
}

// Combo perfiles
void perfil_habitacion_function(int id, gpointer user_data)
{
   gchar* name_profile = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[id]));
   window[id].readFromXmlProfileElements(name_profile);
   window[id].writeToXmlProfileNameIndex(gtk_combo_box_get_active(GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[id])));
}
void on_perfil_habitacion_1_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_1, user_data);
}
void on_perfil_habitacion_2_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_2, user_data);
}
void on_perfil_habitacion_3_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_3, user_data);
}
void on_perfil_habitacion_4_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_4, user_data);
}
void on_perfil_habitacion_5_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_5, user_data);
}
void on_perfil_habitacion_6_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_6, user_data);
}
void on_perfil_habitacion_7_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_7, user_data);
}
void on_perfil_habitacion_8_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_8, user_data);
}
void on_perfil_habitacion_9_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_9, user_data);
}
void on_perfil_habitacion_10_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_10, user_data);
}
void on_perfil_habitacion_11_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_11, user_data);
}
void on_perfil_habitacion_12_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_12, user_data);
}
void on_perfil_habitacion_13_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_13, user_data);
}
void on_perfil_habitacion_14_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_14, user_data);
}
void on_perfil_habitacion_15_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_15, user_data);
}
void on_perfil_habitacion_16_changed (GtkButton *button, gpointer user_data)
{
  perfil_habitacion_function(ID_HABITACION_16, user_data);
}

void on_perfil_selection_combo_changed (GtkButton *button, gpointer user_data)
{
  rs232_comm::t_element* p_profile = NULL;

  gchar* profile_name = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->perfil_selection_combo));

  p_profile = window[0].readFromXmlProfileElements(profile_name);
  gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->profile_name), profile_name);

  gchar porcentaje[10];
  for(int i = 0; i < HOURS_PROFILE_NUMBER; i++)
  {
     sprintf(porcentaje, "%d", (p_profile+i)->porcentaje);
     gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->porcentajes[i]), porcentaje);
  }
}

// Auto hours funtionality
void on_auto_function(int id, gpointer user_data)
{
  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->autoHourWidget[id])))
  {
    window[id].put_auto_intervalo_flag(true);
    window[id].writeToXmlAutoProfileFlag(false);
    gtk_widget_set_sensitive(((ventana*)user_data)->autoProfileWidget[id],false);
    gtk_widget_set_sensitive(((ventana*)user_data)->profileWidget[id],false);
  }
  else
  {
    window[id].put_auto_intervalo_flag(false);
    window[id].writeToXmlAutoProfileFlag(false);
    gtk_widget_set_sensitive(((ventana*)user_data)->autoProfileWidget[id],true);
    gtk_widget_set_sensitive(((ventana*)user_data)->profileWidget[id],true);
  }
}
void on_auto_habitacion_1_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_1, user_data);
}
void on_auto_habitacion_2_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_2, user_data);
}
void on_auto_habitacion_3_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_3, user_data);
}
void on_auto_habitacion_4_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_4, user_data);
}
void on_auto_habitacion_5_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_5, user_data);
}
void on_auto_habitacion_6_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_6, user_data);
}
void on_auto_habitacion_7_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_7, user_data);
}
void on_auto_habitacion_8_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_8, user_data);
}
void on_auto_habitacion_9_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_9, user_data);
}
void on_auto_habitacion_10_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_10, user_data);
}
void on_auto_habitacion_11_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_11, user_data);
}
void on_auto_habitacion_12_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_12, user_data);
}
void on_auto_habitacion_13_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_13, user_data);
}
void on_auto_habitacion_14_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_14, user_data);
}
void on_auto_habitacion_15_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_15, user_data);
}
void on_auto_habitacion_16_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_function(ID_HABITACION_16, user_data);
}

void on_auto_perfil_function(int id, gpointer user_data)
{
  if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(((ventana*)user_data)->autoProfileWidget[id])))
  {
    window[id].writeToXmlAutoProfileFlag(true);
    window[id].put_auto_intervalo_flag(false);
    gtk_widget_set_sensitive(((ventana*)user_data)->autoHourWidget[id],false);
    gtk_widget_set_sensitive(((ventana*)user_data)->openHourWidget[id],false);
    gtk_widget_set_sensitive(((ventana*)user_data)->closeHourWidget[id],false);
  }
  else
  {
    window[id].writeToXmlAutoProfileFlag(false);
    window[id].put_auto_intervalo_flag(false);
    gtk_widget_set_sensitive(((ventana*)user_data)->autoHourWidget[id],true);
    gtk_widget_set_sensitive(((ventana*)user_data)->openHourWidget[id],true);
    gtk_widget_set_sensitive(((ventana*)user_data)->closeHourWidget[id],true);
  }
}
void on_auto_perfil_habitacion_1_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_1, user_data);
}
void on_auto_perfil_habitacion_2_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_2, user_data);
}
void on_auto_perfil_habitacion_3_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_3, user_data);
}
void on_auto_perfil_habitacion_4_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_4, user_data);
}
void on_auto_perfil_habitacion_5_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_5, user_data);
}
void on_auto_perfil_habitacion_6_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_6, user_data);
}
void on_auto_perfil_habitacion_7_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_7, user_data);
}
void on_auto_perfil_habitacion_8_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_8, user_data);
}
void on_auto_perfil_habitacion_9_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_9, user_data);
}
void on_auto_perfil_habitacion_10_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_10, user_data);
}
void on_auto_perfil_habitacion_11_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_11, user_data);
}
void on_auto_perfil_habitacion_12_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_12, user_data);
}
void on_auto_perfil_habitacion_13_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_13, user_data);
}
void on_auto_perfil_habitacion_14_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_14, user_data);
}
void on_auto_perfil_habitacion_15_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_15, user_data);
}
void on_auto_perfil_habitacion_16_toggled(GtkButton *button, gpointer user_data)
{
  on_auto_perfil_function(ID_HABITACION_16, user_data);
}

void edit_profiles_clicked_cb (GtkButton *button, gpointer user_data)
{
  gtk_widget_show_all(((ventana*)user_data)->edit_profiles_win);
}

void save_profile_clicked_cb (GtkButton *button, gpointer user_data)
{
  const gchar* profile_name = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->profile_name));
  profile.set_profile_name((const char*)profile_name);

  gchar* opened_point;

  for(int i = 0; i < HOURS_PROFILE_NUMBER; i++)
  {
     opened_point = (gchar*)gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->porcentajes[i]));
     profile.set_opened_point(atoi((char*)opened_point), i);
  }

  profile.write_profile_xml();
  int profile_number = profile.read_profile_names_from_xml();

  for(int i = 0; i < profile_number; i++)
  {
    gtk_combo_box_remove_text (GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[0]), i);
    printf("profiles: %s\n", profile.list_profile_names[i]);
  }
  for(int i = 0; i < profile_number; i++)
  {
    gtk_combo_box_insert_text (GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[0]), i, (const gchar*) profile.list_profile_names[i]);
  }

  for(int i = 0; i<ENTRIES; i++)
    gtk_combo_box_set_active(GTK_COMBO_BOX(((ventana*)user_data)->profileWidget[i]), window[i].getIndexProfile());

  gtk_widget_hide(((ventana*)user_data)->edit_profiles_win);
}

void cancel_profile_clicked_cb (GtkButton *button, gpointer user_data)
{
  printf("The profile process was closed.\n");
  gtk_widget_hide(((ventana*)user_data)->edit_profiles_win);
}

void window1_destroy_cb (GtkObject *object, gpointer  user_data)
{
  printf("The process is closed.\n");
  gtk_main_quit ();
  
}

} // Llave importante
