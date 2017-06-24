



// includes (Headerfiles):
#include "Headerfiles/MainGame.h"


// constructor:
MainGame::MainGame(_ScreenWidth,_ScreenHeight,_window,_GameState) :
   _ScreenWidth(500),
   _ScreenHeight(500),
   _window(nullptr),
   _GameState(GameState::PLAY){

}

// destructor:
MainGame::~MainGame(){

}

// function which runs the game till Gamestate changes
void MainGame::Run(){

   // initilize Systems -> see void InitSystem() START:
   InitSystem();

   // loop which one decides if game stops -> see void RunningLoop() END:
   RunningLoop();
}

// initilize Systems for Window creation
void MainGame::InitSystem(){
   // start SDL with everything initilized
   SDL_Init(SDL_INIT_EVERYTHING);

   // setting up window/screen
   _window = SDL_CreateWindow("Strategy Game",
                              SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED,
                              _ScreenWidth,
                              _ScreenHeight,
                              SDL_WINDOW_OPENGL);
   // Error code for Window creation:
   //if(_window == nullptr){fatalError("SDL Window could not be created!");}
}

// as long this function will be executed game will run:
void MainGame::RunningLoop(){
    while (pGameState != GameState::EXIT){
        processInput();         // start handels input
    }
}



// Event-handeling; prozess inputs by player
void MainGame::processInput(){

    SDL_Event evnt;        // variable for events ( 1=pending; 2=none available)

    // process inputs
    while (SDL_PollEvent(&evnt)){               // while event true (=1)
        switch (evnt.type) {
            // exit game by "x-out"
            case SDL_QUIT:
                pGameState = GameState::EXIT;   // change GameState to EXIT
                break;
            // handel Mouse-input:
            case SDL_MOUSEMOTION:
                std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
                break;
            default:
                break;
        }
    }

}


// draw the game:
//void MainGame::drawGame(){



//}
