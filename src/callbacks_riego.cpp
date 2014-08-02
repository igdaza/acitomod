#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <time.h>

#include "callbacks_riego.h"
#include "rs232_comm.h"
#include "Interface.h"
#include "riego.h"

using namespace std;

extern "C" {

Riego sector_1;
Riego sector_2; 
Riego sector_3;
Riego sector_4;
Riego sector_5; 
Riego sector_6;
Riego sector_7;
Riego sector_8; 
Riego sector_9;
Riego sector_10; 
Riego sector_11;

//Funciones de riego manual
void on_turn_on_sector_1_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_1.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_1), (gchar*)sector_1.get_text());
}

void on_turn_on_sector_2_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_2.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_2), (gchar*)sector_2.get_text());
}

void on_turn_on_sector_3_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_3.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_3), (gchar*)sector_3.get_text());
}

void on_turn_on_sector_4_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_4.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_4), (gchar*)sector_4.get_text());
}

void on_turn_on_sector_5_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_5.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_5), (gchar*)sector_5.get_text());
}

void on_turn_on_sector_6_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_6.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_6), (gchar*)sector_6.get_text());
}

void on_turn_on_sector_7_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_7.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_7), (gchar*)sector_7.get_text());
}

void on_turn_on_sector_8_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_8.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_8), (gchar*)sector_8.get_text());

}

void on_turn_on_sector_9_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_9.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_9), (gchar*)sector_9.get_text());

}

void on_turn_on_sector_10_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_10.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_10), (gchar*)sector_10.get_text());

}

void on_turn_on_sector_11_clicked (GtkButton       *button,
                                  gpointer         user_data)
{
   sector_11.turn_on();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_11), (gchar*)sector_11.get_text());
}

void on_turn_off_sector_1_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
   sector_1.turn_off();
   gtk_entry_set_text(GTK_ENTRY(((ventana*)user_data)->state_sector_1), (gchar*)sector_1.get_text());
}

void on_turn_off_sector_2_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_3_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_4_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_5_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_6_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_7_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_8_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_9_clicked (GtkButton       *button,
                                   gpointer         user_data)
{
}

void on_turn_off_sector_10_clicked (GtkButton       *button,
                                    gpointer         user_data)
{
}

void on_turn_off_sector_11_clicked (GtkButton       *button,
                                    gpointer         user_data)
{
}

// Funciones de riego automático
// Sector_1
void on_turn_on_hour_1_sector_1_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_1 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_1));
   sector_1.put_hour_1(hour);
}

void on_minutes_1_sector_1_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_1));
   sector_1.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_1_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_1 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_1));
   sector_1.put_hour_2(hour);
}

void on_minutes_2_sector_1_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_1));
   sector_1.put_minutes_2(atoi((const char*)text));
}

// Sector_2
void on_turn_on_hour_1_sector_2_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_2 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_2));
   sector_2.put_hour_1(hour);
}

void on_minutes_1_sector_2_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_2));
   sector_2.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_2_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_2 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_2));
   sector_2.put_hour_2(hour);
}

void on_minutes_2_sector_2_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_2));
   sector_2.put_minutes_2(atoi((const char*)text));
}

// Sector_3
void on_turn_on_hour_1_sector_3_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_3 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_3));
   sector_3.put_hour_1(hour);
}

void on_minutes_1_sector_3_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_3));
   sector_3.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_3_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_3 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_3));
   sector_3.put_hour_2(hour);
}

void on_minutes_2_sector_3_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_3));
   sector_3.put_minutes_2(atoi((const char*)text));
}

// Sector_4
void on_turn_on_hour_1_sector_4_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_4 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_4));
   sector_4.put_hour_1(hour);
}

void on_minutes_1_sector_4_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_4));
   sector_4.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_4_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_4 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_4));
   sector_4.put_hour_2(hour);
}

void on_minutes_2_sector_4_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_4));
   sector_4.put_minutes_2(atoi((const char*)text));
}

// Sector_5
void on_turn_on_hour_1_sector_5_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_5 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_5));
   sector_5.put_hour_1(hour);
}

void on_minutes_1_sector_5_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_5));
   sector_5.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_5_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_5 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_5));
   sector_5.put_hour_2(hour);
}

void on_minutes_2_sector_5_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_5));
   sector_5.put_minutes_2(atoi((const char*)text));
}

// Sector_6
void on_turn_on_hour_1_sector_6_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_6 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_6));
   sector_6.put_hour_1(hour);
}

void on_minutes_1_sector_6_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_6));
   sector_6.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_6_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_6 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_6));
   sector_6.put_hour_2(hour);
}

void on_minutes_2_sector_6_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_6));
   sector_6.put_minutes_2(atoi((const char*)text));
}

// Sector_7
void on_turn_on_hour_1_sector_7_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_7 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_7));
   sector_7.put_hour_1(hour);
}

void on_minutes_1_sector_7_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_7));
   sector_7.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_7_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_7 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_7));
   sector_7.put_hour_2(hour);
}

void on_minutes_2_sector_7_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_7));
   sector_7.put_minutes_2(atoi((const char*)text));
}

// Sector_8
void on_turn_on_hour_1_sector_8_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_8 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_8));
   sector_8.put_hour_1(hour);
}

void on_minutes_1_sector_8_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_8));
   sector_8.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_8_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_8 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_8));
   sector_8.put_hour_2(hour);
}

void on_minutes_2_sector_8_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_8));
   sector_8.put_minutes_2(atoi((const char*)text));
}

// Sector_9
void on_turn_on_hour_1_sector_9_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_9 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_9));
   sector_9.put_hour_1(hour);
}

void on_minutes_1_sector_9_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_9));
   sector_9.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_9_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_9 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_9));
   sector_9.put_hour_2(hour);
}

void on_minutes_2_sector_9_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_9));
   sector_9.put_minutes_2(atoi((const char*)text));
}

// Sector_10
void on_turn_on_hour_1_sector_10_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_10 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_10));
   sector_10.put_hour_1(hour);
}

void on_minutes_1_sector_10_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_10));
   sector_10.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_10_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_10 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_10));
   sector_10.put_hour_2(hour);
}

void on_minutes_2_sector_10_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_10));
   sector_10.put_minutes_2(atoi((const char*)text));
}

// Sector_11
void on_turn_on_hour_1_sector_11_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_1_Sector_11 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_1_sector_11));
   sector_11.put_hour_1(hour);
}

void on_minutes_1_sector_11_changed (GtkButton       *button,
                                    gpointer         user_data)

{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_1_sector_11));
   sector_11.put_minutes_1(atoi((const char*)text));
}

void on_turn_on_hour_2_sector_11_changed (GtkButton       *button,
                                         gpointer         user_data)
{
   printf("\nHour_2_Sector_11 .............\n");
   gchar* hour = gtk_combo_box_get_active_text(GTK_COMBO_BOX(((ventana*)user_data)->turn_on_hour_2_sector_11));
   sector_11.put_hour_2(hour);
}

void on_minutes_2_sector_11_changed (GtkButton       *button,
                                    gpointer         user_data)
{
   const gchar* text = gtk_entry_get_text(GTK_ENTRY(((ventana*)user_data)->minutes_2_sector_11));
   sector_11.put_minutes_2(atoi((const char*)text));
}

} // Llaves importantes
