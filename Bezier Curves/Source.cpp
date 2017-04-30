//  Bezier Curves in C++

#include "Header1.h"
#include "cSDL.h"
#include "Geometry.h"


class interactiveCurve{
public:
	interactiveCurve(SDL_Point x_passed[4]){

		for (int i = 0; i < 4; i++){
			points[i] = x_passed[i];
		}

		curve = new Bezier(points);
		curve->setConstructor(true);
		
		buttonDown = false;

		movingPoint = -1;
		mouse.x = -11;
		mouse.y = -11;
	}
	

	int checkPosition(){ //Returns -1 - not near any points, or i - near point i
		for (int i = 0; i < 4; i++){
			if (dist(mouse, points[i]) < 10){
				return(i);
			}
		}
		return(-1);
	}

	void setX(){
		points[movingPoint] = mouse;
		curve->setAnchors(points);
		cout << "Moving! \n";
	}
	
	void eventHandler(SDL_Event *e){
		if (e->type == SDL_MOUSEBUTTONDOWN)
		{
			if (e->button.button == SDL_BUTTON_LEFT){

				cout << "Button Down! \n";
				buttonDown = true;

				if (movingPoint == -1){
					mouse.x = e->button.x;
					mouse.y = e->button.y;
					movingPoint = checkPosition();
				}
				else{
					
				}


			}

		}
		else if (e->type == SDL_MOUSEMOTION)
		{
			if (movingPoint != -1){
				mouse.x = e->motion.x;
				mouse.y = e->motion.y;
				setX();
			}
			
		}
		else if (e->type == SDL_MOUSEBUTTONUP)
		{
			buttonDown = false;
			movingPoint = -1;
			cout << "Button Up! \n";
		}

	}

	int draw(SDL_Renderer *renderer){
		return(curve->draw(renderer));
	}

private:
	Bezier *curve;
	SDL_Point points[4];
	SDL_Point mouse;
	int movingPoint;
	bool buttonDown;
};


int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	int SCREENHEIGHT = 800;
	int SCREENWIDTH = 1280;

	bool quit = false;
	bool watch_mouse = false;
	cSDL* oSDL = new cSDL(&quit, SCREENWIDTH, SCREENHEIGHT);
	SDL_Rect rectangle;
	Rectangle background(0, 0, SCREENHEIGHT, SCREENWIDTH, 255, 255, 255);
	

	SDL_Point anchors[4];
	anchors[0].x = 100;
	anchors[0].y = 100;
	anchors[1].x = 200;
	anchors[1].y = 400;
	anchors[2].x = 400;
	anchors[2].y = 200;
	anchors[3].x = 500;
	anchors[3].y = 500;

	interactiveCurve curve1(anchors);


	int j = 0;
	bool mouse_down = false;

	cout << "Press q to quit. \n";
	while (quit == false)
	{

		oSDL->Begin();

		background.draw(oSDL->GetRenderer());
		
		curve1.draw(oSDL->GetRenderer());




		oSDL->End();

		curve1.eventHandler(oSDL->GetMainEvent());

		//cout << "Tic! \n";

		if (oSDL->GetMainEvent()->type == SDL_KEYDOWN)
		{
			if (oSDL->GetMainEvent()->key.keysym.sym == SDLK_q)
				quit = true;
		}
		else if (oSDL->GetMainEvent()->type == SDL_MOUSEBUTTONDOWN)
		{
			if (oSDL->GetMainEvent()->button.button == SDL_BUTTON_LEFT){
				
			}
				
		}
		else if (oSDL->GetMainEvent()->type == SDL_MOUSEBUTTONUP)
		{
			if (oSDL->GetMainEvent()->button.button == SDL_BUTTON_LEFT){
				mouse_down = false;
			}

		}
		else if (oSDL->GetMainEvent()->type == SDL_QUIT)	
		{
				quit = true;
		}

		/*if (watch_mouse == true)
		{
			if (oSDL->GetMainEvent()->type == SDL_MOUSEMOTION)
			{
				
			}
		}*/

		SDL_Delay(50);
	}

	delete oSDL;
	SDL_Quit();

	return 0;
}
