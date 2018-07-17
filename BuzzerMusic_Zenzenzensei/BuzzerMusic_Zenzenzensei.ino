#define BPM 190
#define PIN 12

void setup() {
  pinMode(2, INPUT);
}

/* ---------------------------------------------------------------------------------------*/
int notes[] = {  // C1 - B7
  /* 1 */33,35,37,39,41,44,46,49,52,55,58,62,
  /* 2 */65,69,73,78,82,87,92,98,104,110,117,123,
  /* 3 */131,139,147,156,165,175,185,196,208,220,233,247,
  /* 4 */262,277,294,311,330,349,370,392,415,440,466,494,
  /* 5 */523,554,587,622,659,698,740,784,831,880,932,988,
  /* 6 */1047,1109,1175,1245,1319,1397,1480,1568,1661,1760,1865,1976,
  /* 7 */2093,2217,2349,2489,2637,2794,2960,3136,3322,3520,3729,3951
};

void note( int num, int oct, int len ){
  int freq = notes[ ( num - 1 ) + (  oct - 1 ) * 12 ];
  tone ( PIN, freq );
  delay ( ( 240000 / BPM ) / len );
  noTone(PIN);
}

void rest(int len){
  noTone(PIN);
  delay( ( 240000 / BPM ) / len );
}

void chord( int num, int oct, int len, int arg ){
  // Sus4: 0, Major: 1, Minor: 2
  int dot = 128;
  int freq[] = { 0,0,0,0,0,0 };
  int args[] = {0,5-arg,7};
  int thisNum = num; int thisOct = oct;
  for(int cnt = 0; cnt < 3; cnt++){
    thisNum = thisNum + cnt + args[cnt];
    if( thisNum > 12 ) {
      thisNum -= 12;
      thisOct= oct + 1;
    }
    freq[cnt*2] = thisNum;
    freq[cnt*2+1] = thisOct;
  }
  for(int i = 0; i < (dot/len); i++){
      note(freq[i%3],freq[i%3+1],dot);
    }
    noTone(PIN);
};
/* ---------------------------------------------------------------------------------------*/

