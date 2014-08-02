#if !defined (_INTERFACE_H)
#define _INTERFACE_H

#define HOURS_PROFILE_NUMBER 15
#define ENTRIES 16

static char* namePorcentajeWidget[] = {(char*)"porcentaje_07", (char*)"porcentaje_08", (char*)"porcentaje_09", (char*)"porcentaje_10", (char*)"porcentaje_11", (char*)"porcentaje_12", (char*)"porcentaje_13", (char*)"porcentaje_14", (char*)"porcentaje_15", (char*)"porcentaje_16", (char*)"porcentaje_17", (char*)"porcentaje_18", (char*)"porcentaje_19", (char*)"porcentaje_20", (char*)"porcentaje_21"};

static char* nameOpenButtonWidget[] = { (char*)"abrir_habitacion_1", (char*)"abrir_habitacion_2", (char*)"abrir_habitacion_3", (char*)"abrir_habitacion_4", (char*)"abrir_habitacion_5", (char*)"abrir_habitacion_6", (char*)"abrir_habitacion_7", (char*)"abrir_habitacion_8", (char*)"abrir_habitacion_9", (char*)"abrir_habitacion_10", (char*)"abrir_habitacion_11", (char*)"abrir_habitacion_12", (char*)"abrir_habitacion_13", (char*)"abrir_habitacion_14", (char*)"abrir_habitacion_15", (char*)"abrir_habitacion_16"};

static char* nameCloseButtonWidget[] = { (char*)"cerrar_habitacion_1", (char*)"cerrar_habitacion_2", (char*)"cerrar_habitacion_3", (char*)"cerrar_habitacion_4", (char*)"cerrar_habitacion_5", (char*)"cerrar_habitacion_6", (char*)"cerrar_habitacion_7", (char*)"cerrar_habitacion_8", (char*)"cerrar_habitacion_9", (char*)"cerrar_habitacion_10", (char*)"cerrar_habitacion_11", (char*)"cerrar_habitacion_12", (char*)"cerrar_habitacion_13", (char*)"cerrar_habitacion_14", (char*)"cerrar_habitacion_15", (char*)"cerrar_habitacion_16"};

static char* nameTextWidget[] = { (char*)"text_habitacion_1", (char*)"text_habitacion_2", (char*)"text_habitacion_3", (char*)"text_habitacion_4", (char*)"text_habitacion_5", (char*)"text_habitacion_6", (char*)"text_habitacion_7", (char*)"text_habitacion_8", (char*)"text_habitacion_9", (char*)"text_habitacion_10", (char*)"text_habitacion_11", (char*)"text_habitacion_12", (char*)"text_habitacion_13", (char*)"text_habitacion_14", (char*)"text_habitacion_15", (char*)"text_habitacion_16"};

static char* nameAutoHourWidget[] = { (char*)"auto_habitacion_1", (char*)"auto_habitacion_2", (char*)"auto_habitacion_3", (char*)"auto_habitacion_4", (char*)"auto_habitacion_5", (char*)"auto_habitacion_6", (char*)"auto_habitacion_7", (char*)"auto_habitacion_8", (char*)"auto_habitacion_9", (char*)"auto_habitacion_10", (char*)"auto_habitacion_11", (char*)"auto_habitacion_12", (char*)"auto_habitacion_13", (char*)"auto_habitacion_14", (char*)"auto_habitacion_15", (char*)"auto_habitacion_16"}; 

static char* nameOpenHourWidget[] = { (char*)"hora_subida_habitacion_1", (char*)"hora_subida_habitacion_2", (char*)"hora_subida_habitacion_3", (char*)"hora_subida_habitacion_4", (char*)"hora_subida_habitacion_5", (char*)"hora_subida_habitacion_6", (char*)"hora_subida_habitacion_7", (char*)"hora_subida_habitacion_8", (char*)"hora_subida_habitacion_9", (char*)"hora_subida_habitacion_10", (char*)"hora_subida_habitacion_11", (char*)"hora_subida_habitacion_12", (char*)"hora_subida_habitacion_13", (char*)"hora_subida_habitacion_14", (char*)"hora_subida_habitacion_15", (char*)"hora_subida_habitacion_16"};

