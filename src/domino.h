#ifndef domino_H_
#define domino_H_

#include "gameplay.h"
#include <string>

using namespace gameplay;

/**
 * Main game class.
 */
class domino: public Game
{
public:

    /**
     * Constructor.
     */
    domino();

    /**
     * @see Game::keyEvent
     */
	void keyEvent(Keyboard::KeyEvent evt, int key);
	
    /**
     * @see Game::touchEvent
     */
    void touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex);

protected:

    /**
     * @see Game::initialize
     */
    void initialize();

    /**
     * @see Game::finalize
     */
    void finalize();

    /**
     * @see Game::update
     */
    void update(float elapsedTime);

    /**
     * @see Game::render
     */
    void render(float elapsedTime);

private:

    /**
     * Draws the scene each frame.
     */
    bool drawScene(Node* node);
    void drawSplash(void* param);

    Scene* _scene;
    Form* _form;
    bool _touched;
    int _touchX;
    int _touchY;
    Node* _FichaA;
    Node* _FichaB;

};

#endif
