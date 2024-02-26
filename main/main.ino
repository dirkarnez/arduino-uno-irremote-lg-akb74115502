//#include <IRremote.hpp>
//#define IR_RECEIVE_PIN 7
//
//void setup()
//{
//  Serial.begin(9600);
//  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
//}
//
//void loop() {
//  if (IrReceiver.decode()) {
//      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
//      IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
//      IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
//      IrReceiver.resume(); // Enable receiving of the next value
//  }
//}
//
//// 1
////Protocol=NEC Address=0x4 Command=0x11 Raw-Data=0xEE11FB04 32 bits LSB first
////Send with: IrSender.sendNEC(0x4, 0x11, <numberOfRepeats>);
//
//// choose input
////Protocol=NEC Address=0x4 Command=0xB Raw-Data=0xF40BFB04 32 bits LSB first
////Send with: IrSender.sendNEC(0x4, 0xB, <numberOfRepeats>);
/*
MIT License
Copyright 2021 Michael Schoeffler (https://www.mschoeffler.com)
Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/
/*
 * This is an example source code of a tutorial on how to do IR communication with the Arduino Uno. 
 * This program is for a sending Arduino Uno that sends an IR signal each second.
 */

#include <IRremote.h> // >v3.0.0
                                            
uint8_t tSendPin = 3;
void setup()  
{  
  pinMode(tSendPin, OUTPUT);
  IrSender.begin(tSendPin, ENABLE_LED_FEEDBACK, USE_DEFAULT_FEEDBACK_LED_PIN); // Specify send pin and enable feedback LED at default feedback LED pin
}  
                               
void loop()  
{  
  IrSender.sendNECRaw(0xF40BFB04, 0); // the address 0x0102 with the command 0x34 is sent 
  delay(1000); // wait for one second
}  
