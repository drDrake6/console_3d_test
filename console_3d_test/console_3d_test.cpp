#include "Headers.h"



int main()
{
	//system("mode con cols=160 lines=57");

	ConsoleBufferString* buffer = ConsoleBufferString::Instance(_FULL_SCREAN_);
	buffer->HideCursor(); 
	buffer->NotHighLightConsole();
	
   Set<string> game_space;

   game_space.Add("###################");
   game_space.Add("#                 #");
   game_space.Add("#                 #");
   game_space.Add("#                 #");
   game_space.Add("#                 #");
   game_space.Add("#        ##       #");
   game_space.Add("#        ##       #");
   game_space.Add("#                 #");
   game_space.Add("#                 #");
   game_space.Add("#          ########");
   game_space.Add("#                 #");
   game_space.Add("#######      ######");
   game_space.Add("#     #           #");
   game_space.Add("#  ####           #");
   game_space.Add("#                 #");
   game_space.Add("#                 #");
   game_space.Add("###################");

   Map map(game_space);
   Entity* player = new Player(2.0f, 12.0f, 0.0f, 60.0f, 1.5f, 47.0f, 1.5f, 30.0f, 0.25f, 2.0f, map);

   FPS _fps;

   while (true)
   {
	   _fps.current_Calc_Period();
	   buffer->Render(map, player, _fps);
	   if (!player->Controle(map, _fps)) break;
   }

   _getch();
}