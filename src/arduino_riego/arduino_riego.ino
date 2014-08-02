#include <SoftwareSerial.h>
#include <Timer.h>
#include <IRremote.h>
#include "/home/igdaza/domotica/src_python/message_def.h"

#define txPin 2     //D2(arduino) --> ACP220(RX)
#define rxPin 3     //D3(arduino) --> ACP220(TX)
#define sector1 4   //D4(arduino) --> IN1(Relay)
#define sector2 5   //D5(arduino) --> IN2(Relay)
#define sector3 6   //D6(arduino) --> IN3(Relay)
#define sector4 7   //D7(arduino) --> IN4(Relay)
#define sector5 8   //D8(arduino) --> IN5(Relay)
#define sector6 9   //D9(arduino) --> IN6(Relay)
#define sector7 10  //D10(arduino) --> IN7(Relay)
#define presion 11  //D11(arduino) --> IN8(Relay)
#define pozo    12  //D12(arduino) --> 
#define irPin 13


#define DEBUG True


typedef struct t_message
{
  long int id_home;
  long int id_window;
  long int command;
  long int time;
  long int status;
  long int ack;
};

t_message message;
t_message* p_message;

char message_aux[24];
int status;
int count_bytes;

void init_message();
void power_up(long int sector, long int time);
void power_down(long int sector);

SoftwareSerial apc220(rxPin, txPin);
Timer timer_riego;
Timer timer_pozo;

int timer_id;
int timer_id_pozo;

long int sector_id;

IRrecv irrecv(irPin);
decode_results results;

void callback_power_off(void)
{

  Serial.println("Power_off sector");

  timer_riego.stop(timer_id);

  //digitalWrite(presion, LOW);

  if (sector_id == ID_SECTOR_1)
    digitalWrite(sector1, LOW);
  else if (sector_id == ID_SECTOR_2)
    digitalWrite(sector2, LOW);
  else if (sector_id == ID_SECTOR_3)
    digitalWrite(sector3, LOW);
  else if (sector_id == ID_SECTOR_4)
    digitalWrite(sector4, LOW);
  else if (sector_id == ID_SECTOR_5)
    digitalWrite(sector5, LOW);
  else if (sector_id == ID_SECTOR_6)
    digitalWrite(sector6, LOW);
  else if (sector_id == ID_SECTOR_7)
    digitalWrite(sector7, LOW);
  else if (sector_id == ID_SECTOR_8)
    digitalWrite(presion, LOW);
}

void callback_power_off_pozo(void)
{
  Serial.println("Power_off pozo");
  digitalWrite(pozo, LOW);
  timer_pozo.stop(timer_id_pozo);
}

void callback_power_off_presion(void)
{
  Serial.println("Power_off presion");
  digitalWrite(presion, LOW);
}

