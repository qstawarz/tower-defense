#ifndef TOWER_DEFENSE_DISPLAY_H
#define TOWER_DEFENSE_DISPLAY_H

#define WINDOW_SIZE_X 1080 //SDL_WINDOW_FULLSCREEN
#define WINDOW_SIZE_Y 720 //SDL_WINDOW_FULLSCREEN
#define FRAME_RATE 60
#define FRAME_DELAY 1000 / FRAME_RATE

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Display
{
public:
	Display();
	~Display();
	Display(const Display &);
	Display &operator=(const Display &);

	void initAll();
	void initSDL();
	void initSDLImg();
	void initSDLWindow();
	void initSDLRenderer();
	void initSDLFont();
	void clearRenderer();
	void presentRenderer();

	SDL_Window &getWindow();
	SDL_Renderer &getRenderer();
	TTF_Font &getFont();

protected:

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	TTF_Font *font;

};

#endif //TOWER_DEFENSE_DISPLAY_H