void loop() {
  int s = digitalRead(2);
  if (s == LOW) {
    /* -- START -- */
    ///*
    // INTRO - A
    note(12,3,16);note(1,4,16);note(4,4,16);note(12,3,16);//1
    note(12,4,8);note(7,4,8);note(2,5,16);rest(16);note(2,5,16);rest(16);note(4,5,16);rest(16);
    note(7,5,4);note(12,4,8);note(4,5,8);note(12,4,8);note(5,5,8);note(4,5,8);note(12,4,4);
    note(12,3,16);note(1,4,16);note(4,4,16);note(12,3,16);//2
    note(12,4,16);rest(16);note(7,4,16);rest(16);note(2,5,16);rest(16);note(2,5,16);rest(16);note(4,5,16);rest(16);
    note(7,5,4);note(12,4,8);note(4,5,8);note(12,4,8);note(5,5,8);note(4,5,8);note(12,4,4);
    note(12,3,16);note(1,4,16);note(4,4,16);note(12,3,16);//3
    note(12,4,8);note(7,4,8);note(2,5,16);rest(16);note(2,5,16);rest(16);note(4,5,16);rest(16);
    note(7,5,4);note(12,4,8);note(4,5,8);note(12,4,8);note(5,5,8);note(4,5,8);note(12,4,4);
    note(12,4,32);rest(32);note(4,5,32);rest(32);note(7,5,32);rest(32);note(4,5,32);rest(32);//4
    note(2,5,8);note(12,4,8);note(2,5,8);note(7,4,8);note(12,4,8);note(7,4,8);
    note(7,5,16);rest(8);note(7,5,16);rest(8);note(7,5,16);rest(16);note(7,5,16);rest(8);note(7,5,16);rest(8);note(7,5,16);rest(16);

    //INTRO - B
    note(7,3,16);note(2,4,16);note(4,4,16);note(7,3,16);
    note(12,4,16);rest(16);note(5,3,16);rest(16);note(2,5,16);rest(16);note(5,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(5,5,16);rest(16);note(7,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(7,5,16);rest(16);note(7,3,16);rest(16);note(12,4,16);rest(16);note(7,3,16);rest(16);
    note(7,3,16);note(2,4,16);note(4,4,16);note(7,3,16);
    note(12,4,16);rest(16);note(5,3,16);rest(16);note(2,5,16);rest(16);note(5,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(5,5,16);rest(16);note(7,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(2,5,16);rest(16);note(7,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(7,3,16);note(2,4,16);note(4,4,16);note(7,3,16);
    note(12,4,16);rest(16);note(5,3,16);rest(16);note(2,5,16);rest(16);note(5,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(5,5,16);rest(16);note(7,3,16);rest(16);note(4,5,16);rest(16);note(7,3,16);rest(16);
    note(7,5,16);rest(16);note(7,3,16);rest(16);note(12,4,16);rest(16);note(7,3,16);rest(16);
    note(12,4,16);note(4,5,16);note(7,5,16);note(4,4,16);
    note(2,5,8);note(12,4,8);note(2,5,8);note(7,4,8);note(12,4,4);note(12,4,2);
    rest(4);
    
    //MERODY - A
    note(7,4,16);rest(16);note(7,4,16);rest(16);note(12,4,4);note(12,2,16);rest(16);note(2,5,16);rest(16);note(12,4,4);
    note(12,2,16);rest(16);rest(8);note(12,2,16);rest(16);rest(8);note(12,2,16);rest(16);
    note(7,4,16);rest(16);note(5,5,8);rest(16);note(4,5,8);rest(8);note(2,5,8);note(12,4,4);
    note(5,3,16);rest(16);rest(8);note(5,3,16);rest(16);rest(8);note(5,3,16);rest(16);rest(8);
    note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);
    note(12,4,8);note(5,3,16);rest(16);note(2,5,8);note(5,3,16);rest(16);
    note(4,5,16);rest(16);note(2,5,16);rest(16);note(4,5,16);rest(16);note(5,5,16);rest(16);
    note(4,5,16);rest(16);note(12,4,16);rest(16);note(12,4,16);rest(16);note(2,5,16);rest(16);
    note(4,5,16);rest(16);note(5,5,16);rest(16);note(4,5,16);rest(16);note(5,5,16);rest(16);
    note(4,5,16);rest(16);rest(8);note(2,5,8);rest(8);note(12,4,4);
    note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);
    note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);
    note(12,3,16);rest(16);note(5,3,16);rest(16);note(12,3,16);rest(16);note(5,3,16);rest(16);
    note(12,4,4);note(12,2,16);rest(16);note(7,4,16);rest(16);note(7,4,4);
    note(12,2,16);rest(16);note(12,2,16);rest(16);note(12,2,16);rest(16);note(12,2,16);rest(16);note(12,2,16);rest(16);
    note(7,4,8);note(5,5,8);rest(16);note(4,5,8);rest(16);note(2,5,8);note(12,4,4);
    note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);
    note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);
    note(12,4,8);note(5,3,16);rest(16);note(2,5,8);note(5,3,16);rest(16);
    note(4,5,16);rest(16);note(2,5,16);rest(16);note(4,5,16);rest(16);note(5,5,16);rest(16);
    note(4,5,16);rest(16);note(12,4,16);rest(16);note(12,4,16);rest(16);note(2,5,16);rest(16);
    note(4,5,16);rest(16);note(5,5,16);rest(16);note(4,5,16);rest(16);note(5,5,16);rest(16);
    note(4,5,4);note(2,5,8);note(12,4,8);note(12,4,4);
    note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);note(5,3,16);rest(16);
    note(12,3,16);rest(16);note(12,3,16);rest(16);note(12,3,16);rest(16);note(12,3,16);rest(16);
    note(12,4,8);note(12,3,8);note(2,5,8);note(12,3,8);
    note(4,5,16);rest(16);note(2,5,16);rest(16);note(4,5,16);rest(16);note(2,5,16);rest(16);
    note(4,5,16);rest(16);note(12,4,16);rest(16);note(12,4,16);rest(16);note(2,5,16);rest(16);
    note(4,5,16);rest(16);note(5,5,16);rest(16);note(4,5,16);rest(16);note(5,5,16);rest(16);
    note(4,5,8);rest(8);note(2,5,8);rest(8);note(12,4,1);rest(1);
    
    //MERODY - B
    note(12,4,16);note(9,3,16);note(2,5,16);note(9,3,16);note(4,5,16);note(9,3,16);
    note(12,4,16);note(9,3,16);note(2,5,16);note(9,3,16);note(4,5,16);rest(16);
    note(12,4,16);note(5,3,16);note(2,5,16);note(5,3,16);note(4,5,16);note(5,3,16);
    note(12,4,16);note(5,3,16);note(2,5,16);note(5,3,16);note(4,5,16);note(5,3,16);
    note(12,4,16);note(5,3,16);note(2,5,16);note(5,3,16);note(4,5,16);note(5,3,16);
    note(12,4,16);note(5,3,16);note(7,5,2);rest(4);note(2,5,16);rest(16);note(2,5,8);note(2,5,4);
    note(7,3,16);rest(16);note(7,3,16);rest(16);note(7,3,16);rest(16);note(7,3,16);rest(16);note(7,3,16);rest(16);rest(8);
    note(12,4,16);note(9,3,16);note(2,5,16);note(9,3,16);note(4,5,16);note(9,3,16);
    note(12,4,16);note(9,3,16);note(2,5,16);note(9,3,16);note(4,5,16);rest(16);
    note(12,4,16);note(5,3,16);note(2,5,16);note(5,3,16);note(4,5,16);note(5,3,16);
    note(12,4,16);note(5,3,16);note(2,5,16);note(5,3,16);note(4,5,16);note(5,3,16);
    note(12,4,16);note(5,3,16);note(2,5,16);note(5,3,16);note(4,5,16);note(5,3,16);
    note(12,4,16);note(5,3,16);note(7,5,2);rest(4);note(2,5,16);rest(16);note(2,5,8);note(2,5,4);
    note(7,3,16);rest(16);note(7,3,16);rest(16);note(7,3,16);rest(16);note(7,3,16);rest(16);
    
    note(12,4,8);note(9,4,8);note(12,4,4);note(9,4,8);note(12,4,4);note(9,4,8);note(12,4,2);note(9,4,8);rest(8);note(9,4,4);rest(8);
    note(7,4,8);note(2,5,4);note(2,5,16);rest(16);note(2,5,4);note(4,5,8);note(5,5,4);note(4,5,2);rest(4);rest(8);
    note(9,4,8);note(12,4,4);note(9,4,8);note(12,4,4);note(9,4,8);note(12,4,2);note(9,4,4);note(7,4,4);rest(4);
    
    note(4,5,2);note(4,5,4);note(4,5,8);note(2,5,16);rest(16);
    note(2,5,2);note(2,5,4);note(2,5,8);note(12,4,16);rest(16);
    note(12,4,2);note(12,4,4);note(12,4,8);note(2,5,16);rest(16);note(2,5,2);rest(8);
    //*/
    
    // MERODY - C
    note(12,4,32);rest(32);rest(16);note(12,4,32);rest(32);rest(16);note(12,4,32);rest(32);rest(16);
    note(12,4,32);note(9,3,32);note(7,5,8);rest(16);note(12,4,32);note(9,3,32);note(7,5,8);rest(16);note(12,4,32);note(9,3,32);note(7,5,8);rest(16);
    note(2,5,16);note(5,3,16);note(2,5,16);note(5,3,16);note(2,5,16);note(5,3,16);note(2,5,16);note(5,3,16);note(2,5,16);note(5,3,16);note(12,4,8);rest(16);
    note(5,3,16);note(12,4,16);note(5,3,16);note(12,4,16);note(5,3,16);note(12,4,16);note(5,3,16);
    note(7,5,16);note(12,3,16);note(7,5,16);note(12,3,16);rest(16);note(12,3,16);note(7,5,16);note(12,3,16);note(7,5,16);note(12,3,16);
    note(4,5,16);note(12,3,16);note(4,5,16);note(12,3,16);note(2,5,4);
    rest(16);note(7,3,16);rest(16);note(7,3,16);note(12,4,16);note(7,3,16);
    note(12,4,16);note(7,3,16);note(2,5,16);note(7,3,16);note(4,5,16);note(7,3,16);
    note(2,5,8);rest(8);
    
    rest(8);
    
    /* -- END -- */
  }
}
