#include <graphics.h>
#include <cstdio>
#include <conio.h>

static int program = 1;

void presentframe(int& page) {
    setvisualpage(page);
    page = 1 - page;
    setactivepage(page);
}

int main(int argc, char** argv){
	initwindow(800, 800, "Title of the window");
	
	int page = 0;
	int x = 10;
	int y = 100;
	int width = 90;
	int height = 100;
	int dx = 3;
	int dy = 3;
	char exitText[] = "Press any key to exit";
	
	setbkcolor(BLACK);
	setcolor(WHITE);
	settextjustify(CENTER_TEXT, TOP_TEXT);
		
	while (program == 1){
		if (kbhit()) {
			program = 0;
		}

		x += dx;
		y += dy;

		if (x <= 0 || x + width >= getmaxx()) {
			dx = -dx;
			x += dx;
		}

		if (y <= 0 || y + height >= getmaxy()) {
			dy = -dy;
			y += dy;
		}

		cleardevice();
		rectangle(x, y, x + width, y + height);
		outtextxy(getmaxx() / 2, getmaxy() / 2, exitText);
		presentframe(page);
		delay(1);
	};
	cleardevice();
	return 0;
}