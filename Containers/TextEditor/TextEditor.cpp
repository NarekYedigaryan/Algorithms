#include "./TextEditor.h"

void TextEditor::type(const std::string& value)
{
    undoStack.push(text);
    text += value; 
    while (!redoStack.empty())
    {
       redoStack.pop();
    }
    
}

void TextEditor::undo()
{
  if(!undoStack.empty())
  {
    redoStack.push(text);
    text = undoStack.top();
    undoStack.pop();
  }
}

void TextEditor::redo()
{
  if(!redoStack.empty())
  {
    text = redoStack.top();
    undoStack.push(text);
    redoStack.pop();

  }
}

void TextEditor::print()
{
  std::cout<<text<<std::endl;
}


