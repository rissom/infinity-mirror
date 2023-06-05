
void bitbang() {
//   timing worked with 16MHz clock
//   X R27:R26 -> address counter of current data byte
//   Y R29:R28 -> temp data pointer
//   Z R31:R30 -> num bytes/strip
cli();
asm volatile(

    // initialising X and Z

    "ldi r26, lo8(leds) \n\t"
    "ldi R27, hi8(leds)"           "\n\t" // high adr of led
    "ldi R30, 80"                  "\n\t" // low of NUM_LEDs 112*3
    "ldi R31, 1"                   "\n\t" // hi of NUM_LEDs 112*3
    
    "nextbyte:"                    "\n\t"

    "mov r28,r26"                  "\n\t" // mov y,x
    "mov r29,r27"                  "\n\t"
    "LDI R16,80"                   "\n\t" // low of NUM_LEDs 112*3
    "LDI R17,1"                    "\n\t" // hi of NUM_LEDs 112*3

    // load strip bytes in R18 - R21
    "LDD r18,Y+0"                  "\n\t" //
    "ADD r28, r16"                 "\n\t" // YL + r16
    "ADC r29, r17"                 "\n\t" // YH + r17
    "LDD r19,Y+0"                  "\n\t" //  
    "ADD r28, r16"                 "\n\t" // YL + r16
    "ADC r29, r17"                 "\n\t" // YH + r17
    "LDD r20,Y+0"                  "\n\t" //
    "ADD r28, r16"                 "\n\t" // YL + r16
    "ADC r29, r17"                 "\n\t" // YH + r17
    "LDD r21,Y+0"                  "\n\t" //

    "ADIW X,1"                     "\n\t" // increase x by one: address of next data
    
    "LDI R22,8"                    "\n\t" //  bitcounter: 8 bits in bytes

    "nextbit:"                     "\n\t"

    "LSL R21"                      "\n\t"
    "ROL R23"                      "\n\t"
    "LSL R20"                      "\n\t"
    "ROL R23"                      "\n\t"
    

    "LDI R24,255"                  "\n\t"  // data for port c
    "OUT 8,R24"                    "\n\t"  // all ones!

    "LSL R19"                      "\n\t"
    "ROL R23"                      "\n\t"
    "LSL R18"                      "\n\t"
    "ROL R23"                      "\n\t"
    
    "OUT 8,R23"                    "\n\t"   // data for port c
    
    "NOP"                          "\n\t"
    "NOP"                          "\n\t"
    "NOP"                          "\n\t"
    "NOP"                          "\n\t"
   
    "LDI R23,00"                   "\n\t"  // all zeros
    "OUT 8,R23"                    "\n\t"  // data for port c

    "NOP"                          "\n\t"
 
    "DEC R22"                      "\n\t"
    "BRNE nextbit"                 "\n\t" // branch if not zero 

    "SBIW Z,1"                     "\n\t"
    "BRNE nextbyte"                "\n\t" // branch if not zero 
  :::"r16","r17","r18","r19","r20","r21","r22","r23","r24","r26","r27","r28","r29","r30","r31");
  sei();
}
