export module Circle;

import <iostream>;
import <string_view>;

export struct Circle {
   void Print() const { std::cout << "Hello, I'm Circle!\n"; }
   std::string_view Name() const { return "Circle"; }
};
