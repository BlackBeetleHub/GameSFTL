#include "Game.h"


Game::Game()
{
}

void Game::run()
{
	window.create(VideoMode(1366, 768),"SlimeSpecial");
	GameLoop();
}


Game::~Game()
{
}

void Game::GameLoop()
{
	Object obj1;
	Object obj2;
	Object obj3;
	Object obj4;
	Texture objtext;
	if (!objtext.loadFromFile("sprites/terra/terra_platform.png")) {
		printf("error\n");
	}

	Texture fontext;
	if (!fontext.loadFromFile("sprites/terra/fon.jpg")) {
		printf("error\n");
	}
	Sprite fon;
	fon.setTexture(fontext);
	fon.setTextureRect(IntRect(0,0,1366,768));
	fon.setPosition(0, 0);
	obj1.create(&objtext, 95, 0, 161, 25, 400,400);
	obj2.create(&objtext, 95, 0, 161, 25, 200 , 600);
	obj3.create(&objtext, 95, 0, 161, 25 , 600 , 200);
	obj4.create(&objtext, 95, 0, 161, 25, 1000, 600);
	LvlWorld world;
	world.AddObject(obj1);
	world.AddObject(obj2);
	world.AddObject(obj3);
	world.AddObject(obj4);
	AnimationManager anim;
	Texture text;
	if (!text.loadFromFile("sprites/evil/hero.png")) {
		printf("error\n");
	}
	vector<IntRect> n;
	vector<IntRect> stay;
	vector<IntRect> attack;
	attack.push_back(IntRect(4, 140, 46, 52));
	attack.push_back(IntRect(60, 144, 50, 49));
	attack.push_back(IntRect(127, 147, 89, 49));
	stay.push_back(IntRect(324,9,47,57));
	stay.push_back(IntRect(381,9,47,59));
	stay.push_back(IntRect(441,11,46,57));
	n.push_back(IntRect(3, 80, 54, 48));
	n.push_back(IntRect(69, 80, 52, 48));
	n.push_back(IntRect(128,81,61,46));
	anim.create("Attack", text, attack, 0.004);
	anim.create("Walk", text, n, 0.002);
	anim.create("Stay", text, stay, 0.002);
	anim.set("Stay");
	anim.play();
	//std::cout << stay.size() << std::endl;
	int x, y;
	x = y = 200;
	Clock clock;
	bool ModeFly = false;
	bool flip = false;
	Clock grav;
	bool onGround = false;
	bool jump = false;
	int hjump = 0;
	while (window.isOpen())
	{
		
		float time = clock.getElapsedTime().asMicroseconds();
		float time2 = grav.getElapsedTime().asSeconds();
		clock.restart();
		Event even;
		time = time / 800;
		std::cout << time << endl;
		if (time > 20) {
			time = 20;
		}
		if (ModeFly) {
			onGround = false;
			//y += 1*time;
		}
		if (!onGround && !ModeFly) {
			y = y + 2 * time2 * time2 / 2;
		}

		onGround = false;
		for (int i = 0; i < world.terra.size(); i++) {
			int dy = world.terra[i].sprite.getPosition().y;
			int dx = world.terra[i].sprite.getPosition().x;
			int w = world.terra[i].sprite.getTextureRect().width;
			int h = world.terra[i].sprite.getTextureRect().height;
			if (y + 55 >= dy && y <= dy + world.terra[i].hight && dy + h > y + 55 && x + 50 > dx && x < dx + w) {
				y -= 1;
				onGround = true;
				grav.restart();
			}
		}
		if (y > 700) {
			y -= 5;
			onGround = true;
			grav.restart();
		}
		if (y < 0) {
			y += 5;
		}
		if (x < 0) {
			x += 5;
		}
		if (x > 1300) {
			x -= 5;
		}
		while (window.pollEvent(even))
		{
			if (even.type == Event::Closed)
				window.close();
		}
		anim.set("Stay");
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			anim.set("Stay");
			anim.flip(false);
			anim.set("Walk");
			anim.flip(false);
			x += 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
			anim.set("Stay");
			anim.flip(false);
			anim.set("Walk");
			anim.flip(false);
			x += 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::F)) {
			if (!ModeFly) {
				ModeFly = true;
			}
			else {
				ModeFly = false;
				grav.restart();
			}
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			anim.set("Stay");
			anim.flip(true);
			anim.set("Walk");
			anim.flip(true);
			x--;
		}
		if (Keyboard::isKeyPressed(Keyboard::E)) {
			anim.set("Attack");
		}
		if (Keyboard::isKeyPressed(Keyboard::A) && Keyboard::isKeyPressed(Keyboard::LShift)) {
			anim.set("Stay");
			anim.flip(true);
			anim.set("Walk");
			anim.flip(true);
			x -= 5;
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			anim.set("Walk");
			if(!jump){
				jump = true;
			}
		}

		if (hjump == 300) {
			jump = false;
			hjump = 0;
		}
		if (jump) {
			y--;
			hjump++;
				//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			anim.set("Walk");
			y++;
		}
	
		window.draw(fon);
		world.draw(window);
		anim.draw(window, x, y);
		anim.tick(time);
		window.display();
		window.clear(Color(255,255,255));
	}
}
