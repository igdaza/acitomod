#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include "Interface.h"

extern "C" {

void put_init_window_status(int id, gpointer user_data);

void window1_destroy_cb  (GtkObject *object, gpointer  user_data);
void on_domotica_win_show(GtkButton *button, gpointer user_data);
bool time_handler(GtkWidget *widget);

void abrir_todas_clicked_cb (GtkButton *button, gpointer user_data);
void cerrar_todas_clicked_cb (GtkButton *button, gpointer user_data);

// Open button windows
void abrir_ventana(int id, gpointer user_data);
void on_abrir_habitacion_1_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_2_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_3_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_4_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_5_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_6_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_7_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_8_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_9_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_10_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_11_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_12_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_13_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_14_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_15_clicked(GtkButton *button, gpointer user_data);
void on_abrir_habitacion_16_clicked(GtkButton *button, gpointer user_data);

// Close button windows
void cerrar_ventana(int id, gpointer user_data);
void on_cerrar_habitacion_1_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_2_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_3_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_4_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_5_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_6_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_7_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_8_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_9_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_10_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_11_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_12_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_13_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_14_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_15_clicked(GtkButton *button, gpointer user_data);
void on_cerrar_habitacion_16_clicked(GtkButton *button, gpointer user_data);


// Combo hora subida
void hora_subida_funcion(int id, gpointer user_data);
void on_hora_subida_habitacion_1_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_2_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_3_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_4_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_5_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_6_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_7_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_8_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_9_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_10_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_11_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_12_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_13_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_14_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_15_changed (GtkButton *button, gpointer user_data); 
void on_hora_subida_habitacion_16_changed (GtkButton *button, gpointer user_data); 
// Combo hora bajada

void hora_bajada_funcion(int id, gpointer user_data);
void on_hora_bajada_habitacion_1_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_2_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_3_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_4_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_5_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_6_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_7_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_8_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_9_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_10_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_11_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_12_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_13_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_14_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_15_changed (GtkButton *button, gpointer user_data); 
void on_hora_bajada_habitacion_16_changed (GtkButton *button, gpointer user_data); 

// Perfiles
void perfil_habitacion_function(int id, gpointer user_data);
void on_perfil_habitacion_1_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_2_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_3_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_4_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_5_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_6_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_7_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_8_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_9_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_10_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_11_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_12_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_13_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_14_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_15_changed (GtkButton *button, gpointer user_data);
void on_perfil_habitacion_16_changed (GtkButton *button, gpointer user_data);

// Auto hora bajada
void on_auto_function(int id, gpointer user_data);
void on_auto_habitacion_1_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_2_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_3_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_4_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_5_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_6_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_7_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_8_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_9_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_10_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_11_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_12_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_13_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_14_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_15_toggled(GtkButton *button, gpointer user_data);
void on_auto_habitacion_16_toggled(GtkButton *button, gpointer user_data);

void on_auto_perfil_habitacion_1_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_2_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_3_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_4_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_5_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_6_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_7_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_8_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_9_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_10_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_11_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_12_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_13_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_14_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_15_toggled(GtkButton *button, gpointer user_data);
void on_auto_perfil_habitacion_16_toggled(GtkButton *button, gpointer user_data);

void edit_profiles_clicked_cb (GtkButton *button, gpointer user_data);
void cancel_profile_clicked_cb (GtkButton *button, gpointer user_data);
void save_profile_clicked_cb (GtkButton *button, gpointer user_data);
};
