#include "Scene.hpp"

const int MET2PIX = 16; // 640 / 80 = 8

enum _moveState {
   MS_STOP,
   MS_LEFT,
   MS_RIGHT,
 };

 _moveState moveState;

float w_box = 0.5;
float h_box = 0.5;

const int WIDTH = 640;
const int HEIGHT = 480;

const int SCALED_WIDTH = WIDTH / MET2PIX;
const int SCALED_HEIGHT = HEIGHT / MET2PIX;

Scene::Scene():
  world(b2Vec2(0.0f, -30.0f))
{
  b2BodyDef groundBodyDef;
  groundBodyDef.position.Set(0.0f, -40.0f);

  groundBody = world.CreateBody(&groundBodyDef);

  b2PolygonShape groundBox;
  groundBox.SetAsBox(50.0f, 5.0f);

  groundBody->CreateFixture(&groundBox, 0.0f);

  b2BodyDef bodyDef;
  bodyDef.type = b2_dynamicBody;
  bodyDef.position.Set(0.0f, -10.0f);
  body = world.CreateBody(&bodyDef);

  b2PolygonShape dynamicBox;
  dynamicBox.SetAsBox(2.0f, 2.0f);

  b2FixtureDef fixtureDef;
  fixtureDef.shape = &dynamicBox;
  fixtureDef.density = 1.0f;
  //fixtureDef.friction = 1.0f;

  body->CreateFixture(&fixtureDef);
  moveState = MS_STOP;
}

Scene::~Scene() {}

void Scene::ProcessKeyboard(const uint8_t* state)
{
  b2Vec2 pos = body->GetPosition();

  moveState = MS_STOP;

	if (state[SDL_SCANCODE_RIGHT])
	{
    moveState = MS_RIGHT;
		//body->SetTransform(b2Vec2(pos.x + 0.16f, pos.y), body->GetAngle());
	}
	if (state[SDL_SCANCODE_LEFT])
	{
    moveState = MS_LEFT;
		//body->SetTransform(b2Vec2(pos.x - 0.16f, pos.y), body->GetAngle());
    //body->ApplyForce(b2Vec2(-400.0f, 0.0f),  body->GetWorldCenter(), true);
	}
  if (state[SDL_SCANCODE_SPACE])
	{
    //float impulse = body->GetMass() * 3.5f;
    //body->ApplyLinearImpulse(b2Vec2(0,impulse), body->GetWorldCenter(), true);
    body->ApplyLinearImpulse(b2Vec2(0,50), body->GetWorldCenter(), true);
	}
  if (state[SDL_SCANCODE_DOWN])
	{
    //body->ApplyForceToCenter(b2Vec2(10.0f, 0.0f), true);
	}
}

void Scene::update(float deltaTime) {
  int32 velocityIterations = 6;
  int32 positionIterations = 2;

  b2Vec2 vel = body->GetLinearVelocity();
  float desiredVel = 0;
  switch ( moveState )
  {
    case MS_LEFT:  desiredVel = -12; break;
    case MS_STOP:  desiredVel =  0; break;
    case MS_RIGHT: desiredVel =  12; break;
  }
  float velChange = desiredVel - vel.x;
  float force = body->GetMass() * velChange / deltaTime;
  body->ApplyForceToCenter( b2Vec2(force,0), true );

  world.Step(deltaTime, velocityIterations, positionIterations);
}

void Scene::render(SDL_Renderer* renderer) {
  SDL_SetRenderDrawColor(
    renderer,
    255,
    255,
    255,
    255
  );

  SDL_Rect groundBox;
  groundBox.w = static_cast<int>(100.f * MET2PIX);
  groundBox.h = static_cast<int>(10.0f * MET2PIX);
  groundBox.x = static_cast<int>(groundBody->GetPosition().x * MET2PIX);
  groundBox.y = static_cast<int>(-(groundBody->GetPosition().y + 5.0f) * MET2PIX);

  SDL_Rect box;
  box.w = static_cast<int>(4.0f * MET2PIX);
  box.h = static_cast<int>(4.0f * MET2PIX);
  box.x = static_cast<int>(body->GetPosition().x * MET2PIX);
  box.y = static_cast<int>(-(body->GetPosition().y + 2.0f) * MET2PIX);

  SDL_RenderFillRect(renderer, &groundBox);
  SDL_RenderFillRect(renderer, &box);
}
