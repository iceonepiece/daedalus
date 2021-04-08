#include "Window.hpp"

Window::Window(int width, int height)
:mWidth(width)
,mHeight(height)
{

}

Window::~Window()
{

}

bool Window::Initialize()
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

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGui::StyleColorsDark();

  ImGui_ImplSDL2_InitForOpenGL(mWindow, mContext);
  ImGui_ImplOpenGL3_Init("#version 330");

  return true;
}

void Window::Render()
{
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplSDL2_NewFrame(mWindow);
  ImGui::NewFrame();

  ImGui::Begin("Hello, world!");
  ImGui::Text("This is some useful text.");
  ImGui::End();

  ImGui::ShowDemoWindow(&show_demo_window);

  ImGui::Render();

  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  SDL_GL_SwapWindow(mWindow);
}

void Window::Destroy()
{
  SDL_GL_DeleteContext(mContext);
  SDL_DestroyWindow(mWindow);
  SDL_Quit();
}
