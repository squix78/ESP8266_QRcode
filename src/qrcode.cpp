#include <Arduino.h>
#include "qrcode.h"
#include "qrencode.h"

QRcode::QRcode(MiniGrafx *gfx, uint16_t foregroundColor, uint16_t backgroundColor){
	this->gfx = gfx;
	this->foregroundColor = foregroundColor;
	this->backgroundColor = backgroundColor;
}


void QRcode::render(int16_t x, int16_t y, uint16_t color){
	gfx->setColor(color);
	gfx->fillRect(x, y, scale, scale);
}

void QRcode::setScale(uint8_t scale) {
	this->scale = scale;
}

void QRcode::drawQRCode(int16_t xOffset, int16_t yOffset, String message) {

  // create QR code
  message.toCharArray((char *)strinbuf,260);
  qrencode();

  // print QR Code
  for (byte x = 0; x < WD; x+=2) {
    for (byte y = 0; y < WD; y++) {
      if ( QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // black square on top of black square
        render(x * scale + xOffset, y * scale + yOffset, foregroundColor);
        render((x+1) * scale + xOffset, y * scale + yOffset, foregroundColor);
      }
      if (!QRBIT(x,y) &&  QRBIT((x+1),y)) {
        // white square on top of black square
        render(x * scale + xOffset, y * scale + yOffset, backgroundColor);
        render((x+1) * scale + xOffset, y * scale + yOffset, foregroundColor);
      }
      if ( QRBIT(x,y) && !QRBIT((x+1),y)) {
        // black square on top of white square
        render(x * scale + xOffset, y * scale + yOffset, foregroundColor);
        render((x+1) * scale + xOffset, y * scale + yOffset, backgroundColor);
      }
      if (!QRBIT(x,y) && !QRBIT((x+1),y)) {
        // white square on top of white square
        render(x * scale + xOffset, y * scale + yOffset, backgroundColor);
        render((x+1) * scale + xOffset, y * scale + yOffset, backgroundColor);
      }
    }
    Serial.println();
  }



}
