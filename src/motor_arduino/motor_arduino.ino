#include <SoftwareSerial.h>
#include "/home/igdaza/domotica/src_python/message_def.h"
#include <IRremote.h>

//#define DEBUG TRUE

#define ID_MOTOR ID_HABITACION_7

#define setPin 2
#define openPin 3   //D3(arduino) --> IN1(Relay)
#define closePin 4  //D4(arduino) --> IN2(Relay)
#define enablePin 5
#define rxPin 6
#define txPin 7
#define irPin 8


#define ledPin 12

typedef enum e_status 
{
  NONE = 0,
  OPEN = 1,
  CLOSE = 2
};


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

static e_status internal_status = NONE;

char message_aux[24];
bool to_do;
int status;
int count_bytes;

void init_message();
void open(long int time_ms);
void close(long int time_ms);

SoftwareSerial apc220(rxPin, txPin);
IRrecv irrecv(irPin);
decode_results results;

void setup()
{  
  internal_status = NONE;
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  pinMode(enablePin, OUTPUT);
  digitalWrite(enablePin, HIGH);

  pinMode(setPin, OUTPUT);
  digitalWrite(setPin, HIGH);

  init_message();
  apc220.begin(9600);  
  Serial.begin(9600);  
  status = NULL_STATUS;
  to_do = false;
  count_bytes = 0;
  pinMode(openPin, OUTPUT);
  pinMode(closePin, OUTPUT);

  irrecv.enableIRIn(); // Start the receiver
}

void loop()
{   
  if (irrecv.decode(&results)) 
  {
    #ifdef DEBUG
    Serial.println(results.value);
    #endif
    irrecv.resume(); // Receive the next value
    if (results.value == 16724175)  //Key = 1 -> Open
      if (internal_status == OPEN)
        close(TIME_100*1000);
      else
        open(TIME_100*1000);
    else if (results.value == 16718055)  //Key = 2 -> Close
      if (internal_status == CLOSE)
        open(TIME_100*1000);
      else
        close(TIME_100*1000);
  }

  int n = apc220.available();

  if(n > 0)
  {
    apc220.readBytes((message_aux+count_bytes), n);

    count_bytes = count_bytes + n;
    #ifdef DEBUG
    Serial.println(count_bytes);
    #endif
    n = 0;
  }

  if(count_bytes == sizeof(t_message))
  {
    count_bytes = 0;
    memcpy((char*)p_message, message_aux, sizeof(t_message));

    if(message.id_home == ID_HOME && 
      message.id_window == ID_MOTOR)
    {
      if (message.command == POWER_UP)
      {
        to_do = true;
        status = OPEN_STATUS;
        message.status = status;
        message.ack = OK;
      }
      else if(message.command == POWER_DOWN)
      {
        to_do = true;
        status = CLOSE_STATUS;
        message.status = status;
        message.ack = OK;
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

    #ifdef DEBUG
    Serial.println("Message information: ");
    Serial.println(message.id_home);
    Serial.println(message.id_window);
    Serial.println(message.command);
    Serial.println(message.time);
    Serial.println(message.status);
    Serial.println(message.ack);
    Serial.println();
    #endif
  }

  if(to_do)
  {
    if (message.command == POWER_UP)
      open(message.time);
    else if (message.command == POWER_DOWN)
      close(message.time);

    to_do = false;
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

void open(long int time_ms)
{
  #ifdef DEBUG
  Serial.println("Open action");
  #endif
  internal_status = OPEN;
  digitalWrite(openPin, HIGH);
  delay(time_ms);
  digitalWrite(openPin, LOW);

}

void close(long int time_ms)
{
  #ifdef DEBUG
  Serial.println("Close action");
  #endif
  internal_status = CLOSE;
  digitalWrite(closePin, HIGH);
  delay(time_ms);
  digitalWrite(closePin, LOW);
}