void setup()
{  

  init_message();
  apc220.begin(9600);  
  Serial.begin(9600);  
  status = NULL_STATUS;
  count_bytes = 0;
  pinMode(sector1, OUTPUT);
  pinMode(sector2, OUTPUT);
  pinMode(sector3, OUTPUT);
  pinMode(sector4, OUTPUT);
  pinMode(sector5, OUTPUT);
  pinMode(sector6, OUTPUT);
  pinMode(sector7, OUTPUT);
  pinMode(presion, OUTPUT);
  pinMode(pozo,    OUTPUT);
  digitalWrite(sector1, LOW);
  digitalWrite(sector2, LOW);
  digitalWrite(sector3, LOW);
  digitalWrite(sector4, LOW);
  digitalWrite(sector5, LOW);
  digitalWrite(sector6, LOW);
  digitalWrite(sector7, LOW);
  digitalWrite(presion, LOW);
  digitalWrite(pozo, LOW);

  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{   
  timer_riego.update();
  timer_pozo.update();

  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value);
    irrecv.resume(); // Receive the next value

    if (results.value == 16724175)       //Key = 1 -> Sector1
      power_up(ID_SECTOR_1, 30);
    else if (results.value == 16718055)  //Key = 2 -> Sector2
      power_up(ID_SECTOR_2, 30);
    else if (results.value == 16743045)  //Key = 3 -> Sector3
      power_up(ID_SECTOR_3, 30);
    else if (results.value == 16716015)  //Key = 4 -> Sector4
      power_up(ID_SECTOR_4, 30);
    else if (results.value == 16726215)  //Key = 5 -> Sector5
      power_up(ID_SECTOR_5, 30);
    else if (results.value == 16734885)  //Key = 6 -> Sector6
      power_up(ID_SECTOR_6, 30);
    else if (results.value == 16728765)  //Key = 7 -> Sector7
      power_up(ID_SECTOR_7, 30);
    else if (results.value == 16732845)  //Key = 9 -> Pozo
      power_up(ID_SECTOR_9, 10);
    else if (results.value == 16738455)  //Key = 0 -> Apagar
    {
      power_down(ID_SECTOR_1);
      power_down(ID_SECTOR_2);
      power_down(ID_SECTOR_3);
      power_down(ID_SECTOR_4);
      power_down(ID_SECTOR_5);
      power_down(ID_SECTOR_6);
      power_down(ID_SECTOR_7);
      power_down(ID_SECTOR_8);
      power_down(ID_SECTOR_9);
    }
  }

  int n = apc220.available();

  if(n > 0)
  {
    apc220.readBytes((message_aux+count_bytes), n);

    count_bytes = count_bytes + n;
    n = 0;
  }

  if(count_bytes == sizeof(t_message))
  {
    count_bytes = 0;
    memcpy((char*)p_message, message_aux, sizeof(t_message));

    if(message.id_home == ID_HOME && 
       (message.id_window == ID_SECTOR_1 ||
        message.id_window == ID_SECTOR_2 ||
        message.id_window == ID_SECTOR_3 ||
        message.id_window == ID_SECTOR_3 ||
        message.id_window == ID_SECTOR_5 ||
        message.id_window == ID_SECTOR_6 ||
        message.id_window == ID_SECTOR_7 ||
        message.id_window == ID_SECTOR_8 ||
        message.id_window == ID_SECTOR_9))
    {
      if (message.command == POWER_UP)
      {
        status = OPEN_STATUS;
        message.status = status;
        message.ack = OK;
        power_up(message.id_window, message.time);
      }
      else if(message.command == POWER_DOWN)
      {
        status = CLOSE_STATUS;
        message.status = status;
        message.ack = OK;
        power_down(message.id_window);
      }
      else if(message.command == GET_STATUS)
      {
        message.command = message.command;
        message.status = status;
        message.ack = OK;
      }
      else
        message.ack = NO_OK;

      apc220.write((uint8_t*) &message, sizeof(t_message));
    }

    Serial.println("Message information: ");
    Serial.println(message.id_home);
    Serial.println(message.id_window);
    Serial.println(message.command);
    Serial.println(message.time);
    Serial.println(message.status);
    Serial.println(message.ack);
    Serial.println();
  }
}

void init_message()
{
  p_message = &message;
  message.id_home = 0;
  message.id_window = 0;
  message.command = 0;
  message.time = 0;
  message.status = 0;
  memset(&message_aux, '0', sizeof(message_aux));
}

void power_up(long int id, long int time)
{
  if (id != ID_SECTOR_9)
  {
    Serial.println("Power_on sector");
    sector_id = id;
    timer_id = timer_riego.after(time*60*1000, callback_power_off);
    digitalWrite(presion, HIGH);
    if (sector_id == ID_SECTOR_1)
      digitalWrite(sector1, HIGH);
    else if (sector_id == ID_SECTOR_2)
      digitalWrite(sector2, HIGH);
    else if (sector_id == ID_SECTOR_3)
      digitalWrite(sector3, HIGH);
    else if (sector_id == ID_SECTOR_4)
      digitalWrite(sector4, HIGH);
    else if (sector_id == ID_SECTOR_5)
      digitalWrite(sector5, HIGH);
    else if (sector_id == ID_SECTOR_6)
      digitalWrite(sector6, HIGH);
    else if (sector_id == ID_SECTOR_7)
      digitalWrite(sector7, HIGH);
  }
  else if (id == ID_SECTOR_9)
  {
    Serial.println("Power_on pozo");
    timer_id_pozo = timer_pozo.after(time*60*1000, callback_power_off_pozo);
    digitalWrite(pozo, HIGH);
  }
}

void power_down(long int sector_id)
{
  if (sector_id != ID_SECTOR_9)
  {
    Serial.println("Power_off sector");
    timer_riego.stop(timer_id);
    //digitalWrite(presion, LOW);
    if (sector_id == ID_SECTOR_1)
      digitalWrite(sector1, LOW);
    else if (sector_id == ID_SECTOR_2)
      digitalWrite(sector2, LOW);
    else if (sector_id == ID_SECTOR_3)
      digitalWrite(sector3, LOW);
    else if (sector_id == ID_SECTOR_4)
      digitalWrite(sector4, LOW);
    else if (sector_id == ID_SECTOR_5)
      digitalWrite(sector5, LOW);
    else if (sector_id == ID_SECTOR_6)
      digitalWrite(sector6, LOW);
    else if (sector_id == ID_SECTOR_7)
      digitalWrite(sector7, LOW);
  }
  else if (sector_id == ID_SECTOR_9)
  {
    Serial.println("Power_off pozo");
    timer_pozo.stop(timer_id_pozo);
    digitalWrite(pozo, LOW);
  }
}