static char* nameCloseHourWidget[] = { (char*)"hora_bajada_habitacion_1", (char*)"hora_bajada_habitacion_2", (char*)"hora_bajada_habitacion_3", (char*)"hora_bajada_habitacion_4", (char*)"hora_bajada_habitacion_5", (char*)"hora_bajada_habitacion_6", (char*)"hora_bajada_habitacion_7", (char*)"hora_bajada_habitacion_8", (char*)"hora_bajada_habitacion_9", (char*)"hora_bajada_habitacion_10", (char*)"hora_bajada_habitacion_11", (char*)"hora_bajada_habitacion_12", (char*)"hora_bajada_habitacion_13", (char*)"hora_bajada_habitacion_14", (char*)"hora_bajada_habitacion_15", (char*)"hora_bajada_habitacion_16"};

static char* nameAutoProfileWidget[] = { (char*)"auto_perfil_habitacion_1", (char*)"auto_perfil_habitacion_2", (char*)"auto_perfil_habitacion_3", (char*)"auto_perfil_habitacion_4", (char*)"auto_perfil_habitacion_5", (char*)"auto_perfil_habitacion_6", (char*)"auto_perfil_habitacion_7", (char*)"auto_perfil_habitacion_8", (char*)"auto_perfil_habitacion_9", (char*)"auto_perfil_habitacion_10", (char*)"auto_perfil_habitacion_11", (char*)"auto_perfil_habitacion_12", (char*)"auto_perfil_habitacion_13", (char*)"auto_perfil_habitacion_14", (char*)"auto_perfil_habitacion_15", (char*)"auto_perfil_habitacion_16"};

static char* nameProfileWidget[] = { 
        (char*)"perfil_habitacion_1", 
        (char*)"perfil_habitacion_2", 
        (char*)"perfil_habitacion_3", 
        (char*)"perfil_habitacion_4", 
        (char*)"perfil_habitacion_5", 
        (char*)"perfil_habitacion_6", 
        (char*)"perfil_habitacion_7", 
        (char*)"perfil_habitacion_8", 
        (char*)"perfil_habitacion_9", 
        (char*)"perfil_habitacion_10", 
        (char*)"perfil_habitacion_11", 
        (char*)"perfil_habitacion_12", 
        (char*)"perfil_habitacion_13", 
        (char*)"perfil_habitacion_14", 
        (char*)"perfil_habitacion_15", 
        (char*)"perfil_habitacion_16"};

