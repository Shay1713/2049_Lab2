


// 2.
void configButtons() {
    P7SEL = P7SEL & ~(BIT4 | BIT0); // Select pin 4 and 0 to 0 for IO and keep all other
    P3SEL = P3SEL & ~(BIT6); // Select pin 6 to 0 for IO and keep all other
    P2SEL = P2SEL & ~(BIT2); // Select pin 2 to 0 for IO and keep all other

    P7DIR = P7DIR & ~(BIT4 | BIT0);
    P3DIR = P3DIR & ~(BIT6);
    P2DIR = P2DIR & ~(BIT2);


}

// 3.
unsigned char buttonState() {
    unsigned char s1 = (P7IN & BIT0);
    unsigned char s2 = (P3IN & BIT6) << 1;
    unsigned char s3 = (P2IN & BIT2) << 2;
    unsigned char s4 = (P7IN & BIT4) << 3;
    
    return s1 + s2 + s3 + s4;
}

// 4.
/**
* There are 12 main notes in music before it goes up the next octave so an unsigned char can store those
* For both pitch and duration it takes larger numbers so an unsigned int should be able to take care of those
* In a perfect world I would like to map out Through the Fire and the Flames which has 3722 notes in actual Guitar Hero
* It would take 18610 bytes or about 18 kB which would be too much for RAM but could be held with FLASH
* 
* 
*/

// 5.
void configUserLED(char inbits) {
    P6SEL = P6SEL & ~(BIT4 | BIT3 | BIT2 | BIT1); // Set pin 4,3,2,1 to IO and keep the others as default
    P6DIR = P6DIR | (BIT4 | BIT3 | BIT2 | BIT1); // Set pin 4,3,2,1 to output

    if (inbits & BIT0) {
        P6OUT = P6OUT | BIT2; // Turn on BIT2 or D1/LED1
    } else {
        P6OUT = P6OUT & ~ BIT2; // Turn off BIT2 or D1/LED1
    }
    if (inbits & BIT1) {
        P6OUT = P6OUT | BIT1; // Turn on BIT1 or D2/LED2
    } else {
        P6OUT = P6OUT & ~BIT1; // Turn off BIT1 or D2/LED2
    }
}