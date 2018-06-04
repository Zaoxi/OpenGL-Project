#include "DrawingManager.h"

DrawingManager * DrawingManager::instance = nullptr;

DrawingManager* DrawingManager::GetInstance()
{
	if (instance == nullptr) instance = new DrawingManager();
	return instance;
}

DrawingManager::DrawingManager()
{
	drawingObject = new DrawingObject();
	viewController = new ViewController();
}

DrawingManager::~DrawingManager()
{
	delete drawingObject;
	delete viewController;
}

DrawingObject* DrawingManager::GetDrawingObject()
{
	return drawingObject;
}

ViewController* DrawingManager::GetViewController()
{
	return viewController;
}