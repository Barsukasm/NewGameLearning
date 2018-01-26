#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>

using namespace sf;

float offsetX = 0, offsetY = 0;

const int H = 17;
const int W = 150;

RenderWindow window(VideoMode(800, 600, 24), "LearningGame", Style::Fullscreen);

String TileMap[H] = {
	"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                                                                                                    0",
	"0                                                                             bkkkkkkkkkkkkkkkke                                                     0",
	"0                                                                       r                                                                            0",
	"0                                                                      rr                                                                            0",
	"0                                                                     rrr                                                                            0",
	"0                    bkkke                                           rrrr                                                                            0",
	"0                                      t0                           rrrrr                                                                            0",
	"0G                                     y0              t0          rrrrrr                                                                            0",
	"0           d    g       d             n0              n0         rrrrrrr                                                                            0",
	"GGGGGGGGGGGGGGGGGGGGGGGGGGGGZGGGGGGGGGGGGGGZGGGGGGGGGGZGGGGGGGGGGGGGGGGGGGGGGZGGGGGGZGGGGGGGGGGGZGGGGGZGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
	"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGZGGGGGGGGGGGGGGGGGGGGGGZGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
	"GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG",
};


void DrawMap(Sprite *tile) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			switch (TileMap[i][j]) {
			case 'G'://ground
				tile->setTextureRect(IntRect(128, 128, 64, 64));
				break;
			case 'Z'://ground with loza
				tile->setTextureRect(IntRect(193, 128, 64, 64));
				break;
			case 'r'://rock
				tile->setTextureRect(IntRect(897, 64, 64, 64));
				break;
			case 'g'://cactus
				tile->setTextureRect(IntRect(897, 0, 64, 64));
				break;
			case 'b'://left end of platform
				tile->setTextureRect(IntRect(577, 320, 64, 64));
				break;
			case 'e'://right end of platform
				tile->setTextureRect(IntRect(769, 320, 64, 64));
				break;
			case 'k'://middle of platform
				tile->setTextureRect(IntRect(641, 320, 64, 64));
				break;
			case 't'://top of column
				tile->setTextureRect(IntRect(385, 64, 64, 64));
				break;
			case 'y'://middle of column
				tile->setTextureRect(IntRect(449, 64, 64, 64));
				break;
			case 'n'://bottom of column
				tile->setTextureRect(IntRect(513, 64, 64, 64));
				break;
			case 'd'://flower
				tile->setTextureRect(IntRect(961, 0, 64, 64));
				break;
			case ' ':
			case '0':continue;
			}
			tile->setPosition(j * 64 - offsetX, i * 64 - offsetY);
			window.draw(*tile);
		}
	}
}

int main() {
	
	Texture tileset;
	tileset.loadFromFile("images/Image-Tileset.png");
	
	Sprite tile(tileset);

	Clock clock;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) window.close();
		};

		if (Keyboard::isKeyPressed(Keyboard::Up)) offsetY -= 0.5;
		if (Keyboard::isKeyPressed(Keyboard::Down)) offsetY += 0.5;
		if (Keyboard::isKeyPressed(Keyboard::Left)) offsetX -= 0.5;
		if (Keyboard::isKeyPressed(Keyboard::Right)) offsetX += 0.5;
		if (Keyboard::isKeyPressed(Keyboard::Escape)) window.close();

		window.clear(Color(107, 140, 255));
		DrawMap(&tile);
		window.display();
	}
	return 0;
}