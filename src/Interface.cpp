/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "Interface.h"

int
main (int argc, char *argv[])
{
    GtkBuilder *builder;
    ventana *domotica;
 
    domotica = g_slice_new (ventana);
 
    gtk_set_locale ();
    gtk_init (&argc, &argv);

    builder = gtk_builder_new ();
    
    gtk_builder_add_from_file (builder, "/home/igdaza/domotica/src/gui/main_gui.glade", NULL);

    domotica->domotica_win = GTK_WIDGET (gtk_builder_get_object (builder, "domotica_win"));
    domotica->edit_profiles_win = GTK_WIDGET (gtk_builder_get_object (builder, "edit_profiles_win"));

    for (int i = 0; i < ENTRIES; i++)
    {
        domotica->openWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameOpenButtonWidget[i]));
        domotica->closeWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameCloseButtonWidget[i]));
        domotica->textWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameTextWidget[i]));
        domotica->autoHourWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameAutoHourWidget[i]));
        domotica->openHourWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameOpenHourWidget[i]));
        domotica->closeHourWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameCloseHourWidget[i]));
        domotica->profileWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameProfileWidget[i]));
        domotica->autoProfileWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameAutoProfileWidget[i]));
        domotica->profileWidget[i] = GTK_WIDGET (gtk_builder_get_object (builder, nameProfileWidget[i]));
    }
    
    // Riego
    // Sector_1
    domotica->turn_on_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_1"));
    domotica->turn_off_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_1"));
    domotica->state_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_1"));
    domotica->auto_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_1"));
    domotica->turn_on_hour_1_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_1"));
    domotica->turn_on_hour_2_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_1"));
    domotica->minutes_1_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_1"));
    domotica->minutes_2_sector_1 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_1"));
    // Sector_2
    domotica->turn_on_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_2"));
    domotica->turn_off_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_2"));
    domotica->state_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_2"));
    domotica->auto_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_2"));
    domotica->turn_on_hour_1_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_2"));
    domotica->turn_on_hour_2_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_2"));
    domotica->minutes_1_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_2"));
    domotica->minutes_2_sector_2 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_2"));
    // Sector_3
    domotica->turn_on_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_3"));
    domotica->turn_off_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_3"));
    domotica->state_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_3"));
    domotica->auto_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_3"));
    domotica->turn_on_hour_1_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_3"));
    domotica->turn_on_hour_2_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_3"));
    domotica->minutes_1_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_3"));
    domotica->minutes_2_sector_3 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_3"));
    // Sector_4
    domotica->turn_on_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_4"));
    domotica->turn_off_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_4"));
    domotica->state_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_4"));
    domotica->auto_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_4"));
    domotica->turn_on_hour_1_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_4"));
    domotica->turn_on_hour_2_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_4"));
    domotica->minutes_1_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_4"));
    domotica->minutes_2_sector_4 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_4"));
    // Sector_5
    domotica->turn_on_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_5"));
    domotica->turn_off_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_5"));
    domotica->state_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_5"));
    domotica->auto_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_5"));
    domotica->turn_on_hour_1_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_5"));
    domotica->turn_on_hour_2_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_5"));
    domotica->minutes_1_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_5"));
    domotica->minutes_2_sector_5 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_5"));
    // Sector_6
    domotica->turn_on_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_6"));
    domotica->turn_off_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_6"));
    domotica->state_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_6"));
    domotica->auto_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_6"));
    domotica->turn_on_hour_1_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_6"));
    domotica->turn_on_hour_2_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_6"));
    domotica->minutes_1_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_6"));
    domotica->minutes_2_sector_6 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_6"));
    // Sector_7
    domotica->turn_on_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_7"));
    domotica->turn_off_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_7"));
    domotica->state_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_7"));
    domotica->auto_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_7"));
    domotica->turn_on_hour_1_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_7"));
    domotica->turn_on_hour_2_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_7"));
    domotica->minutes_1_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_7"));
    domotica->minutes_2_sector_7 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_7"));
    // Sector_8
    domotica->turn_on_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_8"));
    domotica->turn_off_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_8"));
    domotica->state_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_8"));
    domotica->auto_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_8"));
    domotica->turn_on_hour_1_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_8"));
    domotica->turn_on_hour_2_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_8"));
    domotica->minutes_1_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_8"));
    domotica->minutes_2_sector_8 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_8"));
    // Sector_9
    domotica->turn_on_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_9"));
    domotica->turn_off_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_9"));
    domotica->state_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_9"));
    domotica->auto_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_9"));
    domotica->turn_on_hour_1_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_9"));
    domotica->turn_on_hour_2_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_9"));
    domotica->minutes_1_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_9"));
    domotica->minutes_2_sector_9 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_9"));
    // Sector_10
    domotica->turn_on_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_10"));
    domotica->turn_off_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_10"));
    domotica->state_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_10"));
    domotica->auto_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_10"));
    domotica->turn_on_hour_1_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_10"));
    domotica->turn_on_hour_2_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_10"));
    domotica->minutes_1_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_10"));
    domotica->minutes_2_sector_10 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_10"));
    // Sector_11
    domotica->turn_on_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_sector_11"));
    domotica->turn_off_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_off_sector_11"));
    domotica->state_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "state_sector_11"));
    domotica->auto_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "auto_sector_11"));
    domotica->turn_on_hour_1_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_1_sector_11"));
    domotica->turn_on_hour_2_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "turn_on_hour_2_sector_11"));
    domotica->minutes_1_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_1_sector_11"));
    domotica->minutes_2_sector_11 = GTK_WIDGET (gtk_builder_get_object (builder, "minutes_2_sector_11"));


    // Botones comunes
    domotica->edit_profiles = GTK_WIDGET (gtk_builder_get_object (builder, "edit_profiles"));

    // Perfiles
    domotica->profile_name = GTK_WIDGET (gtk_builder_get_object (builder, "profile_name"));
    domotica->perfil_selection_combo = GTK_WIDGET (gtk_builder_get_object (builder, "perfil_selection_combo"));

    for(int i =0; i<HOURS_PROFILE_NUMBER; i++)
       domotica->porcentajes[i] =  GTK_WIDGET (gtk_builder_get_object (builder, namePorcentajeWidget[i]));

    domotica->save_profile = GTK_WIDGET (gtk_builder_get_object (builder, "save_profile"));
    domotica->cancel_profile = GTK_WIDGET (gtk_builder_get_object (builder, "cancel_profile"));

    gdk_threads_init ();
    gdk_threads_enter();
    /* connect signals, passing our TutorialTextEditor struct as user data */
    gtk_builder_connect_signals (builder, domotica);

    /* free memory used by GtkBuilder object */
    g_object_unref (G_OBJECT (builder));

    gtk_widget_show (domotica->domotica_win);               
    gtk_main ();
    gdk_threads_leave();

    return 0;
}

