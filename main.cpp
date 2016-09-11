#include <SFML/Graphics.hpp>


using namespace sf;

int ground = 800;
bool onGround;
bool onGround2;

struct Player
{
	Sprite s;
	Texture t;

	float dx, dy;
	float frame;
	FloatRect  rect;
	Player(char* file)
	{
		t.loadFromFile(file);
		s.setTexture(t);
		rect = FloatRect(0,0,60,70);
		s.setTextureRect(IntRect(0, 0, 50, 70));
		frame = 0;
		dx = 0; dy = 0;		
	}
	void update(float time)
	{
		rect.left +=dx*time;
		if(!onGround) dy += 0.0007*time;
		rect.top +=dy*time;
		if(rect.top > ground) 
		{
			rect.top = ground;
			onGround = onGround2 = true;
			dy = 0;
		}
		frame+=0.004*time;
		if(frame > 9.2) frame-=9;
		if(dx > 0) s.setTextureRect(IntRect(112+50*int(frame),0,50,70));
		if(dx < 0) s.setTextureRect(IntRect(112+50*int(frame)+50,0,-50,70));
		if(dy < -0.0001) s.setTextureRect(IntRect(50, 80, 50, 70));
		if(dy > 0.0001) s.setTextureRect(IntRect(10, 80, 45, 70));

		s.setPosition(rect.left, rect.top);
		dx = 0;
	}
};
int main()
{
	Player player("halo.png");
	sf::RenderWindow window(sf::VideoMode(1600, 900), "SFML");
	float frame = 0;
	Clock clock; 

        while (window.isOpen())
        {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time/500;
        	Event event;
        	while (window.pollEvent(event))
        	{
        		if (event.type == sf::Event::Closed)
                	window.close();
        	}
		if(Keyboard::isKeyPressed(Keyboard::Left))
		{
			player.dx = - 0.2;
		}
		if(Keyboard::isKeyPressed(Keyboard::Right))
		{
			player.dx =  0.2;
		}

		if(Keyboard::isKeyPressed(Keyboard::Up))
		{
			if(onGround)
			{
				player.dy -=  0.5;
				onGround = false;
				
			}
			
		}

		player.update(time);
       		window.clear();
        	window.draw(player.s);
        	window.display();
    	}
        return 0;
}
