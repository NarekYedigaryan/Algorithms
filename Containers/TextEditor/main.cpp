#include "./TextEditor.h"
#include <limits>
#include <string>
void functionality(TextEditor& obj)
{
   system("cls");
   std::cout<<"Write a text - 1"<<std::endl;
   std::cout<<"Print a text - 2"<<std::endl;
   std::cout<<"Undo - 3"<<std::endl;
   std::cout<<"Redo - 4"<<std::endl;
   std::cout<<"Exit - 5"<<std::endl;
   int operations;
   do
   {
       std::cout<<"Select One Of The Operations - ";
       std::cin>>operations;
       std::cout<<std::endl;

       std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
       if(operations == 1)
       {
         std::string text = "";
         std::cout<<"Enter a text - ";
         std::cin>>text;
         obj.type(text);
       }
       else if(operations == 2)
       {
         obj.print();
       }
       else if(operations == 3)
       {
         obj.undo();
       }
       else
       {
         obj.redo();
       }
   }
   while(operations != 5);
}

int main()
{
    TextEditor obj;
    functionality(obj);
}