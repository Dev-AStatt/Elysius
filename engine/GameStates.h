#pragma once

class GameStates {
public:
    enum eGameStates {
        gs_play,
        gs_pause,
    };
    enum eMouseFocus {
        mf_game,
        mf_menu,
    };

    //set the active game state to
    void setGameState(const eGameStates newState) {
        if(gs_UpdatedThisTick) {return;}
        activeGameState = newState;
        gs_UpdatedThisTick = true;
    }
    void setMouseFocus(const eMouseFocus newFocus) {
        if(mf_UpdatedThisTick) {return;}
        mouseFocus = newFocus;
        mf_UpdatedThisTick = true;
    }

    //returns
    int GameState() const {return activeGameState;}
    int MouseFocus() const {return mouseFocus;}
    void clearFlags() {gs_UpdatedThisTick = false; mf_UpdatedThisTick = false;}


private:
    int activeGameState = gs_play;
    int mouseFocus = mf_game;
    bool gs_UpdatedThisTick = false;
    bool mf_UpdatedThisTick = false;
};
