#define PUMPCOUNTS 4      // Number Pumps
#define RELAYCHANNELS 4
#define RELAYTIMES 6
#define KEYPADI2C 0x20
#define LCD_ADR 0x27


  // PIN MAPPING NICHT ÄNDERN!!!
  #define RELAY1 2
  #define RELAY2 3
  #define RELAY3 4
  #define RELAY4 5
  #define DOSE4 9      // Dosierpumpe 
  #define DOSE3 10      // Dosierpumpe 
  #define DOSE2 11     // Dosierpumpe 
  #define DOSE1 12     // Dosierpumpe 

// Größe Vorratsflaschen Dünger in ml
const int dose_val = 150;

// Neu zuordnung der Pins für Dosierung
const int dosingPins[]={DOSE1,DOSE2,DOSE3,DOSE4};

// Pumpen Einstellungen
// Uhrzeit, Aktive, Name, Pin Adresse (von array oben), Status (ignorieren, nur wichtig für Programm), Milliliter per minute, Milliliter pro Dosierungconst 
PUMP dosing[] = {  
{get_ts(10,0,0),1,"D1",dosingPins[0],60,5},
{get_ts(11,0,0),1,"D2",dosingPins[1],60,6},
{get_ts(11,25,0),1,"D3",dosingPins[2],60,3},
{get_ts(11,26,0),1,"D4",dosingPins[3],60,3},
//{get_ts(11,23,0),0,"D3",dosingPins[2],60,3},
//{get_ts(11,28,0),0,"D1",dosingPins[0],60,5},
};

boolean dosingState[PUMPCOUNTS];

const int relayPIN[]= {RELAY1,RELAY2,RELAY3,RELAY4};
RELAY relays[RELAYCHANNELS][RELAYTIMES] = { 
  {{get_ts(0,0,0),1},{get_ts(17,10,0),0},{get_ts(17,15,0),1},{get_ts(17,20,0),0},{get_ts(17,25,0),1},{get_ts(17,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}},
  {{get_ts(0,0,0),0},{get_ts(10,0,0),1},{get_ts(11,30,0),0},{get_ts(19,0,0),1},{get_ts(20,0,0),0},{get_ts(21,30,0),0}}
};

