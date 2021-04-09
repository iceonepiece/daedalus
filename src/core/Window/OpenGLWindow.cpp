#include "OpenGLWindow.hpp"

OpenGLWindow::OpenGLWindow(int width, int height)
:Window(width, height)
{}

OpenGLWindow::~OpenGLWindow()
{}

bool OpenGLWindow::Initialize()
{
  if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO) != 0)
  {
    SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
    return false;
  }

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

  mWindow = SDL_CreateWindow(
    "Daedalus Engine",
    SDL_WINDOWPOS_CENTERED,
    SDL_WINDOWPOS_CENTERED,
    mWidth,
    mHeight,
    (SDL_WindowFlags)(SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE|SDL_WINDOW_ALLOW_HIGHDPI)
  );

  if (!mWindow)
  {
    SDL_Log("Failed to create window: %s", SDL_GetError());
    return false;
  }

  mContext = SDL_GL_CreateContext(mWindow);

  if (glewInit() != GLEW_OK)
  {
    SDL_Log("Failed to initialize GLEW.");
    return false;
  }

  return true;
}

void OpenGLWindow::Destroy()
{
  SDL_GL_DeleteContext(mContext);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}

void OpenGLWindow::Run()
{
  ProcessInput();
  Update();
  Render();
}

void OpenGLWindow::ProcessInput()
{
  SDL_Event event;
  while (SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_QUIT:
        mApplication->Stop();
        break;
    }
  }

  const Uint8* state = SDL_GetKeyboardState(NULL);
  if (state[SDL_SCANCODE_ESCAPE])
  {
    mApplication->Stop();
  }

  // Do something here
}

void OpenGLWindow::Update()
{
  while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));

  float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000.0f;
  if (deltaTime > 0.05f)
  {
    deltaTime = 0.05f;
  }
  mTicksCount = SDL_GetTicks();

  // Do something here
}

void OpenGLWindow::Render()
{
  glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Do something here

  SDL_GL_SwapWindow(mWindow);
}
