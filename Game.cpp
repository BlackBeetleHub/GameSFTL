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
	obj1.Create(&objtext, "block", 95, 0, 161, 25, 400,400,b2_staticBody,&World);
	obj2.Create(&objtext, "block", 95, 0, 161, 25, 200 , 600, b2_staticBody, &World);
	obj3.Create(&objtext, "block", 95, 0, 161, 25 , 600 , 200, b2_staticBody, &World);
	obj4.Create(&objtext, "block", 95, 0, 161, 25, 1000, 600, b2_staticBody, &World);
	//setWall(0, 0, 1, 768);
	setWall(-6830, 768, 13660, 1);
	setWall(-6830, -400, 13660, 1);
	//setWall(1366, 0, 1, 768);
	LvlWorld world;
	world.AddObject(obj1);
	world.AddObject(obj2);
	world.AddObject(obj3);
	world.AddObject(obj4);
	AnimationManager *anim = new AnimationManager();
	AnimationManager *animBot = new AnimationManager();
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
	anim->create("Attack", text, attack, 0.004f);
	anim->create("Walk", text, n, 0.002f);
	anim->create("Stay", text, stay, 0.002f);
	anim->set("Stay");
	anim->play();
	animBot->create("Attack", text, attack, 0.004f);
	animBot->create("Walk", text, n, 0.002f);
	animBot->create("Stay", text, stay, 0.002f);
	animBot->set("Stay");
	animBot->play();
	GameActor player;
	//Entity bot;
	//bot.Create("Bill",100,100,20,30,10,1,2,&World,animBot);
	player.Create(200, 200, 40, 60, 100, 10, 10, &World, anim);
	Camera camera;
	camera.init(&player);
	camera.bindSizeWindow(1366, 768);
	world.bindCamera(&camera);
	Object testo;
	testo.Create(&fontext, "Testo", 0, 0, 30, 30, 200, 200, b2_dynamicBody, &World);
	world.AddObject(testo);
	//world.AddObject(bot);
	Clock clock;
	MoveRight *R = new MoveRight();
	MoveLeft *L = new MoveLeft();
	MoveUp *U = new MoveUp();
	MoveDown *Down = new MoveDown();
	Attack *A = new Attack();
	MoveAttackRight *AD = new MoveAttackRight();
	MoveAttackLeft *AE = new MoveAttackLeft();
	InputHandler inputHandler;
	inputHandler.bindButtonA(R);
	inputHandler.bindButtonD(L);
	inputHandler.bindButtonW(U);
	inputHandler.bindButtonS(Down);
	inputHandler.bindButtonE(A);
	inputHandler.bindButtonsE_A(AE);
	inputHandler.bindButtonsE_D(AD);
	while (window.isOpen())
	{
		float time = static_cast<float>(clock.getElapsedTime().asMicroseconds());
		clock.restart();
		Event even;
		time = time / 800;
		if (time > 20) {
			time = 20;
		}

		if (Mouse::isButtonPressed(Mouse::Right)) {
			Vector2i mousePos = Mouse::getPosition();
			Object tes;
			tes.Create(&fontext, "Testo", 0, 0, 30, 30, mousePos.x, mousePos.y, b2_dynamicBody, &World);
			world.AddObject(tes);
		}
		while (window.pollEvent(even))
		{
			if (even.type == Event::Closed)
				window.close();
		}
		World.Step(1 / 60.f, 8, 3);
		Command* command = inputHandler.handleInput();
		if (command) {
			command->execute(player);
		}
		window.draw(fon);
		world.draw(window);
		anim->tick(time);
		animBot->tick(time);
		player.draw(window);
		for (b2Body* it = World.GetBodyList(); it != 0; it = it->GetNext()) {
			if (it->GetUserData() == "Player") {
				//player.draw(window);
			}
		}
		window.display();
		window.clear(Color(255,255,255));
	}
	delete R;
	delete L;
	delete U;
	//delete A;
	delete Down;
	delete AD;
	delete AE;
}
