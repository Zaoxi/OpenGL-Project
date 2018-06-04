
class ViewController
{
private :
	void moveForward();
	void moveLeft();
	void moveRight();
	void moveBackward();
	void rotateRight();
	void rotateLeft();
	void rotateUp();
	void rotateBottom();
public :
	ViewController();
	void ReshapeFunc(int w, int h);
	void KeyboardFunc(unsigned char key, int x, int y);
	void MousePassiveFunc(int x, int y);
	
};