#include "domino.h"
#include <iostream>

// Declare our game instance
domino game;

domino::domino()

    : _scene(NULL), _touched(false), _touchX(0), _touchY(0)
{
}

void domino::initialize()
{
	// Display Intro Screen
	displayScreen(this, &domino::drawSplash, NULL, 1000L);

    // Load scene.
    _scene = Scene::load("res/scene.scene");
	// Update the aspect ratio for our scene's camera to match the current device resolution
    _scene->getActiveCamera()->setAspectRatio(getAspectRatio());

    //_form = Form::create("res/scene.form");
	//_FichaA = _scene->findNode("ficha66");

}

void domino::finalize()
{
	SAFE_RELEASE(_scene);

}

void domino::update(float elapsedTime)
{

}

void domino::render(float elapsedTime)
{
    // Clear the color and depth buffers
    clear(CLEAR_COLOR_DEPTH, Vector4::zero(), 1.0f, 0);

    // Visit all the nodes in the scene for drawing
    _scene->visit(this, &domino::drawScene);
}

bool domino::drawScene(Node* node)
{
    // If the node visited contains a model, draw it
    Model* model = node->getModel(); 
    if (model)
    {
        model->draw();
    }
    return true;
}

void domino::keyEvent(Keyboard::KeyEvent evt, int key)
{

    if (evt == Keyboard::KEY_PRESS)
    {
        switch (key)
        {
        case Keyboard::KEY_ESCAPE:
            exit();
            break;
        }
    }
}

void domino::touchEvent(Touch::TouchEvent evt, int x, int y, unsigned int contactIndex)
{

    switch (evt)
    {
    	case Touch::TOUCH_PRESS:
    	{

    	}
    	break;

    	case Touch::TOUCH_RELEASE:
    {


    }
        break;

    	case Touch::TOUCH_MOVE:
    {
    	int deltaX = x - _touchX;
        int deltaY = y - _touchY;

        _touchX = x;
        _touchY = y;

        Ray ray;

        Camera* camera = _scene->getActiveCamera();
        camera->pickRay(getViewport(), x, y, &ray);

        float distance;

        distance = ray.intersects(_scene->findNode("ficha00")->getBoundingSphere());
        if (distance != Ray::INTERSECTS_NONE){
        	_FichaA = _scene->findNode("ficha00");
        	//_scene->findNode("ficha00")->translateX(MATH_DEG_TO_RAD(deltaX * 0.5f));
        	//_scene->findNode("ficha00")->translateY(MATH_DEG_TO_RAD(deltaY * 0.5f));
        }
        _FichaA->translateX(MATH_DEG_TO_RAD(deltaX * 0.5f));
        _FichaA->translateY(MATH_DEG_TO_RAD(deltaY * -0.5f));
        /*
        distance = ray.intersects(_scene->findNode("ficha01")->getBoundingSphere());
        if (distance != Ray::INTERSECTS_NONE){
        _FichaA = _scene->findNode("ficha01");
		}
		distance = ray.intersects(_scene->findNode("ficha02")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha02");
		}
		distance = ray.intersects(_scene->findNode("ficha03")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha03");
		}
		distance = ray.intersects(_scene->findNode("ficha04")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha04");
		}
		distance = ray.intersects(_scene->findNode("ficha05")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha05");
		}
		distance = ray.intersects(_scene->findNode("ficha06")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha06");
		}
		distance = ray.intersects(_scene->findNode("ficha11")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha11");
		}
		distance = ray.intersects(_scene->findNode("ficha12")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha12");
		}
		distance = ray.intersects(_scene->findNode("ficha13")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha13");
		}
		distance = ray.intersects(_scene->findNode("ficha14")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha14");
		}
		distance = ray.intersects(_scene->findNode("ficha15")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha15");
		}
		distance = ray.intersects(_scene->findNode("ficha16")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha16");
		}
		distance = ray.intersects(_scene->findNode("ficha22")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha22");
		}
		distance = ray.intersects(_scene->findNode("ficha23")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha23");
		}
		distance = ray.intersects(_scene->findNode("ficha24")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha24");
		}
		distance = ray.intersects(_scene->findNode("ficha25")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha25");
		}
		distance = ray.intersects(_scene->findNode("ficha26")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha26");
		}
		distance = ray.intersects(_scene->findNode("ficha33")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha33");
		}
		distance = ray.intersects(_scene->findNode("ficha34")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha34");
		}
		distance = ray.intersects(_scene->findNode("ficha35")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha35");
		}
		distance = ray.intersects(_scene->findNode("ficha36")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha36");
		}
		distance = ray.intersects(_scene->findNode("ficha44")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha44");
		}
		distance = ray.intersects(_scene->findNode("ficha45")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha45");
		}
		distance = ray.intersects(_scene->findNode("ficha46")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha46");
		}
		distance = ray.intersects(_scene->findNode("ficha55")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha55");
		}
		distance = ray.intersects(_scene->findNode("ficha56")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha56");
		}
		distance = ray.intersects(_scene->findNode("ficha66")->getBoundingSphere());
		if (distance != Ray::INTERSECTS_NONE){
			_FichaA = _scene->findNode("ficha66");
		}
		*/
    }

    	break;
    }
}

void domino::drawSplash(void* param)
{
    clear(CLEAR_COLOR_DEPTH, Vector4(0, 0, 0, 1), 1.0f, 0);
    SpriteBatch* batch = SpriteBatch::create("res/logo_powered_white.png");
    batch->start();
    batch->draw(this->getWidth() * 0.5f, this->getHeight() * 0.5f, 0.0f, 512.0f, 512.0f, 0.0f, 1.0f, 1.0f, 0.0f, Vector4::one(), true);
    batch->finish();
    SAFE_DELETE(batch);
}

