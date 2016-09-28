#include "Game.h"

float const SCALE = 30.f;
const float DEG = 57.29577f;
b2Vec2 Gravity(0.f, 9.8f);
b2World World(Gravity);

float offsetx = 0;
float offsety = 0;

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

void setWall(int x, int y, int w, int h) {
	b2PolygonShape shape;
	shape.SetAsBox(static_cast<float32>(w/2), static_cast<float32>(h/2));
	b2BodyDef bdef;
	bdef.position.Set(static_cast<float32>(x + w/2), static_cast<float32>(y + h/2));
	b2Body *body = World.CreateBody(&bdef);
	body->CreateFixture(&shape, 1);
}

void Game::GameLoop()
{
	Object obj1;
	Object obj2;
	Object obj3;
	Object obj4;
	Texture objtext;
	objtext.setSmooth(true);
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
	setWall(400, 400, 161, 25);
	setWall(200, 600, 161, 25);
	setWall(600, 200, 161, 25);
	setWall(1000, 600, 161, 25);
	//setWall(0, 0, 1, 768);
	setWall(0, 768, 13660, 1);
	setWall(0, 0, 13660, 1);
	//setWall(1366, 0, 1, 768);
	LvlWorld world;
	world.AddObject(obj1);
	world.AddObject(obj2);
	world.AddObject(obj3);
	world.AddObject(obj4);
	AnimationManager anim;
	Texture text;
	text.setSmooth(true);
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
	anim.create("Attack", text, attack, 0.004f);
	anim.create("Walk", text, n, 0.002f);
	anim.create("Stay", text, stay, 0.002f);
	anim.set("Stay");
	anim.play();;
	int x, y;
	x = 400;
	y = 200;
	Clock clock;
	/*bool flip = false;
	b2PolygonShape shape;
	shape.SetAsBox(20 , 30);
	b2BodyDef bdef;
	bdef.type = b2_dynamicBody;
	bdef.position.Set(x + 20 , y + 30);
	b2Body *pbody = World.CreateBody(&bdef);
	pbody->CreateFixture(&shape, 1);
	pbody->SetUserData("player");*/
	GameActor player;
	player.create(200,200,40,60,100,10,10,&World,&anim);
	JumpCommand *jump = new JumpCommand();
	InputHandler inputHandler;
	inputHandler.bindButtonA(jump);
	inputHandler.bindButtonD(jump);
	inputHandler.bindButtonW(jump);
	inputHandler.bindButtonS(jump);
	while (window.isOpen())
	{
		float time = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		Event even;
		time = time / 800;
		if (time > 20) {
			time = 20;
		}
		while (window.pollEvent(even))
		{
			if (even.type == Event::Closed)
				window.close();
		}
		World.Step(1 / 60.f, 8, 3);
		anim.set("Stay");
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			anim.set("Stay");
			anim.flip(false);
			anim.set("Walk");
			anim.flip(false);
			pbody->ApplyLinearImpulse(b2Vec2(1000, 0), pbody->GetWorldCenter(), true);
			//world.scrool(-5, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::D) && Keyboard::isKeyPressed(Keyboard::LShift)) {
			anim.set("Stay");
			anim.flip(false);
			anim.set("Walk");
			anim.flip(false);
			x += 5;
		}
		if (Keyboard::isKeyPressed(Keyboard::F)) {
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			anim.set("Stay");
			anim.flip(true);
			anim.set("Walk");
			anim.flip(true);
			pbody->ApplyLinearImpulse(b2Vec2(-1000, 0), pbody->GetWorldCenter(), true);
			//world.scrool(5, 0);
			//scrool(-1, 0);
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
			pbody->ApplyLinearImpulse(b2Vec2(0, -9000), pbody->GetWorldCenter(), true);
			//world.scrool(0, -5);
		}

		if (Keyboard::isKeyPressed(Keyboard::S)) {
			anim.set("Walk");
			y++;
		}
		Command* command = inputHandler.handleInput();
		if (command) {
			command->execute(GameActor());
		}
		offsetx = pbody->GetPosition().x;
		offsety = pbody->GetPosition().y;
		window.draw(fon);
		world.draw(window , offsetx - 500, offsety -500);
		anim.tick(time);
		for (b2Body* it = World.GetBodyList(); it != 0; it = it->GetNext()) {
			if (it->GetUserData() == "player") {
				b2Vec2 pos = it->GetPosition();
				anim.draw(window, (int)pos.x - 20 - offsetx + 500, (int)pos.y -30 - offsety + 500);
			}
		}
		window.display();
		window.clear(Color(255,255,255));
	}
}
