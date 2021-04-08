#include "core/Editor.hpp"

int main(int argc, char** argv)
{
  Editor editor = Editor(1280, 720);

  bool success = editor.Initialize();

  if (success)
  {
    editor.Run();
  }

  editor.Destroy();

  return 0;
}
