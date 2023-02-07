#ifndef DEFENITIONS_H
#define DEFENITIONS_H


/// \group SCREEN
/// \brief Параметры главного окна
#define SCREEN_TITLE "Flappy Bird"
#define SCREEN_WIDHT 768
#define SCREEN_HEIGHT 1024

/// \group SPLASH
/// \brief Параметры окна при включении
#define SPLASH_STATE_SHOW_TIME 2.0
#define SPLASH_SCENE_BACKGROUND_FILEPATH "resources/images/Splash Background.png"

/// \group MAIN_MENU
/// \brief Компонеты главного меню
#define MAIN_MENU_BACKGROUND_FILEPATH "resources/images/sky.png"
#define MAIN_MENU_TITLE_FILEPATH "resources/images/title.png"
#define MAIN_MENU_PLAY_BUTTON_FILEPATH "resources/images/PlayButton.png"

///\brief Задний фон
#define GAME_BACKGROUND_FILEPATH "resources/images/sky.png"

/// \group PIPE
/// \brief Компонеты труб
#define PIPE_UP_FILEPATH "resources/images/PipeUp.png"
#define PIPE_DOWN_FILEPATH "resources/images/PipeDown.png"
#define PIPE_SCORING_FILEPATH "resources/images/InvisibleScoringPipe.png"
///\brief Скорость перемещения труб
#define PIPE_MOVEMENT_SPEED 200.0f
///\brief Частота появления труб
#define PIPE_SPAWN_FREQUENCY 1.2f

/// \group LAND
/// \brief Компонеты земли
#define LAND_FILEPATH "resources/images/Land.png"

/// \group BIRD_FRAME
/// \brief Компоненты птицы
#define BIRD_FRAME_1_FILEPATH "resources/images/bird-01.png"
#define BIRD_FRAME_2_FILEPATH "resources/images/bird-02.png"
#define BIRD_FRAME_3_FILEPATH "resources/images/bird-03.png"
#define BIRD_FRAME_4_FILEPATH "resources/images/bird-04.png"

///\brief Частота обновления анимации (махания крыльями)
#define BIRD_ANIMATION_DURATION 0.4f

/// \group BIRD_STATE
/// \brief Состояния птицы в движении
#define BIRD_STATE_STILL 1
#define BIRD_STATE_FALLING 2
#define BIRD_STATE_FLYING 3

///\brief Гравитация при падении птицы
#define GRAVITY 350.0f
///\brief Скорость полета птицы
#define FLYING_SPEED 350.0f
///\brief Продолжительность полета птицы
#define FLYING_DURATION 0.25f

/// \group ROTATION
/// \brief Параметры поворота модельки птицы при падении и взлете
#define ROTATION_SPEED 100.0f
#define MAX_ROTATION 25.0f

/// \group GAME_OVER
/// \brief Компоненты окончания игры
#define GAME_OVER_BACKGROUND_FILEPATH "resources/images/sky.png"
#define GAME_OVER_FLASH_SPEED 1500.0f
#define GAME_OVER_TITLE_FILEPATH "resources/images/Game-Over-Title.png"
#define GAME_OVER_BODY_FILEPATH "resources/images/Game-Over-Body.png"
#define TIME_BEFORE_GAME_OVER 1.0f
#define GAME_OVER_SIZE_SCORE_TEXT 56

/// \group SCORE
/// \brief Параметры счета
#define SIZE_SCORE_TEXT 128
#define FLAPPY_FONT_FILEPATH "resources/fonts/FlappyFont.ttf"

/// \brief путь до файла с лучшим результатои
#define HIGH_SCORE_FILEPATH "resources/highscore.txt"

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
