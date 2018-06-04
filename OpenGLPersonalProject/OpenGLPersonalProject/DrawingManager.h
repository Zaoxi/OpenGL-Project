#include "DrawingObject.h"
#include "ViewController.h"

class DrawingManager
{
private :
	static DrawingManager * instance;
	DrawingObject * drawingObject;
	ViewController * viewController;
	DrawingManager();
public :
	static DrawingManager* GetInstance();
	DrawingObject* GetDrawingObject();
	ViewController* GetViewController();
	~DrawingManager();
};