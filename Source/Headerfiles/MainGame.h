//
//
//

#ifndef __StrategyGame__MainGame__
#define __StrategyGame__MainGame__

// includes (Library)
#include <SDL2/SDL.h>         // MACOS specific


// MainGame.h :

enum class GameState {PLAY, EXIT};

class MainGame{
public:
   MainGame();       // konstructor
   ~MainGame();      // destructor

   void Run();


private:

   void InitSystem();
   void RunningLoop();

   // GameState -> running or not?
   GameState _GameState;

   // SDL-specific variables
   SDL_Window* _window;
   int _ScreenWidth;
   int _ScreenHeight;

   // rendering/drawing window

   void drawGame();

   // event-handeling with SDL
   void _ProcessInput();

};


#endif // end of defined(__StrategyGame__MainGame__)
