export module ShapeFactory;

import <array>;
import <ranges>;
import <stdexcept>;
import <string_view>;

import Shape;
import Circle;
import Triangle;
import Rectangle;

export {
   using Shape = ShapeImpl<Circle, Rectangle, Triangle>;

   Shape MakeShape(std::string_view name)
   {
      const std::array prototypes{
         Shape(Circle()),
         Shape(Triangle()),
         Shape(Rectangle())
      };

      auto it = std::ranges::find(prototypes, name, &Shape::Name);
      if(it == prototypes.end())
         throw std::invalid_argument("Unknown shape type");

      return *it;
   }
};
