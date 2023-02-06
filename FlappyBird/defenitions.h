#ifndef DEFENITIONS_H
#define DEFENITIONS_H

#define SCREEN_TITLE "Flappy Bird"
#define SCREEN_WIDHT 768
#define SCREEN_HEIGHT 1024

#define SPLASH_STATE_SHOW_TIME 2.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/images/Splash Background.png"

#define MAIN_MENU_BACKGROUND_FILEPATH "resources/images/sky.png"
#define MAIN_MENU_TITLE_FILEPATH "resources/images/title.png"
#define MAIN_MENU_PLAY_BUTTON_FILEPATH "resources/images/PlayButton.png"

#define GAME_BACKGROUND_FILEPATH "resources/images/sky.png"
#define GAME_BACKGROUND_FILEPATH "resources/images/sky.png"

#define PIPE_UP_FILEPATH "resources/images/PipeUp.png"
#define PIPE_DOWN_FILEPATH "resources/images/PipeDown.png"
#define PIPE_MOVEMENT_SPEED 200.0f
#define PIPE_SPAWN_FREQUENCY 1.2f

#define PIPE_SCORING_FILEPATH "resources/images/InvisibleScoringPipe.png"

#define LAND_FILEPATH "resources/images/Land.png"

#define BIRD_FRAME_1_FILEPATH "resources/images/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "resources/images/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "resources/images/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "resources/images/bird-04.png"
#define BIRD_ANIMATION_DURATION 0.4f
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

#define GRAVITY 350.0f
#define FLYING_SPEED 350.0f
#define FLYING_DURATION 0.25f

#define ROTATION_SPEED 100.0f
#define MAX_ROTATION 25.0f

#define GAME_OVER_BACKGROUND_FILEPATH "resources/images/sky.png"
#define GAME_OVER_FLASH_SPEED 1500.0f

#define SIZE_SCORE_TEXT 128
#define FLAPPY_FONT_FILEPATH "resources/fonts/FlappyFont.ttf"
/*!
 * \enum GameStates
 * \brief игровые состояния мини игрового конечного автомата
 */
enum GameStates{
    eReady,
    ePlaying,
    eGameOver
};

#endif // DEFENITIONS_H
