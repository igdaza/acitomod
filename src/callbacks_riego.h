#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>
#include "Interface.h"

extern "C" {

//Riego
void on_turn_on_sector_1_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_2_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_3_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_4_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_5_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_6_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_7_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_8_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_9_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_10_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_on_sector_11_clicked (GtkButton       *button,
                                  gpointer         user_data);

void on_turn_off_sector_1_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_2_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_3_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_4_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_5_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_6_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_7_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_8_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_9_clicked (GtkButton       *button,
                                   gpointer         user_data);

void on_turn_off_sector_10_clicked (GtkButton       *button,
                                    gpointer         user_data);

void on_turn_off_sector_11_clicked (GtkButton       *button,
                                    gpointer         user_data);

void on_turn_on_hour_1_sector_1_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_2_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_3_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_4_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_5_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_6_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_7_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_8_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_9_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_10_changed (GtkButton       *button,
                                         gpointer         user_data);
void on_turn_on_hour_1_sector_11_changed (GtkButton       *button,
                                         gpointer         user_data);

void on_turn_on_hour_2_sector_1_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_2_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_3_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_4_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_5_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_6_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_7_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_8_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_9_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_10_changed (GtkButton       *button,
                                        gpointer         user_data);
void on_turn_on_hour_2_sector_11_changed (GtkButton       *button,
                                         gpointer         user_data);

void on_minutes_1_sector_1_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_2_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_3_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_4_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_5_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_6_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_7_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_8_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_9_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_10_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_1_sector_11_changed (GtkButton       *button, gpointer         user_data);

void on_minutes_2_sector_1_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_2_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_3_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_4_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_5_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_6_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_7_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_8_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_9_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_10_changed (GtkButton       *button, gpointer         user_data);
void on_minutes_2_sector_11_changed (GtkButton       *button, gpointer         user_data);
};
