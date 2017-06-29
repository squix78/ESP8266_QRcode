#include <MiniGrafx.h>

class QRcode
{
	private:
		MiniGrafx *gfx;
		void render(int16_t x, int16_t y, uint16_t color);

		uint16_t foregroundColor, backgroundColor;

	public:
		QRcode(MiniGrafx *gfx, uint16_t foregroundColor, uint16_t backgroundColor);
		void create(int16_t xOffset, int16_t yOffset, String message);
};
