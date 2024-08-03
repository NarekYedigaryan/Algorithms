#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <iostream>
#include <stack>
class TextEditor
{
public:
  void type(const std::string& value);
  void undo();
  void redo();
  void print();
private:
  std::stack<std::string> undoStack;
  std::stack<std::string> redoStack;
  std::string text;
  
  
};
#endif