typedef struct {
  GtkWidget               *domotica_win;

  GtkWidget*              openWidget[ENTRIES];
  GtkWidget*              closeWidget[ENTRIES];
  GtkWidget*              textWidget[ENTRIES];
  GtkWidget*              autoHourWidget[ENTRIES];
  GtkWidget*              openHourWidget[ENTRIES];
  GtkWidget*              closeHourWidget[ENTRIES];
  GtkWidget*              autoProfileWidget[ENTRIES];
  GtkWidget*              profileWidget[ENTRIES];
  
  //Riego
  // Sector_1
  GtkWidget*               turn_on_sector_1;
  GtkWidget*               turn_off_sector_1;
  GtkWidget*               state_sector_1;
  GtkWidget*               auto_sector_1;
  GtkWidget*               turn_on_hour_1_sector_1;
  GtkWidget*               turn_on_hour_2_sector_1;
  GtkWidget*               minutes_1_sector_1;
  GtkWidget*               minutes_2_sector_1;
  // Sector_2
  GtkWidget*               turn_on_sector_2;
  GtkWidget*               turn_off_sector_2;
  GtkWidget*               state_sector_2;
  GtkWidget*               auto_sector_2;
  GtkWidget*               turn_on_hour_1_sector_2;
  GtkWidget*               turn_on_hour_2_sector_2;
  GtkWidget*               minutes_1_sector_2;
  GtkWidget*               minutes_2_sector_2;
  // Sector_3
  GtkWidget*               turn_on_sector_3;
  GtkWidget*               turn_off_sector_3;
  GtkWidget*               state_sector_3;
  GtkWidget*               auto_sector_3;
  GtkWidget*               turn_on_hour_1_sector_3;
  GtkWidget*               turn_on_hour_2_sector_3;
  GtkWidget*               minutes_1_sector_3;
  GtkWidget*               minutes_2_sector_3;
  // Sector_4
  GtkWidget*               turn_on_sector_4;
  GtkWidget*               turn_off_sector_4;
  GtkWidget*               state_sector_4;
  GtkWidget*               auto_sector_4;
  GtkWidget*               turn_on_hour_1_sector_4;
  GtkWidget*               turn_on_hour_2_sector_4;
  GtkWidget*               minutes_1_sector_4;
  GtkWidget*               minutes_2_sector_4;
  // Sector_5
  GtkWidget*               turn_on_sector_5;
  GtkWidget*               turn_off_sector_5;
  GtkWidget*               state_sector_5;
  GtkWidget*               auto_sector_5;
  GtkWidget*               turn_on_hour_1_sector_5;
  GtkWidget*               turn_on_hour_2_sector_5;
  GtkWidget*               minutes_1_sector_5;
  GtkWidget*               minutes_2_sector_5;
  // Sector_6
  GtkWidget*               turn_on_sector_6;
  GtkWidget*               turn_off_sector_6;
  GtkWidget*               state_sector_6;
  GtkWidget*               auto_sector_6;
  GtkWidget*               turn_on_hour_1_sector_6;
  GtkWidget*               turn_on_hour_2_sector_6;
  GtkWidget*               minutes_1_sector_6;
  GtkWidget*               minutes_2_sector_6;
  // Sector_7
  GtkWidget*               turn_on_sector_7;
  GtkWidget*               turn_off_sector_7;
  GtkWidget*               state_sector_7;
  GtkWidget*               auto_sector_7;
  GtkWidget*               turn_on_hour_1_sector_7;
  GtkWidget*               turn_on_hour_2_sector_7;
  GtkWidget*               minutes_1_sector_7;
  GtkWidget*               minutes_2_sector_7;
  // Sector_8
  GtkWidget*               turn_on_sector_8;
  GtkWidget*               turn_off_sector_8;
  GtkWidget*               state_sector_8;
  GtkWidget*               auto_sector_8;
  GtkWidget*               turn_on_hour_1_sector_8;
  GtkWidget*               turn_on_hour_2_sector_8;
  GtkWidget*               minutes_1_sector_8;
  GtkWidget*               minutes_2_sector_8;
  // Sector_9
  GtkWidget*               turn_on_sector_9;
  GtkWidget*               turn_off_sector_9;
  GtkWidget*               state_sector_9;
  GtkWidget*               auto_sector_9;
  GtkWidget*               turn_on_hour_1_sector_9;
  GtkWidget*               turn_on_hour_2_sector_9;
  GtkWidget*               minutes_1_sector_9;
  GtkWidget*               minutes_2_sector_9;
  // Sector_10
  GtkWidget*               turn_on_sector_10;
  GtkWidget*               turn_off_sector_10;
  GtkWidget*               state_sector_10;
  GtkWidget*               auto_sector_10;
  GtkWidget*               turn_on_hour_1_sector_10;
  GtkWidget*               turn_on_hour_2_sector_10;
  GtkWidget*               minutes_1_sector_10;
  GtkWidget*               minutes_2_sector_10;
  // Sector_11
  GtkWidget*               turn_on_sector_11;
  GtkWidget*               turn_off_sector_11;
  GtkWidget*               state_sector_11;
  GtkWidget*               auto_sector_11;
  GtkWidget*               turn_on_hour_1_sector_11;
  GtkWidget*               turn_on_hour_2_sector_11;
  GtkWidget*               minutes_1_sector_11;
  GtkWidget*               minutes_2_sector_11;

  // Botón de edición de perfiles
  GtkWidget*              edit_profiles;

  // Ventana de edición de perfiles
  GtkWidget*              edit_profiles_win;

  GtkWidget*              profile_name;
  GtkWidget*              perfil_selection_combo;

  GtkWidget*              porcentajes[HOURS_PROFILE_NUMBER];

  GtkWidget*              save_profile;
  GtkWidget*              cancel_profile;
}ventana;



#endif // _INTERFACE_H

