import <array>;
import ShapeFactory;

int main()
{
   const std::array shapes = {
      MakeShape("Circle"),
      MakeShape("Rectangle"),
      MakeShape("Triangle")
   };

   for(const auto& s : shapes)
      s.Print();

   return 0;
}
