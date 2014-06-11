#define PUMPCOUNTS 4      // Number Pumps
#define RELAYCHANNELS 4
#define RELAYTIMES 6
#define KEYPADI2C 0x20
#define LCD_ADR 0x27


  // PIN MAPPING NICHT ÄNDERN!!!
  #define RELAY1 1
  #define RELAY2 2
  #define RELAY3 3
  #define RELAY4 4
  #define DOSE6 6      // Dosierpumpe 
  #define DOSE5 7      // Dosierpumpe 
  #define DOSE4 8      // Dosierpumpe 
  #define DOSE3 9      // Dosierpumpe 
  #define DOSE2 10     // Dosierpumpe 
  #define DOSE1 11     // Dosierpumpe 

// Größe Vorratsflaschen Dünger in ml
const int dose_val = 150;

// Neu zuordnung der Pins für Dosierung
const int dosingPins[]={DOSE1,DOSE2,DOSE3,DOSE4};

// Pumpen Einstellungen
// Uhrzeit, Aktive, Name, Pin Adresse (von array oben), Status (ignorieren, nur wichtig für Programm), Milliliter per minute, Milliliter pro Dosierungconst 
PUMP dosing[] = {  
{get_ts(10,0,0),0,"D1",dosingPins[0],60,5},
{get_ts(11,0,0),0,"D2",dosingPins[1],60,6},
{get_ts(11,25,0),0,"D3",dosingPins[2],60,3},
{get_ts(11,26,0),0,"D4",dosingPins[3],60,3},
//{get_ts(11,23,0),0,"D3",dosingPins[2],60,3},
//{get_ts(11,28,0),0,"D1",dosingPins[0],60,5},
};

boolean dosingState[PUMPCOUNTS];

const int relayPIN[]= {RELAY1,RELAY2,RELAY3,RELAY4};
RELAY relays[RELAYCHANNELS][RELAYTIMES] = { 
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}}
};

