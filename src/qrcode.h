#include <MiniGrafx.h>

class QRcode
{
	private:
		MiniGrafx *gfx;
		void render(int16_t x, int16_t y, uint16_t color);

		uint16_t foregroundColor, backgroundColor;
		uint8_t scale = 1;

	public:
		QRcode(MiniGrafx *gfx, uint16_t foregroundColor, uint16_t backgroundColor);
		void drawQRCode(int16_t xOffset, int16_t yOffset, String message);
		void setScale(uint8_t scale);
};
